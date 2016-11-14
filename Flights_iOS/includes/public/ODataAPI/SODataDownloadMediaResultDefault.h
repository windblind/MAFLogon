//
//  SODataDownloadMediaResultDefault.h
//  ODataAPI
//
//  Copyright (c) 2015 SAP. All rights reserved.
//

#import "SODataDownloadMediaResult.h"

@interface SODataDownloadMediaResultDefault : NSObject<SODataDownloadMediaResult>

/**
 * Custon initializer
 * @param stream the input stream
 * @param contentType the content type of the media stream
 * @param contentLength the total length of the media stream
 */
- (id) initWithInputStream:(NSInputStream* )stream contentType:(NSString*)contentType contentLength:(NSInteger)contentLength;

@end
