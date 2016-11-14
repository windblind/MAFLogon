//
//  SAMLConfigProviderProtocol.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Defines SAML2ConfigProvider interface. <br>
 Implementations will be called when request execution requires SAML authentication.
 */
@protocol SAML2ConfigProviderProtocol <NSObject>

/**
 Called when SAML2 authentication is needed for request execution.
 @param url : url which secured with SAML
 @param completionBlock : call the completionBlock when provider finishes its tasks. All the parameters are mandatory. <br>
 */
-(void) provideSAML2ConfigurationForURL:(NSURL*)url completionBlock:(void (^)(NSString* responseHeader, NSString* finishEndPoint, NSString* finishParameters))completionBlock;


@end
