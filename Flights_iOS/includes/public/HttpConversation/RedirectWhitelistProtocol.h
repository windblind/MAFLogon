//
//  RedirectWhitelistProtocol.h
//  HttpConversation
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RedirectWhitelistProtocol <NSObject>

/**
 Invoked when redirect is going to happen to a new URL
 @param aURL The URL that needs to be validated.
 @return YES, if the URL is valid, NO, if not
 */
-(BOOL) isValidUrl:(NSURL*)anURL;


@end
