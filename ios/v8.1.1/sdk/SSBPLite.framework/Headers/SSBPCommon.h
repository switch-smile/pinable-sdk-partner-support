//
//  SSBPCommon.h
//  SSBPCore
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_Common_h
#define SSBP_AppSDK_Static_Common_h

#import <UIKit/UIKit.h>

#define SSBP_ERRDOMAIN                  @"com.switch-smile.ssbpsdk"
#define SSBP_AUTH_APPKEY_ERROR          @"appKeyまたはその他のパラメータが設定されていません。"
#define SSBP_SERVER_ERROR               @"なんらかの原因で、サーバーに接続できませんでした。"

#define SSBP_APPKEY                     @"AppKey"
#define SSBP_SECRET_KEY                 @"SecretKey"
#define SSBP_TARGET_HOST                @"TargetHost"
#define SSBP_APPID                      @"AppId"

#define SSBP_TIMEOUT_INTERVAL           @"TimeoutInterval"
#define SSBP_RETRY_COUNT                @"RetryCount"
#define SSBP_RETRY_INTERVAL             @"RetryInterval"

#define SSBP_PARAM_CONTENT_PATH         @":content_path"
#define SSBP_PARAM_MAP_PATH             @":map_path"
//#define SSBP_PARAM_WAIT_TIME            @":content_wait_time"
#define SSBP_PARAM_FACILITY_VER         @":facility_version"
#define SSBP_PARAM_BEACON_VER           @":beacon_version"
#define SSBP_PARAM_NAVI_VER             @":navi_version"
#define SSBP_PARAM_GLOBAL_INTERVAL      @"OfferHandlingGlobalInterval"
#define SSBP_PARAM_HANDLING_INTERVAL    @"OfferHandlingInterval"
#define SSBP_PARAM_REQUEST_INTERVAL     @"OfferRequestInterval"
#define SSBP_PARAM_GPS_GLOBAL_INTERVAL      @"GpsOfferHandlingGlobalInterval"
#define SSBP_PARAM_GPS_HANDLING_INTERVAL    @"GpsOfferHandlingInterval"
#define SSBP_PARAM_GPS_REQUEST_INTERVAL     @"GpsOfferRequestInterval"
#define SSBP_PARAM_SSID_GLOBAL_INTERVAL     @"SsidOfferHandlingGlobalInterval"
#define SSBP_PARAM_SSID_HANDLING_INTERVAL   @"SsidOfferHandlingInterval"
#define SSBP_PARAM_SSID_REQUEST_INTERVAL    @"SsidOfferRequestInterval"
#define SSBP_PARAM_SDK_RUN_CONTROL      @"SdkRunControl"
#define SSBP_PARAM_BEACON_LOG_INTERVAL_COUNT    @"BeaconLogSendIntervalCount"
#define SSBP_PARAM_BEACON_LOG_INTERVAL_SEC      @"BeaconLogSendIntervalSec"
#define SSBP_PARAM_GET_BATTERY_ENABLE   @"GetBatteryEnable"
#define SSBP_PARAM_GET_LOCATION_BACKGROUND_MODE_ENABLE   @"getLocationMode"
#define SSBP_PARAM_GET_SSID_INTERVAL    @"GetSsidInterval"
#define SSBP_PARAM_SSID_LOG_SEND_INTERVAL_MIN       @"SsidLogSendIntervalMin"
#define SSBP_PARAM_SSID_LOG_SEND_INTERVAL_COUNT     @"SsidLogSendIntervalCount"
#define SSBP_PARAM_GET_SSID_ENABLE                  @"GetSsidEnable"
#define SSBP_PARAM_GPS_LOG_SEND_INTERVAL_MIN        @"GpsLogSendIntervalMin"
#define SSBP_PARAM_GPS_LOG_SEND_INTERVAL_COUNT      @"GpsLogSendIntervalCount"
#define SSBP_PARAM_GET_GPS_ENABLE                   @"GetGpsEnable"
#define SSBP_PARAM_GPS_DISTANCE_FILTER              @"GPSDistFilter"
#define SSBP_PARAM_REQUEST_GLOBAL_INTERVAL          @"OfferRequestGlobalInterval"
#define SSBP_PARAM_COUPON_POCKET_ENABLE             @"CouponPocketEnable"
#define SSBP_PARAM_COUPON_POCKET_REQUST_INTERVAL    @"CouponRequestInterval"
#define SSBP_PARAM_ENABLE_DEBUG_LOG                 @"EnableDebugLog"
#define SSBP_PARAM_SEND_BEACON_DEBUG_LOG            @"SendBeaconDebugLog"
#define SSBP_PARAM_WI2_ENABLE                       @"wi2Enable"
#define SSBP_PARAM_WI2_LO_CD                        @"wi2_lo_cd"
#define SSBP_PARAM_WI2_LO_PASSWORD                  @"wi2_lo_password"
#define SSBP_PARAM_WI2_SSID_NAME                    @"wi2_ssid_name"
#define SSBP_PARAM_AREA_CPN_ENABLE                  @"enableGetAreaCpn"
#define SSBP_PARAM_AREA_OFFER_DISPLAY_AFTER         @"area_offer_display_after"

