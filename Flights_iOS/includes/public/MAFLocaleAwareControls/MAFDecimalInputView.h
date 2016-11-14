//
//  MAFDecimalInputTextField.h
//  MAFTestProject
//
//  Created by Muehlbauer, Jan (external) on 2/24/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>


@class MAFDecimalInputView;


/**
 
 @brief Delegate holding change event callbacks.
 
 This protocol can be used by external observers of the MAFDecimalInputView to 
 be informed about state changes like didBeginEdit, didEdit, didEndEdit.
 
 @author Jan Muehlbauer (external)
 
 */
@protocol MAFDecimalInputTextFieldDelegate <NSObject>

@optional

/**
 Callback method called upon didBeginEditing event in input view.
 */
- (void) decimalInputFieldDidBeginEditing:(MAFDecimalInputView*)sender;

/**
 Callback method called upon didEdit event in input view.
 */
- (void) decimalInputFieldDidEdit:(MAFDecimalInputView*)sender;

/**
 Callback method called upon didEndEditing event in input view.
 */
- (void) decimalInputFieldDidEndEditing:(MAFDecimalInputView*)sender;

@end

/**
 @class MAFDecimalInputView
 
 @brief Input view for decimal numbers.
 
 The MAFDecimalInputTextField class is a control which
 allows the user to enter decimal numbers. The control
 ensures that only proper decimal numbers are entered
 and the number is also formatted (i.e. separators are
 added at proper places) according to the current Locale.
 
 @author Jan Muehlbauer (external)
*/
@interface MAFDecimalInputView : UIView <UITextFieldDelegate>
{
	id <MAFDecimalInputTextFieldDelegate> delegate;
	
	UITextField* txtInput;
	
	NSInteger maximumIntegerDigits;
	NSInteger minimumFractionDigits;
	NSInteger maximumFractionDigits;
	bool numberHasSign;
	bool showThousandSeparator;
}

/// delegate for handling value changes within control
@property (nonatomic, assign) id <MAFDecimalInputTextFieldDelegate> delegate;

/// property holding the maximum number of integer digits 
@property (nonatomic, assign) NSInteger maximumIntegerDigits;

/// property holding the minimum number of fractional digits (decimal places)
@property (nonatomic, assign, setter=setMinimumFractionDigits:) NSInteger minimumFractionDigits;

/// property holding the maximum number of fractional digits (decimal places) 
@property (nonatomic, assign, setter=setMaximumFractionDigits:) NSInteger maximumFractionDigits;

/// property holding flag whether decimal number should be signed
@property (nonatomic, assign) bool numberHasSign;

/// property holding flag whether thousand separators should be used
@property (nonatomic, assign) bool showThousandSeparator;

/// property with current value of the control
@property (nonatomic, assign, getter=getValue, setter=setValue:) NSDecimalNumber* value;

/// property with current value of the control as string
@property (nonatomic, readonly, getter=getText) NSString* text;

/// property holding font of the edit field text 
@property (nonatomic, retain, getter=getFont, setter=setFont:) UIFont* font;

/// property with value of placeholder text
@property (nonatomic, assign, getter=getPlaceholder, setter=setPlaceholder:) NSString* placeholder;

@end
