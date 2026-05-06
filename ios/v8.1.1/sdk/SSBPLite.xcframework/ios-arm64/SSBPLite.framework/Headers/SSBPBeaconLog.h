//
//  SSBPBeaconLog.h
//  SSBPSdk
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_BeaconLog_h
#define SSBP_AppSDK_Static_BeaconLog_h
#import "SSBPBaseModel.h"

@interface SSBPBeaconLog : NSObject <NSCoding, SSBPBaseModel>

@property (copy, nonatomic) NSString *beaconId;
@property (assign, nonatomic) NSInteger proximity;
@property (copy, nonatomic) NSString *accuracy;
@property (copy, nonatomic) NSString *rssi;
@property (copy, nonatomic) NSString *latitude;
@property (copy, nonatomic) NSString *longitude;
@property (copy, nonatomic) NSString *gpsAccuracy;
@property (copy, nonatomic) NSString *timestamp;

@property (copy, nonatomic) NSString *uuid;
@property (copy, nonatomic) NSString *major;
@property (copy, nonatomic) NSString *minor;

@property (copy, nonatomic) NSString *idfa;

@end

#endif
