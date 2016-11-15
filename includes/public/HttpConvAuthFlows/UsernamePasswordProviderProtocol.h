//
//  UsernamePasswordProviderProtocol.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Defines UsernamePasswordProvider interface. <br>
 Implementations will be called when request execution requires basic authentication.
 */
@protocol UsernamePasswordProviderProtocol <NSObject>

/**
 Called when basic authentication challenge occurs during request execution.
 @param authChallenge : NSURLAuthenticationChallenge
 @param completionBlock : call the completionBlock when provider finishes its tasks. Return NSURLCredential instance, if challenge is handled, or return an NSError instance, if not. <br>
 */
-(void) provideUsernamePasswordForAuthChallenge:(NSURLAuthenticationChallenge*)authChallenge completionBlock:(void (^)(NSURLCredential*, NSError*))completionBlock;

@end
