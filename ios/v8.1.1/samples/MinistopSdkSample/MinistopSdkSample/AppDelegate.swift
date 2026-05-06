import UIKit
import SSBPLite
import UserNotifications

@main
class AppDelegate: UIResponder, UIApplicationDelegate, UNUserNotificationCenterDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {

        SSBPPinableEDetector.activate()

        UNUserNotificationCenter.current().delegate = self
        UNUserNotificationCenter.current().requestAuthorization(
            options: [.alert, .sound, .badge]
        ) { granted, error in
            if let error { print("[SSBP] Notification auth error: \(error)") }
            else { print("[SSBP] Notification permission granted: \(granted)") }
        }

        if let ssbp = SSBPSdkIF.sharedInstance() {
            configureSdkMasterAndActivate(ssbp)
        }

        window = UIWindow(frame: UIScreen.main.bounds)
        window?.rootViewController = UINavigationController(rootViewController: HomeTableViewController())
        window?.makeKeyAndVisible()
        return true
    }

    /// Pinable SDK How To Use (iOS) v8.0 Step 4: after `setMaster`, finish init in `didFinishCheckMaster`, then call `applicationNewActive`.
    /// Reference: `applicationNewActive` reads `app_info.csv`. Do not call `applicationNewActive` before master check succeeds when using `setMaster`.
    private func configureSdkMasterAndActivate(_ ssbp: SSBPSdkIF) {
        let infos = ssbp.getAppInfos() as? [TSsbpApp] ?? []

        ssbp.registerDisplayOfferAdPopup()

        guard let name = infos.first?.appName, !name.isEmpty else {
            NSLog("[SSBP] ⚠️ app_info.csv: no app row / empty appName — setMaster skipped; calling applicationNewActive without master sync.")
            ssbp.applicationNewActive()
            return
        }

        if infos.count > 1 {
            NSLog("[SSBP] Multiple rows in app_info.csv — sample uses first row appName: %@", name)
        }

        ssbp.register(to: self, didFinishCheckMaster: { error in
            if let error {
                NSLog("[SSBP] didFinishCheckMaster error: %@ — activating SDK anyway", error.localizedDescription)
            }
            DispatchQueue.main.async {
                ssbp.applicationNewActive()
            }
        })
        ssbp.setMaster(name)
    }

    // MARK: - UNUserNotificationCenterDelegate

    func userNotificationCenter(_ center: UNUserNotificationCenter,
                                willPresent notification: UNNotification,
                                withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        completionHandler([.alert, .sound])
    }

    func userNotificationCenter(_ center: UNUserNotificationCenter,
                                didReceive response: UNNotificationResponse,
                                withCompletionHandler completionHandler: @escaping () -> Void) {
        if let offerId = response.notification.request.content.userInfo["offerId"] as? String {
            HomeTableViewController.markOfferTapPending(offerId)
        }
        SSBPSdkIF.sharedInstance()?.applicationDidReceiveLocalNotification(response)
        completionHandler()
    }

    // MARK: - App lifecycle

    func applicationDidBecomeActive(_ application: UIApplication) {
        SSBPPinableEDetector.isInBackground = false
        SSBPSdkIF.sharedInstance()?.applicationBecomeActive()
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        SSBPPinableEDetector.isInBackground = true
        SSBPSdkIF.sharedInstance()?.applicationEnterBackground()
    }

    func applicationWillTerminate(_ application: UIApplication) {
        SSBPSdkIF.sharedInstance()?.applicationTerminateCompleted(nil)
    }

}
