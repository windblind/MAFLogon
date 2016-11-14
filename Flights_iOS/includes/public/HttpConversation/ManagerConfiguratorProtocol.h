//
//  ManagerConfigurator.h
//  HttpConversation
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HttpConversationManager.h"
#import <UIKit/UIKit.h>

/**
 Defines ManagerConfigurator interface
*/
@protocol ManagerConfiguratorProtocol <NSObject>

/**
 Holds reference to UIViewController instance. Filters can display additional views on top of it.
*/
@property (weak) UIViewController* parentView;

/**
 Call this method to configure @see HttpConversationManager instance. <br>
 ManagerConfigurator instances can add RequestFilterProtocol, ResponseFilterProtocol and ChallengeFilterProtocol implementations.
 @param manager: HttpConversationManager instance to be configured
*/
-(void) configureManager:(HttpConversationManager*)manager;

@end