#define SSBP_FACILITY_VER               @"ssbp_facilityVer"
#define SSBP_BEACON_VER                 @"ssbp_beaconVer"
#define SSBP_NAVI_VER                   @"ssbp_naviVer"

#define SSBP_ENDPOINT_SYSPARAMS         @"EndpointSysParams"
#define SSBP_ENDPOINT_LOCALES           @"EndpointLocales"
#define SSBP_ENDPOINT_BEACONOFFERS      @"EndpointBeaconOffers"
#define SSBP_ENDPOINT_GPS_OFFERS        @"EndpointGpsOffers"
#define SSBP_ENDPOINT_SSID_OFFERS       @"EndpointSsidOffers"
#define SSBP_ENDPOINT_GEOFENCEOFFERS    @"EndpointGeofenceOffers"
#define SSBP_ENDPOINT_UPDATEDEVICEINFO  @"EndpointUpdateDeviceInfo"
#define SSBP_ENDPOINT_AREACAMPAIGNS     @"EndpointAreaCampaigns"

// Key Offer Information
#define SSBP_OFFER_KEY_OFFER_LIST       @"offer_list"
#define SSBP_OFFER_KEY_IS_OFFER_LIST    @"isOfferList"
#define SSBP_OFFER_KEY_OFFER_ID_IN_LIST @"offerIdInList"
#define SSBP_OFFER_KEY_OFFER_THUMB      @"offerThumb"
#define SSBP_OFFER_KEY_OFFER_INDEX      @"offerIndex"
#define SSBP_OFFER_KEY_DESIGN           @"design"
#define SSBP_OFFER_KEY_VIDEO            @"video"
#define SSBP_OFFER_KEY_VIDEO_TYPE       @"videoType"
#define SSBP_OFFER_KEY_LANDING_PAGE     @"landingPage"
#define SSBP_OFFER_KEY_OFFER_TITLE      @"offerTitle"
#define SSBP_OFFER_KEY_THUMB_URL        @"thumbURL"
#define SSBP_OFFER_KEY_IMAGES           @"imageS"
#define SSBP_OFFER_KEY_IMAGEL           @"imageL"
#define SSBP_OFFER_KEY_BG_BT_TITLE      @"backgroundButtonTitle"
#define SSBP_OFFER_KEY_FG_BT_TILTE      @"forgroundButtonTitle"
#define SSBP_OFFER_KEY_BT_COLOR         @"buttonColor"
#define SSBP_OFFER_KEY_TYPE             @"type"
#define SSBP_OFFER_KEY_PAGEID           @"pageId"
#define SSBP_OFFER_KEY_DESCRIPTION      @"offerDescription"
#define SSBP_OFFER_KEY_VIDEO_URL        @"videoURL"
#define SSBP_OFFER_KEY_OFFFERID         @"offerId"
#define SSBP_OFFER_KEY_URL              @"url"
#define SSBP_OFFER_KEY_RESURL           @"resUrl"
#define SSBP_OFFER_KEY_SENDER_NAME      @"senderName"
#define SSBP_OFFER_KEY_EXPIRE_DATE      @"expireDate"
#define SSBP_OFFER_KEY_EXTERNAL_BR      @"externalBrowser"
#define SSBP_OFFER_KEY_PUSH_STYLE       @"push_style"
#define SSBP_OFFER_KEY_GIFTEE           @"giftee"
#define SSBP_OFFER_KEY_RECEIVED_AT      @"receivedAt"
#define SSBP_OFFER_KEY_WIDTH_RATE       @"widthRate"
#define SSBP_OFFER_KEY_HEIGHT_RATE      @"heightRate"
#define SSBP_OFFER_KEY_LEFT_SPC         @"leftSpc"
#define SSBP_OFFER_KEY_TOP_SPC          @"topSpc"
#define SSBP_OFFER_DATA_DELAY_FOR_WATING_PARENTVIEW  @"offerDataBeDelayedWatingParentView"
#define SSBP_QUEUE_OFFER                @"ssbp_queue_offer"
#define SSBP_LOG_CPN_SEND_ID            @"logCpnSendId"
#define SSBP_LOG_AREA_CPN_SEND_ID       @"logAreaCpnSendId"

