//
//  TSsbpOffer.h
//
//  Created by Ayumi Togashi on 2016/04/22.
//  Copyright © 2016年 Switch Smile co.,ltd. All rights reserved.
//

#ifndef SSBP_App_Static_TSsbpOffer_h
#define SSBP_App_Static_TSsbpOffer_h

#import <Foundation/Foundation.h>
#import "SSBPStore.h"

@interface TSsbpOffer : NSObject <SSBPEqualable, NSCoding>

// ID
@property (assign, nonatomic) NSInteger nId;

// Offer Info
@property (copy, nonatomic) NSString *offerId;
@property (copy, nonatomic) NSString *offerName;
@property (copy, nonatomic) NSString *offerAction;
@property (copy, nonatomic) NSArray<SSBPStore *> *offerTexts;
@property (copy, nonatomic) NSArray<SSBPStore *> *offerLinks;
@property (copy, nonatomic) NSString *offerStartAt;
@property (copy, nonatomic) NSString *offerEndAt;

// ステータス
@property (assign, nonatomic) NSInteger status;
// 取得日時
@property (copy, nonatomic) NSString *acquiredDate;
// 使用日時
@property (copy, nonatomic) NSString *usedDate;

@property (copy, nonatomic) NSString *createdDate;
@property (copy, nonatomic) NSString *updatedDate;

@property (strong, nonatomic) NSString *logCpnSendId;
@property (strong, nonatomic) NSString *logAreaCpnSendId;

-(NSString *)getValueLink: (NSString *)key;
-(NSString *)getValueText: (NSString *)key;
-(BOOL)checkExpiredOffer;
-(BOOL)checkExpiredOfferAfterTime:(int)displayAfter;

@end

#endif
