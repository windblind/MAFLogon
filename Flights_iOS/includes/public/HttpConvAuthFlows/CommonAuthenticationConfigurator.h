//
//  CommonAuthenticationConfigurator.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ManagerConfiguratorProtocol.h"
#import "UsernamePasswordProviderProtocol.h"
#import "ClientCertProviderProtocol.h"
#import "SAML2ConfigProviderProtocol.h"
#import "OAuth2ConfigProviderProtocol.h"

/**
 Configurator which contains the common authentication methods: basic, client certificate, OAuth and SAML.
*/
@interface CommonAuthenticationConfigurator : NSObject <ManagerConfiguratorProtocol>

/**
 Disables registration of custom NSHTTPURLProtocol implementation. <br>
 By default it is set to NO.
 @param disable: disable registration
 */
+(void) disableNSHTTPURLProtocolReplacement:(BOOL)disable;

/**
 Returns if registration of NSHTTPURLProtocol is enabled or not.
 */
+(BOOL) isNSHTTPURLProtocolReplacementEnabled;

/**
 Adds a UsernamePasswordProtocol implementation.
 @param usernamePasswordProvider
*/
-(void) addUsernamePasswordProvider:(id<UsernamePasswordProviderProtocol>) usernamePasswordProvider;

/**
 Returns all the added UsernamePasswordProtocol implementations
 @return UsernamePasswordProtocol implementations
*/
-(NSArray*) allUsernamePasswordProvider;

/**
 Adds a ClientCertProviderProtocol implementation.
 @param clientCertProvider
 */
-(void) addClientCertProvider:(id<ClientCertProviderProtocol>) clientCertProvider;

/**
 Returns all the added ClientCertProviderProtocol implementations
 @return ClientCertProviderProtocol implementations
 */
-(NSArray*) allClientCertProvider;

/**
 Adds a SAMLConfigProviderProtocol implementation.
 @param samlConfigProvider
 */
-(void) addSAML2ConfigProvider:(id<SAML2ConfigProviderProtocol>) samlConfigProvider;

/**
 Returns all the added SAMLConfigProviderProtocol implementations
 @return SAMLConfigProviderProtocol implementations
 */
-(NSArray*) allSAML2ConfigProvider;

/**
 Adds a OAuthConfigProviderProtocol implementation.
 @param oauthConfigProvider
 */
-(void) addOAuth2ConfigProvider:(id<OAuth2ConfigProviderProtocol>) oauth2ConfigProvider;

/**
 Returns all the added OAuthConfigProviderProtocol implementations
 @return OAuthConfigProviderProtocol implementations
 */
-(NSArray*) allOAuth2ConfigProvider;


@end
