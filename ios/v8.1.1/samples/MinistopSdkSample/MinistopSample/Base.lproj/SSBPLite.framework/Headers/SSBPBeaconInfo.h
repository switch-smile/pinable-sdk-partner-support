//
//  SSBPBeaconInfo.h
//  SSBPSdk
//
//  Created by Hung on 2018/06/11.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#ifndef SSBPBeaconInfo_h
#define SSBPBeaconInfo_h
#import "SSBPBaseModel.h"

@interface SSBPBeaconInfo : NSObject <SSBPBaseModel>

@property (copy, nonatomic) NSString *uuid;
@property (copy, nonatomic) NSString *major;
@property (copy, nonatomic) NSString *minor;
@property (copy, nonatomic) NSArray<NSString *> *beaconTags;
@property (copy, nonatomic) NSString *latitude;
@property (copy, nonatomic) NSString *longitude;
@property (copy, nonatomic) NSString *altitude;

@end

#endif /* SSBPBeaconInfo_h */
