//
//  MAFLandscapeCalendarView.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 4/11/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import "MAFCalendarView.h"

#define iPad    UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad
#define MAFWeekViewHourBarWidth         (iPad ? 50 : 48)
#define MAFWeekViewDayBarHeight  (iPad ? 84 : 24)   // including 1px bottom margin line
#define MAFWeekViewSepBarHeight   (iPad ? 0 : 5)  
#define MAFWeekViewBoxWidth     (iPad ? 138.8 : 131)
#define MAFWeekViewBoxHeight     (iPad ? 88 : 34)
#define MAFWeekViewOffset        (iPad ? 22 : 50)
#define MAFWeekViewWeekWidth   MAFWeekViewBoxWidth*7
#define MAFWeekViewWeekHeight  (iPad ? MAFWeekViewBoxHeight*24+7*MAFWeekViewOffset : MAFWeekViewBoxHeight*24+2*MAFWeekViewOffset)

typedef enum
{
    MAFLandscapeCalendarViewSegmentTop = 0,
    MAFLandscapeCalendarViewSegmentMid,
    MAFLandscapeCalendarViewSegmentBottom
} MAFLandscapeCalendarViewSegment;


/**
 @class MAFLandscapeCalendarView
 
 @brief Week-wise view on appointments (week view).
 
 This class displays appointments scheduled for a week in a rectangular grid view. It has a top day header area displaying day 
 labels for the columns (MAFLandscapeCalendarDayView), a hour area at the left hand side (MAFLandscapeCalendarHourView)
 and a week canvas area displaying the appointments (MAFLandscapeCalendarWeekView).
 
 @author Marc Roettig (external)
 
*/
@interface MAFLandscapeCalendarView : MAFCalendarView

/**
 Designated initializer.
 
 @param frame the frame outlining the view
*/
-(id)initWithFrame:(CGRect)frame;

/**
  *  @brief       Sets the weekdays
  *  @param      The date from where the weekdays will be filled
 */
-(void)setStartDate:(NSDate *)startDate_;

/**
 Trigger display of the week.
 */
-(void)reloadView;

/**
 Trigger display of next week.
*/
-(void)showNextWeek;
/**
 Trigger display of previous week.
 */
-(void)showPreviousWeek;
/**
 Tells whether the current day is displayed in week view.
 */
-(BOOL)showsCurrentDay;
/**
 *  @brief       Triggers focusing(scroll to view) of top, mid or bottom area of week view.
 *  @param      segment The segment the focul will be on.
 */
-(void)focusOnSegment:(MAFLandscapeCalendarViewSegment)segment;
/**
 *  @brief      Places an appointment at given coordinates within month view.
 *  @param      dayIdx Day of week with index
 *  @param      startWeek The week the appointmnet will be placed in.
 *  @param      weeks  The duration of the appointment
 *  @param      title  The title for the appointment
 *  @param      location The location for the appointment
 */
-(void)placeAppointmentAtDay:(int)dayIdx atHour:(int)startHour withDuration:(int)hours withTitle:(NSString*)title andLocation:(NSString*)location;

/**
 TODO
 */
-(int)calculateNumberOfRowsForTheWeek:(NSArray*)weekdays withAllDayApps:(NSArray*)alldayApps;


