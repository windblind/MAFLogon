//
//  MAFMonthCalendarItemView.h
//  CalendarControl
//
//  Created by Muehlbauer, Jan (external) on 3/20/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@class MAFMonthCalendarItemView;

/**
 Delegate protocol for class MAFMonthCalendarItemDelegate.
*/
@protocol MAFMonthCalendarItemDelegate <NSObject>

/**
 Callback method to get all the appointment scheduled for the given day
 
 @param day the respective day (as date)
 */

-(NSArray*)getAllAppoitmentForDay:(NSDate*)day;

/**
 Callback method yielding information whether an appointment was scheduled for the given day.
 
 @param sender source item view
 @param day the respective day (as date) 
*/
-(BOOL)monthCalendarItemViewHasAppointment:(MAFMonthCalendarItemView*)sender forDay:(NSDate*)day;

/**
 Callback method called upon item selection by user within the month view.
*/
-(void)monthCalendarItemViewSelected:(MAFMonthCalendarItemView*)sender;

@end

/**
 @class MAFMonthCalendarItemView
 
 @brief View class for day items within the month calendar view.
 
 @author Jan Muehlbauer (external) Sven Arndt (external) Marc Roettig (external)
 
*/
@interface MAFMonthCalendarItemView : UIView
{
    @protected
    UIView* bview;
	UIButton* button;
    NSInteger day;
    BOOL enabled;
    BOOL selected;
    BOOL current;
    BOOL used;
}

@property (retain) UIView* bview;
@property (retain) UIButton* button;

/// property holding information whether this item is currently used (relevant for caching)
@property (assign, getter = isUsed) BOOL used;

@property (assign, getter = isEnabled) BOOL enabled;
/// property holding information whether this item is currently selected
@property (assign, getter = isSelected) BOOL selected;
/// property holding information whether this element represents the current day
@property (assign, getter = isCurrent) BOOL current;
/// property holding the delegate reference to the MAFMonthCalendarItemDelegate
@property (assign) id<MAFMonthCalendarItemDelegate> delegate;

@property (assign) NSInteger itemID;

@property (retain, nonatomic) NSDate* date;

@property (retain) UIFont*  dayFont;
@property (retain) UIColor* dayTextColor;
@property (retain) UIColor* dayBackgroundColor;
@property (retain) UIColor* dayDisabledBackgroundColor;
@property (retain) UIColor* dayBorderColor;

/*
@property (retain) UIColor* selectedDayGradientColor1;
@property (retain) UIColor* selectedDayGradientColor2;
@property (retain) UIColor* selectedDayGradientColor3;
*/
@property (retain) NSMutableArray* selectedDayGradient;

@property (retain) UIColor* selectedDayBorderColor;

//color of the selected cell's text color
@property (retain) UIColor* selectedDayTextColor;
//color of the current day cell's text color
@property (retain) UIColor* currentDayTextColor;


//Shadows
@property (retain) UIColor* dayShadowColor;
@property (retain) UIColor* currentDayShadowColor;
@property (retain) UIColor* selectedDayShadowColor;
@property (retain) UIColor* disabledDayShadowcolor;
@property (retain) UIColor* tileShadowcolor;

@property (retain) UIColor* currentDayColor;
@property (retain) UIColor* currentDayBorderColor;

@property (retain) UIColor* currentSelectedDayColor;
@property (retain) UIColor* currentSelectedDayBorderColor;


@property (retain) UIColor* dayTextGradientColorTop;
@property (retain) UIColor* dayTextGradientColorBottom;

@property (retain) UIColor* dayTextDisabledGradientColorTop;
@property (retain) UIColor* dayTextDisabledGradientColorBottom;
@property (retain) UIColor* dayTextDisabledColor;

@property (retain) NSString* CalendarMonthViewDayTileStyle;
@property (retain) NSString* CalendarMonthViewDayTileSelectedStyle;
@property (retain) NSString* CalendarMonthViewDayTileCurrentStyle;
@property (retain) NSString* CalendarMonthViewDayTileCurrentSelectedStyle;
@property (retain) NSString* CalendarMonthViewDayTileTextImageStyle;
@property (retain) NSString* CalendarMonthViewDayTileDisabledTextImageStyle;


/*
@property (retain) UIColor* selectedDayTextGradientColorTop;
@property (retain) UIColor* selectedDayTextGradientColorBottom;

@property (retain) UIColor* currentSelectedDayTextGradientColorTop;
@property (retain) UIColor* currentSelectedDayTextGradientColorBottom;

@property (retain) UIColor* dayCircleGradientColorTop;
@property (retain) UIColor* dayCircleGradientColorBottom;

@property (retain) UIColor* selectedDayCircleGradientColorTop;
@property (retain) UIColor* selectedDayCircleGradientColorBottom;

@property (retain) UIColor* currentSelectedDayCircleGradientColorTop;
@property (retain) UIColor* currentSelectedDayCircleGradientColorBottom;
*/



- (id) initWithFrame:(CGRect)frame date:(NSDate*)date;
- (void)reinitWithFrame:(CGRect)frame date:(NSDate*)date;
+(NSDateComponents*) ComponentsFromDate:(NSDate*)date;
-(void)doMAFStyling;


@end
