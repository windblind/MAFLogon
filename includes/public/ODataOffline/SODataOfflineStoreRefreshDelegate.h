// *****************************************************
// Copyright (c) 2013 SAP AG or an SAP affiliate company. All rights reserved.
// *****************************************************

@class SODataOfflineStore;

@protocol SODataOfflineStoreRefreshDelegate <NSObject>
@optional
/**
 * Called when a refresh has started
 *
 * @param store the offline store being refreshed
 */
- (void) offlineStoreRefreshStarted:(SODataOfflineStore*) store;
/**
 * Called when a refresh has finished.
 * Guaranteed to be invoked at the end of the refresh processing regardless of the outcome of the refresh.
 *
 * @param store the offline store being refreshed
 */
- (void) offlineStoreRefreshFinished:(SODataOfflineStore*) store;
@required
/**
 * Called when a refresh has finished successfully
 *
 * @param store the offline store being refreshed
 */
- (void) offlineStoreRefreshSucceeded:(SODataOfflineStore*) store;
/**
 * Called when a refresh has failed
 *
 * @param store the offline store being refreshed
 * @param error the error that occurred 
 */
- (void) offlineStoreRefreshFailed:(SODataOfflineStore*) store
			     error:(NSError*) error;
@end

