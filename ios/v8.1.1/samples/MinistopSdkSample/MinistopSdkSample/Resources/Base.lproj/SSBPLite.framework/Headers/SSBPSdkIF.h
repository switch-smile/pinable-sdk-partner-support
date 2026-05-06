///
///  SSBPSdkIF.h\n
///  SSBPSdk\n
/// The SSBPSdkIF class communicates to SDK from the application. This class is used for starting detection of beacon and geofence, after-detection content reference and log registration. You can do the basic SDK processing with this class.\n
///  Created by Ayumi Togashi on 2016/04/22.\n
///  Copyright © 2016年 Switch Smile co.,ltd. All rights reserved.
///

#ifndef SSBP_AppSDK_Static_SSBPSdkIF_h
#define SSBP_AppSDK_Static_SSBPSdkIF_h

#import <Foundation/Foundation.h>
#import "SSBPScannerManager.h"
#import "SSBPConfig+Lite.h"
#import "BaseRequest.h"
#import "SSBPOfferIF.h"
#import "TSsbpApp.h"
#import "SSBPCustomerId.h"

typedef NS_ENUM (NSInteger, GeofenceDebug) {
    kNone = -1,
    kStandard = 0,
    kFull = 1,
    kEnhanced = 2
};

typedef NS_ENUM (NSInteger, LogDebug) {
    LogDebugNone = 0,
    LogDebugFull = 1
};

typedef NS_ENUM(NSUInteger, OfferBeaconSelectMode) {
    OfferBeaconSelectModeNearest = 0,
    OfferBeaconSelectModeLatest
};
/// By execute getUuid method, notification complete regardless of result is success or failure. Assume that executing detection start after using this notification
typedef void (^DidStart)(void);
/// Notify the gotten GPS information When getting GPS information, it is called when there is a change in latitude and longitude and error information
/// @param error \n
/// Type: NSError \n
/// Value: Error
typedef void (^DidFinishLocation)(NSError *error);
/// Notify as log message of SDK.\n
/// Timing that may be used as application operation (consider adding on request).
/// @param type \n
/// Type: NSString \n
/// Value: \n
/// EnterRegion:beacon area In notification ExitRegion:beacon area Out notification\n RangeBeacon: notification before interval check Regard with corresponding beacon check\n EnterGeofence:geofence area In notification\n
/// ExitGeofence:geofence area Out notification\n
/// EnteredGeofence:geofence area In completed notification\n
/// ExitedGeofence:geofence area Out completed notification
/// @param title \n
/// Type: NSString \n
/// Value: \n
/// Message title \n
/// ※When type is EnterGeofence/ExitGeofence/EnteredGeofence/ExitedGeofence, it’s geofenceId
/// @param message \n
/// Type: NSString \n
/// Value: Message offer
typedef void (^DidMessage)(NSString *type, NSString *title, NSString *message);
/// Notify corresponding geofence that is detected.\n
/// Notify at the timing of joining in near the set area\n
/// Assume that execute offer getting and message displaying to notification area, by using this notification.
/// @param geofenceId \n
/// Type: NSString \n
/// Value: Detected geofenceID
typedef void (^ScannerHitGeofence)(NSString *geofenceId, NSString *message);
typedef void (^ScannerHitGeofenceOffers)(NSArray<SSBPOffer *> *ssbpOffers, NSString *geofenceId);
/// Notify corresponding beacon that is detected.\n
/// Notify at the timing when interval is added according with uuid/major/minor and proximity condition of beacon information.\n
/// Assume that execute offer getting after using this notification.
/// @param beacon TSsbpBeacon object
typedef void (^ScannerHitBeacon)(TSsbpBeacon *beacon);
typedef void (^ScannerHitBeaconOffers)(NSArray<SSBPOffer *> *ssbpOffers, TSsbpBeacon *beacon);

typedef void (^SsbpOnOfferReceive)(SSBPOffer *ssbpOffer);

typedef void (^DidChangeNearest)(NSString *beaconId);
typedef void (^DidChangeBeacon)(SSBPRegionInfo *info);
typedef void (^WatchBeaconsDetected)(NSDictionary<NSString *, NSArray<TSsbpBeacon *> *> *beacons);

typedef void (^DidFinishHeading)(CLHeading *heading);

typedef void (^DidFinishCheckMaster)(NSError *error);
typedef void (^DidFinishUpdateDeviceInfo)(void);
typedef void (^DidAddOffer)(NSString *offerId, SSBPOfferStatus status);

