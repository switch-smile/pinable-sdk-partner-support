//
//  SSBPAdvertisementConfig.h
//  SSBPSdk
//
//  Created by Hung on 2018/10/24.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SSBPPopupDelay) {
    SSBPPopupDelayTimeNone = 0,
    SSBPPopupDelayDisplayOne,
    SSBPPopupDelayTime5M,
    SSBPPopupDelayTime15M,
    SSBPPopupDelayTime30M,
    SSBPPopupDelayTime1H,
    SSBPPopupDelayTime3H,
    SSBPPopupDelayTime6H,
    SSBPPopupDelayTime12H,
    SSBPPopupDelayTime24H
};

@interface SSBPAdvertisementConfig : NSObject

/// Popup time delay each ad | default is None means display only one.
@property (assign, nonatomic) SSBPPopupDelay popupDelayEachAd;
/// Popup time delay value
@property (assign, nonatomic, readonly) NSInteger popupDelayEachAdValue;

@end
