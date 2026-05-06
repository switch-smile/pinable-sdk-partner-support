//
//  TSsbpApp.h
//
//  Created by Ayumi Togashi on 2016/09/15.
//  Copyright © 2016年 Switch Smile co.,ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_TSsbpApp_h
#define SSBP_AppSDK_Static_TSsbpApp_h

#import <Foundation/Foundation.h>

@interface TSsbpApp : NSObject

@property (copy, nonatomic) NSString *appId;
@property (copy, nonatomic) NSString *appName;
@property (copy, nonatomic) NSString *appKey;
@property (copy, nonatomic) NSString *secretKey;
@property (copy, nonatomic) NSString *host;
@property (copy, nonatomic) NSString *deviceId;
@property (assign, nonatomic) BOOL useBeaconLog;
@property (assign, nonatomic) BOOL useOfferLog;
@property (assign, nonatomic) BOOL useNotification;
@property (copy, nonatomic) NSString *csvFacilities;
@property (copy, nonatomic) NSString *csvFloors;
@property (copy, nonatomic) NSString *csvBeacons;
@property (copy, nonatomic) NSString *csvNodes;
@property (copy, nonatomic) NSString *csvEdges;

@end

#endif
