//
//  MAFMonthCalendarView.h
//  CalendarControl
//
//  Created by Muehlbauer, Jan (external) on 3/19/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "MAFCalendarView.h"
#import "MAFAppointment.h"
#import "MAFMonthComboCalendarView.h"
#import "MAFMonthCalendarItemView.h"

/**
 @class MAFMonthCalendarView
 
 @brief Calendar view on appointments for one month.
 
 This view class presents all appointments scheduled for a specific month.
 
 @details To initialize the MAFMonthCalendarView use the selector "initWithFrame:".
 Note though that it overrides the width and height of the provided frame to the size that
 fits the month to be displayed.
 
 The width of the view is static while the height depends on the month to be 
 displayed, since the number of weeks varies from month to month between 5 to 6
 weeks. 
 
 @author Jan Muehlbauer (external) Sven Arndt (external) Marc Roettig (external)
 
*/

@protocol MAFMonthCalendarViewDelegate <NSObject>
@optional
/**
 Callback method triggered when user selects a day range within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param firstDay day the first selected day
 @param lastDay day the last selected day
 @paramselectionArray array of the seleted days (MAFMontCalendarItemView)
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectRange:(NSDate*)firstDay lastDay:(NSDate*)lastDay selectionArray:(NSArray*)selectionArray;

/**
 Callback method triggered when user selects a day range within the MAFCalendarView and the selection finished.
 
 @param sender the respective calender view container
 @param firstDay day the first selected day
 @param lastDay day the last selected day
 @param selectionArray array of the seleted days (MAFMontCalendarItemView)
 */
-(void)calendarView:(MAFCalendarView*)sender rangeSelectionCompleted:(NSDate*)firstDay lastDay:(NSDate*)lastDay selectionArray:(NSArray*)selectionArray;


@end

enum MAFDaySelectionBehaviorType : NSUInteger {
    MAFDaySelectionBehaviorNavigationBased = 0,
    MAFDaySelectionBehaviorFirstDay = 1,
};

@interface MAFMonthCalendarView : MAFCalendarView <MAFMonthCalendarItemDelegate>
{
	UIView* viewDays;
    UILabel* monthLabel;
    BOOL isPaging;
    MAFMonthCalendarItemView* currentCalendarItem;
    MAFMonthCalendarItemView* selectedCalendarItem;
    enum MAFDaySelectionBehaviorType defaultSelection;
    /////
    NSMutableArray* m_SelectedCalendarItemArray;
    MAFMonthCalendarItemView* highlightedCalendarItem;
    NSMutableArray* tileCache;
    UIButton* cmdNextMonth;
	UIButton* cmdPreviousMonth;
    UIView* nextTouchArea;
    UIView* prevTouchArea;
}

// property holding the delegate handling day selections within the month view
//@property (assign) id<MAFMonthCalendarViewDelegate> delegate;
@property (retain,nonatomic) UIView* slaveView; 

@property (assign) CGSize calendarItemSize;

//is animation running or not
@property (assign) BOOL isRefreshing;

//apply the setted styles
-(void)doMAFStyling;

// MAF properties

@property (nonatomic,retain) NSArray* monthLabelBackgroundGradientColor;
@property (nonatomic,assign) CGPoint startPoint;
@property (nonatomic,assign) CGPoint endPoint;

@property (nonatomic, assign) enum MAFDaySelectionBehaviorType defaultSelection;
@property (assign,nonatomic) id<MAFMonthCalendarViewDelegate> rangeSelectionDelegate;
@property (nonatomic, retain) UILabel* monthLabel;
@property (nonatomic, retain) UIFont*  monthLabelFont;
@property (nonatomic, retain) UIColor* monthLabelTextColor;
@property (nonatomic, retain) UIColor* monthLabelTextShadowColor;
@property (nonatomic, retain) UIColor* navigationArrowColor;

@property (nonatomic, retain) NSMutableArray* tileCache;
@property (nonatomic, retain) UIFont*  weekDaysFont;
@property (nonatomic, retain) UIColor* weekDaysTextColor;
@property (nonatomic, retain) UIColor* weekDaysShadowColor;

@property (nonatomic, retain) UIButton* cmdNextMonth;
@property (nonatomic, retain) UIButton* cmdPreviousMonth;
@property (nonatomic, retain) UIView* nextTouchArea;
@property (nonatomic, retain) UIView* prevTouchArea;

@property (nonatomic, retain) NSString* CalendarMonthViewMonthTextLabelStyle;
@property (nonatomic, retain) NSString* CalendarMonthViewMonthNavigationArrowsStyle;
@property (nonatomic, retain) NSString*  CalendarMonthViewWeekDayTextLabelStyle;

@property (nonatomic, retain) NSMutableArray* selectedCalendarItemArray;
@property (nonatomic, assign) float lengthOfLongPress;

- (void)rangeSelectionEnabled:(BOOL)enabled;
// !!! Redeclared internally - doublecheck whether it should be exposed - if not, remove
//- (UIImage*)getArrowWithSize:(CGSize)sInner withinBox:(CGSize)sOuter andDirection:(int)dir;
- (void) resizeWithFrame:(CGRect)newframe;
- (void) refreshTiles;
- (NSDate*)getSelectedDay;
- (NSArray*)getSelectedDayArray;
- (void)setSelectedDay:(NSDate*)selectedDay;
- (void)setSelectedRangeFrom:(NSDate*)startDate to:(NSDate*)endDate;


@end
