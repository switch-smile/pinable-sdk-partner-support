package com.ministop.sdk.sample

import android.app.Activity
import android.app.Application
import android.os.Bundle
import android.util.Log
import jp.pinable.ssbp.core.model.SSBPOfferData
import jp.pinable.ssbp.lite.SSBPOfferManager

/**
 * ============================================================
 * [SIMPLE MODE] — Capture offer data when the SDK shows its own popup
 * ============================================================
 *
 * Simple mode (offerAction starts with "pinablee_"):
 *   - The SDK fetches data from the server and renders its own popup.
 *   - ssbpOnOfferReceive is NOT fired before the popup appears.
 *   - The only way to know what is being displayed:
 *     → Listen to Activity lifecycle and read SSBPOfferData from the Intent
 *       of SSBPOfferPopupActivity.
 *
 * Why we hook both onActivityCreated AND onActivityResumed:
 *   - First show: SDK creates a new Activity → onActivityCreated fires.
 *   - Subsequent shows: SDK may reuse the existing Activity (singleTask /
 *     REORDER_TO_FRONT flags), so onActivityCreated does NOT fire again.
 *     onActivityResumed fires in both cases.
 *   - We track the last logged offerId to avoid duplicate log entries when
 *     both callbacks fire for the same Activity instance.
 *
 * Key fields in SSBPOfferData:
 *   - offerId     : Campaign ID
 *   - title       : Title displayed on the popup
 *   - desc        : Description / body text
 *   - type        : Action type (url, video, giftee…)
 *   - url         : Destination URL when the user taps the button
 *   - offerAction : "pinablee_popup", "pinablee_video"… — confirms Simple mode
 */
class MainApplication : Application() {

    companion object {
        // Provide application context for SharedPreferences access in companion methods
        lateinit var instance: MainApplication
    }

    override fun onCreate() {
        super.onCreate()
        instance = this
        // Restore logs saved before the process was killed
        MainActivity.loadPersistedLogs(this)

        registerActivityLifecycleCallbacks(object : ActivityLifecycleCallbacks {

            // Track last logged offer to prevent duplicate entries
            private var lastLoggedKey = ""

            override fun onActivityCreated(activity: Activity, savedInstanceState: Bundle?) {
                logSdkPopupIfPresent(activity)
            }

            override fun onActivityResumed(activity: Activity) {
                // Catches the case where SDK reuses the Activity (no onActivityCreated)
                logSdkPopupIfPresent(activity)
            }

            private fun logSdkPopupIfPresent(activity: Activity) {
                val offerData: SSBPOfferData = activity.intent
                    ?.getParcelableExtra(SSBPOfferManager.INTENT_EXTRA_OFFER_DATA)
                    ?: return

                // Dedup: same offer already logged in this activity instance
                val key = "${System.identityHashCode(activity)}_${offerData.offerId}"
                if (key == lastLoggedKey) return
                lastLoggedKey = key

                // -------------------------------------------------------
                // At this point the app has full data for whatever the SDK
                // is currently displaying → use for tracking / analytics
                // -------------------------------------------------------
                val title = offerData.title?.ifBlank { null }
                    ?: offerData.offerName
                    ?: offerData.offerId?.toString()
                    ?: "Unknown"
                val msg = "[${MainActivity.TAG}] [${MainActivity.now()}]" +
                        " 💎 SDK DATA IDENTIFIED: $title" +
                        " (id=${offerData.offerId}, mode=SIMPLE/SDK-UI)"

                Log.i(MainActivity.TAG, msg)
                Log.d(MainActivity.TAG,
                    "  title       = ${offerData.title}\n" +
                    "  desc        = ${offerData.desc}\n" +
                    "  type        = ${offerData.type}\n" +
                    "  url         = ${offerData.url}\n" +
                    "  offerAction = ${offerData.offerAction}"
                )

                MainActivity.appendLog(msg)
            }

            override fun onActivityStarted(activity: Activity) {}
            override fun onActivityPaused(activity: Activity) {}
            override fun onActivityStopped(activity: Activity) {}
            override fun onActivitySaveInstanceState(activity: Activity, outState: Bundle) {}
            override fun onActivityDestroyed(activity: Activity) {
                // Reset dedup key when SDK activity is destroyed
                if (lastLoggedKey.startsWith("${System.identityHashCode(activity)}_")) {
                    lastLoggedKey = ""
                }
            }
        })
    }
}
