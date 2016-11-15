//
//  MAFTreeViewItemDelegate.h
//  MAFTreeView
//
//  Created by Foldvari, Robert on 2012.03.21..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MAFTreeItem.h"

@class MAFTreeViewController;

/**
 This protocol contains delegate methods to notify registered class about events that were triggered by user.
 */
@protocol MAFTreeViewItemDelegate <NSObject>

/**
 Delegate methos to notify implementing class that the user selected a Leaf Item in treeview.
 @param controller The viewcontroller of the tree
 @param leafItem The leaf item item that was selected
 */
- (void) treeViewController:(MAFTreeViewController*)controller didSelectLeafItem:(id<MAFTreeItem>)leafItem;

@end
