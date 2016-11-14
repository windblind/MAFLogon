//
//  MAFCurrencySelectorTableViewCell.h
//  MAFTestProject
//
//  Created by Muehlbauer, Jan (external) on 2/28/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFTableViewCell.h"

/**
 @class MAFCurrencySelectorTableViewCell
 
 @brief Table view cell for input of currencies (selector-style).
 
 @author Jan Muehlbauer (external)
 
*/
@interface MAFCurrencySelectorTableViewCell : MAFTableViewCell
{
	NSString* currencyCode;
	
	UIView* viewEdit;
	UIButton* cmdCurrenySelector;
	
	id<MAFValueHelpCollection> currencyCodeValueHelpCollection;
}

/// property holding the current currency code
@property (nonatomic, retain, getter=getCurrencyCode, setter=setCurrencyCode:) NSString* currencyCode;

/// property holding the current currency code MAFValueHelpCollection
@property (nonatomic, retain, getter=getCurrencyCodeValueHelpCollection, setter=setCurrencyCodeValueHelpCollection:) id<MAFValueHelpCollection> currencyCodeValueHelpCollection;

/**
 Initializer.
 
 @param reuseIdentifier table view reuse identifier
 @param formatterSettings any specific formatter settings 
*/
-(id)initWithReuseIdentifier:(NSString*)reuseIdentifier;

@end
