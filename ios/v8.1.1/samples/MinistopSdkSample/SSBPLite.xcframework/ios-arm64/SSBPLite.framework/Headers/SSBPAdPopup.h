//
//  SSBPAdPopup.h
//  SSBPSdk
//
//  Created by Hung on 2018/10/15.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SSBPAdvertisementConfig.h"
#import "TSsbpBeacon.h"

typedef void (^DidFailToReceiveAdWithError)(NSError *error);
typedef void (^WillLeaveApplication)(void);
typedef void (^WillPresentScreen)(void);
typedef void (^WillDismissScreen)(void);
typedef void (^DidDismissScreen)(void);

/// Popup SSBP Ad small size 320x100
SSBP_EXTERN const SSBPAdSize SSBPAdPopupSizeSmall;
/// Popup SSBP Ad medium size 320x250
SSBP_EXTERN const SSBPAdSize SSBPAdPopupSizeMedium;
// Popup SSBP Ad leaderboard size 728x250
SSBP_EXTERN const SSBPAdSize SSBPAdPopupSizeLeaderboard;

SSBP_FINAL
@interface SSBPAdPopup : NSObject

- (instancetype)initWithSize:(SSBPAdSize)size config:(SSBPAdvertisementConfig *)config tapNotification:(BOOL)tap;
- (instancetype)initWithSize:(SSBPAdSize)size config:(SSBPAdvertisementConfig *)config;

/// Present ad popup with general ads
- (void)refreshAds;
/// Present ad popup with beacon
- (void)refreshAdsWithBeacon:(TSsbpBeacon *)beacon;

/// Callback tell ad request failed
- (void)didFailToReceiveAdWithError:(DidFailToReceiveAdWithError)handler;
/// Callback tell a ad popup will be presented.
- (void)willPresentScreen:(WillPresentScreen)handler;
/// Callback tell a ad popup is to be animated off the screen.
- (void)willDismissScreen:(WillDismissScreen)handler;
/// Callback tell a ad popup had been animated off the screen.
- (void)didDismissScreen:(DidDismissScreen)handler;
/// Callback tell a user click will open another app
- (void)willLeaveApplication:(WillLeaveApplication)handler;

/// Register event for show ad when detect beacon
- (void)registerTo:(UIViewController *)root;
/// Unregister event, ad not show when detect beacon anymore
- (void)unregister;
/// Remove ad popup from parent
- (void)removeFromParent;

@end
