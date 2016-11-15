//
//  MAFSettingsStoring.h
//  MAFSettingScreen
//
//  Created by David Egresits on 6/10/11.
//  Copyright 2011 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MAFSettingsValue : NSObject
{
	NSObject* m_OldValue;
	NSObject* m_ChangeToValue;
	BOOL m_ShouldSaveToSecureStore;
}

@property (nonatomic, retain) NSObject* oldValue;
@property (nonatomic, retain) NSObject* changeToValue;
@property (nonatomic, assign) BOOL shouldSaveToSecureStore;

@end

/**
 MAFSettingsStoring : protocol which defines how different values can be stored in and retrieved from the settings store.
**/
@protocol MAFSettingsStoring <NSObject>
@required

#pragma mark Setters

/**
 * Set value for the key and save it temporaly
 * @param value: bool value
 * @param key: key for the value
 * @remark the full save is alter the synchronize call
 */
- (void)setBool:(BOOL)value      forKey:(NSString*)key;

/**
 * Set value for the key and save it temporaly
 * @param value: float value
 * @param key: key for the value
 * @remark the full save is alter the synchronize call
 */
- (void)setFloat:(float)value    forKey:(NSString*)key;

/**
 * Set value for the key and save it temporaly
 * @param value: double value
 * @param key: key for the value
 * @remark the full save is alter the synchronize call
 */
- (void)setDouble:(double)value  forKey:(NSString*)key;

/**
 * Set value for the key and save it temporaly
 * @param value: integer value
 * @param key: key for the value
 * @remark the full save is alter the synchronize call
 */
- (void)setInteger:(int)value    forKey:(NSString*)key;

/**
 * Set value for the key and save it temporaly
 * @param value: object value
 * @param key: key for the value
 * @remark the full save is alter the synchronize call
 */
- (void)setObject:(id)value      forKey:(NSString*)key;
/**
 * Set value for the key and save it temporaly into the keychain
 * @param value: object value
 * @param key: key for the value
 * @param flag_in: enable save into secure store
 * @remark the full save is alter the synchronize call
 */
- (void)setObject:(id)value forKey:(NSString*)key toSecureStore:(BOOL)flag_in;

#pragma mark Getters

/**
 * Get the value for the key
 * @param key: key for the value
 * @returns bool value
 */
- (BOOL)boolForKey:(NSString*)key;

/**
 * Get the value for the key
 * @param key: key for the value
 * @returns float value
 */
- (float)floatForKey:(NSString*)key;

/**
 * Get the value for the key
 * @param key: key for the value
 * @returns double value
 */
- (double)doubleForKey:(NSString*)key;

/**
 * Get the value for the key
 * @param key: key for the value
 * @returns integer value
 */
- (int)integerForKey:(NSString*)key;

/**
 * Get the value for the key
 * @param key: key for the value
 * @returns object value
 */
- (id)objectForKey:(NSString*)key;

#pragma mark Synchronize and get changed values

/**
 * Write settings to a permanant storage
 * @returns YES on success, NO otherwise
 */
- (BOOL)synchronize; 
@optional

/**
 * Get changed values dictionary
 * @returns dictionary of SeetingsValue objects
 * @remark The old/newValue of a SettingsValue can be a NSNumber or an other object 
 *         (You can call the [number floatValue] to get a float, etc.)
 */
- (NSDictionary*) getValuesChanged;

/**
 * Clear the cached contents from the SettongsStore
 */
- (void)clear;
@end