typedef void (^DidReceiveAds)(NSString *type, NSString *header, NSString *body);
// Location authorization status
typedef void (^DidChangeLocationAuthorizationStatus)(CLAuthorizationStatus status);
//Entry/Exit ranging callback
typedef void (^DidEnterRegion)(NSString *UUID, int major, int minor, NSString *message);
typedef void (^DidExitRegion)(NSString *UUID, int major, int minor, NSString *message);
//Checkin-Checkout callbacks
typedef void (^DidCheckin)(TSsbpBeacon *checkinBeacon);
typedef void (^DidCheckout)(TSsbpBeacon *checkoutBeacon);
typedef void (^OnOpenCouponPocketList)(void);
/// The SSBPSdkIF class communicates to SDK from the application. This class is used for starting detection of beacon and geofence, after-detection content reference and log registration. You can do the basic SDK processing with this class.
@interface SSBPSdkIF : NSObject

@property (strong, nonatomic) SSBPConfig *config;

/// SSBP App name.\n
/// Read-only.\n
/// Initial value: empty string.\n
/// App name get from CSV.
@property (copy, nonatomic, readonly) NSString *appName;
/// SSBP App key.\n
/// Read-only.\n
/// Initial value is empty string.\n
/// SSBP App key get from CSV.
@property (copy, nonatomic, readonly) NSString *appKey;
/// SSBP secret key.\n
/// Read-only.\n
/// Initial value is empty string.\n
/// SSBP secret key get from CSV.
@property (copy, nonatomic, readonly) NSString *secretKey;
/// Used as the corresponding language when acquiring information. corresponding to multiple languages.\n
/// Read-Write.\n
/// Value can be set using SSBPManager setDeviceLocale method.
@property (copy, nonatomic) NSString *localeId;
/// Used as a standard language for acquiring multilingual information.\n
/// Read-only.\n
/// SSBPManager setDeviceLocale method.
@property (copy, nonatomic, readonly) NSString *localeDefault;
/// A unique device ID is registered in association with this device ID and it is used for discriminating the target etc.\n
/// Read-only.\n
/// SSBPManager updateDeviceInfo method.
@property (copy, nonatomic, readonly) NSString *deviceId;
/// Device token use for push notification.\n
/// Read-only.
@property (copy, nonatomic, readonly) NSString *deviceToken;
/// A random device identifier.\n
/// Read-Write.\n
/// The Identifier for Advertisers (known as the IDFA) is a random device identifier assigned by Apple to a user's device. Advertisers use this identifier to track data so they can deliver customized advertising.\n
/// idfa is declared as a property in SSBPSdkIF class.
@property (readonly, copy, nonatomic) NSString *idfa;
/// Access of SSBPScannerManager class
@property (strong, nonatomic) SSBPScannerManager *ssbpScanner;
/// Access of SSBPOfferIF class
@property (strong, nonatomic) SSBPOfferIF *ssbpOffer;

@property (assign, nonatomic) GeofenceDebug ssbpGeofenceDebug;
@property (assign, nonatomic) LogDebug ssbpLogDebug;
/// SHARED_INSTANCE to use as singleton instance.\n
/// Please don’t use alloc init and copy.
+ (SSBPSdkIF *)sharedInstance;
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead.")));
/// Get App info from CVS by SSBPCsvIF.
- (NSArray<TSsbpApp *> *)getAppInfos;
/// Update the setting with appName corresponding application information, and reconstruct the internally held data with latest information. Here, the Master means, app name. If appName does not apply, we will rebuild the data internally held in the current setting with the latest information. It can be used for data corruption etc. When processing is completed, it is notified by didFinishCheckMaster callback of SSBPSdkIF.\n
/// Eg: [[SSBPSdkIF sharedInstance] setMaster:<APP_NAME>];
- (void)setMaster:(NSString *)appName;

