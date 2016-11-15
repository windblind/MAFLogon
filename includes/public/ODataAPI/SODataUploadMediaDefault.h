//
//  SODataUploadMediaDefault.h
//  ODataAPI
//
//  Copyright (c) 2015 SAP. All rights reserved.
//

#import "SODataUploadMedia.h"

@interface SODataUploadMediaDefault : NSObject<SODataUploadMedia>

/**
 * Custon initializer
 * @param filePath the path of the file to upload
 * @param contentType the content type of the media stream
 */
- (id) initWithFileAtPath:(NSString*)filePath contentType:(NSString*)contentType;


/**
 * Custon initializer
 * @param data the data to upload
 * @param contentType the content type of the media stream
 */
- (id) initWithData:(NSData*)data contentType:(NSString*)contentType;

@end
