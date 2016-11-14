//
//  MAFTreeViewActionDelegate.h
//  MAFTreeView
//
//  Created by Foldvari, Robert on 2012.03.28..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MAFTreeViewAction.h"

@class MAFTreeViewController;

/**
 This protocol defines delegates that can be used to notify the implementing class that curtain action occured on 
 the Tree View.
 */
@protocol MAFTreeViewActionDelegate

/**
 This delegate method notifyes the implementing class that the user selected one of the defined actions
 @param controller The viewcontroller that displayed the action bar.
 @param action The action that was selected by the user.
 @param items The item array that contains the selected items.
 */
- (void) treeViewController:(MAFTreeViewController*)controller didSelectAction:(MAFTreeViewAction*)action forItems:(NSArray*)items; 

@end
