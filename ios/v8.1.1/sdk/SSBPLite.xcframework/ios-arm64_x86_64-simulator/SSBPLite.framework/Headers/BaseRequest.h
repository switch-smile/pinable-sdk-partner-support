//
//  BaseRequest.h
//  SSBPSdk
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_BaseRequest_h
#define SSBP_AppSDK_Static_BaseRequest_h

@interface BaseRequest : NSObject

@property (copy, nonatomic) NSString *appKey;
@property (assign, nonatomic) NSInteger t;
@property (copy, nonatomic) NSString *digest;

- (void)makeDigest;

@end

#endif
