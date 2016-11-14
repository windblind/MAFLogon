//
//  MAFApplicationSettingsMetaProperty.h
//  MAFLogonManagerNG
//
//  Copyright (c) 2015 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum MAFApplicationSettingsCollectionKinds {
    MAFApplicationSettingsCollectionKindNone,
    MAFApplicationSettingsCollectionKindCollection
} MAFApplicationSettingsCollectionKinds;

typedef enum MAFApplicationSettingsPropertyTypes {
    MAFApplicationSettingsPropertyTypeString,
    MAFApplicationSettingsPropertyTypeBoolean,
    MAFApplicationSettingsPropertyTypeByte,
    MAFApplicationSettingsPropertyTypeInt8,
    MAFApplicationSettingsPropertyTypeInt16,
    MAFApplicationSettingsPropertyTypeInt32,
    MAFApplicationSettingsPropertyTypeComplex
} MAFApplicationSettingsPropertyTypes;

@interface MAFApplicationSettingsMetaProperty : NSObject <NSCoding, NSCopying>

/**
 * CollectionKind of the meta property
 */
@property (nonatomic, readonly, assign) MAFApplicationSettingsCollectionKinds collectionKind;

/**
 * Check whether the value of the property can be null
 */
@property (nonatomic, readonly, assign) BOOL isNullable;

/**
 * Check whether the value of the property can be set
 */
@property (nonatomic, readonly, assign) BOOL isReadOnly;

/**
 * Name of the property
 */
@property (nonatomic, readonly, copy) NSString* name;

/**
 * Type of the property
 */
@property (nonatomic, readonly, assign) MAFApplicationSettingsPropertyTypes type;

/**
 * Edm type of the property
 */
@property (nonatomic, readonly, copy) NSString* typeName;

/*
 * Validates the value based on the MAFApplicationSettingsMetaProperty
 * @param propertyValue value to for validation
 */
-(BOOL)validate:(id)propertyValue;

@end
