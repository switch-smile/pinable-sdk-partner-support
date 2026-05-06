//
//  SSBPCsvIF.h
//  SSBPSdk
//
//  Created by Ayumi Togashi on 2016/09/27.
//  Copyright © 2016年 Switch Smile co.,ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_SSBPCsvIF_h
#define SSBP_AppSDK_Static_SSBPCsvIF_h

#import <Foundation/Foundation.h>
#import "SSBPBeacon.h"
#import "TSsbpApp.h"

@interface SSBPCsvIF : NSObject

- (NSArray<TSsbpApp *> *)getAppInfos;
- (TSsbpApp *)getAppInfo:(NSString *)appName;
- (NSArray<SSBPBeacon *> *)getBeaconCSV:(NSString *)since csvBeacons:(NSString *)csvBeacons;

- (NSString *)getLastUpdate;

@end

#endif
