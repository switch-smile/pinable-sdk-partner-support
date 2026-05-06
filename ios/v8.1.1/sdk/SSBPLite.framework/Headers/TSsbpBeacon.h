//
//  TSsbpBeacon.h
//
//  Copyright (c) 2016年 Switch Smile co.,ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_TBeacon_h
#define SSBP_AppSDK_Static_TBeacon_h

#import <Foundation/Foundation.h>

/// Beacon information class.\n
/// This class holds the values of a beacon. The values includes beaconId, beacon name, UUID, Major, Minor, Proximity, battery level etc.
@interface TSsbpBeacon : NSObject<NSCoding>

// Primary ID
@property (assign, nonatomic) NSInteger nId;
// Beacon ID
@property (copy, nonatomic) NSString *beaconId;
// Beacon name
@property (copy, nonatomic) NSString *beaconName;
// Beacon uuid
@property (copy, nonatomic) NSString *uuid;
/// Beacon major
@property (copy, nonatomic) NSString *major;
@property (copy, nonatomic) NSString *realMajor;
/// Beacon minor
@property (copy, nonatomic) NSString *minor;
/// 距離(４段階)
/// Beacon proximity
@property (assign, nonatomic) NSInteger proximity;
/// Accuracy
@property (assign, nonatomic) double accuracy;
// CoreBluetoothで判別に利用するもの
@property (copy, nonatomic) NSString *localName;
@property (copy, nonatomic) NSString *moduleId;
/// Latitude of GPS
@property (copy, nonatomic) NSString *latitude;
/// longitude of GPS
@property (copy, nonatomic) NSString *longitude;
/// altitude
@property (copy, nonatomic) NSString *altitude;
/// facilityID
@property (copy, nonatomic) NSString *facilityId;
/// Facility remove flag
@property (assign, nonatomic) BOOL facilityRemove;
/// floorID
@property (copy, nonatomic) NSString *floorId;
/// X coordinate of setting position for floor image
@property (assign, nonatomic) NSInteger relativeX;
/// Y coordinate of setting position for floor image
@property (assign, nonatomic) NSInteger relativeY;
/// Action identifier list
@property (copy, nonatomic) NSString *actions;

/// Battery level of beacon
@property (assign, nonatomic) NSInteger batteryLevel;
/// signal strength
@property (assign, nonatomic) NSInteger rssi;
/// txPower of the beacon, ie, RSSI at 1 meter
@property (assign, nonatomic) NSInteger txPower;

/// Created date time
@property (copy, nonatomic) NSString *createdDate;
/// Update date time
@property (copy, nonatomic) NSString *updatedDate;

- (NSString *)beaconFullName;

@end

#endif
