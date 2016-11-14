//
//  MAFTreeViewController.h
//  MAFTreeView
//
//  Created by Foldvari, Robert on 2012.03.21..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFTreeViewItemDelegate.h"
#import "MAFTreeItem.h"
#import "MAFTreeContentProvider.h"
#import "MAFTreeViewCellDelegate.h"
#import "MAFUITableView.h"

/**
 This View Controller is responsible to manage, present and store data of the Tree View.
 */
@interface MAFTreeViewController : UIViewController <UITableViewDataSource, UITableViewDelegate> {
    id<MAFTreeItem>             m_CurrentNode;
    id<MAFTreeContentProvider>  m_ContentProvider;
    NSArray*                    m_ChildrenItems;
    MAFUITableView*             m_TableView;
    id<MAFTreeViewItemDelegate> m_ItemDelegate;
    id<MAFTreeViewCellDelegate> m_CellDelegate;
    BOOL                        displayImage;
    CGRect                      m_ViewFrame;
}

/**
 The delegate of the Tree View Item that will be called upon Child related event.
 */
@property (nonatomic, retain) id<MAFTreeViewItemDelegate> itemDelegate;

/**
 The delegate of the Tree View cell badge that will be called to calculate badge text.
 */
@property (nonatomic, retain) id<MAFTreeViewCellDelegate> cellDelegate;

/**
 The Table View ojbect that will present the Tree View.
 */
@property (nonatomic, retain) MAFUITableView* treeTableView;

/**
 General Tree View data container objec. Represents all different Tree View ojbects that will be
 handled by the component at runtime.
 */
@property (nonatomic, retain) id<MAFTreeContentProvider> contentProvider;

/**
 This is the data object to store currently visible Node.
 */
@property (nonatomic, retain) id<MAFTreeItem> currentNode;

/**
 Array of children of the currently active/visible TreeView ojbect
 */
@property (nonatomic, retain) NSArray* childrenItems;

/**
 Should display the icon in the beginning of the row
 */
@property (nonatomic, assign) BOOL displayImage;

/**
 Frame size for the TableView of the tree
 */
@property (nonatomic, assign) CGRect viewFrame;

/**
 Update the tree data and reload the table
 */
-(void) reloadTable;

@end


