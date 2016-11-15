//
//  SODataRequestParam.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Holds the parameters for an OData server request
 */
@protocol SODataRequestParam <NSObject>

/**
 Tag can be added to the RequestParam
 */
@property (nonatomic, copy) NSString* customTag;

@end
