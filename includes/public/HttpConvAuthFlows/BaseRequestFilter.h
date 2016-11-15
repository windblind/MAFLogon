//
//  BaseRequestPlugin.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RequestFilterProtocol.h"

@class HttpConversationManager;

/**
 Base RequestFilter implementation, defines properties which are used in RequestFilters.
*/
@interface BaseRequestFilter : NSObject

/**
 Original NSMutableURLRequest instance
*/
@property (weak) NSMutableURLRequest* mutableRequest;

/**
 HttpConversationManager instance
*/
@property (strong) HttpConversationManager* conversationManager;

/**
 CompletionBlock
*/
@property (copy) void (^completionBlock)();

@end
