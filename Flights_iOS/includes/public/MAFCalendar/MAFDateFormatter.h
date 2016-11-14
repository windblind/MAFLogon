//
//  MAFDateFormatter.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 3/22/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MAFDateFormatter : NSObject
{
    @private
    NSMutableDictionary* hourFormatStyles;
    NSMutableDictionary* fullhourFormatStyles;
    NSDateFormatter* formatter;
    NSCalendar* calendar;
}


+(MAFDateFormatter*)instance;

-(NSArray*)getWeekDays;
-(NSDate*)createDateFromString:(NSString*)dateStr withFormat:(NSString*)formatStr andTimezone:(NSTimeZone*)timezone;
-(NSDate*)createDateFromString:(NSString*)dateStr withFormat:(NSString*)formatStr;
-(NSString *)localizedTimeStringFromDate:(NSDate *)date;
-(NSString *)localizedTimeStringFromDate:(NSDate *)date withTimezone:(NSTimeZone*)timezone;
-(NSString*)stringFromDate:(NSDate*)date withFormat:(NSString*)dateFmt;

@property (retain,getter = getCalendar, setter = setCalendar:) NSCalendar* calendar;

@end
