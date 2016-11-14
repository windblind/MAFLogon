#import <Foundation/Foundation.h>
#import "SODataOfflineStoreOptions.h"
#import "SODataOfflineStoreDelegate.h"
#import "SODataOfflineStoreRefreshDelegate.h"
#import "SODataOfflineStoreFlushDelegate.h"
#import "SODataOfflineStoreRequestErrorDelegate.h"
#import "SODataStoreSync.h"
#import "SODataStoreAsync.h"

/**
 * An Offline Store is represented by an SODataOfflineStore object in the code. 
 * An Offline Store embodies a single OData Endpoint, exposed by an OData Producer, 
 * that is taken offline. A fully initialized offline store provides the 
 * application with the ability to query and modify the data of that OData 
 * Endpoint seamlessly in a disconnected environment. 
 *
 * The offline store is a particular implementation of an OData Store as defined 
 * by the Harmonized OData API. The Harmonized OData API is a set of interfaces 
 * and objects which define the standard interactions an application can make 
 * with an OData Endpoint. These interactions include such things as executing 
 * OData read and modification requests and perusing the OData Endpoint 
 * metadata definition. Only those behaviours that are specific to the 
 * offline store are documented here.
 *
 * A defining request is an OData read request that targets the OData Endpoint 
 * associated with the offline store and retrieves a subset of the OData Endpoint data.
 * Before a store is opened, it is initialized with a set of defining requests. 
 * The set of data that is made available while disconnected on the device corresponds 
 * to the union of data received by executing all of the defining requests. 
 * During initialization, the offline store communicates with the server 
 * to collect the data from that OData Endpoint and stores it locally on the device.
 *
 * Over time, the locally stored data may grow out of date compared to the OData Endpoint. 
 * The offline store is brought back up to date with the OData Endpoint by means of 
 * a refresh. During a refresh, the offline store communicates with the server
 * to re-collect the data from the OData Endpoint and reconciles 
 * it with the locally stored data. An application has the ability to instruct the 
 * offline store to only refresh a subset of locally stored data. This can be done 
 * in order to minimize or prioritize the amount of data that must be refreshed. 
 * This is done by providing a subset of defining request names to the refresh 
 * mechanism. The refreshed data will correspond to the union of the data received 
 * by the subset of defining requests. 
 * Refreshing only a subset of the data may result in inconsistent relationship 
 * data on the client.
 *
 * An offline store enables the application to modify data while disconnected. 
 * As a result, modification requests made to the offline store are stored 
 * locally in a request queue until connectivity can be re-established.
 * When connectivity is available, the application must flush the request 
 * queue in order to propagate the stored requests to the OData Producer. 
 * During a flush, the offline store communicates with the server
 * and attempts to execute all of the stored requests against the OData 
 * Producer. If the OData Producer fails one of the queued requests during a 
 * flush, the client is notified in two ways: 
 * 1. If the requestErrorDelegate property of the offline store is set, then 
 * the delegate method is invoked. 
 * 2. By querying the contents of the error archive. 
 *
 * The error archive is exposed to the application as an OData collection and is 
 * accessible through OData read requests to the URL /ErrorArchive.
 * The error archive must be cleared out by the application by executing 
 * DELETE requests against the individual entries in the error archive.
 *
 */
@interface SODataOfflineStore : NSObject <SODataStoreAsync>

/**
 * Indicates whether the store is currently open.
 * A store is considered open if the openStoreWithOptions method has been called successfully
 * and closeStoreWithError has not yet been called
 *
 */
@property (atomic, assign, readonly, getter=isOpen) bool open;
/**
 * The store delegate.  
 * The methods of this delegate are called at various stages during the execution of OpenStoreWithError.
 */
@property (nonatomic, strong) id<SODataOfflineStoreDelegate> offlineStoreDelegate;
/**
 * The request error delegate.  
 * Modify requests executed against the Offline Store are applied to the local store and are stored in the request queue.
 * When the request queue is flushed by invoking scheduleFlushQueuedRequestsWithDelegate these pending requests are 
 * sent to the server and applied to the backend OData Producer.
 * In the event that one of these flushed requests fails against the backend OData Producer the details of the request
 * are stored in the Error Archive and this delegate is called.
 * Note that the flush operation will report a successful result even if some requests have failed against the backend OData Producer.
 */
@property (nonatomic, strong) id<SODataOfflineStoreRequestErrorDelegate> requestErrorDelegate;

/**
 * Performs static initialization of global memory data structures.
 * This method must be called exactly once at the start of the application,
 * before anything else from the Offline OData library is called.
 * An ideal time to call this method is during the application:didFinishLaunchingWithOptions: delegate
 */
