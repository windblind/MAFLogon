//
//  MAFDayDetailNavigation.h
//  CalendarControl
//
//  Created by Alpaslan, Eymen (external) on 4/5/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 @brief Delegate protocol for day view navigation bar.
*/
@protocol MAFDayDetailNavigationDelegate
/**
 Called when transition (either left-to-right or right-to-left) to new day with given date is requested.
*/
-(void)changeDayWithAnimation:(int)lrAnimation toStartDate:(NSDate*)startDate_;
/**
 Triggers display of current time of day inidcator line in day view.
*/
-(void)showCurrentTime:(BOOL)flag;

-(BOOL)willChangeToDay:(NSDate*)day;
@end

/**
 @class MAFDayDetailNavigation
 @brief Navigation bar for day view.
 
 This class provides navigation bar functionality for the day view to change
 between days and also display the date label of the current day.
 
 @author Eymen Alpaslan (external)
*/
@interface MAFDayDetailNavigation : UIView
{
    id <MAFDayDetailNavigationDelegate> navigationDelegate;
    UILabel* dayLabel;
    UILabel* dateLabel;
    int dayCounter;
    UIButton* cmdNextDay;
    UIButton* cmdPreviousDay;
    NSObject* parent;
}

- (id) initWithFrame:(CGRect)frame andParent:(NSObject*)parent;
- (void) refresh;
- (void) changeColorOfTheDay;
- (void) updateDayTitle;

- (void) cmdRefreshDayView;
- (void) cmdNextDay_Tapped;
- (void) cmdPreviousDay_Tapped;


/// property holding the delegate for the navigation bar
@property(nonatomic,retain) id <MAFDayDetailNavigationDelegate> navigationDelegate;
/// property holding flag whether the day view is currently doing a animated transition 
@property(assign,nonatomic) BOOL animationController;



@end
