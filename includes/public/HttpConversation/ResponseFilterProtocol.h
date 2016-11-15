//
//  ResponsePluginProtocol.h
//  HttpConversation
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HttpConversationManager;

/**
 Defines the ResponseFilter interface. <br>
 ResponseFilter is an object, which will be called when the request is finished, and it can modify the <i>urlResponse</i>
 and the <i>responseData</i> instances before the request executor gets the result.
*/
@protocol ResponseFilterProtocol <NSObject>

/**
 Delegate method called after the request is executed.
 @param urlResponse: contains the overview result of the finished request
 @param responseData: contains the data returned for the finished request
 @param conversationManager: copy of HttpConversationManager instance, can be used for starting additional requests
 @param completionBlock: call the block when the filter finished its job. <br>Return YES, if the original request needs to be restarted.
                            This can happen if the ResponseFilter started a new request for some additional authentication, which is needed for the original request, like SAML.
*/
-(void) processResponse:(NSURLResponse*)urlResponse responseData:(NSData*)responseData conversationManager:(HttpConversationManager*)conversationManager completionBlock:(void (^)(BOOL shouldRestartRequest))completionBlock;

@end
