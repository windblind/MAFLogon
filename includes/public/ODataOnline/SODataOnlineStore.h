//
//  SODataOnlineStore.h
//  ODataOnline_CR
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SODataStoreAsync.h"
#import "SODataStoreSync.h"
#import "SODataStore.h"
#import "SODataOnlineStoreDelegate.h"
#import "SODataOnlineStoreOptions.h"
#import "HttpConversationManager.h"

/**
 Online store implementation offering asynchronous functions for OData operations. One OnlineODataStore instance represents one service endpoint. The application can open several OnlineODataStore
 for the different endpoints in parallel.<br>
 <br>
 <h1>Opening an OnlineODataStore</h1>
 The ODataOnline Store should be initialized at first with the following method:
 <code>[[SODataOnlineStore alloc] initWithURL:[NSURL URLWithString:baseUrl] httpConversationManager:manager options:storeOptions];</code>
 An url the absolute URL of the service endpoint), a HttpConversationManager (see bellow) and an ODataOnlineStoreOptions (different store options - see bellow) should be passed as parameters. The
 HttpConversationManager needs to be configured before.
 The application can open the OnlineODataStore with <code>openStoreWithError</code> method.
 <br>
 Sample code:
 <pre>
 SODataOnlineStoreOptions* storeOptions = [[SODataOnlineStoreOptions alloc] init];
 storeOptions.requestFormat = SODataDataFormatXML;
 //enabe cache - optional
 storeOptions.useCache = YES;
 storeOptions.cacheEncryptionKey = kSODataCacheEncrytionKey; //NSString* as encryption key
 storeOptions.useForceMetadataDownload = NO;
 HttpConversationManager* manager = [[HttpConversationManager alloc] init];
 //configure HttpConversationManager
 CommonAuthenticationConfigurator* commonConfig = [[CommonAuthenticationConfigurator alloc] init];
 [commonConfig addUsernamePasswordProvider:self];
 [commonConfig configureManager:manager];
 NSString* baseUrl = self.baseUrl;
 self.store= [[SODataOnlineStore alloc] initWithURL:[NSURL URLWithString:baseUrl] httpConversationManager:manager options:storeOptions];
 [self.store setOnlineStoreDelegate:self];
 NSError* error = nil;
 [self.store openStoreWithError:error];
 </pre>
 <br>
 <h2>Obtaining HttpConversationManager</h2>
 A HttpConversationManager can be instantiated by its default init method. Once the HttpConversationManager is instantiated it must be configured to be able to handle common authentication/authorization
 flows (for ex.: Basic Auth).
 <br>
 <h3>MAF Logon Manager Configurator</h3>
 CommonAuthenticationConfigurator is used to configure HttpConversationManager. It can also handle credentials. In this case the application should implement UsernamePasswordProviderProtocol. The method
 configureManager should be always called.
 <br>
 <pre>
 HttpConversationManager* manager = [[HttpConversationManager alloc] init];
 CommonAuthenticationConfigurator* commonConfig = [[CommonAuthenticationConfigurator alloc] init];
 [commonConfig addUsernamePasswordProvider:self];
 [commonConfig configureManager:manager];
 </pre>
 <br>
 <h2>Options</h2>
 In the <code>initWithURL</code> method the application can provide OnlineODataStore.OnlineStoreOptions to configure the store. Store options contain the following fields:<br>
 <ul>
 <li><code>requestFormat</code> - can be <code>SODataDataFormats.SODataDataFormatXML</code>, <code>SODataDataFormats.SODataDataFormatJSON</code>, <code>SODataDataFormats.SODataDataFormatDefault</code>.
 Default value is <code>SODataDataFormats.SODataDataFormatDefault</code>. It specifies the format how the client sends the requests. <code>SODataDataFormats.SODataDataFormatDefault</code> means that if
 the OData version is 2.0 or 3.0 then the format is <code>SODataDataFormats.SODataDataFormatXML</code>. If the OData version is 4.0 then the format is <code>SODataDataFormats.SODataDataFormatJSON</code></li>
 <li><code>useForceMetadataDownload</code> - can be true/false. Default value is true. If it is true when the store is opened the OnlineODataStore downloads the metadata from the endpoint. Then the
 metadata is persisted.
 If this option is false when the store is opened then OnlineOdataStore tries to load it from the persistency. If the metadata does not exist in the persistency OnlineODataStore downloads it from the
 endpoint.</li>
 <li><code>useCache</code> - can be true/false. Default value is false. If it is true the technical cache feature is enabled. The following options are considered only if useCache is true.</li>
 <li><code>cacheEncryptionKey</code> - (only relevant is useCache=true) an encryption key used to encrypt/decrypt cache persistent store. This is mandatory to be set if useCache is true (no default
 value).</li>
 <li><code>cacheSizeLimit</code> - (only relevant is useCache=true) maximum cache size in kBytes. The default value is 16384 kBytes. If the cache size exceeds this limit then older cache items are
 removed from the cache.</li>
 </ul>
 <br>
 <h1>Technical cache</h1>
 The technical cache is an enhancement of the Harmonized OData API to optimize the server communication for online stores. The cached responses of previous OData requests enable the library to perform
 conditional (delta) request – either by HTTP or OData provided mechanism – to optimize the bandwidth utilization. The library should only perform this conditional request if the feature is enabled on
 the server (handling delta tokens).<br>
 Additionally an application can use the provided cache content to improve the user experience. It is in the responsibility of the application developer to use this feature and add the necessary
 implementation. From the library perspective it should make no difference if the callbacks are used or skipped by the application.
 Technical cache is disabled by default. It can be enabled by OnlineODataStore.OnlineStoreOptions.useCache option flag when the store is opened.
 <br>
 <h2>Technical Cache - Out of scope</h2>
 The technical cache should not support features listed below. Most of these capabilities are already provided by the offline OData store (aka Mobilink). In case an application requires these features it
 is recommended to switch to the offline store
 <ul>
 <li>Not queries in cached content. A response is associated to a particular request (including all parameters) and should be treated as an unbreakable unit. The cached content should only be used if the
 request URL of a second request is (literally) identical</li>
 <li>No CUD request when out of coverage o In case the device out of coverage and a CUD request is triggered, the library should fail and behave as if the technical cache is not enabled. The technical
 cache should not queue any request for a delayed processing.</li>
 </ul>
 The technical cache can run in active mode and in passive mode.<br>
 <h2>Technical Cache - Active Mode</h2>
 In active mode OnlineOdataStore uses the technical cache for optimization. In each request OnlineOdataStore notifies the application about the cached response within
 ODataRequestDelegate.requestCacheResponse(ODataRequestExecution) callback. Then OnlineODataStore sends the request to the server. When the server response arrives it notifies the application about the
 server response within ODataRequestDelegate.requestCacheResponse(ODataRequestExecution) callback.
 <br>
 Callback sequence for successful request:
 <ul>
 <li>requestStarted (Status == “Initialized”)</li>
 <li>requestCacheResponse (Status == “InProgress”)</li>
 <li>requestServerResponse (Status == “InProgress”)</li>
 <li>requestFinished (Status == “Completed”)</li>
 </ul>
 <br>
 Callback sequence for failure request:
 <ul>
 <li>requestStarted (Status == “Initialized”)</li>
 <li>requestCacheResponse (Status == “InProgress”)</li>
 <li>requestFailed (Status == “Failed”)</li>
 <li>requestFinished (Status == “Failed”)</li>
 </ul>
 <br>
 <h2>Technical Cache - Passive Mode</h2>
 In passive mode OnlineOdataStore uses only the cached data. This case there is no network round-trip. Typically this mode is used when there is no network coverage. In each request OnlineOdataStore
 notifies the application about the cached response within ODataRequestListener.requestCacheResponse(ODataRequestExecution) callback. Then there is no request to the server.<br>
 Callback sequence for successful request:
 <ul>
 <li>requestStarted (Status == “Initialized”)</li>
 <li>requestCacheResponse (Status == “InProgress”)</li>
 <li>requestFinished (Status == “Completed”)</li>
 </ul>
 <br>
 Callback sequence for failure request:
 <ul>
 <li>requestStarted (Status == “Initialized”)</li>
 <li>requestFailed (Status == “FailedInProgress”)</li>
 <li>requestFinished (Status == “Failed”)</li>
 </ul>
 <br>
 <h2>Technical Cache - useCache Flag per requests</h2>
 It can happen that the application does not want to use the cache for some specific requests. E.g. ATP checks. This case the application can disable the cache for that request with specifying
 <code>"useCache"="NO"</code> option within the request.<br>
 <h2>Technical Cache - closeCache/reopenCache</h2>
 The technical cache can be closed (closeCache). When the technical cache is closed the online store does not read/write cache data, does not handle delta responses, and does not invoke
 ODataRequestDelegate.requestCacheResponse callback. The store behaves exactly the same as the cache was not enabled in store open. When the cache is closed its secure persistent storage is also closed.
 This feature is typically used by the application when the application switches foreground/background. (It is a security product standard that the secure stores MUST be closed when the app goes to
 background). After reopen (reopenCache) the technical cache is used again. In reopenCache the application MUST provide the encryption key.
 If the store was opened with cache disabled, then closeCache or reopenCache can not be invoked.
 <br>
 <h1>Life-cycle of OnlineODataStore</h1>
 When an OnlineOdataStore is opened it can be used to send/receive OData requests/responses. An OnlineODataStore can be closed. In closed state the requests can not be executed.<br>
 There can be more OnlineODataStore opened by the application for the different or the same base URL. The only restriction is that if the technical cache is enabled then there can't be other store opened
 with technical cache for the same base URL. (If it happens an error will be the result.)
 <br>
 <h1>Tables of OnlineODataStore and Technical Cache states</h1> The following tables summarize what callbacks are called in different states considering the different request scenarios
 (single/batch, Read/CUD, useCache=true/false).<br>
 <h2>1. Table</h2> This table summarizes the callbacks in case of
 <ul>
 <li>a single read request with <code>useCache=true</code> or</li>
 <li>a batch including at least one read request with <code>useCache=true</code>.</li>
 </ul>
 <br>
 <table border="1">
 <tr>
 <th>Mode</th>
 <th>Store state</th>
 <th>Cache enabled and opened</th>
 <th>Cache enabled but closed</th>
 <th>Cache disabled</th>
 </tr>
 <tr>
 <td>Active</td>
 <td>Open</td>
 <td>cacheResponse / serverResponse</td>
 <td>serverResponse</td>
 <td>serverResponse</td>
 </tr>
 <tr>
 <td>Active</td>
 <td>Close</td>
 <td>failure</td>
 <td>failure</td>
 td>failure</td>
 </tr>
 <tr>
 <td>Passive</td>
 <td>Open</td>
 <td>cacheResponse</td>
 <td>failure</td>
 <td>N/A</td>
 </tr>
 <tr>
 <td>Passive</td>
 <td>Close</td>
 <td>failure</td>
 <td>failure</td>
 <td>N/A</td>
 </tr>
 </table>
 <h2>2. Table</h2> This table summarizes the callbacks in case of
 <ul>
 <li>a single CUD request or</li>
 <li>a single read request with <code>useCache=false</code> or</li>
 <li>a batch including only CUDs or read requests with <code>useCache=false</code>.</li>
 </ul>
 <br>
 <table border="1">
 <tr>
 <th>Mode</th>
 <th>Store state</th>
 <th>Cache enabled and opened</th>
 <th>Cache enabled but closed</th>
 <th>Cache disabled</th>
 </tr>
 <tr>
 <td>Active</td>
 <td>Open</td>
 <td>serverResponse</td>
 <td>serverResponse</td>
 <td>serverResponse</td>
 </tr>
 <tr>
 <td>Active</td>
 <td>Close</td>
 <td>failure</td>
 <td>failure</td>
 <td>failure</td>
 </tr>
 <tr>
 <td>Passive</td>
 <td>Open</td>
 <td>failure</td>
 <td>failure</td>
 <td>N/A</td>
 </tr>
 <tr>
 <td>Passive</td>
 <td>Close</td>
 <td>failure</td>
 <td>failure</td>
 <td>N/A</td>
 </tr>
 </table>
 <br>
 <h1>Examples</h1> <h2>Example of online store open</h2> This example shows how to open an <code>OnlineODataStore</code>. The example below uses the MAF Logon Manager configurator
 for the HTTP conversation Manager. Technical cache is enabled in this store. <br>
 The class must implement the following delegates: SODataOnlineStoreDelegate, SODataRequestDelegate, UsernamePasswordProviderProtocol
 <br>
 <pre>
 //called for credentials handling
 -(void)provideUsernamePasswordForAuthChallenge:(NSURLAuthenticationChallenge *)authChallenge completionBlock:(void (^)(NSURLCredential *, NSError *))completionBlock {
    NSURLCredential* credential = [NSURLCredential credentialWithUser:username password:password persistence:NSURLCredentialPersistenceForSession];
    completionBlock(credential, nil);
 }
 
 -(void)onlineStoreOpenFailed:(SODataOnlineStore *)store error:(NSError *)error {
    //Store open was not successful
 }
 
 -(void)onlineStoreOpenFinished:(SODataOnlineStore *)store {
    //Store open was successful
 }
 
 String baseUrl = "https://host:port/.../RMTSAMPLEFLIGHT/";
 
 //Store options
 SODataOnlineStoreOptions* storeOptions = [[SODataOnlineStoreOptions alloc] init];
 storeOptions.requestFormat = SODataDataFormatXML;
 //enabe cache - optional
 storeOptions.useCache = YES;
 storeOptions.cacheEncryptionKey = kSODataCacheEncrytionKey; //NSString* as encryption key
 storeOptions.useForceMetadataDownload = NO;
 //Create and configure HTTP Conversation Manager
 HttpConversationManager* manager = [[HttpConversationManager alloc] init];
 CommonAuthenticationConfigurator* commonConfig = [[CommonAuthenticationConfigurator alloc] init];
 [commonConfig addUsernamePasswordProvider:self];
 [commonConfig configureManager:manager];
 self.store= [[SODataOnlineStore alloc] initWithURL:[NSURL URLWithString:baseUrl] httpConversationManager:manager options:storeOptions];
 [self.store setOnlineStoreDelegate:self];
 NSError* error = nil;
 //Open store
 [self.store openStoreWithError:error];
 
 Example of schedule request
 This example shows how to schedule a request asynchronously.
 
 // create a read request
 SODataRequestParamSingleDefault* requestParam = [[SODataRequestParamSingleDefault alloc] initWithMode:SODataRequestModeRead resourcePath:@"TravelagencyCollection"];
 [self.store scheduleRequest:requestParam delegate:self];
 
 -(void)requestServerResponse:(id<SODataRequestExecution>)requestExecution {
    //response from server
    if ([[requestExecution response] conformsToProtocol:\@protocol(SODataResponseSingle)]) {
        id<SODataPayload> payload = [(SODataResponseSingleDefault*)[requestExecution response] payload];
    }
 }
 
 -(void)requestCacheResponse:(id<SODataRequestExecution>)requestExecution {
    //response from technical cache
    if ([[requestExecution response] conformsToProtocol:\@protocol(SODataResponseSingle)]) {
        id<SODataPayload> payload = [(SODataResponseSingleDefault*)[requestExecution response] payload];
    }
 }
 
 -(void)requestFailed:(id<SODataRequestExecution>)requestExecution error:(NSError *)error {
    //sheduled request failed
 }
 </pre>
 */
