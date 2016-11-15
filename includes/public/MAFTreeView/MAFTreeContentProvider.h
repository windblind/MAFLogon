//
//  MAFTreeContentProvider.h
//  MAFTreeView
//
//  Created by Foldvari, Robert on 2012.03.28..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MAFTreeItem.h"

/**
 Protocol to reach the node items
 */
@protocol MAFTreeContentProvider

/**
 Getter method to get the root element.
 @returns MAFTreeItem element.
 */
- (id<MAFTreeItem>) getRootNode;

/**
 Collect the children items of a specified node.
 @param node The node of which children are needed.
 @returns An array with the children elements.
 */
- (NSArray*) getChildrenOfNode:(id<MAFTreeItem>)node;

/**
 Collect the children leafs of a specified node.
 @param node The node of which leafs are needed.
 @returns An array with the leaf elements.
 */
- (NSArray*) getChildrenLeafOfNode:(id<MAFTreeItem>)node;

/**
 Count the children elements of a specified node recursively for every subnode.
 @param node The node from where the count should start.
 @returns An array with the leaf elements.
 */
- (int) countLeafsRecursively:(id<MAFTreeItem>)node;

/**
 Decide that is it necessary to indent all of the labels in the custom cell. It occurs if there are minimum one element with icon.
 @param node The node of which children should check.
 @param onlyLeaf Bool value to decide should display only the leaf element of the level.
 @returns YES if at least one element has an image. NO otherwise.
 */
- (BOOL) shouldDisplayImage:(id<MAFTreeItem>)node onlyLeaf:(BOOL)onlyLeaf;

@end
