//
//  SSBPBaseModel.h
//  SSBPSdk
//
//  Created by Hung on 2018/06/11.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

@protocol SSBPBaseModel

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
- (NSString *)makeStringForDigest;

@end

@protocol SSBPEqualable

- (BOOL)isEqual:(id)object;

@end
