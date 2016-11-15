//
//  SODataDownloadMediaResult.h
//  ODataAPI
//
//  Copyright (c) 2015 SAP. All rights reserved.
//


/**
 * Represents a media content.
 *
 */
@protocol SODataDownloadMediaResult <NSObject>

/**
 Retrieves the stream of the media content.
 */
@property (nonatomic, strong) NSInputStream* inputStream;

/**
 Retrieves the content type of the media content.
 */
@property (nonatomic, copy) NSString* contentType;

/**
 Retrieves the content lenth of the media content.
 */
@property (nonatomic, assign) NSInteger contentLength;


@end
