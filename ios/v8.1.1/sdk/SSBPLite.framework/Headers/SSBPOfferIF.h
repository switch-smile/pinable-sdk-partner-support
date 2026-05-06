//
//  SSBPOfferIF.h
//  SSBPSdk
//
//  Created by Hung on 2018/06/06.
//  Copyright © 2018 Hung. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SSBPOffer.h"
#import "TSsbpBeacon.h"
#import "TSsbpOffer.h"
#import "TSsbpOfferReference.h"

typedef NS_ENUM(NSUInteger, SSBPOfferStatus) {
    SSBPOfferStatusNew = 0,
    SSBPOfferStatusChange,
    SSBPOfferStatusReceive,
};

/// The process in the SSBPOfferID class for holding, acquiring and updating the offer information in the internal DB.\n
/// Can access directly or via SSBPSdkIF with property ssbpOffer.

@interface SSBPOfferIF : NSObject

/// didAddOffer callback when receive an offer
@property (copy, nonatomic) void (^didAddOffer)(NSString *offerId, SSBPOfferStatus status);

/// Added as TSsbpOffer information to the internal DB of the application. When getBeaconOffers (Acquiring the information on beacon-associated offer information), getGeofenceOffers (Obtaining information on Geofence related information) is done, it is acquired as SSBPOffer list. Make them TSsbpOffer and keep them in internal DB so that status management etc can be done. Information that is linked by beaconId and geofenceId is also retained.
/// @param ssbpOffers SSBPOffer
/// @param beacon BeaconID
/// @param geofenceId GeofenceID
- (void)addOffers:(SSBPOffer *)ssbpOffer beacon:(TSsbpBeacon *)beacon geofenceId:(NSString *)geofenceId;
/// Added TSsbpOffer information to the internal DB of the application. If the same offerId exists, update processing will be done. It can be used as updating process when obtaining an offer image.
/// @param offer Offer information
- (void)addOffer:(TSsbpOffer *)offer;

/// Acquisition of the information on which the specified action is included from the internal DB of the application. If action is not specified, all offer information will be acquired.
/// @param action Action name
/// @return In successful acquisition, the list of the information of the offer is returned in the TSsbpOffer array. In case of acquisition failure, nil is returned.
- (NSArray<TSsbpOffer *> *)getInnerOffers:(NSString *)action;
/// Get all offer follow by action, uuid, major and minor.
/// @param action Action name
/// @param uuid Beacon uuid
/// @param major Beacon major
/// @param minor Beacon minor
/// @return In successful acquisition, the list of the information of the offer is returned in the TSsbpOffer array. In case of acquisition failure, nil is returned.
- (NSArray<TSsbpOffer *> *)getInnerOffers:(NSString *)action uuid:(NSString *)uuid major:(NSString *)major minor:(NSString *)minor;
/// Acquiring information on the offer matching the specified beaconId from the internal DB of the application.
/// @param beaconId BeaconID
/// @return In successful acquisition, the list of the information of the offer is returned in the TSsbpOffer array. In case of acquisition failure, nil is returned.
- (NSArray<TSsbpOffer *> *)getInnerBeaconOffers:(NSString *)beaconId;
/// Acquisition of information on offer that matches the specified (uuid, major, minor) from the internal DB of the application.
/// @param uuid Beacon uuid
/// @param major Beacon major
/// @param minor Beacon minor
/// @return In successful acquisition, the list of the information of the offer is returned in the TSsbpOffer array. In case of acquisition failure, nil is returned.
- (NSArray<TSsbpOffer *> *)getInnerBeaconOffers:(NSString *)uuid major:(NSString *)major minor:(NSString *)minor;
/// Acquisition of offer information in which the specified offerId matches from the internal DB of the application.
/// @param offerId OfferID
/// @return With acquisition success, the information of TSsbpOffer type will be returned. In case of acquisition failure, nil is returned.
- (TSsbpOffer *)getInnerOffer:(NSString *)offerId;


// Get all offer which not expried.
- (NSArray<TSsbpOffer *> *)getCoupons;

// Get all offer.
- (NSArray<TSsbpOffer *> *)getAll;
- (NSArray<TSsbpOffer *> *)getAllValidOffer;
- (NSArray<TSsbpOfferReference *> *)getOfferRefByOfferID:(NSString *)offerId;
- (TSsbpOfferReference *)findLastRefByOfferID:(NSString *)offerId;

/// In the application's internal DB, update the status of the offer information whose offerId you specify is updated to used.
/// @param offerId OfferID
/// @return Returns true if update of usage status is successful, false otherwise.
- (BOOL)useOffer:(NSString *)offerId;
/// Delete the offer information that the specified offerId matches in the internal DB of the application.
/// @param offerId OfferID
/// @return True for deletion is true, otherwise it returns false.
- (BOOL)removeOffer:(NSString *)offerId;
- (BOOL)removeOfferRef:(NSString *)offerId;
/// Delete all offer information from internal DB of application.
- (void)clearAllOffer;

- (int)checkOfferStatus:(TSsbpOffer *)item;
@end