+ (void) GlobalInit;

/**
 * Releases global memory data structures.
 * This must be called exactly once and after the last use the Offline OData library.
 * An ideal time to call this method is during the applicationWillTerminate: delegate
 */
+ (void) GlobalFini;


/**
 * Removes the physical store from the file system.
 * All instances of the store must be closed before it can be removed.
 * Only the storeName option must be set in the SODataOfflineStoreOptions object parameter.  
 * All other options can be omitted.
 * GlobalInit must have been called at some point before the operation is invoked.
 *
 * @param options the configuration options for the store.  Only the storeName option needs to be set.
 * @param error the error object passed back in case of an error
 *
 * \sa SODataOfflineStoreOptions
 */
+ (void) RemoveStoreWithOptions:(SODataOfflineStoreOptions*) options
			  error:(NSError**) error;

/**
 * Opens the store asynchronously.  If the offlineStoreDelegate property is set then this delegate will
 * be called upon reaching each stage of the open.
 * The store cannot perform any other operations until it has been opened successfully.
 *
 * Depending on the server configuration, following the open the store may be fully populated 
 * or may require a subsequent refresh to download the initial data.
 *
 * The application must have network connectivity to open a store for the first time.
 * Subsequent attempts to open the store may be performed without network connectivity.
 * 
 * @param options the configuration options for the store
 * @param error the error object passed back in case of an error
 * @return whether the store options were sufficient to begin opening the store
 *
 * \sa SODataOfflineStoreOptions
 */
- (bool) openStoreWithOptions:(SODataOfflineStoreOptions*) options
			error:(NSError**) error;

/**
 * Asynchronously communicates with the server to download any new changes to the OData content.
 * The application must have network connectivity to perform this operation.
 * The delegate methods are called at various stages of the refreshes.
 * 
 * @param delegate the delegate to call when the refresh starts, finishes, or fails.
 */
- (void) scheduleRefreshWithDelegate:(id<SODataOfflineStoreRefreshDelegate>) delegate;

/**
 * Asynchronously communicates with the server to download any new changes to the OData content.
 * The application must have network connectivity to perform this operation.
 * The delegate methods are called at various stages of the refreshes.
 * 
 * @param subset a comma separated list of defining request names.  
 * 	         Only changes received through the listed defining requests will be downloaded.
 * @param delegate the delegate to call when the refresh starts, finishes, or fails.
 *
 */
- (void) scheduleRefreshWithRefreshSubset:(NSString*) subset
				 delegate:(id<SODataOfflineStoreRefreshDelegate>) delegate;

/**
 * Returns whether or not the there are any pending requests stored in the request queue that have 
 * not yet been flushed.
 *
 * @param error the error object passed back in case of an error
 * @return whether or not the request queue is empty
 */
- (bool) getRequestQueueIsEmpty:(NSError*__autoreleasing*) error;

/**
 * Registers a request to download an individual media stream.
 * The registered request must be the read link of the media entity (not the media stream).
 *
 * @param requestName an arbitrary and unique name associated with the defining request.  
 * @param resourcePath the path to the media entity
 */
- (void) registerStreamRequestWithName:(NSString*)requestName
			  resourcePath:(NSString*)resourcePath
				 error:(NSError**) error;

/**
 * Unregisters a previously registered stream request
 *
 * @param requestName The name of the request to unregister
 */
- (void) unregisterStreamRequestWithName:(NSString*)requestName
				   error:(NSError**) error;

/**
 * Registers a request to download an individual media stream.
 * The registered request must be the read link of the media entity (not the media stream).
 * 
 * @throws ODataException
 *		  if an error occurs
 */
- (void) closeStoreWithError:(NSError**) error;

/**
 * Asynchronously starts sending pending modification requests to the server.
 * Modify requests executed against the offline store are applied to the local store and are stored in the request queue.
 * When the request queue is flushed by invoking this method these pending requests are 
 * sent to the server and applied to the backend OData Producer.
 * If a request fails against the OData Producer it will be stored in the Error Archive and trigger a call to the requestErrorDelegate. 
 * Note that the flush operation will report a successful result even if some requests have failed against the backend OData Producer.
 *
 * @param delegate the delegate to call when the flush starts, finishes, or fails.
 */
- (void) scheduleFlushQueuedRequestsWithDelegate:(id<SODataOfflineStoreFlushDelegate>) delegate;

/**
 * Retrieve version information about this library
 *
 * @return a string containing the version information about this library
 */
+ (NSString*) LibraryVersion;

@end



