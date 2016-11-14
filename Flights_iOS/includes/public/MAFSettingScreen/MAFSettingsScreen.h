//
//  MAFSettingsScreen.h
//  MAFSettingScreen
//
//  Created by David Egresits on 6/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

#import "MAFSettingsStoring.h"
#import "MAFSettingsScreenDelegate.h"


@class MAFSettingsReader;
@class MAFSettingsScreen;
@class MAFSettingsSpecifier;
@class MAFSettingsStoring;

/**
 * <pre>
 * <b>Preference Settings Specifier Types (.plist file types)</b>
 * This is a short decription about how build a plist to use with the MAFSettingsUI
 * The MAFSettingsUI uses the same approach implemented by Apple, but extends that with new types
 * Apple Settings Application Schema Reference:
 *		http://developer.apple.com/library/ios/#documentation/PreferenceSettings/Conceptual/SettingsApplicationSchemaReference/Introduction/Introduction.html#//apple_ref/doc/uid/TP40007005-SW1
 * <b>PSGroupSpecifier</b>
 * A new section in the TableView
 *  required items:
 *		•	Type - PSGroupSpecifier
 *  optional items:
 *		•	Title
 *		•	FooterText
 * <b>PSChildPaneSpecifier</b>
 * A cell that navigates for an other view
 *  required items:
 *		•	Type - PSChildPaneSpecifier
 *		•	Title
 *  optional items:
 *		•	File: the name of plist file of the other view
 *		•	ViewController: the class name of the viewController to navigate for
 * <b>PSTitleValueSpecifier</b>
 * A cell that shows a title and a value label
 *  required items:
 *		•	Type - PSTitleValueSpecifier
 *		•	Title
 *		•	Key: key for the cell
 *  optional items:
 *		•	DefaultValue with type numeric (integer)
 *		•	Values: array of the values with type numeric (integer) that could be associated with the preference key
 *		•	Titles: array of strings that represent user-readable versions of the values in the Values array.
 * <b>PSTextFieldSpecifier</b>
 * A cell that shows a title label and an input textfield
 *  required items:
 *		•	Type - PSTextFieldSpecifier
 *		•	Title
 *		•	Key: key for the cell
 *  optional items:
 *		•	DefaultValue
 *		•	IsSecure: If Yes, the text field replaces the typed text with bullet characters. 
 *						If No, the text field is a standard text field that displays the typed text. Default is NO.
 * <b>PSMultiValueSpecifier</b>
 * A cell that shows a title and some value label
 *  required items:
 *		•	Type - PSMultiValueSpecifier
 *		•	Title
 *		•	Key: key for the cell
 *  optional items:
 *		•	DefaultValue with type numeric (integer)
 *		•	Values: array of the values with type numeric (integer) that could be associated with the preference key
 *		•	Titles: array of strings that represent user-readable versions of the values in the Values array.
 * <b>PSToggleSwitchSpecifier</b>
 * A cell that shows a title and a switch button
 *  required items:
 *		•	Type - PSToggleSwitchSpecifier
 *		•	Title
 *		•	Key: key for the cell
 *		•	DefaultValue
 *  optional items:
 *		•	TrueValue: The value associated with the preference when the toggle switch is in the ON position.
 *		•	FalseValue: The value associated with the preference when the toggle switch is in the OFF position.
 * <b>PSSliderSpecifier</b>
 * A cell that shows a slider, with optional images
 *  required items:
 *		•	Type - PSSliderSpecifier
 *		•	Key: key for the cell
 *		•	DefaultValue
 *		•	MinimumValue
 *		•	MaximumValue
 *  optional items:
 *		•	MinimumValueImage: The image to display on the side of the slider representing the minimum value.
 *		•	MaximumValueImage: The image to display on the side of the slider representing the maximum value.
 * <b>PSSliderWithTitleSpecifier</b>
 * A cell that shows a slider with title and value with measure (images optionally)
 *  required items:
 *		•	Type - PSSliderWithTitleSpecifier
 *		•	Title
 *		•	Key: key for the cell
 *		•	DefaultValue
 *		•	MinimumValue
 *		•	MaximumValue
 *  optional items:
 *		•	Measure: Measure of the value which is represented by the slider.
 *		•	MinimumValueImage: The image to display on the side of the slider representing the minimum value.
 *		•	MaximumValueImage: The image to display on the side of the slider representing the maximum value.
 * <b>ASMailComposeSpecifier</b>
 * A cell that shows a mail screen
 *  required items:
 *		•	Type - ASMailComposeSpecifier
 *		•	Title
 *  optional items:
 *		•	Key: key for the cell
 *		•	ASMailComposeToRecipents: array of string
 *		•	ASMailComposeCcRecipents: array of string
 *		•	ASMailComposeBccRecipents: array of string
 *		•	ASMailComposeSubject: string
 *		•	ASMailComposeBody: string
 *		•	ASMailComposeBodyIsHTML: bool value
 * <b>ASOpenURLSpecifier</b>
 * A cell that opens an url in the browser
 *  required items:
 *		•	Type - ASOpenURLSpecifier
 *		•	Title
 *  optional items:
 *		•	Key: key for the cell
 *		•	File: page url, for exapmle: http://www.sap.com
 * <b>ASButtonSpecifier</b>
 * A cell that contains a button
 *  The users action is the "settingsViewController:(MAFSettingsUI*) settingsView buttonTappedForKey:(NSString*) key" method of the 
 *		MAFSettingsUI's delegate.
 *  required items:
 *		•	Type - ASButtonSpecifier
 *		•	Title
 *		•	Key: key for the cell
 * 
 * </pre>
 */


