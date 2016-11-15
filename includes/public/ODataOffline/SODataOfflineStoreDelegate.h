// *****************************************************
// Copyright (c) 2013 SAP AG or an SAP affiliate company. All rights reserved.
// *****************************************************

@class SODataOfflineStore;

/**
 * Offline OData store opening states.
 * These states represent the major activities during initialization and opening of the offline store.
 */
typedef enum SODataOfflineStoreState {
    SODataOfflineStoreOpening,		/* The store has started to open */
    SODataOfflineStoreInitializing,  	/* Initializing the resources for a new store */
    SODataOfflineStorePopulating,	/* Populating the store */
    SODataOfflineStoreDownloading,   	/* Downloading the store */
    SODataOfflineStoreOpen,	    	/* The store has opened successfully */
    SODataOfflineStoreClosed	    	/* The store has been closed by the user while opening */
} SODataOfflineStoreState;

/**
 * Offline OData store notifications.
 * Notifications are hints to the application about the current state of the offline store.
 * They indicate that either a refresh or flush operation was previously interrupted and 
 * may be recovered if performed again.
 */
typedef enum SODataOfflineStoreNotification {
    SODataOfflineStorePendingRefresh,	/* The store was closed while performing a refresh.  
					 * It may be possible to continue the pending refresh by triggering a new refresh. */
    SODataOfflineStorePendingFlush,  	/* The store was closed while flushing the request queue.  
					 * It may be possible to continue the pending flush by triggering a new flush. */
} SODataOfflineStoreNotification;

@protocol SODataOfflineStoreDelegate <NSObject>
@required

/**
 * Called whenever the store state changes during the initialization and opening of the offline store.
 *
 * @param store the offline store being opened
 * @param newState the new state of the store
 *
 * \sa SODataOfflineStoreState
 */
- (void) offlineStoreStateChanged:(SODataOfflineStore*) store 
			    state:(SODataOfflineStoreState) newState;
/**
 * Called if the store fails to open
 *
 * @param store the offline store being opened
 * @param error the error that occurred 
 */
- (void) offlineStoreOpenFailed:(SODataOfflineStore*) store
			  error:(NSError*) error;
@optional
/**
 * Called when the store finishes opening.
 * This is guaranteed to be invoked at the end of the open processing regardless of the outcome of the open.
 *
 * @param store the offline store being opened
 */
- (void) offlineStoreOpenFinished:(SODataOfflineStore*) store;
/**
 * Called once for each notification that is available while opening the store.
 *
 * @param store the offline store being opened
 * @param notification the notification
 *
 * \sa SODataOfflineStoreNotification
 */
- (void) offlineStoreNotification:(SODataOfflineStore*) store
		     notification:(SODataOfflineStoreNotification) notification;
@end

