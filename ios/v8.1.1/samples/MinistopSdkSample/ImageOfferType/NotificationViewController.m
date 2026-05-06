//
//  NotificationViewController.m
//  ImageOfferType
//
//  Created by vfa on 3/8/21.
//  Copyright © 2021 Switch Smile Co., Ltd. All rights reserved.
//

#import "NotificationViewController.h"
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>

@interface NotificationViewController () <UNNotificationContentExtension>


@end

@implementation NotificationViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any required interface initialization here.
}

- (void)didReceiveNotification:(UNNotification *)notification {
    [super didReceiveNotification:notification];
}

@end
