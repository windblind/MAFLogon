//
//  MAFLogonUICustomizationContext.h
//  MAFLogonUING
//
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MAFLogonViewScreenType.h"

@interface MAFLogonUICustomizationContext : NSObject

/**
 Custom header View
*/
@property (retain) UIView* headerView;

/**
 Custom footer View
*/
@property (retain) UIView* footerView;

/**
 * Get the screens frame
 * Deprecated in 1.2 SP3
*/
@property (assign) CGRect viewFrame DEPRECATED_ATTRIBUTE;


/**
 Get the screen type
 */
@property (assign) MAFLogonViewScreenType screenType;

@end
