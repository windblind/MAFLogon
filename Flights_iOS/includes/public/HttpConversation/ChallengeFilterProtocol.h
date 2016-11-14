//
//  ChallengePluginProtocol.h
//  HttpConversation
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HttpConversationManager;

/**
 Defines the ChallengeFilter interface. <br>
 ChallengeFilter is an object, which will be called when the request execution requires some authentication to be successful.
 */
@protocol ChallengeFilterProtocol <NSObject>

/**
 Delegate method called when authentication challenge occurs.
 @param challenge: NSURLAuthenticationChallenge
 @param conversationManager: copy of HttpConversationManager instance, can be used for starting additional requests
 @param completionBlock: call the block when the filter finished its job. <br> Return YES, and a NSURLCredential object, if the challenge is handled, or return NO and nil, if the challenge is not handled. If return YES and NSURLCredential object is nil, it will be handled as no credential provided.
 */
-(void) handleChallenge:(NSURLAuthenticationChallenge*)challenge conversationManager:(HttpConversationManager*)conversationManager completionBlock:(void (^)(BOOL useCredential, NSURLCredential* credential))completionBlock;


@end
