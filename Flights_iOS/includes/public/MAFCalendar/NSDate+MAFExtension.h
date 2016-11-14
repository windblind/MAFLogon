//
//  NSDate+NSDate_MAFExtension.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 3/23/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSDate (MAFExtension)

+(void)getDay:(NSInteger*)day weekDay:(NSInteger*)weekday month:(NSInteger*)month andYear:(NSInteger*)year fromDate:(NSDate*)date;
/* return weather the date is today or not
 @param date The date to be examined 
 */
+(BOOL)isDateToday:(NSDate*)date;
/* Created a date from an NSString object
 @param dateStr The string that will be created into an NSDate
 @param formatStr The format of the dateStr NSString
 */
+(NSDate*)createDateFromString:(NSString*)dateStr withFormat:(NSString*)formatStr;
/*
 toDayBoundaryCeil
 @param date
 @param timeZone
 */
+(NSDate*)toDayBoundaryCeil:(NSDate*)date withTimeZone:(NSTimeZone*)timeZone;

/*
 toDayBoundaryFloor
 @param date
 @param timeZone
 */
+(NSDate*)toDayBoundaryFloor:(NSDate*)date withTimeZone:(NSTimeZone*)timeZone;
/*
 toDayBoundaryCeil
 @param date
 */
+(NSDate*)toDayBoundaryCeil:(NSDate*)date;
/*
 toDayBoundaryFloor
 @param date
 */
+(NSDate*)toDayBoundaryFloor:(NSDate*)date;
/*
 toAttributedHourLabel
 @param text
  @param font
   @param textcolor
   @param periodColor
 */
+(NSMutableAttributedString*)toAttributedHourLabel:(NSString*)text withFont:(UIFont*)font withTextColor:(UIColor*)textcolor andPeriodColor:(UIColor*)periodColor;
/*
 isWithinStart
 @param start
 @param end
 */
-(BOOL)isWithinStart:(NSDate*)start andEnd:(NSDate*)end;
-(BOOL)isDayEqual:(NSDate*)date;
/**
 Determines over how many weeks this month is spread (5 or 6 Weeks).
 @remarks It uses the current calendar ([NSCalendar currentCalendar]) for the
 calculations.
 @return number of weeks
 */
-(NSInteger)numberOfWeeksInMonth;
@end
