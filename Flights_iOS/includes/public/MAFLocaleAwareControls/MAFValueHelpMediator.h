//
//  MAFValueHelpMediator.h
//  MAFMadiatorArchitectureTest
//
//  Created by Muehlbauer, Jan (external) on 2/29/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MAFValueHelpAccessor.h"
#import "MAFValueHelpController.h"

#import "MAFAddressTableViewCell.h"
#import "MAFCurrencyTableViewCell.h"
#import "MAFCurrencyValueTableViewCell.h"
#import "MAFCurrencySelectorTableViewCell.h"

#import "MAFPhoneNumberTableViewCell.h"

@class MAFValueHelpMediator;

/**
 
 @brief Interface between mediator and any concrete view controller from framework user space.
 
 This protocol is used to forward request of choice dialog (aka MAFValueHelpController) and information about
 state changes to any associated object (usually a UIViewController) set as delegate of the Mediator instance.
 
 @author Marc Roettig (external), Jan Muehlbauer (external)
 
*/
@protocol MAFValueHelpMediatorDelegate <NSObject>

/**
 Signal to implementor that display of a MAFValueHelpController is needed (implemented method has to initiate display
 of MAFValueHelpController, for example by displaying a Popover or pushing the MAFValueHelpController on the current
 navigation stack).
 
 @param sender the issuing MAFValueHelpMediator
 @param controller the controller to be displayed
 @param requestor reference to the requesting view (used mainly for Popover views as anchors).
*/
- (void) valueHelpMediator:(MAFValueHelpMediator*)sender requestsDisplayOfValueHelpController:(MAFValueHelpController*)controller requestor:(UIView*)requestor;

@optional

/**
 Callback for any MAFValueHelpAccessor implementor to be informed about didBeginEdit event for value (identified by key name).
 
 @param sender the respective MAFValueHelpMediator who was notfied about value change in a MAFControl
 @param accessor the requesting MAFValueHelp accessor
 @param key the key name of the affected value
*/ 
- (void) valueHelpMediator:(MAFValueHelpMediator*)sender didBeginEditingValueOfAccessor:(id<MAFValueHelpAccessor>)accessor forKey:(NSString*)key;

/**
 Callback for any MAFValueHelpAccessor implementor to be informed about didEdit event for value (identified by key name).
 
 @param sender the respective MAFValueHelpMediator who was notfied about value change in a MAFControl
 @param accessor the requesting MAFValueHelp accessor
 @param key the key name of the affected value
*/
- (void) valueHelpMediator:(MAFValueHelpMediator*)sender didEditValueOfAccessor:(id<MAFValueHelpAccessor>)accessor forKey:(NSString*)key;

/**
 Callback for any MAFValueHelpAccessor implementor to be informed about didEndEdit event for value (identified by key name).
 
 @param sender the respective MAFValueHelpMediator who was notfied about value change in a MAFControl
 @param accessor the requesting MAFValueHelp accessor
 @param key the key name of the affected value
*/
- (void) valueHelpMediator:(MAFValueHelpMediator*)sender didEndEditingValueOfAccessor:(id<MAFValueHelpAccessor>)accessor forKey:(NSString*)key;

@end

/**
 @class MAFValueHelpMediator
 
 @brief Mediator between MAFControls and framework user space.
 
 The MAFValueHelpMediator class delivers (in a factory like fashion) MAFControls to consumers. The
 delivered MAFControls all have to implement the MAFValueHelpAccessor protocol, which allows by means
 of the delegate property to endow the delivered products to store a reference to the Mediator instance
 from which they originated. Thus the MAFValueHelpAccessor (and thus MAFControls) are enabled to communicate
 with their mediator and also reuqest display of choice dialogs and the like.
 
 @author Marc Roettig (external), Jan Muehlbauer (external)
 
*/
@interface MAFValueHelpMediator : NSObject <MAFValueHelpAccessorDelegate>
{
	id <MAFValueHelpMediatorDelegate> delegate;
}

/// property holding the associated MAFValueHelpMediatorDelegate used for dialog display request 
@property (nonatomic, assign) id <MAFValueHelpMediatorDelegate> delegate;

/**
 Delivers a AdressTableViewCell to be used within a UITableView.
 
 @return address table view cell
*/
- (MAFAddressTableViewCell*) getAddressTableViewCell;

/**
 Delivers a MAFCurrencyTableViewCell to be used within a UITableView.
 
 @param formatterSetting the settings for the currency formatter
 
 @return currency table view cell
*/
- (MAFCurrencyTableViewCell*) getCurrencyTableViewCellWithCurrencyFormatterSetting:(MAFCurrencyFormatterSettings*)formatterSettings;

/**
 Delivers a MAFCurrencyValueTableViewCell to be used within a UITableView.

 @param formatterSetting the settings for the currency formatter
 
 @return currency table view cell
*/
- (MAFCurrencyValueTableViewCell*) getCurrencyValueTableViewCellWithCurrencyFormatterSetting:(MAFCurrencyFormatterSettings*)formatterSettings;

/**
 Delivers a MAFCurrencySelectorTableViewCell to be used within a UITableView.
 
 @param formatterSetting the settings for the currency formatter
 
 @return currency table view cell
*/
- (MAFCurrencySelectorTableViewCell*) getCurrencySelectorTableViewCell;

/**
 Delivers a MAFPhoneNumberTableViewCell to be used within a UITableView.
 
 @return phone numer table view cell
*/
- (MAFPhoneNumberTableViewCell*) getPhoneNumberTableViewCell;

@end
