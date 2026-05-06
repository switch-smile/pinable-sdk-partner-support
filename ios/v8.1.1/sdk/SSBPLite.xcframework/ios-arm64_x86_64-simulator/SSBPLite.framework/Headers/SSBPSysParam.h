//
//  SSBPSysParam.h
//  SSBPSdk
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_SysParam_h
#define SSBP_AppSDK_Static_SysParam_h
#import "SSBPBaseModel.h"

@interface SSBPSysParam : NSObject <SSBPBaseModel>

@property (copy, nonatomic) NSString *sysKey;
@property (copy, nonatomic) NSString *sysValue;

@end

#endif
