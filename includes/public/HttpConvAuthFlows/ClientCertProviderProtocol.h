//
//  ClientCertAuthProviderProtocol.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Defines ClientCertProvider interface. <br>
 Implementations will be called when request execution requires client certificate authentication.
*/
@protocol ClientCertProviderProtocol <NSObject>

/**
 Called when client certificate authentication challenge occurs during request execution.
 @param authChallenge : NSURLAuthenticationChallenge
 @param completionBlock : call the completionBlock when provider finishes its tasks. Return NSURLCredential instance, if challenge is handled, or return an NSError instance, if not. <br>
*/
-(void) provideClientCertForAuthChallenge:(NSURLAuthenticationChallenge*)authChallenge completionBlock:(void (^)(NSURLCredential*, NSError*))completionBlock;

@end
