//
//  MAFCurrencyTableViewCell.h
//  MAFTestProject
//
//  Created by Muehlbauer, Jan (external) on 2/23/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFTableViewCell.h"
#import "MAFCurrencyFormatter.h"
#import "MAFDecimalInputView.h"

/**
 @class MAFCurrencyTableViewCell
 
 @brief Table view cell for input of currencies.
 
 @author Jan Muehlbauer (external)
 
*/
@interface MAFCurrencyTableViewCell : MAFTableViewCell
{	
	MAFCurrencyFormatterSettings* currencyFormatterSettings;
	NSDecimalNumber* currencyValue;
	NSString* currencyCode;
	
	UIView* viewEdit;
	UIButton* cmdCurrenySelector;
	MAFDecimalInputView* txtCurrencyValue;
	
	id<MAFValueHelpCollection> currencyCodeValueHelpCollection;
	id<MAFValueHelpCollection> amountTypeValueHelpCollection;
}

/// property holding the current amount type of the control
@property (nonatomic, retain, getter=getAmountType, setter=setAmountType:) NSString* amountType;

/// property holding the current currency code of the control
@property (nonatomic, retain, getter=getCurrencyCode, setter=setCurrencyCode:) NSString* currencyCode;

/// property holding the current currency value 
@property (nonatomic, assign, getter=getCurrencyValue, setter=setCurrencyValue:) NSDecimalNumber* currencyValue;

/// property holding the current currency code MAFValueHelpCollection 
@property (nonatomic, retain, getter=getCurrencyCodeValueHelpCollection, setter=setCurrencyCodeValueHelpCollection:) id<MAFValueHelpCollection> currencyCodeValueHelpCollection;

/// property holding the current amount type MAFValueHelpCollection 
@property (nonatomic, retain, getter=getAmountTypeValueHelpCollection, setter=setAmountTypeValueHelpCollection:) id<MAFValueHelpCollection> amountTypeValueHelpCollection;

/**
 Initializer.
 
 @param reuseIdentifier table view reuse identifier
 @param formatterSettings any specific formatter settings 
*/
-(id)initWithReuseIdentifier:(NSString*)reuseIdentifier currencyFormatterSettings:(MAFCurrencyFormatterSettings*)formatterSettings;

@end
