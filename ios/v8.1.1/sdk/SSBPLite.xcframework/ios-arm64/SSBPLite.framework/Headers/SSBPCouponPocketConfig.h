//
//  SSBPCouponPocketConfig.h
//  SSBPSdk
//
//  Created by vfa on 8/3/21.
//  Copyright © 2021 Togashi Ayumi. All rights reserved.
//

#ifndef SSBPCouponPocketConfig_h
#define SSBPCouponPocketConfig_h
@interface SSBPCouponPocketConfig: NSObject

@property (strong, nonatomic) NSString* appVendorName;
@property (strong, nonatomic) UIColor *backgroundColor;
@property (strong, nonatomic) UIColor *textColor;

@property (strong, nonatomic) UIColor *primaryButtonColor;
@property (strong, nonatomic) UIColor *primaryButtonTextColor;
@property (strong, nonatomic) UIColor *primaryButtonDisableColor;
@property (strong, nonatomic) UIColor *primaryButtonDisableTextColor;

@property (strong, nonatomic) UIColor *secondaryButtonColor;
@property (strong, nonatomic) UIColor *secondaryButtonTextColor;

@property (strong, nonatomic) UIColor *termOfUseBGColor;

@property (strong, nonatomic) UIColor *usedItemColor;

@property (strong, nonatomic) UIColor *couponDisableColor;
@property (strong, nonatomic) UIColor *couponDisableTextColor;

//@property (assign, nonatomic) UIFont *font;

+ (SSBPCouponPocketConfig *)sharedInstance;
@end

#endif /* SSBPCouponPocketConfig_h */
