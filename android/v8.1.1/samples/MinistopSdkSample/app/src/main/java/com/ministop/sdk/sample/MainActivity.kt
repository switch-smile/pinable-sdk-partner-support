package com.ministop.sdk.sample

import android.content.Context
import android.content.Intent
import android.os.Build
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import com.ministop.sdk.sample.databinding.ActivityMainBinding
import jp.pinable.ssbp.core.db.TSsbpOffer
import jp.pinable.ssbp.lite.SSBPSdkIF
import jp.pinable.ssbp.lite.SSBPSdkListenerAdapter
import jp.pinable.ssbp.lite.SwitchSmile
import org.json.JSONArray
import org.json.JSONObject
import java.text.SimpleDateFormat
import java.util.Date
import java.util.Locale

/**
 * ============================================================
 * How to identify which data the SDK is displaying
 * ============================================================
 *
 * The SDK operates in two modes, determined by offerAction:
 *
 * 1. NORMAL mode  (offerAction does NOT start with "pinablee_")
 *    → SDK calls SdkOfferListener.ssbpOnOfferReceive() with full JSON data.
 *    → The app is responsible for parsing and rendering its own UI.
 *    → See: SdkOfferListener below.
 *
 * 2. SIMPLE mode  (offerAction starts with "pinablee_")
 *    → SDK renders its own popup; ssbpOnOfferReceive is NOT called.
 *    → Capture offer data via ActivityLifecycleCallbacks when SDK Activity is created.
 *    → See: MainApplication.kt
 *
 * Background notification:
 *    When the app is in the background, the SDK shows a system notification instead
 *    of a popup. ssbpOnOfferReceive still fires (process is alive) and the offer is
 *    logged to logHistory. When the user brings the app to foreground, logs are replayed.
 *    If the app was killed, data is captured when the user taps the notification
 *    (SSBPOfferPopupActivity is created → MainApplication.onActivityCreated fires).
 *
 * Logcat filter tag: SSBP_SDK_EXT
 * ============================================================
 */
