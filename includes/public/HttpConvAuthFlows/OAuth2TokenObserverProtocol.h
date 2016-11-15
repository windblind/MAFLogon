//
//  OAuthTokenObserverProtocol.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HttpConversationObserverProtocol.h"

/**
 Defines OAuth2TokenObserver interface. <br>
 Implementations will be called when OAuth authentication flow is completed, and token is present.
*/
@protocol OAuth2TokenObserverProtocol <HttpConversationObserverProtocol>

/**
 Called when OAuth2 token is ready for usage.
 @param token: OAuth2 token
*/
-(void) observeOAuth2Token:(NSString*)token;

@end
