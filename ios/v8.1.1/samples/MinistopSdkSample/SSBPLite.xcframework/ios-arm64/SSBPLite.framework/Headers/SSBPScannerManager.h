//
//  SSBPLiteScannerManager.h
//  SSBPLite
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_LiteScannerManager_h
#define SSBP_AppSDK_Static_LiteScannerManager_h

#import <CoreLocation/CoreLocation.h>

#import "SSBPBeaconScanner.h"
#import "SSBPBeacon.h"
#import "SSBPOffer.h"
#import "TSsbpBeacon.h"
#import "SSBPRangingBeacon.h"

@interface SSBPScannerManager : SSBPBeaconScanner

@property (copy, nonatomic) void (^didFinishCheckMaster)(void);
@property (copy, nonatomic) void (^scannerHitBeaconOffers)(NSArray<SSBPOffer *> *ssbpOffers, TSsbpBeacon *beacon);

@property (copy, nonatomic) void (^ssbpOnOfferReceive)(SSBPOffer *ssbpOffer);

@property (nonatomic) BOOL isCheckingMaster;

- (void)regetMaster;
- (void)checkMaster;

- (void)setBeaconList:(NSArray<SSBPBeacon *> *)ssbpBeacons updateTime:(NSString *)updateTime;
- (void)getBeaconOffers:(TSsbpBeacon *)beacon;
- (void)getBeaconOffers:(TSsbpBeacon *)beacon completionBlock:(void(^)(SSBPOffer *offer, NSArray<SSBPOffer *> *offers))completionBlock;
- (void)getGpsOffers:(NSString *)latitude longitude:(NSString *)longitude completionBlock:(void(^)(SSBPOffer *offer))completionBlock;
- (void)getSsidOffers:(NSString *)ssid completionBlock:(void(^)(SSBPOffer *offer))completionBlock;

- (void)getAreaCampaigns:(TSsbpBeacon *)beacon completionBlock:(void(^)(SSBPOffer *offer))completionBlock;

@end

#endif
