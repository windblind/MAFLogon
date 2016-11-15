//
//  BaseResponsePlugin.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HttpConversationManager;

/**
 Base ResponseFilter implementation, defines properties which are used in ResponseFilters.
 */
@interface BaseResponseFilter : NSObject

/**
 NSURLResponse instance
 */
@property (weak) NSURLResponse* urlResponse;

/**
 NSData instance
 */
@property (weak) NSData* responseData;

/**
 HttpConversationManager instance
*/
@property (strong) HttpConversationManager* conversationManager;

/**
 CompletionBlock
 */
@property (copy) void (^completionBlock)(BOOL);

@end