#define SSBP_OFFER_KEY_OFFER_ACTION             @"offerAction"
#define SSBP_OFFER_MAX_TIME_RETRY_SHOW_OFFER    5
#define SSBP_DEVIDE_RECORD_NUM                  100
// Key Notification
#define SSBP_OFFER_ACTION_VIDEO_IDENTIFIER      @"VIDEO_ACTION"
#define SSBP_OFFER_ACTION_IMAGE_IDENTIFIER      @"IMAGE_ACTION"
#define SSBP_OFFER_CATEGORY_VIDEO_IDENTIFIER    @"OfferPopupVideo"
#define SSBP_OFFER_CATEGORY_IMAGE_IDENTIFIER    @"OfferPopupImage"



#define SSBP_ENDPOINT_ADDBEACONDEBUGLOGS        @"EndpointAddBeaconDebugLogs"
#define SSBP_ENDPOINT_BEACONLOGS        @"EndpointAddBeaconLogs"
#define SSBP_ENDPOINT_OFFERLOGS         @"EndpointAddOfferLogs"

#define SSBP_ENDPOINT_UUIDS             @"EndpointGetUuids"

#define SSBP_ENDPOINT_GET_ADVERTISEMENT @"EndpointGetAdvertisement"
#define SSBP_ENDPOINT_GET_PUSH_CAMPAIGN @"EndpointGetPushCampaign"
#define SSBP_ENDPOINT_GET_PUSH_AD       @"EndpointGetPushAd"

#define SSBP_ENDPOINT_ADD_TAP_LOG           @"EndpointAddAdTapLogs"
#define SSBP_ENDPOINT_ADD_GPS_LOG           @"EndpointAddGpsLogs"
#define SSBP_ENDPOINT_ADD_APP_LAUNCH_LOG    @"EndpointAddAppLaunchLogs"
#define SSBP_ENDPOINT_ADD_WIFI_LOG          @"EndpointAddWifiLogs"
#define SSBP_ENDPOINT_SEND_ANALYTICS        @"EndpointSendAnalytics"
#define SSBP_ENDPOINT_GET_SSIDS             @"EndpointGetSsids"
#define SSBP_ENDPOINT_GET_ALL_COUPON        @"EndpointGetAllCoupon"
#define SSBP_ENDPOINT_GET_BEACON_COUPON     @"EndpointGetBeaconCoupon"
#define SSBP_ENDPOINT_ADD_COUPON_POCKET_LOGS    @"EndpointAddCouponPocketLogs"
#define SSBP_ENDPOINT_GET_COUPON_CONF       @"EndpointGetCouponConf"

