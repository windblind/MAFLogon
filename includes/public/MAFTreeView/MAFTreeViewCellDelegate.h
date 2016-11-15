//
//  MAFTreeViewCellDelegate.h
//  MAFTreeView
//
//  Created by Kiri, Gyula on 2012.05.04..
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Delegate to modify the badge view label
 */
@protocol MAFTreeViewCellDelegate <NSObject>

/**
 Define the badge value of the custom tree view cell.
 @param nodeItem The id of the cell where the badge appears.
 */
- (NSString*) calculateValueForBadgeView:(id<MAFTreeItem>)nodeItem;

@end
