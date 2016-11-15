//
//  SODataLink.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataPayload.h"

/**
 Represents a link to a particular resource within a store.
 */
@protocol SODataLink <SODataPayload>

/**
 Returns the relative path of the resource which is to be interpreted relative to the base URL of the service.
 */
@property (readonly, nonatomic, copy) NSString* resourcePath;

@end
