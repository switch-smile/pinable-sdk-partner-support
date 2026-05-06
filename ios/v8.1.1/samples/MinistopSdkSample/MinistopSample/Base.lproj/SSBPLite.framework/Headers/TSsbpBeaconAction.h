//
//  TSsbpBeaconAction.h
//
//  Copyright (c) 2016年 Switch Smile co.,ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_TBeaconAction_h
#define SSBP_AppSDK_Static_TBeaconAction_h

#import <Foundation/Foundation.h>

@interface TSsbpBeaconAction : NSObject

// ID
@property (assign, nonatomic) NSInteger nId;
// ビーコンID
@property (copy, nonatomic) NSString *beaconId;

@property (copy, nonatomic) NSString *uuid;
@property (copy, nonatomic) NSString *major;
@property (copy, nonatomic) NSString *minor;
// ステータス
@property (assign, nonatomic) NSInteger status;
// 使用日時
@property (copy, nonatomic) NSString *usedDate;

@property (copy, nonatomic) NSString *createdDate;
@property (copy, nonatomic) NSString *updatedDate;

@end

#endif