@property (assign) BOOL isReadOnly;
//apply the setted styles
-(void)doMAFStyling;
/// property holding array of dates (NSDate) for week days to be displayed in the week view
@property (retain,nonatomic) NSMutableArray* weekDays;
/// property holding array of strings to be placed at hour labels (beginning from bottom)
@property (retain,nonatomic) NSArray* hourLabels;
/// property holding flag whether current hour indicator line shall be displayed
@property (assign) BOOL showHourIndicator;
/// property holding font of week day label
@property (retain) UIFont*  weekdayLabelFont;
/// property holding font of week day number (within month) label
@property (retain) UIFont*  weekdayNumberLabelFont;
/// property holding background color of week day
@property (retain) UIColor* weekdayBackgroundColor;
/// property holding background color of week day (current day)
@property (retain) UIColor* currentWeekDayBackgroundColor;
/// property holding text color of week day label
@property (retain) UIColor* weekdayLabelTextColor;
/// property holding text color of week day number (within month) label
@property (retain) UIColor* weekdayNumberLabelTextColor;
/// property holding text color of week day label (current day)
@property (retain) UIColor* currentWeekDayLabelTextColor;
/// property holding text color of week day number (within month) label (current day)
@property (retain) UIColor* currentWeekDayNumberLabelTextColor;
/// property holding background color of week canvas
@property (retain) UIColor* weekBackgroundColor;
/// property holding background color of week gutter area (top/bottom)
@property (retain) UIColor* weekGutterBackgroundColor;
/// property holding stroke color of full hour separator line
@property (retain) UIColor* weekFullHourSeparatorColor;
/// property holding stroke color of half hour separator line
@property (retain) UIColor* weekHalfHourSeparatorColor;
/// property holding color of current hour indicator line
@property (retain) UIColor* hourIndicatorColor;
/// property holding color of current hour lefthand side knob view
@property (retain) UIColor* hourIndicatorKnobColor;
/// property holding border color of current hour lefthand side knob view
@property (retain) UIColor* hourIndicatorKnobBorderColor;
/// property holding font of full hour label
@property (retain) UIFont* hourLabelFont;
/// property holding color of full hour label
@property (retain) UIColor* hourLabelColor;
/// property holding the background color of the HourView
@property (retain) UIColor* hourviewBackground;
/// property holding font of highlighted full hour label
@property (retain) UIColor* hourLabelHighlightColor;
/// property holding color of hour period label
@property (retain) UIColor* hourPeriodLabelColor;
/// propert holding border color of view
@property (retain,nonatomic) UIColor* borderColor;
// property holding the backgroundcolor of the topHeaderView
@property(retain,nonatomic) UIColor* topHeaderBackground;
//property holding the fontColor of the TopHeader's text
@property(retain,nonatomic) UIColor* topHeaderFontColor;
//property holding the fontfamily and size of the topheader's font
@property (retain,nonatomic) UIFont* topHeaderFont;
@property(retain) UIColor* verticalShadowStart;
@property(retain) UIColor* verticalShadowStop;
@property(retain) UIColor* vertical2ShadowStart;
@property(retain) UIColor* vertical2ShadowStop;
@property(retain) UIColor* vertical3ShadowStart;
@property(retain) UIColor* vertical3ShadowStop;
@property(retain) UIColor* horizontalShadowStart;
@property(retain) UIColor* horizontalShadowStop;



@property(retain,nonatomic) NSString* CalendarWeekViewHorizontalGradientStyle;
@property(retain,nonatomic) NSString* CalendarWeekViewVerticalGradientStyle;
@property(retain,nonatomic) NSString* CalendarWeekViewLowerHeaderVerticalGradientStyle;
@property(retain,nonatomic) NSString* CalendarWeekViewTopHeaderVerticalGradientStyle;

@property (retain,nonatomic) NSString*  CalendarWeekViewTopHeaderStyle ;
@property (retain,nonatomic) NSString*  CalendarWeekViewWeekdayNumberTextLabelStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewCurrentWeekdayNumberTextLabelStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewWeekdayTextLabelStyle;
@property (retain,nonatomic) NSString* CalendarWeekViewCurrentWeekdayTextLabelStyle;
@property (retain,nonatomic) NSString* CalendarWeekViewFullHourSeparatorColorStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewHalfHourSeparatorColorStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewGutterStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewCanvasStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewHourIndicatorColorStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewHourLabelFontStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewHourLabelHighlightColorStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewHourPeriodLabelColorStyle;
@property (retain,nonatomic) NSString* CalendarWeekViewHourKnobIndicatorStyle ;
@property (retain,nonatomic) NSString* CalendarWeekViewHourBackgroundStyle;

@end
