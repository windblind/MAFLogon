//
//  NSMutableURLRequest+HttpConversation.h
//  HttpConversation
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 ChangeSet definition
*/
@interface ChangeSet : NSObject

@property (strong) NSMutableArray* changeRequests;

@end

/**
 Category extension for NSMutableURLRequest to support batch request sending
*/
@interface NSMutableURLRequest (HttpConversation)

/**
 Contains batch requests, which are NSMutableURLRequest instances
*/
@property (strong) NSMutableArray* batchElements;

/**
 Generates batch request content, call before sending a batch request
*/
-(void) prepareBatchRequest;

@end