@interface SODataOnlineStore : NSObject <SODataStoreAsync, SODataStoreSync>

/**
 SOData Open Store Delegate. \sa SODataOnlineStoreDelegate
 */
@property (nonatomic, weak) id<SODataOnlineStoreDelegate> onlineStoreDelegate;

/**
 * Create a new store instance asynchronously with with given service url, requestHeaders and delegates
 * @param url of the service
 * @param httpConversationManager HttpConversationManager object which contains the logon data and runs the requests
 */
-(id) initWithURL:(NSURL*)url httpConversationManager:(HttpConversationManager*)httpConversationManager;

/**
 * Create a new store instance asynchronously with with given service url, requestHeaders and delegates
 * @param url of the service
 * @param httpConversationManager HttpConversationManager object which contains the logon data and runs the requests
 * @param options of the store
 */
-(id) initWithURL:(NSURL*)url httpConversationManager:(HttpConversationManager*)httpConversationManager options:(SODataOnlineStoreOptions*)options;

/**
 * Set passive mode for ODataOnline Cache
 * @param isPassive set to YES if you want to use the cache in passive mode
 * @param error Any returned error
 */
-(BOOL)setPassive:(BOOL)isPassive error:(NSError **)error;

/**
 * Check whether Caching is enabled
 */
-(BOOL)isCacheEnabled;