#define SSBP_ENDPOINT_CUSTOMER_IDS      @"AddCustomerIds"
#define SSBP_ENDPOINT_RANGING_BEACONS   @"EndpointGetRangingBeacons"

#define SSBP_DATA_UPDATE_DEVICE_INF0   @"DeviceInfo"

#define SSBP_MQTT_TARGET_TCP            @"MQTTTargetTcp"
#define SSBP_MQTT_TARGET_TCP_PORT       @"MQTTTargetTcpPort"

#define SSBP_MQTT_AUTH_DISABLE          @"0"
#define SSBP_MQTT_AUTH_ENABLE           @"1"
#define SSBP_MQTT_ENABLE                @"MQTTAuthEnable"
#define SSBP_MQTT_USERNAME              @"MQTTUserName"
#define SSBP_MQTT_PASSWORD              @"MQTTPassword"

#define SSBP_PUBLISHTOPIC_BEACONLOGS    @"PublishTopicBeaconLogs"
#define SSBP_SUBSCRIBETOPIC_BEACONLOGS  @"SubscribeTopicBeaconLogs"

#define SSBP_LOCALE_ID                  @"LocaleID"
#define SSBP_LOCALE_DEFAULT             @"LocaleDefault"
#define SSBP_USED_LOCALE_ID             @"UsedLocaleId"
#define SSBP_DEVICE_ID                  @"DeviceID"
#define SSBP_DEVICE_TOKEN               @"DeviceToken"

#define SSBP_STORE_BEACON_LOGS          @"ssbp_beacon_logs"
#define SSBP_STORE_BEACON_SEND_LOGS     @"ssbp_beacon_send_logs"
#define SSBP_STORE_CONTENT_LOGS         @"ssbp_content_logs"
#define SSBP_LAST_TIME_SEND_BEACON_LOGS     @"ssbp_last_time_send_beacon_logs"
#define SSBP_BEACON_LOGS_INTERVAL_COUNT     @"ssbp_beacon_logs_interval_count"
#define SSBP_BEACON_LOGS_INTERVAL_SEC       @"ssbp_beacon_logs_interval_sec"

#define SSBP_IS_CHANGE_BEACON           @"ssbp_isChangeBeacon"

//#define SSBP_CONFIG_WAIT_TIME                   @"ssbp_config_wait_time"
#define SSBP_CONFIG_USE_GEOFENCE                @"ssbp_config_use_geofence"
#define SSBP_CONFIG_USE_NOTIFICATION            @"ssbp_config_use_notification"
//#define SSBP_CONFIG_LIMIT_HISTORY_WAIT_TIME     @"ssbp_config_litmit_history_wait_time"
#define SSBP_CONFIG_MIN_INTERVAL                @"ssbp_config_min_interval"
#define SSBP_CONFIG_LAUNCH_NOTIFICATION         @"ssbp_config_launch_notification"
#define SSBP_CONFIG_GPS_INFO_NOTIFICATION       @"ssbp_config_gps_info_notification"
#define SSBP_CONFIG_USE_BEACON_LOG              @"ssbp_config_use_beacon_log"
#define SSBP_CONFIG_USE_OFFER_LOG               @"ssbp_config_use_offer_log"
#define SSBP_CONFIG_BEACON_SELECT_MODE          @"ssbp_config_beacon_select_mode"
#define SSBP_DETECT_BEACON                      @"ssbp_detect_beacon"
#define SSBP_CONFIG_ALREADY_CONFIG_DEFAULT      @"ssbp_config_already_config_default"


