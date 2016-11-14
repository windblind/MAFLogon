//
//  MAFTreeController.h
//  MAFTreeView
//
//  Created by Foldvari, Robert on 2012.03.26..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFTreeViewController.h"

/**
 Navigation controller to navigate between the levels of the tree
 */
@interface MAFTreeController : UINavigationController

/**
 The ViewController which handle the browse mode of the Treeview.
 */
@property (nonatomic, retain) MAFTreeViewController* contentViewController;

/**
 Initialize the MAFTreeController with the given style.
 @param style The style that should use the TableView (plain, grouped, etc.).
 @returns MAFTreeController instance.
 */
- (id)initWithStyle:(UITableViewStyle)style;

@end