/**
 * Check whether the cache is in passive mode or in active
 */
-(BOOL)isPassive;

/**
 * Delete the content of the cache. Returns error in case of cache is closed.
 *
 * @param error Any returned error
 */
-(BOOL)resetCache:(NSError**)error;

/**
 * Delete the content of the cache for a specific URL in case of there's no opened store for that URL. Returns error if there's one.
 *
 * @param url the url of the cached data to delete
 * @param error Any returned error
 */
+(BOOL)resetCache:(NSURL*)url error:(NSError**)error;

/**
 * Opens the store with the URL passed during init
 *
 * @param error Any returned error
 */
-(BOOL)openStoreWithError:(NSError**)error;

/**
 * Closes the store. Returns error if the store is already closed.
 *
 * @param error Any returned error
 *
 */
-(BOOL)closeWithError:(NSError**)error;

/**
 * Closes the cache if it is enabled. Returns error if the store is already closed.
 *
 * @param error Any returned error
 *
 */
-(BOOL)closeCacheWithError:(NSError**)error;

/**
 * Reopens the cache if it is enabled. <br>
 * The online store uses data encryption data to persist the cache data. The application has to provide the encryption key to reopen the cache data.
 *
 * @param encryptionKey the encryption key used to encrypt the data
 * @param error Any returned error
 */