#define SSBP_LAST_TIME_GET_COUPON_POCKET            @"ssbp_last_time_get_coupon_pocket"
#define SSBP_COUPON_POCKET_CONFIG_ALREADY_CONFIG_DEFAULT      @"ssbp_config_already_config_default"
#define SSBP_CP_CONF_NOTIFICATION_WAIT_COUNT        @"ssbp_cp_conf_notification_wait_count"
#define SSBP_CP_CONF_NOTIFICATION_MESSAGE           @"ssbp_cp_conf_notification_message"
#define SSBP_CP_CONF_NOTIFICATION_THUMB             @"ssbp_cp_conf_notification_thumb"
#define SSBP_CP_COUPON_DETECTED_COUNT               @"ssbp_cp_coupon_detected_count"
#define SSBP_CP_NOTIFICATION_CATEGORY_INDENTIFIER   @"ssbp_cp_notification_identifier"
#define SSBP_CP_NOTIFICATION_INDENTIFIER            @"SSBPSDKNotificationCouponPocketCount"

#define SSBP_ENABLE_CHECK_IN_CHECK_OUT          @"ssbp_enable_checkin_checkout"
#define SSBP_CHECKIN_PROXIMITY                  @"ssbp_checkin_proximity"
#define SSBP_CHECKOUT_INTERVAL                  @"ssbp_checkout_interval"

#define SSBP_OFFER_PATH                 @"ssbp_offerPath"

#define SSBP_UUID_DATE                  @"ssbp_uuidDate"
#define SSBP_UUID_LIST                  @"ssbp_uuids"
#define SSBP_SSID_LIST                  @"ssbp_ssids"

#define SSBP_MESSAGE_ENTER_REGION       @"EnterRegion"
#define SSBP_MESSAGE_EXIT_REGION        @"ExitRegion"
#define SSBP_MESSAGE_RANGE_BEACON       @"RangeBeacon"

#define SSBP_MESSAGE_ENTER_GEOFENCE     @"EnterGeofence"
#define SSBP_MESSAGE_EXIT_GEOFENCE      @"ExitGeofence"
#define SSBP_MESSAGE_ENTERED_GEOFENCE   @"EnteredGeofence"
#define SSBP_MESSAGE_EXITED_GEOFENCE    @"ExitedGeofence"

#define SSBP_BEACON_DATE                @"ssbp_beaconDate"

#define SSBP_NON_INTERVAL_BEACON        @"nonInterval"

#define SSBP_OFFER_HANDLING_GLOBAL_INTERVAL             @"ssbp_offer_handling_global_interval"
#define SSBP_OFFER_HANDLING_INTERVAL                    @"ssbp_offer_handling_interval"
#define SSBP_OFFER_REQUEST_INTERVAL                     @"ssbp_offer_request_interval"
#define SSBP_LAST_TIME_OFFER_REQUEST_GLOBAL             @"ssbp_last_time_offer_request_global"
#define SSBP_IS_LAST_TIME_GET_OFFER_FALSE               @"ssbp_is_last_time_get_offer_false"

#define SSBP_GPS_OFFER_HANDLING_GLOBAL_INTERVAL         @"ssbp_gps_offer_handling_global_interval"
#define SSBP_GPS_OFFER_HANDLING_INTERVAL                @"ssbp_gps_offer_handling_interval"
#define SSBP_GPS_OFFER_REQUEST_INTERVAL                 @"ssbp_gps_offer_request_interval"
#define SSBP_GPS_LAST_TIME_OFFER_REQUEST_GLOBAL         @"ssbp_gps_last_time_offer_request_global"

#define SSBP_SSID_OFFER_HANDLING_GLOBAL_INTERVAL        @"ssbp_ssid_offer_handling_global_interval"
#define SSBP_SSID_OFFER_HANDLING_INTERVAL               @"ssbp_ssid_offer_handling_interval"
#define SSBP_SSID_OFFER_REQUEST_INTERVAL                @"ssbp_ssid_offer_request_interval"
#define SSBP_SSID_LAST_TIME_OFFER_REQUEST_GLOBAL        @"ssbp_ssid_last_time_offer_request_global"