/// getting sdk run control. \n
/// Setting is 0 -> All function is nomar\n
/// Setting is 1 -> Stop detect beacon, request offer\n
/// Setting is 2 -> only dectect beacon and send beacon logs.\n
- (int) sdkRunControl;
/// After the splash screen, the necessary processing as the initial motion is executed. Processing such as application authentication, corresponding language acquisition, device ID issuance, resource development of BMS information, confirmation of update of BMS information and update processing according to the result are performed. It is supposed to execute on the opening screen. If you want to process a questionnaire to have attributes set up after opening, it is necessary to have finished language judgment etc, so these initial moves must be done.
- (void)applicationNewActive;
/// SSBP Processing when an application using iOS-SDK returns from the background. The necessary processing is executed when returning from the background. Confirm existence / nonexistence of change of setting language and update of BMS information, update processing according to result, restart of beacon detection and registration of logs being held according to setting are performed. It is assumed to execute within applicationDidBecomeActive of AppDelegate.
- (void)applicationBecomeActive;
/// SSBP Processing when application using iOS-SDK moves to background. The necessary processing is executed when shifting to the background. Depending on the settings, processing such as stop of the GPS and registration of the log that is held is performed. It is supposed to be executed within the applicationDidEnterBackground of AppDelegate.
- (void)applicationEnterBackground;
/// SSBP Processing when the application using the iOS-SDK terminates. The necessary processing is executed when the application is deleted from the APP switcher. Processing such as deletion of the offer with the specific function is done. It is supposed to be executed within the applicationWillTerminate of AppDelegate.
- (void)applicationTerminateCompleted:(void (^)(void))completed;
/// Registration of attribute reply using SSBP iOS-SDK. When processing is completed, it is notified by didFinishUpdateDeviceInfo of SSBPSdkIF callback.
- (void)updateDeviceInfo;
- (void)sdkUpdateDeviceInfo;
/// ON / OFF control setting of beacon detection. Beacon detection will not start unless this setting is ON when the scanStart method is executed. Basically, if beacon detection is fixed at ON, it is necessary to set it to ON at the timing of beacon detection after the initial launch of the application. Please use this setting if you need to control ON / OFF of beacon detection by application.
- (void)setDetectBeacon:(BOOL)flag;
/// Returns the status of beacon detection.
/// @return Returns the status of beacon detection.
- (BOOL)isDetectBeacon;
/// Start beacon detection using SSBP iOS-SDK. Please turn it on together after setting it with setDetectBeacon method. If beacon detection has already been started, the current status will be maintained even if it is executed.\n
/// ※ Can execute expected operation by implement processing at the time of UIApplicationLaunchOptionsLocationKey in condition when didFinishLaunchingWithOptions of AppDelegate is called\n
/// Please implement according to operating condition of actual application.
- (void)scanStart;
/// Stopping beacon detection using SSBP iOS-SDK.  After setting it with the setDetectBeacon method, please execute it together. It takes some time to stop beacon detection. Even when resuming immediately, it should be restarted with scanStart after waiting for about 1 second (possibly more possibly depending on the terminal).
- (void)scanStop;
/// The API initialises the app invoke feature. When application enters into or exits from a specific beacon region set in server, the SDK sends callbacks to the calling application.\n
/// Refer the callbacks, didEnterRegion and didExitRegion for more details about how to get callbacks from the SDK.
- (void)initInvokeApp;
/// Utilize SSBPOfferIF to update the status of the offer information that the specified offerId matches to used. When useOfferLog is set to true, the offer log is retained internally and processed immediately.
/// @param offerId ID of offer
/// @return Returns true if update of usage status is successful, false otherwise.
- (BOOL)useOffer:(NSString *)offerId;
/// Using SSBPOfferIF, deletes the offer information in which offerId to specify matches.
/// @param offerId ID of offer
/// @return In deletion is success, return true.\n
/// In deletion is failure, return false.
- (BOOL)removeOffer:(NSString *)offerId;
/// Using SSBPOfferIF, delete all the offer information. In addition, the beacon detection interval information is deleted.
- (void)clearAllOffer;
/// Using SSBPOfferIF, delete the action information on the specified action. If you use an offer to have multiple roles, it may result in unintentional deletion.
- (void)clearActionOffer:(NSString *)action;
- (void)clearAllBeacon;
/// Client application calls this API to link customer ids to the installed device.
/// @param customerIds Array of SSBPCustomerId objects.\n
/// The `val` cannot be nil for the SSBPCustomerId object in the array.
/// @param result Completion block with API status
-(void)setCustomerIds:(NSArray *)customerIds completion:(void(^)(BOOL status, NSError *error))result;

- (BaseRequest *)getAuthDigest;

#pragma mark - Adv js
- (void)loadSSBPAdsToWebview:(id)webview;

#pragma mark - (un)register event
- (void)unregisterAllFrom:(id)obj;

- (void)registerTo:(id)obj didStart:(DidStart)handler;
/// Unregister didStart callback
/// @param obj ID of didStart
- (void)unregisterDidStartFrom:(id)obj;

