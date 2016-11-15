//
//  SODataPayload.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

/**
 Enumeration for the possible kinds of OData payloads.
 */
typedef enum  {
    SODataTypeNone,
    SODataTypeRaw,
    SODataTypeProperty,
    SODataTypeEntity,
    SODataTypeEntitySet,
    SODataTypeLink,
    SODataTypeLinkList,
    SODataTypeUploadMedia,
    SODataTypeMetadata,
    SODataTypeError,
    SODataTypeBatchResponse
} SODataTypes;

/**
 Marker interface for all kinds of payloads that can be sent over the wire. The specific payload types are described by the nested ODataPayload.Type enumeration. The library supports only the specified 
 payload types and the corresponding provided implementations.
 */
@protocol SODataPayload <NSObject, NSCoding>

@end
