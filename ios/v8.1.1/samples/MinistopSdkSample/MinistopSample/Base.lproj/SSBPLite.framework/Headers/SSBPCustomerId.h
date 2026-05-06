//
//  SSBPCustomerId.h
//  SSBPLite
//
//  Created by Tinku George on 28/10/19.
//  Copyright © 2019 Togashi Ayumi. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef SSBPCustomerId_h
#define SSBPCustomerId_h

/// Customer id information class.\n
/// This class holds the values of a customer id, ie, its key and value.

@interface SSBPCustomerId : NSObject

/// Key for the customer id
@property(copy, nonatomic) NSString *idName;
/// Value for the corresponding key
@property(copy, nonatomic) NSString *val;

@end

#endif
