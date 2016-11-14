//
//  MAFValueHelpAccessor.h
//  MAFMadiatorArchitectureTest
//
//  Created by Muehlbauer, Jan (external) on 2/29/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MAFValueHelpCollection.h"
#import "MAFValueHelpListCollection.h"
#import "MAFValueHelpSectionCollection.h"


@protocol MAFValueHelpAccessor;

/**
 @brief Allows communication of MAFValueHelpAccessor with its Mediator.

 @author Marc Roettig (external) Jan Muehlbauer (external)
*/
@protocol MAFValueHelpAccessorDelegate <NSObject>

/**
 Allows any MAFValueHelpAccessor implementor to request display of an choice dialog to the application user.
 The list of possible values (along with display labels) is stored in a MAFValueHelpCollection object. The
 Mediator instance that delivererd the requesting object will implement this protocol. 
 
 @param sender is the source of the display request
 @param key is the key name of the value to be queried from the user
 @param collection holds the list of values to choose from
 @param title holds a string to be set as title for the dialog
*/
- (void) valueHelpAccessor:(id<MAFValueHelpAccessor>)sender requestSelectionForKey:(NSString*)key withValueHelpCollection:(id<MAFValueHelpCollection>)collection andValueHelpTitle:(NSString*)title;

@optional

/**
 Callback for any MAFValueHelpAccessor implementor to inform about didBeginEdit event for value (identified by key name).
 
 @param sender the respective MAFValueHelpAccessor whose value changed
 @param key the key name of the affected value
*/ 
- (void) valueHelpAccessor:(id<MAFValueHelpAccessor>)sender didBeginEditingValueForKey:(NSString*)key;

/**
 Callback for any MAFValueHelpAccessor implementor to inform about didEdit event for value (identified by key name).
 
 @param sender the respective MAFValueHelpAccessor whose value changed
 @param key the key name of the affected value
*/ 
- (void) valueHelpAccessor:(id<MAFValueHelpAccessor>)sender didEditValueForKey:(NSString*)key;

/**
 Callback for any MAFValueHelpAccessor implementor to inform about didEndEdit event for value (identified by key name).
 
 @param sender the respective MAFValueHelpAccessor whose value changed
 @param key the key name of the affected value
*/ 
- (void) valueHelpAccessor:(id<MAFValueHelpAccessor>)sender didEndEditingValueForKey:(NSString*)key;

@end


/**
 
 @brief Allows generic getter/setter mechanims and event notification for implementors.
 
 The MAFValueHelpAccessor protocol allows any implementing class to
 offer access to its values to any interested remote classes via a
 getter and setter method. The relevant internal values are identified
 by unique key names. 
 
 @author Marc Roettig (external), Jan Muehlbauer (external)
 
 @note Each implementing control should have a list of all advertised 
       key names defined in its header for framework user convenience.
       Mapping of key names to internal values are coded in the getter
       and setter method.
*/
@protocol MAFValueHelpAccessor <NSObject>

/**
 Enforced property for implementing classes holding 
*/
@property (nonatomic, assign) id <MAFValueHelpAccessorDelegate> delegate;

/**
 Set the internal property of a control (identified by unique key name)
 to the supplied value.
 
 @param the new value for the property
 @param the unique key name of the property
*/
- (void) setMAFValue:(NSObject*)value forKey:(NSString*)key;

/**
 Get the current value of a property of a control (identified by unique key name).
 
 @return value of the property
*/ 
- (NSObject*) getMAFValueForKey:(NSString*)key;

@end
