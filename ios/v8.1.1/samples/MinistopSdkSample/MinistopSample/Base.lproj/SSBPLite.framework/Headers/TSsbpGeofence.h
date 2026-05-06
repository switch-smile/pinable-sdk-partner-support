//
//  TSsbpGeofence.h
//
//  Copyright (c) 2016年 Switch Smile co.,ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_TGeofence_h
#define SSBP_AppSDK_Static_TGeofence_h

#import <Foundation/Foundation.h>

@interface TSsbpGeofence : NSObject

// ID
@property (assign, nonatomic) NSInteger nId;

@property (copy, nonatomic) NSString *geofenceId;
@property (copy, nonatomic) NSString *geofenceMessage;
@property (copy, nonatomic) NSString *latitude;
@property (copy, nonatomic) NSString *longitude;
@property (assign, nonatomic) double radius;
@property (copy, nonatomic) NSString *geofenceStartAt;
@property (copy, nonatomic) NSString *geofenceEndAt;

@property (copy, nonatomic) NSString *createdDate;
@property (copy, nonatomic) NSString *updatedDate;

@end

#endif
