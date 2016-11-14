//
//  NSURLResponse+HttpConversation.h
//  HttpConversation
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Category extension on NSHTTPURLResponse to support batch response handling
*/
@interface NSHTTPURLResponse (HttpConversation)

/**
 Contains the received data after request execution
*/
@property (strong) NSData* responseData;

/**
 Contains batch response objects
*/
-(NSArray*) responses;

@end
