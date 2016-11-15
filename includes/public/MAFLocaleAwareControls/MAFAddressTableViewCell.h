//
//  MAFAddressTableViewCell.h
//  MAFAddressInputSample
//
//  Created by Arndt, Sven (external | sovanta AG) on 2/23/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFTableViewCell.h"
#import "MAFAddressFormatterContants.h"
#import "MAFAddressFormatter.h"

/**
 @class MAFAddressTableViewCell
 
 @brief Table cell for input of an address.
 
 This class provides a table cell that can be
 displayed within UITableViews and allows displaying/editing
 of an address. 
 
 @author Sven Arndt (external) Jan Muehlbauer (external) Horst Rothmeier (external) Eymen Alpaslan (external)
 
*/
@interface MAFAddressTableViewCell : MAFTableViewCell <UITextFieldDelegate>
{
    MAFAddressFormatter* addressFormatter;

    NSNumberFormatter* numberFormatter;
	
	NSMutableDictionary* dictAddress;
	
	NSString* countryCode;
	NSString* addressType;
	
	UIView* viewEdit;
	
	id<MAFValueHelpCollection>  countryCodeValueHelpCollection;
	id<MAFValueHelpCollection>  addressTypeValueHelpCollection;
}

/// property holding the current address within a dictionary
@property (nonatomic, retain, getter=getDictAddress, setter=setDictAddress:) NSMutableDictionary* dictAddress;

/// property holding the current country code
@property (nonatomic, assign, getter=getCountryCode, setter=setCountryCode:) NSString* countryCode;

/// property holding the type of address (i.e. home, work, ...)
@property (nonatomic, assign, getter=getAddressType, setter=setAddressType:) NSString* addressType;

/// property holding the current country code MAFValueHelpCollection
@property (nonatomic, retain) id<MAFValueHelpCollection> countryCodeValueHelpCollection;

/// property holding the current address type MAFValueHelpCollection
@property (nonatomic, retain) id<MAFValueHelpCollection> addressTypeValueHelpCollection;

/// property holding flag whether current address is a valid one
@property (nonatomic, readonly, getter=getHasValidAddress) bool hasValidAddress;

/**
 Initializer.
 
 @param reuseIdentifier table view reuse identifier
 
*/
- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier;


/**
 * @param a dictionary containing the address data identified by keys of MAFAddressFormatterContants.h
 * @param whether the table is in editing mode or not
 * @return the height of the cell for the specific address for display and editing mode
 */
+(CGFloat)cellHeightForAddress:(NSDictionary*)addressDictionary editing:(BOOL)editing;

@end
