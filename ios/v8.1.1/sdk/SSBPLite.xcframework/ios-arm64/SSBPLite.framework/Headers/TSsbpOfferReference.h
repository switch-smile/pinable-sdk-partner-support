//
//  TSsbpOfferReference.h
//  SSBPSdk
//
//  Created by Hung on 2018/06/28.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TSsbpOfferReference : NSObject

@property (assign, nonatomic) NSInteger nId;
@property (assign, nonatomic) NSString *offerId;

@property (copy, nonatomic) NSString *beaconId;
@property (copy, nonatomic) NSString *geofenceId;
@property (copy, nonatomic) NSString *uuid;
@property (copy, nonatomic) NSString *major;
@property (copy, nonatomic) NSString *minor;

@property (copy, nonatomic) NSString *createdDate;
@property (copy, nonatomic) NSString *updatedDate;

@end
