//
//  MAFUIGroupDescriptor.h
//
//  Copyright (c) 2012 SAP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAFLogonDictionaryHelper.h"
#import "MAFLogonUIContextConstants.h"

@class MAFLogonMutableArrayHelper;

/**
 On the UI there are fields which belongs together logically.
 There can be groups which can be hidden and should be presented or hidden by a user interaction.
 This object provides information about the group.
 */
@interface MAFLogonUIGroupDescriptor : MAFLogonDictionaryHelper

/**
 Uniquely identifies the data field in the OperationContext
 */
@property (copy) NSString *operationContextKeyName;

/**
 The group can be hidden
 */
@property (assign) BOOL isHideable;
/**
 The switch is enabled which performs the hide of the group
 */
@property (assign) BOOL isHiddenByDefault;
/**
 Array which contains all the fields (MAFLogonUIFieldDescriptor) should be presented in the group
 */
@property (copy) MAFLogonMutableArrayHelper *fieldDescriptors;

/**
 Array which contains all the fields (MAFLogonUIFieldDescriptor) should be presented in the group when the default fieldDescriptor is hidden
 */
@property (copy) MAFLogonMutableArrayHelper *fieldDescriptorsWhenHidden;


/**
 Label for the switch
 */
@property (copy) NSString *groupLabel;

/**
 LabelKey for the switch; uniquely identifies the label, can be used for localization purposes
 */
@property (copy) NSString *groupLabelKey;

/**
 Label for the section header title
 */
@property (copy) NSString *groupTitleLabel;

/**
 LabelKey for the section header title; uniquely identifies the label, can be used for localization purposes
 */
@property (copy) NSString *groupTitleLabelKey;


@end
