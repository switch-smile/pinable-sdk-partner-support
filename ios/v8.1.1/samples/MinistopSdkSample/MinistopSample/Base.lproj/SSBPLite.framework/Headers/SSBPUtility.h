//
//  SSBPUtility.h
//  SSBPSdk
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_Utility_h
#define SSBP_AppSDK_Static_Utility_h
#import "SSBPStore.h"

@interface SSBPUtility: NSObject

// Digest calculation
+ (NSInteger)makeDigest:(NSString *)targetString keyString:(NSString *)keyString result:(NSString **)result;

+ (BOOL)storeString:(NSString *)strings key:(NSString *)key;
+ (NSString *)storeString:(NSString *)key;
+ (BOOL)storeInteger:(NSInteger)value key:(NSString *)key;
+ (NSInteger)storeInteger:(NSString*)key;
+ (BOOL)storeBool:(BOOL)value key:(NSString *)key;
+ (BOOL)storeBool:(NSString*)key;
+ (BOOL)storeObject:(NSObject *)value key:(NSString *)key;
+ (NSObject *)storeObject:(NSString *)key;
+ (NSData *)storeData:(NSString *)key;
+ (BOOL)storeArray:(NSArray *)array key:(NSString *)key;
+ (NSArray *)storeArray:(NSString *)key;
+ (NSArray *)allKeys;
+ (BOOL)storeLicenseKey:(NSString *)license;
+ (NSString *)getLicenseKey:(NSString *)key;

+ (NSData *)AES256EncryptWithKey:(NSData *)data key:(NSString *)key;
+ (NSData *)AES256DecryptWithKey:(NSData *)data key:(NSString *)key;

+ (NSString *)makeUTCDateTimeToString:(NSDate *)date;
+ (NSDate *)makeUTCDateTimeFromString:(NSString *)date;
+ (NSString *)makeLocaleDateToString:(NSDate *)date;
+ (NSInteger)numberOfDaysFromStartDate: (NSDate *)startDate toEndDate: (NSDate *)endDate;
+ (NSDate *)addDays: (NSInteger)day fromDate: (NSDate *)date;
+ (NSString *)makeLocaleDateTimeToString:(NSDate *)date;
+ (NSDate *)makeLocalDateTimeFromString:(NSString *)date;
+ (NSDate *)makeLocalDateTimeFromUTCDateTimeString:(NSString *)date;
+ (NSDate *)appendDate:(NSDate *)date by:(NSTimeInterval)timeInterval;

+ (NSString *)escapeString:(NSString *)str;

+ (BOOL)checkSame:(NSString *)val1 val2:(NSString *)val2;
+ (BOOL)checkStoreSame:(NSArray<SSBPStore *> *)val1 val2:(NSArray<SSBPStore *> *)val2;
+ (BOOL)checkEmpty:(NSString *)str;
+ (BOOL)isDecimal:(NSString *)numStr;

+ (void)openLink:(NSString *)linkStr;

+ (NSString *)matchString:(NSString *)str regex:(NSString *)pattern;

/// Get application state: This is  real Application state. It use for detect Application killed (UIApplicationStateInactive), background (UIApplicationStateBackground) and active (UIApplicationStateActive).
+ (enum UIApplicationState)applicationState;

/// Set application state: This is not real Application state. It use for detect Application killed (UIApplicationStateBackground) and not killed (UIApplicationStateActive).
+ (void)setApplicationState: (UIApplicationState)applicationState;

+ (NSInteger)getCurrentBattery;

/// get current SSID 
+ (NSString *)getSSID API_DEPRECATED_WITH_REPLACEMENT("getSSIDWithCompletion:", ios(4.1, 14.0));

/// get current SSID with completion
+ (void)getSSIDWithCompletion:(void(^)(NSString *))result API_AVAILABLE(ios(14.0.1));
+ (NSString *)identifierForAdvertising;
+ (NSString *)identifierForVendor;
+ (NSString *)urlEncodeUsingEncoding:(NSString *)stringEncode;

@end

#endif
