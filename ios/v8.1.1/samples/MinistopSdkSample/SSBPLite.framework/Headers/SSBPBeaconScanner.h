//
//  SSBPBeaconScanner.h
//  SSBPCore
//
//  Created by Hung on 2018/09/21.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_BeaconScanner_h
#define SSBP_AppSDK_Static_BeaconScanner_h

#import <CoreLocation/CoreLocation.h>

#import "SSBPConfig.h"
#import "SSBPRegionInfo.h"
#import "TSsbpBeacon.h"
#import "TSsbpBeaconAction.h"
#import "TSsbpGeofence.h"
#import "SSBPRangingBeacon.h"

@protocol RangingDelegate <NSObject>

@optional

- (void)rangingBeacon:(int)type region:(CLRegion *)region; //1 for Entry status, 2 for Exit status

@end

@interface SSBPBeaconScanner : CLLocationManager<CLLocationManagerDelegate>

@property (strong, nonatomic) SSBPConfig *config;

@property (copy, nonatomic, readonly) NSString *latitude;
@property (copy, nonatomic, readonly) NSString *longitude;
@property (copy, nonatomic, readonly) NSString *horizontalAccuracy;

@property (assign, nonatomic, readonly) CLLocationDirection magneticHeading;
@property (assign, nonatomic, readonly) CLLocationDirection trueHeading;

@property (strong, nonatomic) NSArray<NSString *> *uuids;
@property (nonatomic, readonly) TSsbpBeacon *lastBeacon;

@property (copy, nonatomic) void (^didStart)(void);
@property (copy, nonatomic) void (^didFinishLocation)(NSError *error);
@property (copy, nonatomic) void (^scannerDidMessage)(NSString *type, NSString* title, NSString *message);
// hit geo
@property (copy, nonatomic) void (^scannerHitGeofence)(NSString *geofenceId, NSString *message);
// hit beacon
@property (copy, nonatomic) void (^scannerHitBeacon)(TSsbpBeacon *beacon);
// change beacons
@property (copy, nonatomic) void (^didChangeNearest)(NSString *beaconId);
@property (copy, nonatomic) void (^didChangeBeacon)(SSBPRegionInfo *info);
@property (copy, nonatomic) void (^watchBeaconsDetected)(NSDictionary<NSString *, NSArray<TSsbpBeacon *> *> *beacons);
// Compass
@property (copy, nonatomic) void (^didFinishHeading)(CLHeading *heading);
// Location authorization status
@property (copy, nonatomic) void (^didChangeLocationAuthorizationStatus)(CLAuthorizationStatus status);

@property (weak, nonatomic) id<RangingDelegate>rangingDelegate;

- (void)scanStartCompleted:(void (^)(NSError *error))completion;
- (void)rangingStop;
- (void)scanStopCompleted:(void (^)(NSError *error))completion;
- (CLAuthorizationStatus)currentLocationAuthorizationStatus;
- (void)forceScanStopCompleted:(void (^)(NSError *error))completion;
- (void)applicationEnterBackground;
- (void)applicationWillTerminal;
- (NSArray *)filterUuids:(NSArray *)uuids;
- (TSsbpBeacon *)filterBeacon:(TSsbpBeacon *)beacon;

- (NSArray<SSBPRegionInfo *> *)getRegionInfoList;

- (NSArray<TSsbpBeacon *> *)getAllBeacons;
- (TSsbpBeacon *)getBeaconWithUuid:(NSString *)uuid major:(NSString *)major minor:(NSString *)minor;
- (NSArray<TSsbpBeacon *> *)getInnerBeacons;
- (TSsbpBeacon *)getInnerBeacon:(NSString *)beaconId;
- (NSArray<TSsbpBeacon *> *)getNearLocationBeacons:(NSInteger)max_num;
- (void)addBeacon:(TSsbpBeacon *)beacon;
- (void)clearAllBeacon;
- (void)clearAllBeaconAction;

- (NSArray<TSsbpBeaconAction *> *)getBeaconActions;
- (TSsbpBeaconAction *)getBeaconAction:(NSString *)beaconId;
- (TSsbpBeaconAction *)getBeaconAction:(NSString *)uuid major:(NSString *)major minor:(NSString *)minor;
- (void)setBeaconActionStatus:(NSString *)beaconId status:(NSInteger)status;
- (void)clearBeaconAction:(NSString *)beaconId;
- (void)clearBeaconAction:(NSString *)uuid major:(NSString *)major minor:(NSString *)minor;

- (void)addGeofence:(TSsbpGeofence *)geofence;
- (void)clearAllGeofence;
- (NSArray<TSsbpGeofence *> *)getInnerGeofences;
- (TSsbpGeofence *)getInnerGeofence:(NSString *)geofenceId;
- (NSArray<TSsbpGeofence *> *)getNearLocationGeofences:(NSInteger)max_num;

- (void)updateAllowsBackgroundLocation;
- (void)startLocationService;
- (void)startSignificantLocationService;
- (void)stopLocationService;

- (void)compassStart;
- (void)compassStop;

#pragma mark - ranging beacons
- (void)startRanging:(NSArray<SSBPRangingBeacon *> *)beacons;
- (NSArray<SSBPRangingBeacon*>*)getAll;
- (SSBPRangingBeacon *)findByBeaconUuid:(NSString *)uuid major:(NSString *)major minor:(NSString *)minor;
- (BOOL)add:(SSBPRangingBeacon *)rangingBeacon;
- (BOOL)updateBeaconDetails:(SSBPRangingBeacon *)rangingBeacon;
- (BOOL)updateDetectionDetails:(SSBPRangingBeacon *)rangingBeacon;
- (BOOL)remove:(SSBPRangingBeacon *)rangingBeacon;

@end

#endif
