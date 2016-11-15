//
//  MAFValueHelpController.h
//  MAFMadiatorArchitectureTest
//
//  Created by Muehlbauer, Jan (external) on 2/29/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFValueHelpListCollection.h"
#import "MAFValueHelpAccessor.h"
#import "MAFStyling.h"

@protocol MAFValueHelpControllerDelegate;

/**
 @class MAFValueHelpController
 
 @brief Controls display of choice dialog to user.
 
 The MAFValueHelpController presents a list-like dialog to the user
 for selection of a value of the presented list. The class is initialized
 with a MAFValueHelpCollection object holding the values to present. The
 object requesting the selection of a value has to adhere to the MAFValueHelpAccessor
 protocol, which allows communicating back the selected value.
 
 @author Marc Roettig (external), Jan Muehlbauer (external)
 
*/
@interface MAFValueHelpController : UIViewController <UITableViewDelegate, UITableViewDataSource, MAFStyling>
{
	id <MAFValueHelpCollection> collection;
	id <MAFValueHelpAccessor> receiver;
	NSString* key;
	
	UITableView* tvValues;
}
/// property holding the MAFValueHelpListCollection
@property (nonatomic, readonly) MAFValueHelpListCollection* collection;

/// property storing the receiver of the ValueHelp request
@property (nonatomic, readonly) id <MAFValueHelpAccessor> receiver;

/// property holding the key name of the requested value
@property (nonatomic, readonly) NSString* key;

/// property holding the key name of the requested value
@property (nonatomic, assign) id<MAFValueHelpControllerDelegate> delegate;


/**
 Initializer used to supply MAFValueHelpColletion to present and the callback "address" of the
 value requesting a selection event.
 
 @param collection stores the list of possible values to choose from
 @param receiver is a reference on the requesting object
 @param key is the key name of the value that will receive the selected value
*/
- (id) initWithValueHelpCollection:(id<MAFValueHelpCollection>)collection receiver:(id<MAFValueHelpAccessor>)receiver key:(NSString*)key;

@end

/**
 This delegate protocol defines a callback mechanism for communicating selection events back
 to the calling ViewController.
 
 @note this is mainly used for iPhone specific code.
 
 @author Roettig, Marc (external)
 
*/
@protocol MAFValueHelpControllerDelegate <NSObject>
/**
 This method is called on the delegate when the user selects one element form the list of possible values.
 
 @param controller the controller displaying the MAFValueHelp dialog
 @param item the user-selected key-value pair
 
*/
-(void)valueHelpController:(MAFValueHelpController*)controller didSelectItem:(MAFKeyValuePair*)item;
@end


