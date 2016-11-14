//
//  MAFApplicationSettings.h
//  MAFLogonManagerNG
//
//  Copyright (c) 2015 SAP AG. All rights reserved.
//

#import "MAFLogonRegistrationContext.h"
#import "MAFLogonSMPConstants.h"
#import "MAFApplicationSettingsProperty.h"
#import "MAFApplicationSettingsReadOnlyProperty.h"

typedef enum ApplicationSettingsInputFormats {
    ApplicationSettingsInputFormatXML,
    ApplicationSettingsInputFormatJSON
}ApplicationSettingsInputFormats;

@interface MAFDeviceInfo : NSObject

/*
 * The model of the device
 */
@property (nonatomic, copy) NSString* model;

/*
 * The type of the device
 */
@property (nonatomic, copy) NSString* type;

/*
 * The subType of the device
 */
@property (nonatomic, copy) NSString* subType;

/*
 * The phoneNumber of the device
 */
@property (nonatomic, copy) NSString* phoneNumber;

/*
 * The IMSI of the device
 */
@property (nonatomic, copy) NSString* imsi;

@end


@interface MAFApplicationSettings : NSDictionary <NSCoding, NSCopying, NSMutableCopying>

/*
 * Download Settings from SMP
 * @param completionBlock Contains the error if the download failed, nil otherwise
 */
-(void)downloadSettingsWithCompletionBlock:(void (^)(NSError*))completionBlock;

/**
 * Get the writable ApplicationSettings properties from the actual ApplicationSettings values
 * @param error Error object is filled in case of problem occurs during getting the writable settings. This can happen for example in compatibility mode, when the user upgrades from SP07 or prevoius version to newer and does not call downloadSettingsWithCompletionBlock: to refresh to the latest. After downloadSettingsWithCompletionBlock: is called it will be fully functional.
 */
-(NSDictionary*)writableSettingsWithError:(NSError**)error;

/*
 * Updates the Settings on the SMP server
 * @param newSettings The settings needs to be updated on the SMP server
 * @param completionBlock Contains the error if the update failed, nil otherwise
 */
-(void)updateSettings:(NSDictionary*)newSettings completionBlock:(void (^)(NSError*))completionBlock;

/*
 * Updates the deviceInfo on the SMP server
 * @param deviceInfo The deviceInfo contains the device specific data: model, type, subType, phoneNumber
 * @param completionBlock Contains the error if the update failed, nil otherwise
 */
-(void)updateDeviceInfo:(MAFDeviceInfo*)deviceInfo completionBlock:(void (^)(NSError*))completionBlock;

/*
 * Setting data can be accessed with it.
 * @param key Key of the Setting object
 * @returns MAFApplicationSettingsReadOnlyProperty of the setting
 */
-(MAFApplicationSettingsReadOnlyProperty*)objectForKey:(id<NSCopying>)key;

/*
 * The ApplicationEndpoint value from the settings
 */
@property (nonatomic, readonly) NSURL* applicationEndpointURL;

/*
 * The ApplicationConnectionID value from the settings
 */
@property (nonatomic, readonly) NSString* applicationConnectionId;

/*
 * The DeviceInfo values from the settings
 */
@property (nonatomic, readonly) MAFDeviceInfo* deviceInfo;

@end