class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private val logAdapter = LogAdapter()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        instance = this

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        binding.rvLogs.layoutManager = LinearLayoutManager(this)
        binding.rvLogs.adapter = logAdapter

        // Replay all logs captured while Activity was gone (background / killed)
        logHistory.forEach { logAdapter.addLog(it) }
        if (logHistory.isNotEmpty()) {
            binding.rvLogs.scrollToPosition(logAdapter.itemCount - 1)
        }

        SwitchSmile.init(this)

        // Required: create the notification channel the SDK uses when app is in background.
        // Without this call, SDK has no channel to post notifications → no notification shows.
        SwitchSmile.setOfferNotificationChannel("Ministop SDK Offers", "ministop_sdk_offers")

        SwitchSmile.setSSBPSdkScannerAdapter(SdkOfferListener())

        // Required: tell the SDK the Activity is starting and pass the launch Intent.
        // If the user tapped a notification while the app was killed, this is the signal for
        // the SDK to re-show the popup instead of just opening the home screen.
        SwitchSmile.setNotificationIntent(intent)
        SSBPSdkIF.getInstance().applicationStartActive(this, savedInstanceState)

        requestNotificationPermission()

        if (SwitchSmile.requirePermission(this)) {
            SwitchSmile.start()
        }

        if (logHistory.isEmpty()) {
            val startMsg = "[$TAG] [${now()}] SDK Monitoring Started (Waiting for Campaign...)"
            Log.i(TAG, startMsg)
            appendLog(startMsg)
        }
    }

    // Called when activity is already running (singleTop) and user taps a notification.
    // Without this, tapping a notification while the app is in foreground/background does nothing.
    override fun onNewIntent(intent: Intent) {
        super.onNewIntent(intent)
        setIntent(intent)
        SwitchSmile.setNotificationIntent(intent)
        SSBPSdkIF.getInstance().applicationUpdateActive(this, intent)
    }

    override fun onResume() {
        super.onResume()
        // Required: tell the SDK the app is now in foreground.
        // Without this call, the SDK always thinks the app is in background and will
        // post a notification instead of showing the popup — even when the screen is visible.
        SSBPSdkIF.getInstance().applicationResumeActive(this)
    }

    override fun onDestroy() {
        super.onDestroy()
        if (instance == this) instance = null
    }

    private fun requestNotificationPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            if (checkSelfPermission(android.Manifest.permission.POST_NOTIFICATIONS)
                != android.content.pm.PackageManager.PERMISSION_GRANTED
            ) {
                requestPermissions(
                    arrayOf(android.Manifest.permission.POST_NOTIFICATIONS),
                    REQ_NOTIFICATION_PERMISSION
                )
            }
        }
    }

    /** Called from UI thread only — updates the RecyclerView. */
    fun refreshUI(message: String) {
        logAdapter.addLog(message)
        binding.rvLogs.scrollToPosition(logAdapter.itemCount - 1)
    }

    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<out String>,
        grantResults: IntArray,
    ) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        SwitchSmile.onPermissionResult(requestCode, permissions, grantResults, this)
    }

    // ================================================================
    // SdkOfferListener — extend SSBPSdkListenerAdapter
    // ================================================================
    // NOT an inner class → holds NO reference to MainActivity.
    // Writes directly to the static logHistory so data is never lost,
    // regardless of whether the Activity is alive or in the background.
    //
    // Register via: SwitchSmile.setSSBPSdkScannerAdapter(SdkOfferListener())
    //
    // ssbpOnOfferReceive is called when the SDK receives an offer from the server.
    // isForeground = false means the app was in background — SDK will show a
    // system notification instead of the popup.
    //
    // TSsbpOffer key fields:
    //   - offerId     : Campaign ID
    //   - offerName   : Campaign name (internal)
    //   - offerAction : Starts with "pinablee_" → SIMPLE mode; otherwise → NORMAL mode
    //   - offerTexts  : JSON string — display content (offerTitle, desc, type, url)
    //   - offerLinks  : JSON string — image URLs (imageL, imageS, thumb)
    // ================================================================
    private class SdkOfferListener :
        SSBPSdkListenerAdapter(SSBPSdkIF.OfferBeaconSelectMode.NEAREST) {

        override fun ssbpOnOfferReceive(isForeground: Boolean, offer: TSsbpOffer?) {
            offer ?: return

            val isSimple = offer.offerAction?.lowercase()?.startsWith("pinablee_") == true
            val mode = if (isSimple) "SIMPLE/SDK-UI" else "NORMAL/APP-JSON"
            // isForeground=false → SDK will show notification; popup will not appear
            val display = if (isForeground) mode else "$mode [notification]"
            val title = parseOfferTitle(offer.offerTexts) ?: offer.offerName ?: "Unknown"

            val msg = "[$TAG] [${now()}] 💎 SDK DATA IDENTIFIED: $title" +
                    " (id=${offer.offerId}, mode=$display)"
            Log.i(TAG, msg)
            Log.d(TAG,
                "  offerName   = ${offer.offerName}\n" +
                "  offerAction = ${offer.offerAction}\n" +
                "  isForeground= $isForeground\n" +
                "  offerTexts  = ${offer.offerTexts}\n" +
                "  offerLinks  = ${offer.offerLinks}"
            )

            // Always persist — no Activity reference needed
            appendLog(msg)
        }
    }

    companion object {
        const val TAG = "SSBP_SDK_EXT"
        private const val REQ_NOTIFICATION_PERMISSION = 1001
        private const val PREFS_NAME = "ssbp_logs"
        private const val PREFS_KEY = "log_history"
        private const val MAX_PERSISTED_LOGS = 200

        var instance: MainActivity? = null
        val logHistory = mutableListOf<String>()

        fun now(): String = SimpleDateFormat("HH:mm:ss", Locale.getDefault()).format(Date())

        /**
         * Load logs saved to SharedPreferences before the process was killed.
         * Called once from MainApplication.onCreate() before any Activity starts.
         */
        fun loadPersistedLogs(context: Context) {
            if (logHistory.isNotEmpty()) return
            val prefs = context.getSharedPreferences(PREFS_NAME, Context.MODE_PRIVATE)
            val raw = prefs.getString(PREFS_KEY, null) ?: return
            try {
                val arr = JSONArray(raw)
                for (i in 0 until arr.length()) logHistory.add(arr.getString(i))
            } catch (_: Exception) {}
        }

        /**
         * Persist log entry, save to disk, and update UI if Activity is alive.
         * Safe to call from any thread, any lifecycle state.
         */
        fun appendLog(message: String) {
            logHistory.add(message)
            // Keep list bounded so SharedPreferences doesn't grow forever
            if (logHistory.size > MAX_PERSISTED_LOGS) logHistory.removeAt(0)
            persistLogs()
            Handler(Looper.getMainLooper()).post {
                instance?.refreshUI(message)
            }
        }

        private fun persistLogs() {
            try {
                val context = MainApplication.instance
                val arr = JSONArray(logHistory)
                context.getSharedPreferences(PREFS_NAME, Context.MODE_PRIVATE)
                    .edit().putString(PREFS_KEY, arr.toString()).apply()
            } catch (_: Exception) {}
        }

        fun parseOfferTitle(offerTexts: String?): String? {
            if (offerTexts.isNullOrBlank()) return null
            return try {
                val json = JSONObject(offerTexts)
                json.optString("offerTitle").ifBlank { null }
                    ?: json.optString("title").ifBlank { null }
            } catch (_: Exception) {
                null
            }
        }
    }
}
