//
//  SSBPCouponView.h
//  SSBPLite
//
//  Created by vfa on 2/2/21.
//  Copyright © 2021 Togashi Ayumi. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "SSBPCouponPocketConfig.h"
#ifndef SSBPCouponView_h
#define SSBPCouponView_h

@interface SSBPCouponView: UIView<UICollectionViewDataSource,UICollectionViewDelegateFlowLayout, UICollectionViewDelegate>

@property (strong, atomic) SSBPCouponPocketConfig *config;
//@property(nonatomic, weak) id<OfferPopupHandlerDesign1Delegate> _Nullable delegate;

//-(void)updateData:(SSBPOfferPopupDetails *_Nonnull)offerDetails;
-(void)loadCoupon:(UIView *) containerView viewController: (UIViewController *)parentVC;
-(void)viewWillAppear;
-(void)viewDidDisappear;
-(void)updateCoupon;
@end

#endif /* SSBPCouponView_h */
