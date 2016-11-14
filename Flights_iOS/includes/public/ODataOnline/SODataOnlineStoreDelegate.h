//
//  SODataOnlineStoreDelegate.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

@class SODataOnlineStore;

/**
 Protocol for SODataOnlineStore opening
 */
@protocol SODataOnlineStoreDelegate <NSObject>

@required

/**
 Succesful delegate call after store opened
 */
-(void)onlineStoreOpenFinished:(SODataOnlineStore*)store;

/**
 Error delegate if store open failed
 */
-(void)onlineStoreOpenFailed:(SODataOnlineStore*)store error:(NSError*)error;

@end
