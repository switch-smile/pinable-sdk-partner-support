//
//  SSBPHttpRequester.h
//
//  Copyright (c) 2016年 Switch Smile Co., Ltd. All rights reserved.
//

#ifndef SSBP_AppSDK_Static_HttpRequester_h
#define SSBP_AppSDK_Static_HttpRequester_h

#import <UIKit/UIKit.h>

@interface SSBPHttpRequester : NSObject <NSURLSessionTaskDelegate>

@property (assign, nonatomic) NSInteger timeoutInterval; //[sec]
@property (assign, nonatomic) NSInteger retryCount;
@property (assign, nonatomic) NSInteger retryInterval; //[msec]

- (NSURLSessionDataTask *)httpRequestGet:(NSString *)url withParam:(NSDictionary *)param completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (NSURLSessionDataTask *)httpRequestPost:(NSString *)url withParam:(NSDictionary *)param withData:(NSData *)data completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
- (NSURLSessionDataTask *)httpRequestJsonPost:(NSString *)url withData:(NSData *)data completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;

- (void)setCancel;

@end

#endif
