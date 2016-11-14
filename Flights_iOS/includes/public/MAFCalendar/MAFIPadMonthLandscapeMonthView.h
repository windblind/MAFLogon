//
//  MAFIPadMonthLandscapeMonthView.h
//  MAFCalendar
//
//  Created by Roettig, Marc (external) on 4/24/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFAppointmentView.h"
#import "MAFIpadMainMonthView.h"
@class MAFIPadMonthLandscapeMonthView;
@class MAFIPadMonthContainer;
typedef struct
{
    int quarter;
    CGPoint point;
} MAFAppointmentViewMoveContext;

@protocol MAFIPadMonthLandscapeMonthViewDelegate
@optional
-(BOOL)monthView:(MAFIPadMonthLandscapeMonthView*)monthView willBeginDrag:(MAFAppointmentView*)view;
-(void)monthView:(MAFIPadMonthLandscapeMonthView*)monthView didBeginDrag:(MAFAppointmentView*)view;
-(void)monthView:(MAFIPadMonthLandscapeMonthView*)monthView isDragging:(MAFAppointmentView*)view withContext:(MAFAppointmentViewMoveContext)context;
-(void)monthView:(MAFIPadMonthLandscapeMonthView*)monthView didEndDrag:(MAFAppointmentView*)view;
-(void)monthView:(MAFIPadMonthLandscapeMonthView*)monthView didBeginDraggingWith:(MAFAppointmentView*)view;
-(void)monthView:(MAFIPadMonthLandscapeMonthView*)monthView didBeginResizing:(MAFAppointmentView*)view;
-(void)monthView:(MAFIPadMonthLandscapeMonthView*)monthView isResizing:(MAFAppointmentView*)view withContext:(MAFAppointmentViewMoveContext)context;
-(void)monthView:(MAFIPadMonthLandscapeMonthView*)monthView didEndResizing:(MAFAppointmentView*)view;
@end

@interface MAFIPadMonthLandscapeMonthView : UIScrollView<MAFAppointmentViewDelegate,UIGestureRecognizerDelegate>
{
@private
    NSString* lastAppViewID;
    NSMutableArray* appointments;
    NSArray* apps;
    UITapGestureRecognizer* tapRecognizer;
    UISwipeGestureRecognizer* leftSwipeRecognizer;
    UISwipeGestureRecognizer* rightSwipeRecognizer;
}
@property (assign,nonatomic) UIScrollView* container;
@property (assign, nonatomic) MAFIpadMainMonthView* parent;
@property (assign, nonatomic) NSObject<MAFIPadMonthLandscapeMonthViewDelegate>* monthViewDelegate;


-(void)updateTimeMarker:(float)y;
-(void)reloadCalendarData;
-(void)placeAppointmentAtDay:(int)dayIdx atWeek:(int)startWeek withDuration:(int)weeks withTitle:(NSString*)title andLocation:(NSString*)location;
@end
