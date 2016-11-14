//
//  MAFSettingsScreenDelegate.h
//  MAFSettingScreen
//
//  Created by David Egresits on 6/10/11.
//  Copyright 2011 SAP AG. All rights reserved.
//

//#import <Cocoa/Cocoa.h>
#import <MessageUI/MessageUI.h>

#import "DataVault.h"
#import "MAFUIView.h"
#import "MAFUITableViewCell.h"

@class MAFSettingsScreen;
@class MAFSettingsSpecifier;

/**

 MAFSettingsScreenDelegate: defines the callback methods, which will be called when a specific operation finished in MAFSettingsScreen.
 
*/
@protocol MAFSettingsScreenDelegate

@required
/**
 * This delegate method is called when a SettingsUI is closed 
 * @param sender: MAFSettingsUI, which is cloased
 * @param dictionaryChanged: dictionary contains the changed settings values
 * @remark The dictionary contains SettingsValue objects.
 *			The old/newValue of a SettingsValue can be a NSNumber or an other object 
 *			(You can call the [number floatValue] to get a float, etc.)
 */
- (void)settingsViewControllerDidEnd:(MAFSettingsScreen*)sender withValuesChanged:(NSDictionary*)dictionaryChanged;
@optional

/**
 * This delegate method is called when a tableview is reloaded with custom section headers
 * @param tableView: tableView, which is reloaded
 * @param key: the key of the section header (PSGroupSpecifier item in plist)
 * @returns: height of the section header
 */
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderForKey:(NSString*)key;

/**
 * This delegate method is called when a tableview is reloaded with custom section headers
 * @param tableView: tableView, which is reloaded
 * @param key: the key of the section header (PSGroupSpecifier item in plist)
 * @returns: UIView of the section header
 */
- (MAFUIView *)tableView:(UITableView *)tableView viewForHeaderForKey:(NSString*)key;

/**
 * This delegate method is called when a custom cell was selected
 * @param specifier: specifier of the cell
 */
- (void)cellForSpecifierDidSelected:(MAFSettingsSpecifier*)specifier;

/**
 * This delegate method is called when a tableview is reloaded with custom cell
 * @param tableView: tableView, which is reloaded
 * @param specifier: the describer of the cell
 * @returns: height of the tableView cell
 */
- (CGFloat)tableView:(UITableView*)tableView heightForSpecifier:(MAFSettingsSpecifier*)specifier;

/**
 * This delegate method is called when a tableview is reloaded with custom section headers
 * @param tableView: tableView, which is reloaded
 * @param specifier: the describer of the cell
 * @returns: MAFUITableViewCell to visualize
 */
- (MAFUITableViewCell*)tableView:(UITableView*)tableView cellForSpecifier:(MAFSettingsSpecifier*)specifier;

/**
 * This delegate method is called when the SettingsUI's delegate has this method, and contains the body of the message
 * @returns message body for the mail
 */
- (NSString*)mailComposeBody;

///**
// * This delegate method is called when the SettingsUI's delegate has this method, and gives back a UIViewController for mail composer delegate
// * @returns a UIViewController, which implements the MFMailComposeViewControllerDelegate protocol
// */
//- (UIViewController<MFMailComposeViewControllerDelegate>*)viewControllerForMailComposeView;

/**
 * This delegate method is called when a custom button was selected
 * @param sender: MAFSettingsUI, which shows the button
 * @param key: the unique key of the button 
 */
- (void)settingsViewController:(MAFSettingsScreen*)sender buttonTappedForKey:(NSString*)key;

/**
 * This delegate method is called when data is read from or written to the Datavault and shall give an unlocked instance back
 * @returns unlocked data vault
 */
- (DataVault*) getUnlockedDatavault;
@end


