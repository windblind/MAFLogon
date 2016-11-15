//
//  OAuthConfigProviderProtocol.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Defines OAuth2ConfigProvider interface. <br>
 Implementations will be called when request execution requires SAML authentication.
 */
@protocol OAuth2ConfigProviderProtocol <NSObject>

/**
 Called when OAuth authentication is needed for request execution.
 @param url : url which secured with OAuth
 @param completionBlock : call the completionBlock when provider finishes its tasks. Return OAuth token if authentication already take place. <br>
 */
-(void) provideOAuth2TokenForURL:(NSURL*)url completionBlock:(void (^)(NSString* token))completionBlock;

/**
 Called when OAuth authentication is needed for request execution.
 @param url : url which secured with OAuth
 @param completionBlock : call the completionBlock when provider finishes its tasks. All the parameters except <i>clientSecret</i> are mandatory. <br>
 */
-(void) provideOAuth2ConfigurationForURL:(NSURL*)url completionBlock:(void (^)(NSURL* authorizationEndpoint, NSURL* tokenEndpoint,NSString* scope, NSString* clientID, NSString* clientSecret))completionBlock;

/**
 Called when a request with OAuth2 authentication finished. <br>
 Implementation should decide if the received response is valid or not. If it is invalid, the provided token shall be deleted.
 @param response: response received from the server
 @param token: token sent with the request
 @param completionBlock: call the completionBlock when provider finishes its tasks. <br>
        If cancelRequest is YES, the request will be canceled, and the response will be returned. <br>
        If restartOAuth2Flow is Yes, the request will be restarted and OAuth2 authentication will took place again. <br>
        If response is acceptable, set both parameter to NO.<br>
        Important: if cancelRequest is YES, the restartOAuth2Flow parameter is omitted.
*/
-(void) isAcceptedResponse:(NSURLResponse*)response forProvidedToken:(NSString*)token completionBlock:(void (^)(BOOL cancelRequest, BOOL restartOAuth2Flow))completionBlock;

@end
