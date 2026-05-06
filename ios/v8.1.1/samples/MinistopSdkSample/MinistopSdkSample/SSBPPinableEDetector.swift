import Foundation
import ObjectiveC

/// Posted on main thread before pinableE UI; userInfo: offerId, offerName, offerAction, offerTitle, offerDescription, type, url, thumbURL, imageL, _trigger.
let SSBPPinableEOfferWillShowNotification = "SSBPPinableEOfferWillShowNotification"

/// Swizzles `SSBPAnalyticsManager.sendAnalyticsOffer:sendEvent:` (Show=1) → posts notification above.
enum SSBPPinableEDetector {

    private static var originalIMP: IMP?

    /// Set from AppDelegate (avoid UIApplication inside swizzle).
    static var isInBackground = false

    /// Before `SSBPSdkIF` setup.
    static func activate() {
        _ = swizzleOnce
    }

    private static let swizzleOnce: Void = {
        let analyticsClass: AnyClass? = {
            if let cls = NSClassFromString("SSBPAnalyticsManager"),
               let getShared = class_getClassMethod(cls, NSSelectorFromString("sharedInstance")) {
                typealias SharedFn = @convention(c) (AnyClass, Selector) -> AnyObject
                let fn = unsafeBitCast(method_getImplementation(getShared), to: SharedFn.self)
                let instance = fn(cls, NSSelectorFromString("sharedInstance"))
                return object_getClass(instance)
            }
            return NSClassFromString("SSBPAnalyticsManager")
        }()

        guard let cls = analyticsClass else {
            NSLog("[SSBP_SDK_EXT] ⚠️ SSBPPinableEDetector: SSBPAnalyticsManager class not found")
            return
        }

        let sel = NSSelectorFromString("sendAnalyticsOffer:sendEvent:")
        guard let method = class_getInstanceMethod(cls, sel) else {
            NSLog("[SSBP_SDK_EXT] ⚠️ SSBPPinableEDetector: method sendAnalyticsOffer:sendEvent: not found")
            return
        }

        originalIMP = method_getImplementation(method)

        // SSBPAnalyticsOfferActionType: Tap=0, Show=1, Swipeout=2, Close=3
        let block: @convention(block) (AnyObject, AnyObject, Int) -> Void = { selfObj, offer, event in

            if let imp = SSBPPinableEDetector.originalIMP {
                typealias Fn = @convention(c) (AnyObject, Selector, AnyObject, Int) -> Void
                unsafeBitCast(imp, to: Fn.self)(selfObj, sel, offer, event)
            }

            guard event == 1 else { return } // 1 = Show

            let offerId     = readStr(offer, "offerId")
            let offerName   = readStr(offer, "offerName")
            let offerAction = readStr(offer, "offerAction")
            let offerTitle  = readStr(offer, "offerTitle")
            let offerDesc   = readStr(offer, "offerDescription")
            let offerType   = readStr(offer, "type")
            let url         = readStr(offer, "url")
            let thumbURL    = readStr(offer, "thumbURL")
            let imageL      = readStr(offer, "imageL")

            guard !offerId.isEmpty else { return }

            let trigger = SSBPPinableEDetector.isInBackground ? "swizzle-bg" : "swizzle"

            let info: [String: Any] = [
                "offerId":          offerId,
                "offerName":        offerName,
                "offerAction":      offerAction,
                "offerTitle":       offerTitle,
                "offerDescription": offerDesc,
                "type":             offerType,
                "url":              url,
                "thumbURL":         thumbURL,
                "imageL":           imageL,
                "_trigger":         trigger,
            ]

            if Thread.isMainThread {
                NotificationCenter.default.post(
                    name: Notification.Name(SSBPPinableEOfferWillShowNotification),
                    object: nil, userInfo: info)
            } else {
                DispatchQueue.main.async {
                    NotificationCenter.default.post(
                        name: Notification.Name(SSBPPinableEOfferWillShowNotification),
                        object: nil, userInfo: info)
                }
            }
        }

        method_setImplementation(method, imp_implementationWithBlock(block))
        NSLog("[SSBP_SDK_EXT] ✅ SSBPPinableEDetector: swizzle active on %@", NSStringFromClass(cls))
    }()

    private static func readStr(_ obj: AnyObject, _ key: String) -> String {
        let sel = NSSelectorFromString(key)
        guard obj.responds(to: sel) else { return "" }
        guard let result = obj.perform(sel)?.takeUnretainedValue() else { return "" }
        return (result as? NSString) as String? ?? ""
    }
}
