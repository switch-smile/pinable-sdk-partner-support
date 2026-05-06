//
//  SSBPBeacon.h
//  SSBPSdk
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_Beacon_h
#define SSBP_AppSDK_Static_Beacon_h

#import <Foundation/Foundation.h>
#import "SSBPBaseModel.h"

@interface SSBPBeacon : NSObject <SSBPBaseModel>

@property (copy, nonatomic) NSString *beaconId;
@property (copy, nonatomic) NSString *beaconName;
@property (copy, nonatomic) NSString *major;
@property (copy, nonatomic) NSString *realMajor;
@property (copy, nonatomic) NSString *minor;
@property (assign, nonatomic) NSInteger proximity;
@property (copy, nonatomic) NSString *actions;
@property (copy, nonatomic) NSString *localName;
@property (copy, nonatomic) NSString *moduleId;
@property (copy, nonatomic) NSString *latitude;
@property (copy, nonatomic) NSString *longitude;
@property (copy, nonatomic) NSString *altitude;
@property (copy, nonatomic) NSString *facilityId;
@property (copy, nonatomic) NSString *floorId;
@property (assign, nonatomic) NSInteger relativeX;
@property (assign, nonatomic) NSInteger relativeY;

@end

#endif
