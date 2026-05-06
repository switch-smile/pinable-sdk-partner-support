# Pinable SDK — Android Integration Guide
### How to identify which campaign data the SDK is delivering (Android)

The SDK has two delivery modes, determined by the `offerAction` field:

| Mode | `offerAction` | Who renders UI |
|---|---|---|
| **SIMPLE** | Starts with `pinablee_` | SDK shows its own popup |
| **NORMAL** | Any other value | App receives data and renders its own UI |

> Ministop currently uses **SIMPLE mode**.

---

## SIMPLE mode — read data from Activity lifecycle

The SDK shows its own popup without calling any app callback beforehand.  
To capture the campaign data being delivered, register `ActivityLifecycleCallbacks` in your `Application` class:

```kotlin
registerActivityLifecycleCallbacks(object : ActivityLifecycleCallbacks {

    private var lastLoggedKey = ""

    override fun onActivityCreated(activity: Activity, savedInstanceState: Bundle?) {
        readSdkPopup(activity)
    }

    override fun onActivityResumed(activity: Activity) {
        // The SDK may reuse the same Activity instance without recreating it,
        // so hook onActivityResumed as well and deduplicate by offerId.
        readSdkPopup(activity)
    }

    private fun readSdkPopup(activity: Activity) {
        val offerData: SSBPOfferData = activity.intent
            ?.getParcelableExtra(SSBPOfferManager.INTENT_EXTRA_OFFER_DATA)
            ?: return  // not an SDK popup — ignore

        val key = "${System.identityHashCode(activity)}_${offerData.offerId}"
        if (key == lastLoggedKey) return
        lastLoggedKey = key

        // ↓ At this point the app has the campaign data the SDK is delivering
        val campaignId = offerData.offerId
        val title      = offerData.title
        val desc       = offerData.desc
        val actionType = offerData.type        // "url" | "video" | "giftee" | …
        val targetUrl  = offerData.url
    }

    override fun onActivityStarted(activity: Activity) {}
    override fun onActivityPaused(activity: Activity) {}
    override fun onActivityStopped(activity: Activity) {}
    override fun onActivitySaveInstanceState(activity: Activity, outState: Bundle) {}
    override fun onActivityDestroyed(activity: Activity) {
        if (lastLoggedKey.startsWith("${System.identityHashCode(activity)}_"))
            lastLoggedKey = ""
    }
})
```

---

## NORMAL mode — read data from the SDK callback

Override `ssbpOnOfferReceive` in your `SSBPSdkListenerAdapter`:

```kotlin
SwitchSmile.setSSBPSdkScannerAdapter(object :
    SSBPSdkListenerAdapter(SSBPSdkIF.OfferBeaconSelectMode.NEAREST) {

    override fun ssbpOnOfferReceive(isForeground: Boolean, offer: TSsbpOffer?) {
        offer ?: return

        // offerTexts / offerLinks are JSON strings — parse to get display content
        val texts  = JSONObject(offer.offerTexts ?: "{}")
        val title  = texts.optString("offerTitle")
        val desc   = texts.optString("desc")
        val type   = texts.optString("type")
        val url    = texts.optString("url")

        val links  = JSONObject(offer.offerLinks ?: "{}")
        val imageL = links.optString("imageL")

        // isForeground=false → SDK is showing a system notification instead of a popup
    }
})
```

---

## Verifying with the sample app

Run `MinistopSdkSample-Android` on a real device near a registered beacon.  
Filter Logcat by tag **`SSBP_SDK_EXT`** — you should see:

```
[SSBP_SDK_EXT] [14:32:10] SDK Monitoring Started (Waiting for Campaign...)
[SSBP_SDK_EXT] [14:33:01] 💎 SDK DATA IDENTIFIED: <title>  (id=…, mode=SIMPLE/SDK-UI)
```

`MainApplication.kt` implements SIMPLE mode capture; `MainActivity.kt` implements NORMAL mode — use them as reference.
