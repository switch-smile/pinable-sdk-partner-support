# Pinable SDK — iOS Integration Guide
### How to identify which campaign data the SDK is delivering (iOS)

The SDK has two delivery modes, determined by the `offerAction` field:

| Mode | `offerAction` | Who renders UI |
|---|---|---|
| **SIMPLE** | Starts with `pinablee_` | SDK shows its own popup |
| **NORMAL** | Any other value | App receives data and renders its own UI |

> Ministop currently uses **SIMPLE mode**.

---

## SIMPLE mode — read data from Notification

The SDK shows its own popup. To capture the campaign data being delivered, activate the detector in `AppDelegate` then observe in your view controller:

**AppDelegate.swift** — activate before SDK setup:

```swift
func application(_ application: UIApplication,
                 didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    SSBPPinableEDetector.activate()
    // ... SDK setup (setMaster, applicationNewActive, etc.)
}
```

**ViewController** — observe and read offer data:

```swift
NotificationCenter.default.addObserver(
    self,
    selector: #selector(onOfferDetected(_:)),
    name: Notification.Name(SSBPPinableEOfferWillShowNotification),
    object: nil
)

@objc private func onOfferDetected(_ note: Notification) {
    let raw = note.userInfo ?? [:]
    func str(_ key: String) -> String { raw[key] as? String ?? "" }

    let offerId = str("offerId")
    guard !offerId.isEmpty else { return }

    // ↓ At this point the app has the campaign data the SDK is delivering
    let campaignId  = offerId
    let title       = str("offerTitle")
    let desc        = str("offerDescription")
    let actionType  = str("type")             // "url" | "video" | "giftee" | …
    let targetUrl   = str("url")
    let offerAction = str("offerAction")      // starts with "pinablee_"
}
```

---

## NORMAL mode — read data from the SDK callback

Register `ssbpOnOfferReceive` callback:

```swift
guard let ssbp = SSBPSdkIF.sharedInstance() else { return }

ssbp.register(to: self, ssbpOnOfferReceive: { offer in
    guard let offer = offer else { return }

    // ↓ This callback is only called for NORMAL mode — app should render its own UI
    let campaignId = offer.offerId ?? ""
    let title      = offer.getValueText("offerTitle") ?? offer.getValueText("title") ?? ""
    let desc       = offer.getValueText("desc") ?? ""
    let actionType = offer.getValueText("type") ?? ""
    let targetUrl  = offer.getValueText("url") ?? ""
    let imageUrl   = offer.getValueLink("imageL") ?? ""
})
```

---

## Verifying with the sample app

Run `MinistopSdkSample-iOS` on a real device near a registered beacon.  
Filter Console by **`SSBP_SDK_EXT`** — you should see:

```
[SSBP_SDK_EXT] [14:32:10] SDK Monitoring Started (Waiting for Campaign...)
[SSBP_SDK_EXT] [14:33:01] 💎 SDK DATA IDENTIFIED: <title>  (id=…, mode=SIMPLE/SDK-UI)
```

`AppDelegate.swift` initializes the SDK; `HomeTableViewController.swift` implements both SIMPLE and NORMAL mode capture — use them as reference.