-(BOOL)reopenCacheWithKey:(NSString*)encryptionKey error:(NSError**)error;

/**
 * Indicates whether the store is opened or closed.
 */
-(BOOL)isOpen;

/**
 * Indicates whether the cache is opened or closed.
 */
-(BOOL)isCacheOpen;

#pragma mark - Block based APIs
// ------------------------------------------------------------------
// Completion-block based API alternatives, provided for convenience
// Completion blocks provide a more straightforward and succint syntax
// REMARK: You shall use either the delegate based APIs or the block based ones.
// NEVER MIX THE TWO FLAVORS!
// ------------------------------------------------------------------
/**
 *  Opens the online or offline store store
 *  Inspect the error once the completion block; nil means no issues
 *
 *  @remark Call this right after facade init to download and parse SVC and metadata
 */
-(void) openStore:(void (^)(id<SODataStoreAsync> store, NSError* error)) completionBlock;

/**
 * Schedule a request for execution
 * @param request the request for execution
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleRequest:(id<SODataRequestParam>)request
                                    completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Scheduling method for reading an Entity set.
 * @param resourcePath the resource path
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleReadEntitySet:(NSString*)resourcePath
                                             options:(NSDictionary*)options
                                          completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a query for execution
 * @param resourcePath the resource path
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleReadEntityWithResourcePath:(NSString*)resourcePath
                                                          options:(NSDictionary*)options
                                                       completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a query for execution
 * @param entity the entity to read
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleReadEntity:(id<SODataEntity>)entity
                                          options:(NSDictionary*)options
                                       completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule an insert for execution
 * @param entity the entity to create
 * @param collectionPath the collection path
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleCreateEntity:(id<SODataEntity>)entity
                                     collectionPath:(NSString*)collectionPath
                                            options:(NSDictionary*)options
                                         completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule an update for execution
 * @param entity the entity to update
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleUpdateEntity:(id<SODataEntity>)entity
                                            options:(NSDictionary*)options completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a patch for execution
 * @param entity the entity to patch
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) schedulePatchEntity:(id<SODataEntity>)entity
                                           options:(NSDictionary*)options
                                        completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a delete for execution
 * @param entity the entity to delete
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleDeleteEntity:(id<SODataEntity>)entity
                                            options:(NSDictionary*)options
                                         completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a delete for execution
 * @param url url of the entity
 * @param eTag ETag of the entity
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleDeleteEntity:(NSString*)resourcePath
                                               etag:(NSString*)etag options:(NSDictionary*)options
                                         completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a read for a list of links
 * @param resourcePath the path of the resource
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleReadLinkSet:(NSString*)resourcePath
                                           options:(NSDictionary*)options
                                        completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a read for a list of links
 * @param resourcePath the path of the resource
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleReadLink:(NSString*)resourcePath
                                        options:(NSDictionary*)options
                                     completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a read for a simple property
 * @param resourcePath the path of the resource
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleReadPropertyPrimitive:(NSString*)resourcePath
                                                     options:(NSDictionary*)options
                                                  completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a read for a complex property
 * @param resourcePath the path of the resource
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleReadPropertyComplex:(NSString*)resourcePath
                                                   options:(NSDictionary*)options
                                                completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a read for a raw property
 * @param resourcePath the path of the resource
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleReadPropertyRaw:(NSString*)resourcePath
                                               options:(NSDictionary*)options
                                            completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

/**
 * Schedule a FunctionImport
 * @param resourcePath the path of the resource with FunctionImport
 * @param options additional paramaters dictionary
 * @param completionBlock block called once execution completes
 */
- (id<SODataRequestExecution>) scheduleFunction:(NSString*)resourcePath
                                        options:(NSDictionary*)options
                                     completion:(void (^)(id<SODataRequestExecution> requestExecution, NSError *error))completionBlock;

@end
