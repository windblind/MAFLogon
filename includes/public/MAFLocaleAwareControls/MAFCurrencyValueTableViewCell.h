//
//  MAFCurrencyValueTableViewCell.h
//  MAFTestProject
//
//  Created by Muehlbauer, Jan (external) on 2/28/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFTableViewCell.h"
#import "MAFCurrencyFormatter.h"
#import "MAFDecimalInputView.h"

/**
 @class MAFCurrencyValueTableViewCell
 
 @brief Table view cell for input of currencies (value-style).
 
 @author Jan Muehlbauer (external)
 
*/
@interface MAFCurrencyValueTableViewCell : MAFTableViewCell
{
	MAFCurrencyFormatterSettings* currencyFormatterSettings;
	NSDecimalNumber* currencyValue;
	
	UIView* viewEdit;
	MAFDecimalInputView* txtCurrencyValue;
	
	id<MAFValueHelpCollection> amountTypeValueHelpCollection;
}

/// property holding the current amount type of the control
@property (nonatomic, retain, getter=getAmountType, setter=setAmountType:) NSString* amountType;

/// property holding the current currency value
@property (nonatomic, assign, getter=getCurrencyValue, setter=setCurrencyValue:) NSDecimalNumber* currencyValue;

/// property holding the current amount type MAFValueHelpCollection 
@property (nonatomic, retain) id<MAFValueHelpCollection> amountTypeValueHelpCollection;

/**
 Initializer.
 
 @param reuseIdentifier table view reuse identifier
 @param formatterSettings any specific formatter settings 
*/
-(id)initWithReuseIdentifier:(NSString*)reuseIdentifier currencyFormatterSettings:(MAFCurrencyFormatterSettings*)formatterSettings;

@end
