//
//  SSBPRegionInfo.h
//
//  Copyright (c) 2016年 Switch Smile co.,ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CoreLocation/CoreLocation.h>

/// Beacon detection state class.\n
/// This class holds the values of a particular region. The values includes beaconId, UUID, Major, Minor, Proximity etc to identify the beacon.
@interface SSBPRegionInfo : NSObject

/// Beacon area identifier
@property (copy, nonatomic) NSString *identifier;
/// BeaconID
@property (copy, nonatomic) NSString *beaconId;
/// Detection proximity
@property (assign, nonatomic) CLProximity proximity;
/// The nearest beaconID based on determined result.
@property (copy, nonatomic, readonly) NSString *nearestBeaconId;
/// Detection date time
@property (strong, nonatomic) NSDate *updatedDate;
/// Detection accuracy
@property (assign, nonatomic) double accuracy;
/// Beacon uuid
@property (copy, nonatomic) NSString *uuid;
/// Beacon major
@property (copy, nonatomic) NSString *major;
/// Beacon minor
@property (copy, nonatomic) NSString *minor;

/// Get average after buffer detected beacon(beaconId), after reduced fluttering, determine the nearest beacon changing. Before execute this process, need to update beaconId.
/// @return Return true if the nearest beacon updated, return false if otherwise.
- (BOOL)checkNearestBeacon;
/// Clear all near beacon id
- (void)clearAll;

@end
