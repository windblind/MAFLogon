//
//  MAFPhoneNumberTableViewCell.h
//
//  Created by Roettig, Marc (external) on 2/24/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFTableViewCell.h"
#import "MAFValueHelpAccessor.h"
#import "MAFPhoneNumberInputView.h"

/// MAFAccessor key for phone number value 
extern NSString * const MAFTableViewCellValueKeyPhoneNumber;
/// MAFAccessor key for phone number type value
extern NSString * const MAFTableViewCellValueKeyPhoneType;

/**
 @class MAFPhoneNumberTableViewCell
 
 @brief Table cell for input of phone numbers.
 
 This class provides a table cell that can be
 displayed within UITableViews and allows displaying/editing
 of phone numbers. The class relies on MAFPhoneNumberInputView
 for editing functionality.
 
 @author Marc Roettig (external)
 
 */
@interface MAFPhoneNumberTableViewCell : MAFTableViewCell <MAFPhoneNumberInputTextFieldDelegate>
{
    @private
        NSString*     value;
        NSString*     defaultValue;
        // internal list of available phone number types (i.e. work, home, ...) 
        NSArray*      phoneTypes;
    
        // reference to the wrapped MAFPhoneNumberInputView for edit mode
        MAFPhoneNumberInputView*  viewEdit;
    
        // helper view for generating seperator lines between subfields
        UIView*       sep;
    
        BOOL          hasValidValue;
        // flag whether cell is currently in editing mode
        BOOL          isEditing;
        
        float         xFirstSeparator;
    
        // gesture recognizer placed on view for catching user taps 
        // on front label to signal pick request of phone number type
        UITapGestureRecognizer* selectPhoneTypeTapRecognizer;
        
        // view responisible for catching user taps on front label
        // to signal pick request of phone number type
        UIView*  selectPhoneTypeTapArea;
}

/**
 Initializer for use of cell within UITableViews.
 
 @param reuseIdentifier
*/
-(id)initWithReuseIdentifier:(NSString *)reuseIdentifier;

/**
 Make this cell editable.
*/
-(void)makeEditable;

/**
 Make this cell uneditable.
*/
-(void)makeUneditable;

/**
 Set this cell in focus and make it editable.
 */
-(void)setEditFocus;

/**
 Set this cell out of focus and make it uneditable.
 */
-(void)unsetEditFocus;

/**
 Returns the stored content (i.e. phone number).
 
 @return phone number as string
*/
-(NSString*)getContent;

/**
 Does the cell hold any (non-null and empty) content.
 
 @return flag whether (non-null and empty) content is stored
*/
-(BOOL)hasContent;

// property holding the delegate handling MAFValueHelp requests 
@property (assign,nonatomic) id<MAFValueHelpAccessorDelegate> delegate;
// property string holding the current phone type (i.e. work, home, iPhone, ...)
@property (retain,nonatomic) NSString* phoneType;
// property string holding the current phone number
@property (retain,nonatomic) NSString* value;
// property array holding list of available phone number types 
@property (retain,nonatomic) NSArray* phoneTypes;

@end
