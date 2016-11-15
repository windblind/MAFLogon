//
//  HttpConversationPluginDelegate.h
//  HttpConversation
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HttpConversationManager;

/**
 Defines the RequestFilter interface. <br>
 RequestFilter is an object, which will be called before the request is triggered, and it can modify the <i>mutableRequest</i> instance before execution, e.g. adding request header, set POST body, etc.
*/
@protocol RequestFilterProtocol <NSObject>

/**
 Delegate method called before executing the request.
 @param mutableRequest: the request instance which will be executed
 @param conversationManager: copy of HttpConversationManager instance, can be used for starting additional requests
 @param completionBlock: call the block when the filter finished the modification of <i>mutableRequest</i> object
*/
-(void) prepareRequest:(NSMutableURLRequest*)mutableRequest conversationManager:(HttpConversationManager*)conversationManager completionBlock:(void (^)())completionBlock;

@end
