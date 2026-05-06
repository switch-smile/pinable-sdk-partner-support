//
//  SSBPUuid.h
//  SSBPSdk
//
//  Created by Hung on 2018/06/11.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#ifndef SSBPUuid_h
#define SSBPUuid_h
#import "SSBPBaseModel.h"

@interface SSBPUuid: NSObject <SSBPBaseModel, NSCoding>

@property (copy, nonatomic) NSString *uuidListVersion;
@property (copy, nonatomic) NSArray<NSString *> *uuids;

@end

#endif /* SSBPUuid_h */
