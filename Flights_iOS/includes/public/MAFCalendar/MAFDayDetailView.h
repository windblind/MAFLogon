//
//  MAFDayDetailView.h
//  CalendarControl
//
//  Created by Alpaslan, Eymen (external) on 4/5/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFDayDetailNavigation.h"
#import "MAFCalendarView.h"

@class MAFAppointmentView;

/**
 @brief Delegate protocol for the child scroll view of the day view.
*/
@protocol MAFDaytimeListScrollViewDelegate <NSObject>
/**
 Called when a day change swipe was detected.
 @param swipeLorR the int meaning left or Right
*/
- (void) swipeToNextDayView:(int)swipeLorR;
/**
 Called to add a full day appointment to the day view.
 @param view The appointment to be added
*/
- (void) addFullDayAppointments:(NSArray*)fullDayApps;
/**
 Called when placement of appointment at specified coordinates is requested.
 @param startHour the starting hour of the appointment
 @param hours The duration of the appointment
 @param title The title for the appointment
 @param location The location for the appointment
*/
- (void) placeAppointmentAtHour:(int)startHour withDuration:(int)hours withTitle:(NSString*)title andLocation:(NSString*)location;
@end

/**
 @class MAFDayDetailView
 @brief Day view on calendar events.
 
 This class is the day view on all appointments scheduled for a day.
 
 @author Eymen Alpaslan (external)
 
*/
@interface MAFDayDetailView : MAFCalendarView <MAFDayDetailNavigationDelegate,MAFDaytimeListScrollViewDelegate,UIGestureRecognizerDelegate>

/// property holding the strings used for the hour labels on left hand side of day view
@property (retain,nonatomic) NSArray* hourLabels;
/// property holding the dayCalendar of the dayview
@property (retain,nonatomic) UIView* dayCalendarView;


/// property holding gradient colors for top area if current day is displayed
@property (retain) NSMutableArray* dayLabelBackgroundGradientColorCurrentDay;
/// property holding gradient colors of background gradient for top area
@property (retain) NSMutableArray* dayLabelBackgroundGradientColor;

@property (assign) CGPoint dayLabelBackgroundGradientStartPoint;
@property (assign) CGPoint dayLabelBackgroundGradientEndPoint;
@property (assign) CGPoint dayLabelBackgroundGradientStartPointCurrentDay;
@property (assign) CGPoint dayLabelBackgroundGradientEndPointCurrentDay;

/// property holding the font of the day label  at top
@property (retain) UIFont*  dayLabelFont;
/// property holding text color of day label at top 
@property (retain) UIColor* dayLabelTextColor;
/// property holding shadow color of day label at top
@property (retain) UIColor* dayLabelTextShadowColor;
/// property holding font of day label if current day is displayed
@property (retain) UIFont*  currentDayLabelFont;
/// property holding color of day label if current day is displayed
@property (retain) UIColor* currentDayLabelTextColor;
/// property holding shadow color of day label if current day is displayed
@property (retain) UIColor* currentDayLabelTextShadowColor;
/// property holding navigation arrow color
@property (retain) UIColor* navigationArrowColor;
/// property holding color of current time indicator line
@property (retain) UIColor* hourIndicatorColor;
/// property holding fill color of lefthand side knob of current time indicator line
@property (retain) UIColor* hourIndicatorKnobColor;
/// property holding border color of lefthand side knob of current time indicator line
@property (retain) UIColor* hourIndicatorKnobBorderColor;
/// property holding background color of day canvas
@property (retain) UIColor* dayBackgroundColor;
/// property holding background color of gutter area of day canvas at top and bottom
@property (retain) UIColor* dayGutterBackgroundColor;
/// property holding color of separator line for full hours
@property (retain) UIColor* dayFullHourSeparatorColor;
/// property holding color of separator line for half hours
@property (retain) UIColor* dayHalfHourSeparatorColor;
/// property holding color of hour label for full hours
@property (retain) UIColor* dayFullHourLabelColor;
/// property holding font of hour label for full hours
@property (retain) UIFont* dayFullHourLabelFont;
/// property holding color of hour label for full hours when highlighted
@property (retain) UIColor* dayFullHourLabelHighlightColor;
/// property holding backgroundcolor of hour dayview
@property (retain) UIColor* fulldayBackground;

@property (retain) NSString* CalendarDayViewDayTextLabelStyle ;
@property (retain) NSString* CalendarDayViewDayTextLabelCurrentDayStyle ;
@property (retain) NSString* CalendarDayViewFullHourFontStyle ;
@property (retain) NSString* CalendarDayViewDayNavigationArrowsStyle ;
@property (retain) NSString* CalendarDayViewCanvasStyle ;
@property (retain) NSString* CalendarDayViewCanvasFullHourLineStyle;
@property (retain) NSString* CalendarDayViewCanvasHalfHourLineStyle ;
@property (retain) NSString* CalendarDayViewCanvasHourLabelColorStyle;
@property (retain) NSString* CalendarDayViewCanvasHourLabelHighlightColorStyle ;
@property (retain) NSString* CalendarDayViewGutterStyle ;
@property (retain) NSString* CalendarDayViewHourIndicatorColorStyle ;
@property (retain) NSString* CalendarDayViewHourKnobIndicatorStyle ;
@property (retain) NSString* CalendarDayViewFullDayBackgroundStyle;

-(void)doMAFStyling;


@end
