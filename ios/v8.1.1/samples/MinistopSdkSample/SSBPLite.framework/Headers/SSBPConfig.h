//
//  SSBPConfig.h
//  SSBPCore
//
//  Created by Hung on 2018/06/25.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef SSBPConfig_h
#define SSBPConfig_h

/// This class holds the basic configuration details like, useGPS flag, useCoreBluetooth flag etc.
@interface SSBPConfig : NSObject

+ (id)sharedInstance;
/// Using GPS Flag\n
/// The initial value is true\n
@property (readonly, assign, nonatomic) BOOL useGPS;
/// Using Geofence Flag\n
/// The initial value is false\n
/// Set value is true to disable Geofence
@property (assign, nonatomic) BOOL useGeofence;
/// Push Notification Usage Flag\n
/// The initial value is false\n
/// Value define in app_info.csv\n
/// Set to true if local push notification as offer by beacon detection is performed instead of push notification using APNs\n
/// Push Notification Usage Flag

@property (assign, nonatomic) BOOL useNotification;
/// Wait time Usage Flag\n
/// The initial value is 60\n
/// Time to delay each getBeaconOffer call, minimum is 60s
@property (assign, nonatomic) NSInteger waitTime __deprecated_msg("SDK no longer support this feature. Please remove it");;
// History of beacons detect, default 20\n
/// Limit beacon history wait time\n
/// Total beacons can be saved, default is 20 item
@property (assign, nonatomic) NSInteger limitHistoryWaitTime __deprecated_msg("SDK no longer support this feature. Please remove it");
/// Min interval Usage Flag\n
/// The initial value is 10s\n
/// If useDate is nil, update useDate with minInterval and use as delay first time getBeaconOffer call.
@property (assign, nonatomic) NSInteger minInterval;
/// can send log app chage state to active
@property (assign, nonatomic) BOOL launchNotification;
/// interval send log gps, unit is minute
@property (assign, nonatomic) NSInteger gpsInfoNotification;

@end

#endif /* SSBPConfig_h */
