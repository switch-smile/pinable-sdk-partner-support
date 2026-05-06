//
//  SSBPNotificationManager.h
//  SSBPSdk
//
//  Created by Hung on 2018/10/19.
//  Copyright © 2018 Togashi Ayumi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "TSsbpOffer.h"
/// Define CompleteOffer callback
/// @param tSsbpOffer \n
/// Type: TSsbpOffer \n
/// Value: TSsbpOffer information
/// @paramt isSilentPush \n
/// Type: BOOL
/// Value: isSilentPush
typedef void (^CompleteOffer)(TSsbpOffer *tSsbpOffer, BOOL isSilentPush);

/// SSBPNotificationManager class is manager of Firebase notification, it receive silent/push notification of offer, advertisement of SSBP content.\n
/// For register need give us your app bunderId, push certification (p12 or p8), after that we create a SSBP-GoogleService-Info.plis file and then add it in your project.
@interface SSBPNotificationManager : NSObject

+ (SSBPNotificationManager *)sharedInstance;
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead.")));

#pragma mark - Event handler
/// Register of push notification, if use UNUserNotificationCenter please set delegate as self into it, place in didFinishLaunchingWithOptions in AppDelegate
/// @param obj \n
/// Type: id \n
/// Value: View context
/// @param finishBlock \n
/// Type: CompleteOffer \n
/// Value: CompleteOffer callback
- (void)registerTo:(id)obj didReceiveOffer:(CompleteOffer)finishBlock;
/// Unregister didReceiveOffer callback
/// @param obj The class want to register receive notification
- (void)unregisterDidReceiveOfferFrom:(id)obj;

#pragma mark - AppDelegate handler
/// Response of notification when app receive action tap to notification or receive direct when app is alive with silent push, place in didReceiveRemoteNotification for both normal and silent push, didReceiveNotificationResponse for normal push if use UNUserNotificationCenter in AppDelegate
/// @param application \n
/// Type: UIApplication \n
/// Value: Instance of UIApplication
/// @param userInfo \n
/// Type: NSDictionary \n
/// Value: Notification data response
- (void)application:(UIApplication *)application didReceiveNotification:(NSDictionary *)userInfo;
/// Response of local notification when app receive action tap to notification, place in didReceiveLocalNotification in AppDelegate
/// @param application \n
/// Type: UIApplication \n
/// Value: Instance of UIApplication
/// @param notification \n
/// Type: UILocalNotification \n
/// Value: Instance of UILocalNotification
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification API_DEPRECATED("Use 'userNotificationCenter: didReceiveNotificationResponse:' instead", ios(4.0, 10.0));
-(void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response API_AVAILABLE(ios(10.0));

#pragma mark - Register notification
/// Register of push notification, if use UNUserNotificationCenter please set delegate as self into it, place in didFinishLaunchingWithOptions in AppDelegate
/// @param application \n
/// Type: UIApplication \n
/// Value: Instance of UIApplication
/// @param delegate \n
/// Type: id \n
/// Value: UNUserNotificationCenterDelegate
/// @param completetion \n
/// Type: BOOL \n
/// Value:
- (void)registerNotification:(UIApplication *)application UNUserNotificationCenterDelegate:(id)delegate completetion:(void (^)(BOOL))completetion;
/// Register FCM token to SSBP server
//- (void)registerFCMToken:(NSString *)FCMToken;

#pragma mark - Local notification
/// Send a local notification
/// @param title \n
/// Type: NSString \n
/// Value: Notification title
/// @param message \n
/// Type: NSString \n
/// Value: Notification message
/// @param info \n
/// Type: NSDictionary \n
/// Value: Notification userInfo
- (void)sendLocalNotification:(NSString *)title message:(NSString *)message info:(NSDictionary *)info;
/// Send a local notification \n
/// Function available from iOS 10 and above
/// @param title \n
/// Type: NSString \n
/// Value: Notification title
/// @param subtitle \n
/// Type: NSString \n
/// Value: Notification subtitle
/// @param message \n
/// Type: NSString \n
/// Value: Notification message
/// @param info \n
/// Type: NSDictionary \n
/// Value: Notification userInfo
- (void)sendLocalNotification:(NSString *)title subtitle:(NSString *)subtitle message:(NSString *)message info:(NSDictionary *)info API_AVAILABLE(ios(10));

#pragma mark - Etc
/// Clear all pending and delivered of local notification from notification center
- (void)clearAllLocalNotification;

@end
