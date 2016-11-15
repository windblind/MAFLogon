//
//  MAFCalendarView.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 3/19/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFCalendarViewDataSource.h"
#import "MAFCalendarViewDelegate.h"
#import "MAFAppointmentDelegate.h"
#import "MAFCalendarNavigationDelegate.h"

@class MAFAppointmentView;

@protocol MAFAppointmentProtocol;


@interface MAFCalendarView : UIView
{
    @protected
     id<MAFCalendarViewDataSource> datasource;
}


@property (retain,nonatomic) NSDate* startDate;
@property (retain,nonatomic) NSDate* endDate;

@property (retain,nonatomic) UIColor* appointmentViewColor;
@property (retain,nonatomic) UIColor* appointmentViewBorderColor;

@property (retain,nonatomic) UIColor* appointmentViewInvitationColor;
@property (retain,nonatomic) UIColor* appointmentViewInvitationBorderColor;


@property (retain,nonatomic) UIColor* appointmentViewTitleColor;
@property (retain,nonatomic) UIColor* appointmentViewLocationColor;


@property (retain,nonatomic) NSString* appointmentViewDefaultTitle;
@property (retain,nonatomic) NSString* appointmentViewDefaultLocation;

@property (assign,nonatomic) id<MAFCalendarViewDataSource> datasource;
@property (assign,nonatomic) id<MAFAppointmentDelegate> appointmentDelegate;
@property (assign,nonatomic) id<MAFCalendarNavigationDelegate> navigationDelegate;
@property (assign,nonatomic) id<MAFCalendarRenderingDelegate> renderingDelegate;
@property (assign,nonatomic) id<MAFCalendarViewDelegate> delegate;

/**
 Sets the range of dates using the specified start and end date.
 
 @param startDate the start date of the range
 @param endDate the end date of the range
 
 */
-(void)setDateRangeToStart:(NSDate*)startDate andEnd:(NSDate*)endDate;

/**
 Will focus the current day within the calendar view.
*/
-(void)focusCurrentDay;

/**
 Will refresh the view (=reload of data + repaint of view).
 */
-(void)refresh;

@end


/**
 The MAFAppointmentViewClientDelegate protocol is used to communicate any change event (i.e. resize) of the parent
 MAFAppointmentView to the client view.
 
*/
@protocol MAFAppointmentViewClientDelegate 
/**
 Called when parent MAFAppointmentView did change height (=temporal duration).
 
 @param view the parent MAFAppointmentView
 @param h the new height in grid units (deltaY) 
*/
-(void)appointmentView:(MAFAppointmentView*)view isResizingToHeight:(float)h DEPRECATED_ATTRIBUTE;
@end


