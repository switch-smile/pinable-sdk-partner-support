//
//  SSBPStore.h
//  SSBPSdk
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_Store_h
#define SSBP_AppSDK_Static_Store_h

#import "SSBPBaseModel.h"

/// Key-Value store information class
@interface SSBPStore : NSObject <SSBPBaseModel, NSCoding, SSBPEqualable>

/// tag
@property (copy, nonatomic) NSString *key;
/// value
@property (copy, nonatomic) NSString *value;

@end

#endif