- (void)registerTo:(id)obj didFinishLocation:(DidFinishLocation)handler;
/// Unregister didFinishLocation callback
/// @param obj The class want to unregister receive event
- (void)unregisterDidFinishLocationFrom:(id)obj;

- (void)registerTo:(id)obj didMessage:(DidMessage)handler;
/// Unregister didMessage callback
/// @param obj The class want to unregister receive event
- (void)unregisterDidMessageFrom:(id)obj;

- (void)registerTo:(id)obj scannerHitGeofence:(ScannerHitGeofence)handler;
/// Unregister scannerHitGeofence callback
/// @param obj The class want to unregister receive event
- (void)unregisterScannerHitGeofenceFrom:(id)obj;

- (void)registerTo:(id)obj scannerHitGeofenceOffers:(ScannerHitGeofenceOffers)handler;
- (void)unregisterScannerHitGeofenceOffersFrom:(id)obj;

- (void)registerTo:(id)obj scannerHitBeacon:(ScannerHitBeacon)handler;
/// Unregister scannerHitBeacon callback
/// @param obj obj of scannerHitBeacon
- (void)unregisterScannerHitBeaconFrom:(id)obj;

/// By execute getBeaconOffers method, notify offer getting result associated with beacon.
/// @param obj The class want to register receive notification\n
///  Key | Type | Value
///  ------| ------ | -------
///  ssbpOffers | NSArray | SSBPOffer array
///  beacon | TSsbpBeacon | TSsbpBeacon object
/// @param handler The call back handler affter hit beacon offers.
- (void)registerTo:(id)obj scannerHitBeaconOffers:(ScannerHitBeaconOffers)handler;
/// Unregister scannerHitBeaconOffers callback
/// @param obj The class want to unregister receive event
- (void)unregisterScannerHitBeaconOffersFrom:(id)obj;

/// after get offers from server, notify offer getting result associated with beacon.
/// @param obj The class want to register receive notification\n
///  Key | Type | Value
///  ------| ------ | -------
///  ssbpOffers | NSArray | SSBPOffer array
/// @param handler The call back handler affter receive offers.
- (void)registerTo:(id)obj ssbpOnOfferReceive:(SsbpOnOfferReceive)handler;
/// Unregister ssbpOnOfferReceive callback
/// @param obj The class want to unregister receive event
- (void)unregisterSsbpOnOfferReceiveFrom:(id)obj;

/// nearest beacon update notification\n
/// Can use in a trigger for updating your current position regarding to navigation.\n
/// ※ In case execute detection based on multi-facilities (different UUID) as important point to determine the nearest beacon, to be notified about nearest beacon of each facility, at the place can detect beacon of multi-facility, can do behavior.
/// @param obj \n
/// Key name: beaconId \n
/// Type: NSString \n
/// Value: New nearest beaconID
/// @param handler The call back handler affter nearest beacon update
- (void)registerTo:(id)obj didChangeNearest:(DidChangeNearest)handler;
/// Unregister didChangeNearest callback
/// @param obj The class want to unregister receive event
- (void)unregisterDidChangeNearestFrom:(id)obj;

/// Beacon detection circumstance update notification \n
/// Status changing (Immediate/Near/Far/Unknown), when go out beacon area or
/// beacon out of management is nearest etc, use to update status.

/// @param obj \n
/// Key Name: info \n
/// Type: SSBPRegionInfo \n
/// Value: Beacon detection circumstance
/// @param handler The call back handler affter beacon was changed
- (void)registerTo:(id)obj didChangeBeacon:(DidChangeBeacon)handler;
/// Unregister didChangeBeacon callback
/// @param obj The class want to unregister receive event
- (void)unregisterDidChangeBeaconFrom:(id)obj;

/// List beacon detection circumstance update notification \n
/// Status changing (Immediate/Near/Far/Unknown), when go out beacon area or
/// beacon out of management is nearest etc, use to update status.
/// @param obj The class want to unregister receive event\n
/// @param handler The call back handler affter beacon was detected
- (void)registerTo:(id)obj watchBeaconsDetected:(WatchBeaconsDetected)handler;
/// Unregister watchBeaconsDetected callback
/// @param obj The class want to unregister receive event
- (void)unregisterWatchBeaconsDetectedFrom:(id)obj;

