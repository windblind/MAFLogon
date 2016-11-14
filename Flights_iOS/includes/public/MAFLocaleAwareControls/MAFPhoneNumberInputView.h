//
//  MAFPhoneNumberInputView.h
//
//  Created by Roettig, Marc (external) on 2/20/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class MAFPhoneNumberInputView;

/**
 
 @brief Delegate holding change event callbacks.
 
 This protocol can be used by external observers of the MAFPhoneNumberInputView
 to be informed about state changes like didBeginEdit, didEdit, didEndEdit.
 
 @author Marc Roettig (external)
 
*/
@protocol MAFPhoneNumberInputTextFieldDelegate <NSObject>

@optional

/**
 Callback method called upon didBeginEditing event in input view.
*/
-(void)phoneNumberInputFieldDidBeginEditing:(MAFPhoneNumberInputView*)sender;

/**
 Callback method called upon didEdit event in input view.
 */
-(void)phoneNumberInputFieldDidEdit:(MAFPhoneNumberInputView*)sender;

/**
 Callback method called upon didEndEditing event in input view.
 */
-(void)phoneNumberInputFieldDidEndEditing:(MAFPhoneNumberInputView*)sender;

@end

/**
 @class MAFPhoneNumberInputView
 
 @brief Input view for phone numbers.
 
 This class provides an input view that allows
 the user to enter phone numbers. Entered values
 are formatted online using MAFFormatter functionality.
 
 @author Marc Roettig (external)
 
*/
@interface MAFPhoneNumberInputView : UIView<UITextFieldDelegate>
{
  @private
    /// a field for entering the phone number
    UITextField*            editField;
    /// holds state of control
    BOOL                    isEditing;
    /// stores the local country code of the device
    NSString*               localCountryCode;
    /// flags whether input has been supplied
    BOOL isFilled;
    /// flags whether an internal set operation is occuring
    BOOL reentrant;
    /// delegate reference for informing external observers about state changes 
    id<MAFPhoneNumberInputTextFieldDelegate> delegate;
}

/// delegate for handling value changes within control 
@property (nonatomic, assign) id <MAFPhoneNumberInputTextFieldDelegate> delegate;
/// the currently stored value of the control
@property (retain,nonatomic,setter = setValue:) NSString* value;
/// used font for display and edit fields (can be changed externally)
@property (retain,nonatomic) UIFont*   font;
/// used background color of display and edit fields (can be changed externally)
@property (retain,nonatomic) UIColor*  backgroundColor;
/// used background color of display and edit fields (can be changed externally)
@property (retain,nonatomic) UIColor*  textColor;

/**
 Initializer (designated). 
 
 @param frame desired frame for the view
*/
-(id)initWithFrame:(CGRect)frame;

/**
 Toggles view between display/edit mode.
*/
-(void)toggleEdit;

/**
 Makes the view editable.
*/
-(void)makeEditable;

/**
 Makes the view uneditable.
*/
-(void)makeUneditable;

/**
 Does the input view have (non-null) input.
 
 @return flag whether input view has some content
*/
-(BOOL)hasContent;

/**
 Makes the input view editable and makes it become firstResponder.
*/
-(void)setEditFocus;

/**
 Makes the input view uneditable and makes it resign from being firstResponder.
*/
-(void)unsetEditFocus;

@end
