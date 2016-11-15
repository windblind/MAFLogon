//
//  MAFCalendarViewDelegate.h
//  MAFCalendar
//
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAFAppointmentProtocol.h"
#import "MAFCalendarNavigationDelegate.h"
#import "MAFCalendarRenderingDelegate.h"

@class MAFAppointmentView;
@class MAFCalendar;
@class MAFCalendarView;
@class MAFListCalendarView;
@class MAFListCalendarViewCell;
@class MAFMonthCalendarView;
@class MAFMonthCalendarItemView;
@class MAFIPadMonthDayBox;

/**
 @brief Delegate protocol for the MAFCalendarView.
 */
@protocol MAFCalendarViewDelegate <NSObject, MAFAppointmentDelegate, MAFCalendarNavigationDelegate, MAFCalendarRenderingDelegate>

@optional

/**
 Deprecated in 1.2
 Please use the calendarView's isReadOnly property
 Callback method triggered when user requests creation of an appointment within a MAFCalendarView.
 
 @param sender the respective calender view container
 
 @return is this calendar read-only
 
 */
-(BOOL)calendarViewIsReadOnly:(MAFCalendarView*)sender DEPRECATED_ATTRIBUTE;


@end
