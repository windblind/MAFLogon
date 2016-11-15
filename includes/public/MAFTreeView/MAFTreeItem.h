//
//  MAFTreeItem.h
//  MAFTreeView
//
//  Created by Foldvari, Robert on 2012.03.20..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 The object describer of the item in the tree
 */
@protocol MAFTreeItem 

/**
 The identifier of the item.
 */ 
@property (nonatomic, retain, readonly) NSString* id;

/**
 The label of the item. It will be appears in summary part of the cell.
 */
@property (nonatomic, retain) NSString* label;

/**
 The icon of the item. It will be appears in the left side of the cell.
 */
@property (nonatomic, retain) UIImage* image;

/**
 Return YES if the current item has any children. NO otherwise.
 */ 
@property (nonatomic, assign) BOOL node;

@end

/**
 The template of the MAFTreeItem. It describes the parent/children model.
 */
@interface MAFTreeItemDefault : NSObject <MAFTreeItem>

/**
 The parent item object of the current node.
 */ 
@property (nonatomic, assign) MAFTreeItemDefault* parent;

/**
 The array of the children of the current node.
 */ 
@property (nonatomic, retain) NSMutableArray* children;

/**
 Initialize a MAFTreeItemDefault instance with the given id.
 @param id_in ID for new initialized item
 */ 
- (id) initWithId:(NSString*)id_in;

@end
