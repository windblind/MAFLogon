//
//  HttpConversationManager.h
//  HttpConversation
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RequestFilterProtocol.h"
#import "ResponseFilterProtocol.h"
#import "ChallengeFilterProtocol.h"
#import "HttpConversationObserverProtocol.h"
#import "RedirectWhitelistProtocol.h"

/**
 Request execution manager class, supports request, response and challenge filtering.
*/
@interface HttpConversationManager : NSObject

@property (weak) id<RedirectWhitelistProtocol> redirectWhitelistImplementation;

/**
 Contains redirect history.
**/
@property (strong) NSMutableArray* redirectHistory;

/**
 Add RequestFilterProtocol implementation to the HttpConversationManager instance. <br>
 RequestFilters will be called before the request is executed.
 @param requestFilter: RequestFilterProtocol implementation
*/
-(void) addRequestFilter:(id<RequestFilterProtocol>)requestFilter;

/**
 Returns all the RequestFilterProtocol implementation added to the HttpConversationManager instance.
*/
-(NSArray*) allRequestFilters;

/**
 Add ResponseFilterProtocol implementation to the HttpConversationManager instance. <br>
 ResponseFilters will be called after the request is executed.
 @param responseFilter: ResponseFilterProtocol implementation
 */
-(void) addResponseFilter:(id<ResponseFilterProtocol>)responseFilter;

/**
 Returns all the ResponseFilterProtocol implementation added to the HttpConversationManager instance.
 */
-(NSArray*) allResponseFilters;

/**
 Add ChallengeFilterProtocol implementation to the HttpConversationManager instance.
 ChallengeFilters will be called when an authentication challenge occurs during request execution.
 @param challengeFilter: ChallengeFilterProtocol implementation
 */
-(void) addChallengeFilter:(id<ChallengeFilterProtocol>)challengeFilter;

/**
 Returns all the ChallengeFilterProtocol implementation added to the HttpConversationManager instance.
 */
-(NSArray*) allChallengeFilters;

/**
 Add HttpConversationObserverProtocol implementations to the HttpConversationManager instance.
 For more information, check HttpConversationObserverProtocol
*/
-(void) addObserver:(id<HttpConversationObserverProtocol>) observer;

/**
 Returns all the observers added to the HttpConversationManager instance.
 */
-(NSArray*) allObservers;

/**
 Execute NSMutableURLRequest instance using HttpConversationManager
 @param urlRequest: NSMutableURLRequest instance
 @param completionHandler: will be called when the request is finished. Contains the response, the received data, and in case of any error the root cause.
*/
-(void) executeRequest:(NSMutableURLRequest*)urlRequest completionHandler:(void (^)(NSData* data, NSURLResponse* response, NSError* error))completionHandler;

/**
 *  Executes an upload request that has a valid body stream
 *
 *  @param urlRequest        request to be executed; the request shall have a valid HTTPBodyStream set
 *  @param completionHandler called upon completing the request; if the upload fails, the error parameter will include information about the issue (see NSURLErrorDomain)
 */
-(void) executeStreamedUploadRequest:(NSMutableURLRequest*)urlRequest completionHandler:(void (^)(NSURLResponse* response, NSError* error))completionHandler;

/**
 *  Executes a download request
 *
 *  @param urlRequest        request to be executed
 *  @param completionHandler called upon completing the request; if the download was succesful, the downloaded data can be accessed through the data stream. Upon failure the error parameter will include information about the issue (see NSURLErrorDomain)
 */
-(void) executeStreamedDownloadRequest:(NSMutableURLRequest*)urlRequest completionHandler:(void (^)(NSInputStream* payloadStream, NSURLResponse* response, NSError* error))completionHandler;

@end
