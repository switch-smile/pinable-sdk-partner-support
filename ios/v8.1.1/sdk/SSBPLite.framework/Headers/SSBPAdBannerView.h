//
//  SSBPAdBannerView.h
//  SSBPSdk
//
//  Created by Hung on 2018/10/15.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TSsbpBeacon.h"

typedef NS_ENUM(NSUInteger, SSBPAdType) {
    SSBPAdTypeText,
    SSBPAdTypeBanner
};

typedef void (^DidFailToReceiveAdWithError)(NSError *error);
typedef void (^WillLeaveApplication)(void);
typedef void (^DidScrollHeightUpdate)(CGFloat height);

/// Banner SSBP Ad small size 320x50
SSBP_EXTERN const SSBPAdSize SSBPAdBannerSizeSmall;
/// Banner SSBP Ad medium size 320x100
SSBP_EXTERN const SSBPAdSize SSBPAdBannerSizeMedium;
/// Banner SSBP Ad leaderboard size 728x90
SSBP_EXTERN const SSBPAdSize SSBPAdBannerSizeLeaderboard;

SSBP_FINAL
@interface SSBPAdBannerView : UIView

- (instancetype)initWithSize:(SSBPAdSize)size type:(SSBPAdType)adType tapNotification:(BOOL)tap;
- (instancetype)initWithSize:(SSBPAdSize)size type:(SSBPAdType)adType;

- (void)refreshAds;
- (void)refreshAdsWithBeacon:(TSsbpBeacon *)beacon;

/// Callback tell ad request failed
- (void)didFailToReceiveAdWithError:(DidFailToReceiveAdWithError)handler;
/// Callback tell a user click will open another app
- (void)willLeaveApplication:(WillLeaveApplication)handler;
/// Callback tell scrollHeight after adview loaded
- (void)didScrollHeightUpdate:(DidScrollHeightUpdate)handler;

/// Register event for refresh ad
- (void)registerTo:(UIViewController *)root;
/// Unregister event, ad not refresh anymore
- (void)unregister;

@end