/// Notify compass information getting.\n
/// At the time get compass information, it’s called after changing orientation.
/// @param obj The class want to register receive event
/// @param handler \n
/// Type: CLHeading
/// Value: CLHeading object
- (void)registerTo:(id)obj didFinishHeading:(DidFinishHeading)handler;
/// Unregister didFinishHeading callback
/// @param obj The class want to unregister receive event
- (void)unregisterDidFinishHeadingFrom:(id)obj;

/// By executing the checkMaster method, notification complete regardless of result is success or failure.\n
/// While registering didFinishCheckMaster callback, please note the following things.\n
/// Call applicationNewActive API and other required APIs like scanStart, setDetectBeacon, enableBeaconOfferAdPopup etc inside the didFinishCheckMaster callback.\n
/// Make sure the code inside didFinishCheckMaster is called in main thread\n
/// The didFinishCheckMaster callback will be invoked multiple times in the application. So please make sure the code inside didFinishCheckMaster will be executed only once.\n
///  For detail, please refrenece SSBP_iOS-SDK-Lite_Reference
/// @param obj The class want to register receive event
/// @param handler The call back handler affter finish checking master
- (void)registerTo:(id)obj didFinishCheckMaster:(DidFinishCheckMaster)handler;
/// Unregister didFinishCheckMaster callback
/// @param obj The class want to unregister receive event
- (void)unregisterDidFinishCheckMasterFrom:(id)obj;

/// Can use in a trigger for updating your device info
/// @param obj The class want to unregister receive event
/// @param handler The call back handler affter finish updating device info
- (void)registerTo:(id)obj didFinishUpdateDeviceInfo:(DidFinishUpdateDeviceInfo)handler;
/// Unregister didFinishUpdateDeviceInfo callback
/// @param obj The class want to unregister receive event
- (void)unregisterDidFinishUpdateDeviceInfoFrom:(id)obj;

/// Can get trigger when beacon change status and receive offer \n
/// Status changing SSBPOfferStatusNew = new offer, SSBPOfferStatusChange = offer updated, SSBPOfferStatusReceive = receive same offer.
/// @param obj \n
/// Key name | Type | Value
/// ------------- | --------| --------
/// offerId | NSString | OfferID
/// status | SSBPOfferStatus | Offer status
/// @param handler The call back handler affter finish adding offer
- (void)registerTo:(id)obj didAddOffer:(DidAddOffer)handler;
/// Unregister didAddOffer callback
/// @param obj The class want to unregister receive event
- (void)unregisterDidAddOfferFrom:(id)obj;

- (void)registerTo:(id)obj didReceiveAds:(DidReceiveAds)handler;
- (void)unregisterDidReceiveAdsFrom:(id)obj;

- (void)registerTo:(id)obj didChangeLocationAuthorizationStatus:(DidChangeLocationAuthorizationStatus)handler;
- (void)unregisterDidChangeLocationAuthorizationStatusFrom:(id)obj;

/// Can get triggered when the application enters into the region of an app invoke beacon.
/// @param obj \n
/// Key name | Type | Value
/// ------------- | --------| --------
/// UUID | NSString | Beacon’s UUID
/// major | int | Beacon’s major
/// minor | int | Beacon’s minor
/// message | NSString | Beacon specific message to the app
/// @param handler The call back handler affter beacon did enter region
- (void)registerTo:(id)obj didEnterRegion:(DidEnterRegion)handler;
/// Unregister didEnterRegion callback
/// @param obj The class want to unregister receive event
- (void)unregisterRangingEntryCallbackFrom:(id)obj;
/// Can get triggered when the application exits from the region of an app invoke beacon.
/// @param obj \n
/// Key name | Type | Value
/// ------------- | --------| --------
/// UUID | NSString | Beacon’s UUID
/// major | int | Beacon’s major
/// minor | int | Beacon’s minor
/// message | NSString | Beacon specific message to the app
/// @param handler The call back handler affter beacon did exit region
- (void)registerTo:(id)obj didExitRegion:(DidExitRegion)handler;
/// Unregister didExitRegion callback
/// @param obj The class want to unregister receive event
- (void)unregisterRangingExitCallbackFrom:(id)obj;

/// The application developers can use this method to enable/disable check-in/out features by passing true/false as an argument. Also, the minimum proximity for checkin and minimum interval for checkout can be specified along with the API. By default, the feature is disabled.
/// @param flag Checkin/checkout enabling flag.\n
/// TRUE for enabling\n
/// FALSE for disabling
/// @param proximity Minimum proximity for check-in\n
/// Possible values:\n
/// 1. CLProximityImmediate\n
/// 2. CLProximityNear\n
/// 3. CLProximityFar\n
/// @param interval Time interval for check-out, in seconds.\n
/// The value must be greater than 0.
- (void)enableCheckInCheckOut:(BOOL)flag checkinProximity:(CLProximity)proximity checkoutInterval:(int)interval;

