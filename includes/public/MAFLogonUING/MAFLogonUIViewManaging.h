//
//  MAFLogonUIViewManaging.h
//
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MAFLogonUIViewManagingDelegate.h"

#import "MAFLogonContext.h"
#import "MAFLogonCoreState.h"

/**
 Protocol to describe view manager behavior
 */
@protocol MAFLogonUIViewManaging

/**
 The component which will be notified when the user starts an operation by pressing a button.
 */
@property (nonatomic, retain) id<MAFLogonUIViewManagingDelegate> viewManagingDelegate;

/**
 Returns the root UIViewController which can be used for present own screens
 @param rootUIViewController : (UIViewController)
 **/
-(UIViewController*) rootUIViewController;

/**
 The method should close the whole UI. The control sould be gave back to the application.
 */
-(void) closeUI;

- (void) showActivityIndicatorWithText:(NSString*)anIndicatorText;
- (void) closeActivityIndicator;

- (void) showSplashView;

- (void) showRegistrationViewWithLogonContext:(MAFLogonContext*)logonContext state:(MAFLogonCoreState*)logonState;

- (void) showPasscodeCreationViewWithLogonContext:(MAFLogonContext*)logonContext;

- (void) showUnlockView;

- (void) showPasscodeChangeView:(BOOL)isDefaultPasswordAllowed isDefaultPasswordUsed:(BOOL)isDefaultPasswordUsed isDefaultPasswordUsedByDefault:(BOOL)isDefaultPasswordUsedByDefault;

- (void) showRegistrationInfoViewWithLogonContext:(MAFLogonContext*)logonContext;

- (void) showBackendPasswordChangeViewWithLogonContext:(MAFLogonContext*)logonContext state:(MAFLogonCoreState*)logonState;

- (void) operationRespondsWithError:(NSError*)anError;

//MCIM related UI's

- (void) showSetSSOPasscodeView;
- (void) showChangeSSOPasscodeView;

- (void) showEnterCredentialsView:(MAFLogonContext*)context usernameChangeable:(BOOL)usernameChangeable;

- (void) showAfariaCredentialsView;

-(void)showMobilePlaceControllerViewWithLogonContext:(MAFLogonContext*)logonContext completionBlock:(void (^)(MAFLogonContext*))completionBlock;

@end
