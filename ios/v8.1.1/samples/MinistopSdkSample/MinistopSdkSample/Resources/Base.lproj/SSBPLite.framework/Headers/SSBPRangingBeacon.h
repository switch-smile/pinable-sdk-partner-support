//
//  SSBPRangingBeacon.h
//  SSBPLite
//
//  Created by Tinku George on 27/11/19.
//  Copyright © 2019 Togashi Ayumi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SSBPBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SSBPRangingBeacon: NSObject <SSBPBaseModel>

@property (copy, nonatomic) NSString *uuid;
@property (copy, nonatomic) NSString *major;
@property (copy, nonatomic) NSString *minor;
@property (nonatomic) int limit_num;
@property (nonatomic) int limit_type; //1 -> Daily, 2 -> Weekly, 3 -> Monthly
@property (nonatomic) int boot_interval;
@property (nonatomic) int did; //1 -> Entry, 2 -> Exit
@property (copy, nonatomic) NSString *msg;
@property (nonatomic) int startDate;
@property (nonatomic) int updateDate;
@property (nonatomic) int updateCount;

@end

NS_ASSUME_NONNULL_END