#define SSBP_COUPON_POCKET_ENABLE                       @"ssbp_coupon_pocket_enable"
#define SSBP_COUPON_POCKET_REQUEST_INTERVAL             @"ssbp_coupon_pocket_request_interval"
#define SSBP_BEACON_COUPON_POCKET_ID_NOT_EXIST_ON_DB    @"ssbp_beacon_coupon_pocket_id_not_exist_on_db"
#define SSBP_COUPON_POCKET_HARD_DELETE_DATE             30
#define SSBP_COUPON_POCKET_LAST_TIME_VALIDATE_COUPONS   @"ssbp_coupon_pocket_last_time_validate_coupons"
#define SSBP_BEACON_COUPON_POCKET_LOG_SEND              @"ssbp_beacon_coupon_pocket_log_send"

#define SSBP_OFFER_REQUEST_GLOBAL_INTERVAL              @"ssbp_offer_request_global_interval"

#define SSBP_SSID_GPS_DISTANCE_FILTER                   @"ssbp_ssid_gps_distance_fillter"
#define SSBP_ENABLE_DEBUG_LOG                   @"ssbp_enable_debug_log"
#define SSBP_SEND_BEACON_DEBUG_LOG                   @"ssbp_send_beacon_debug_log"
#define SSBP_WI2_ENABLE                                 @"ssbp_wi2_enable"
#define SSBP_WI2_LO_CD                                  @"ssbp_wi2_lo_cd"
#define SSBP_WI2_LO_PASSWORD                            @"ssbp_wi2_lo_password"
#define SSBP_WI2_SSID_NAME                              @"ssbp_wi2_ssid_name"

/// Stored data control Sdk.
#define SSBP_SDK_RUN_CONTROL            @"ssbp_sdk_run_control"
#define SSBP_GET_BATTERY_ENABLE         @"ssbp_get_battery_enable"

#define SSBP_OFFER_TRANSPARENT          [UIColor colorWithRed:0 green:0 blue:0 alpha:0.4];
#define SSBP_COUPON_POCKET_SCALE_WH     0.75;
#define SSBP_BUTTON_LIGHT_ACTIVE_COLOR  @"#FFFFFF"
#define SSBP_BUTTON_DEACTIVE_COLOR      @"#858F99"
#define SSBP_BUTTON_DEACTIVE_COLOR      @"#858F99"
#define SSBP_GET_BACKGROUND_LOCATION_ENABLE @"ssbp_get_background_location_enable_mode"

// Stored data get ssid
#define SSBP_SDK_GET_SSID_INTERVAL      @"ssbp_sdk_get_ssid_interval"
#define SSBP_SDK_SSID_LOG_SEND_INTERVAL_MIN     @"ssbp_sdk_ssid_log_send_interval_min"
#define SSBP_SDK_SSID_LOG_SEND_INTERVAL_COUNT     @"ssbp_sdk_ssid_log_send_interval_count"
#define SSBP_SDK_LAST_TIME_GET_SSID     @"ssbp_sdk_get_last_ssid_interval"
#define SSBP_SDK_LAST_TIME_SEND_SSID    @"ssbp_sdk_send_last_ssid_interval"
#define SSBP_SDK_GET_SSID_ENABLE        @"ssbp_sdk_get_ssid_enable"
#define SSBP_STORE_WIFI_LOGS            @"ssbp_store_wifi_logs"
#define SSBP_STORE_SENDING_WIFI_LOGS    @"ssbp_store_sending_wifi_logs"
#define SSBP_STORE_LATEST_SSID          @"ssbp_store_latest_ssid"

