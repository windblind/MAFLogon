//
//  SODataMetaFunctionImportDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SODataMetaFunctionImport.h"

/**
 Represents the metadata of a FunctionImport
 */
@interface SODataMetaFunctionImportDefault : NSObject <SODataMetaFunctionImport>

/**
 * Custon initializer
 * @param name name of the function import
 * @param returnTypeName name of the return type
 * @param isReturnCollection indicates whether the result is a collection or not
 * @param returnEntitySetName name of the entity set which will be returned
 * @param callMethod type of the call method
 * @param parameters the function import parameters
 * @param annotation annotations of the function import
 */
- (id)initWithName:(NSString*)name returnTypeName:(NSString*)returnTypeName isReturnCollection:(BOOL)isReturnCollection returnEntitySetName:(NSString*)returnEntitySetName callMethod:(NSString*)callMethod parameters:(NSDictionary*)parametersDict annotations:(NSDictionary*)annotationsDict;

@end
