//
//  UsernamePasswordResponsePlugin.h
//  HttpConvAuthFlows
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ChallengeFilterProtocol.h"
#import "UsernamePasswordProviderProtocol.h"
#import "BaseChallengeFilter.h"
#import <UIKit/UIKit.h>

/**
 ChallengeFilter which handles basic authentication challenge.
 */
@interface UsernamePasswordChallengeFilter : BaseChallengeFilter <ChallengeFilterProtocol>

/**
 Contains UsernamePasswordProviderProtocol implementations, which will be called to handle the authentication challenge.
*/
@property (strong) NSArray* providers;

/**
 Parent UIViewController.
*/
@property (weak) UIViewController* parentView;

@end
