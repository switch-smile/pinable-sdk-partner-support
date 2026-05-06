//
//  SSBPOfferLog.h
//  SSBPSdk
//
//  Created by Hung on 2018/06/06.
//  Copyright © 2018 Hung. All rights reserved.
//

#ifndef SSBPOfferLog_h
#define SSBPOfferLog_h
#import "SSBPBaseModel.h"

@interface SSBPOfferLog : NSObject <NSCoding, SSBPBaseModel>

@property (assign, nonatomic) NSInteger type;
@property (copy, nonatomic) NSString *offerId;
@property (copy, nonatomic) NSString *beaconId;
@property (copy, nonatomic) NSString *latitude;
@property (copy, nonatomic) NSString *longitude;
@property (copy, nonatomic) NSString *accuracy;
@property (strong, nonatomic) NSDate *getTimestamp;
@property (strong, nonatomic) NSDate *useTimestamp;

// v3
@property (copy, nonatomic) NSString *uuid;
@property (copy, nonatomic) NSString *major;
@property (copy, nonatomic) NSString *minor;

@property (copy, nonatomic) NSString *idfa;

@end

#endif /* SSBPOfferLog_h */
