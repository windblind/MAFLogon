//
//  MAFTreeContent.h
//  MAFTreeView
//
//  Created by Foldvari, Robert on 2012.03.20..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAFTreeItem.h"
#import "MAFTreeContentProvider.h"

#define kMAFASTreeContentRoot             @"MAFTREECONTENTROOT"

/**
 The manager class of the tree data
 */
@interface MAFTreeContent : NSObject <MAFTreeContentProvider>

/**
 The dictictionary that contains the tree items
 */
@property (nonatomic, retain, readonly) NSMutableDictionary* content;

/**
 The root element of the tree
 */
@property (nonatomic, retain, readonly) MAFTreeItemDefault* root;

/**
 Initialize the content tree with the name of the root element.
 @param label_in The name of the root element.
 @returns MAFTreeContent instance.
 */
- (id) initWithRootLabel:(NSString*)label_in;

/**
 Create and add an element to a leaf in the hierarchy.
 @param parent_in The parent element to which the created item will be added.
 @param id_in The id of the new element.
 @param label_in The name of the new element.
 @returns The created MAFTreeItemDefault leaf.
 */
- (MAFTreeItemDefault*) addChildItemToParent:(MAFTreeItemDefault*)parent_in withId:(NSString*)id_in andLabel:(NSString*)label_in;

/**
 Create and add an element to a leaf in the hierarchy.
 @param parent_in The parent element to which the created item will be added.
 @param id_in The id of the new element.
 @param label_in The name of the new element.
 @param image_in The icon of the new element.
 @returns The created MAFTreeItemDefault leaf.
 */
- (MAFTreeItemDefault*) addChildItemToParent:(MAFTreeItemDefault*)parent_in withId:(NSString*)id_in andLabel:(NSString*)label_in andImage:(UIImage*)image_in;

/**
 Remove an element from a node in the hierarchy.
 @param parent_in The parent element to which the created item will be added.
 @param items The array of the elements.
 */
- (void) removeChildrenFromParent:(MAFTreeItemDefault*)parent_in items:(NSArray*)items;

@end
