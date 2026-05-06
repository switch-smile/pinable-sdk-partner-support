//
//  SSBPOffer.h
//  SSBPSdk
//
//  Created by Hung on 2018/06/05.
//  Copyright © 2018 Hung. All rights reserved.
//

#ifndef SSBPOffer_h
#define SSBPOffer_h
#import "SSBPBaseModel.h"
#import "SSBPStore.h"


typedef NS_ENUM(NSUInteger, SSBPOfferActionType) {
    SSBPOfferActionTypeE,
    SSBPOfferActionTypeN
};

/// Offer information class.\n
/// This class holds the properties of an offer. The values includes offer id, offer name, start date, end date etc.
@interface SSBPOffer : NSObject <SSBPBaseModel>

/// Primary ID
@property (copy, nonatomic) NSString *offerId;
/// Name of the offer
@property (copy, nonatomic) NSString *offerName;
/// Type of the offer
@property (copy, nonatomic) NSString *offerAction;
/// Array of SSBPStore objects
@property (copy, nonatomic) NSArray<SSBPStore *> *offerTexts;
/// Array of SSBPStore objects
@property (copy, nonatomic) NSArray<SSBPStore *> *offerLinks;
/// Start date of the offer
@property (strong, nonatomic) NSDate *offerStartAt;
/// End date of the offer
@property (strong, nonatomic) NSDate *offerEndAt;
/// CPN Send ID using in server to track send time
@property (strong, nonatomic) NSString *logCpnSendId;
/// Area CPN Send ID using in server to track send time
@property (strong, nonatomic) NSString *logAreaCpnSendId;
/// Offer index for each offer in offer list
@property(nonatomic, retain) NSString *offerIndex;

- (SSBPOfferActionType)offerType;
- (NSString *)getValueLink: (NSString *)key;

- (NSString *)getValueText: (NSString *)key;
@end

#endif /* SSBPOffer_h */
