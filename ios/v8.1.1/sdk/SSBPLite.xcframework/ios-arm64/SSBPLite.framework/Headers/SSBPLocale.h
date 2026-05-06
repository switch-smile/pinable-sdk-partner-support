//
//  SSBPLocale.h
//  SSBPSdk
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_Locale_h
#define SSBP_AppSDK_Static_Locale_h
#import "SSBPBaseModel.h"

@interface SSBPLocale : NSObject <SSBPBaseModel>

@property (copy, nonatomic) NSString *localeId;
@property (copy, nonatomic) NSString *localeName;
@property (copy, nonatomic) NSString *localeStrings;
@property (assign, nonatomic) NSInteger localeDefault;

@end

#endif