// stored data get GPS
#define SSBP_SDK_GPS_LOG_SEND_INTERVAL_MIN     @"ssbp_sdk_gps_log_send_interval_min"
#define SSBP_SDK_GPS_LOG_SEND_INTERVAL_COUNT     @"ssbp_sdk_gps_log_send_interval_count"
#define SSBP_SDK_LAST_TIME_SEND_GPS     @"ssbp_sdk_send_last_gps_interval"
#define SSBP_SDK_GET_GPS_ENABLE         @"ssbp_sdk_get_gps_enable"
#define SSBP_STORE_GPS_LOGS             @"ssbp_store_gps_logs"
#define SSBP_STORE_SENDING_GPS_LOGS     @"ssbp_store_sending_gps_logs"
#define SSBP_LOG_DEBUG                  @"ssbp_log_debug"

// SSBP Coupon pocket
#define SSBP_COUPON_POCKET_VIEW_CELL_INDENTIFIER        @"SSBPCouponViewCellIdentifier"
#define SSBP_COUPON_POCKET_VIEW_EMPTY_CELL_INDENTIFIER  @"SSBPCouponViewEmptyCellIdentifier"
#define SSBP_COUPON_POCKET_HEADER_VIEW_INDENTIFIER      @"SSBPCouponViewHeaderIdentifier"
#define SSBP_UICOLLECTION_VIEW_CELL_INDENTIFIER         @"SSBPUICollectionViewCellIdentifier"
#define SSBP_SS_TERMS_OF_USE_DEFAULT @"本アプリ"

#define SSBP_BATTERY_MAJOR              32767
#define SSBP_BATTERY_MAJOR_CHECK        32768

#define SSBP_APPLICATION_STATE          @"ssbp_application_state"

#define SSBP_ADMOD_APP_ID               @"ca-app-pub-2740558340103442~6473860192"
#define SSBP_ADMOD_BANNER_ID            @"ca-app-pub-2740558340103442/1115514311"
#define SSBP_ADMOD_INTERSTITIAL_ID      @"ca-app-pub-2740558340103442/7212978794"

#define SSBP_ADMOD_TEST_BANNER          @"ca-app-pub-3940256099942544/2934735716"
#define SSBP_ADMOD_TEST_INTERSTITIAL    @"ca-app-pub-3940256099942544/4411468910"

#define SSBP_EXPLICIT_UUID              @"1233aacc-0dc1-40a7-8085-303a6d64ddb5"

#define SSBP_REGEX_HTTP                 @"(https?:\\/\\/)?(www\\.)?[-\\w@:%._\\+~#=\\-֊‐゠・\\:.·'’‧״་]{2,256}\\.[a-z]{2,256}\\b([-\\w@:%_\\+.~#?&//=\\-֊‐゠・\\:.·'’‧״་]*)"
#define SSBP_REGEX_EMAIL                @"[A-Za-z0-9_.-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,3}"
#define SSBP_REGEX_PHONE                @"((tel|TEL):)?[+]?([0-9０-９][-.]?){7,14}"

#define SSBPLog(format, ...) if ([[NSUserDefaults standardUserDefaults] integerForKey:SSBP_ENABLE_DEBUG_LOG] == 1) { if(@available(iOS 9.0, *)) { os_log(OS_LOG_DEFAULT, ("%s SSBPLog: " format), __PRETTY_FUNCTION__, ## __VA_ARGS__); } else { NSLog((@"%s SSBPLog: " format), __PRETTY_FUNCTION__, ## __VA_ARGS__); } }

#if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
# define SSBP_FINAL __attribute__((objc_subclassing_restricted))
#else
# define SSBP_FINAL
#endif

#if defined(__has_attribute) && __has_attribute(objc_boxable)  // Available starting in Xcode 7.3.
# define SSBP_BOXABLE __attribute__((objc_boxable))
#else
# define SSBP_BOXABLE
#endif

#if defined(__cplusplus)
# define SSBP_EXTERN extern "C" __attribute__((visibility("default")))
#else
# define SSBP_EXTERN extern __attribute__((visibility("default")))
#endif

typedef struct SSBP_BOXABLE SSBPAdSize SSBPAdSize;
struct SSBP_BOXABLE SSBPAdSize {
    CGSize size;
    NSString * sizeString;
};

#endif