/// Returns the status of beacon checkin/checkout feature. It returns TRUE, if the check-in/out feature is enabled and returns FALSE, if the feature is disabled. For detail, please referece SSBP_iOS-SDK-Lite_Reference
/// @return TRUE, if the feature is enabled.\n
/// FALSE, if the feature is disabled.
- (BOOL)isCheckInCheckOut;
/// The method will be invoked when app check-in to a beacon region. The ‘checkInBeacon’ parameter of the ‘DidCheckin’ handler contains the information about the beacon checked-in. Every time a beacon check-in by meeting the specified criteria, the SDK will call the DidCheckin callback to notify the application about the check-in.
/// @param obj\n
/// Key name: checkinBeacon
/// Type: TSsbpBeacon
/// Value: TSsbpBeacon
/// @param handler The call back handler affter checkin
- (void)registerTo:(id)obj didCheckin:(DidCheckin)handler;
/// Unregister didCheckin callback
/// @param obj The class want to unregister receive event
- (void)unregisterCheckinCallbackFrom:(id)obj;
/// The method will be invoked when app checkout from the beacon region. The ‘checkOutBeacon’ parameter of the `DidCheckout` handler contains information about the beacon checked-out. Every time a beacon check-out after check-in by meeting the specified criteria, the SDK will call the DidCheckout callback to notify the application about the check-out.
/// @param obj\n
/// Key name: checkoutBeacon
/// Type: TSsbpBeacon
/// Value: TSsbpBeacon
/// @param handler <#handler description#>
- (void)registerTo:(id)obj didCheckout:(DidCheckout)handler;
/// Unregister didCheckout callback
/// @param obj The class want to unregister receive event
- (void)unregisterCheckoutCallbackFrom:(id)obj;

/// The application developers can use this method to enable/disable the beacon offer notifications by passing true/false as an argument. The parent view controller upon which the offer popup should be shown has to be given as parameter.
/// @param flag Beacon offer notification enabling flag.\n
/// TRUE for enabling\n
/// FALSE for disabling
- (void)enableBeaconOfferAdPopup:(BOOL)flag __deprecated_msg("this function has deprecated, Please use registerDisplayOfferAdPopup instead");
/// While scanning beacons, there are chances for multiple beacons to be detected at same time. The setOfferBeaconSelectMode determines which beacon has to be selected for showing offer. It can select the beacon with its proximity or last update time.
/// @param mode Beacon selection mode. \n
/// OfferBeaconSelectModeNearest - Beacon selected based on proximity \n
/// OfferBeaconSelectModeLatest - Beacon selected based on update time \n
/// Default value = OfferBeaconSelectModeNearest

/// Set Call back process open coupon pocket list from vendor App.
/// @param handler closure handle open coupon pocket list
-(void)onOpenCouponPocketList: (OnOpenCouponPocketList)handler;

/// Register the view which will display offers or ads popup.
- (void)registerDisplayOfferAdPopup;

/// Enable show popup beacon, gps, ssid.
-(void)enablePopup: (BOOL)beacon gps:(BOOL)gps ssid:(BOOL)ssid;

- (void)setOfferBeaconSelectMode:(OfferBeaconSelectMode)mode;
/// Set mode select beacon to Default
- (void)setOfferBeaconSelectModeDefault;

/// For beacon offers, there may be navigations like open Safari browser, open a url in a webview etc. If the application is in background, SDK displays the offer data in local notifications. Application has to call applicationDidReceiveLocalNotification API to inform the SDK when a notification is tapped. The API has to be called in the “userNotificationCenter: didReceiveNotificationResponse: withCompletionHandler:” callback of AppDelegate. The SSBP SDK notification identifier will contain the string “SSBPSDKNotification”.
/// @param response notification's response
- (void)applicationDidReceiveLocalNotification:(UNNotificationResponse *)response API_AVAILABLE(ios(10.0));

/// Setup interval for get ssid offer
/// @param ssid ssid
-(void)setupIntervalGetSsidOffer: (nullable NSString *)ssid;

/// Return sdk version.
-(NSString *)getSdkVersion;
@end

#endif
