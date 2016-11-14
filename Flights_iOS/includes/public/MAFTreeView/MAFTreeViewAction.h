//
//  MAFTreeViewAction.h
//  MAFTreeView
//
//  Created by Peter Nagy on 2012.03.27..
//  Copyright (c) 2012 SAP. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Different action can be added to every level of the tree. (e.g.: delete, modify, send)
 */
@interface MAFTreeViewAction : NSObject 

/**
 The id of the current action.
 */
@property (nonatomic, retain) NSString* actionID;

/**
 The label of the current action. That will be appears on the button.
 */
@property (nonatomic, retain) NSString* actionLabel;

/**
 Initialize an action with the given id and label.
 @param actionID The id of the new action.
 @param actionLabel The name of the new action.
 @returns MAFTreeContent instance.
 */
- (MAFTreeViewAction*) initWithActionID:(NSString*)actionID andLabel:(NSString*)actionLabel;

@end
