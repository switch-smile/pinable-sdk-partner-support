//
//  SSBPThreads.h
//  SSBPCore
//
//  Created by Hung on 2018/10/02.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SSBPThreads : NSObject

+ (void)performTaskInMainQueue:(void (^)(void))task;
+ (void)performSyncTaskInMainQueue:(void (^)(void))task;
+ (void)performTaskInBackground:(void (^)(void))task;
+ (void)perfromTaskInConcurrentQueue:(void (^)(void))task;
+ (void)perfromTaskInSerialQueue:(void (^)(void))task;
+ (void)performTaskAfterDelay:(double)delay task:(void (^)(void))task;
+ (void)perfromTaskInSerialBackgroundQueue:(void (^)(void))task;

@end
