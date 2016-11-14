//
//  MAFTreeViewFactory.h
//  MAFTreeView
//
//  Created by Foldvari, Robert on 2012.03.21..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MAFTreeController.h"
#import "MAFTreeViewItemDelegate.h"
#import "MAFTreeViewActionDelegate.h"
#import "MAFTreeContentProvider.h"

/**
 Creates a TreeController handling the content and calling back the delegate
 @delegate this delegate shall implement the protocol MAFTreeViewItemDelegate
 */
MAFTreeController* mafCreateTreeController(id<MAFTreeContentProvider> contentProvider, id<MAFTreeViewItemDelegate> itemDelegate, id<MAFTreeViewCellDelegate> cellDelegate, CGRect frame);

/**
 Creates a TreeController handling the content, the actions and calling back the delegates
 Maximum three actions are allowed.
 @itemDelegate this delegate shall implement the protocol MAFTreeViewItemDelegate 
 @actionDelegate this delegate shall implement the protocol MAFTreeViewActionDelegate
 */
MAFTreeController* mafCreateTreeControllerWithActions(id<MAFTreeContentProvider> contentProvider, NSArray* actions, id<MAFTreeViewItemDelegate> itemDelegate, id<MAFTreeViewCellDelegate> cellDelegate, id<MAFTreeViewActionDelegate> actionDelegate, CGRect frame);