@interface MAFSettingsScreen : UITableViewController <UITextFieldDelegate, UINavigationControllerDelegate, MFMailComposeViewControllerDelegate> {
	
	NSObject<MAFSettingsScreenDelegate>*  m_Delegate;
 
    NSMutableArray*			m_ViewList;
    NSIndexPath*			m_CurrentIndexPath;
	NSIndexPath*			m_TopmostRowBeforeKeyboardWasShown;
	
	MAFSettingsReader*		m_SettingsReader;
    id<MAFSettingsStoring>  m_SettingsStore;
	NSString*				m_File;
	
	id                      m_CurrentFirstResponder;
    
	BOOL                    m_ShowDoneButton;
	
	UINavigationController* m_NavController;
	
	UIViewController*		m_ParentModalViewController;
}


@property (nonatomic, retain) UIViewController* parentModalViewController;
@property (nonatomic, retain) NSString* sourcePlist;
@property (nonatomic, retain) NSString* bundleFolder;

/**
 * Set that the Settings view should autorotate into the direction of the device
 * @param isAutorotating_in: if yes, then use autorotation
 */
+ (void) setShouldAutoRotateView:(BOOL) isAutorotating_in;

/**
 * This method will present a SettingsUI from the viewController
 * @param viewController_in: the Viewcontroller from which the SettingsUI will be presented
 */
+ (void) showFromViewController:(UIViewController*)viewController_in;

/**
 * This method will present a Logon dialog from the viewController
 * @param viewController_in: the Viewcontroller from which the LogonUI will be presented
 * @param sourcePlistName: plist file from which the Setting will built
 */
+ (void) showFromViewController:(UIViewController*)viewController_in WithSourcePlist:(NSString*)sourcePlistName;

/**
 * This method will present a Logon dialog from the viewController
 * @param viewController_in: the Viewcontroller from which the LogonUI will be presented
 * @param sourcePlistName: plist file from which the Setting will be built
 * @param bundleFolder: bundle folder from which the plist file is taken
 */
+ (void) showFromViewController:(UIViewController*)viewController_in WithSourcePlist:(NSString*)sourcePlistName inBundleFolder:(NSString*)bundleFolder;

/**
 * Set delegate for the settings, this must be the caller class, which implements the MAFSettingsScreenDelegate protocol
 * @param delegate_in: a class implements the MAFSettingsScreenDelegate protocol
 */
+ (void) setDelegate:(NSObject<MAFSettingsScreenDelegate>*)delegate_in;

/**
 * Retrieves the delegate
 */
+ (NSObject<MAFSettingsScreenDelegate>*) delegate;

/**
 * Dismisses the LogonUI
 * @discussion Can be called by clients to dismiss the Logon UI programmatically. Usually you should not do that, but we provide the API for convenience. 
 */
+ (void)dismiss;

/**
 * Synchronizes the default values from the plist files to the NSUserDefaults
 * @discussion You must call this method to set the default values in the NSUserDefaults
 */
+ (void) synchronizeDefaultSettings;
/** 
 * Sychronize the default settings from the given dataSource and his sub files
 * @param dataSourceArr: array from plist file to sychronize
 */
- (void) synchronizeDefaultSettingsFromDataSource:(NSArray*) dataSourceArr;

// subclassing: optionally override these methods to customize appearance and functionality
//- (UITableViewCell*)tableView:(UITableView* )tableView cellForRowAtIndexPath:(NSIndexPath* )indexPath;
//- (NSIndexPath*)tableView:(UITableView* )tableView willSelectRowAtIndexPath:(NSIndexPath* )indexPath;
//- (void)tableView:(UITableView* )tableView didSelectRowAtIndexPath:(NSIndexPath* )indexPath;
//- (UIView*)tableView:(UITableView* )tableView viewForHeaderInSection:(NSInteger)section;
@end