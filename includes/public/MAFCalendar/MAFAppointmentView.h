//
//  MAFAppointmentView.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 3/26/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "MAFDraggableView.h"
#import "MAFAppointmentProtocol.h"
#import "MAFCalendarView.h"
#import "MAFAppointmentViewDelegate.h"



/**
 @brief Struct for defining a grid for MAFAppointmentViews.
 */
typedef struct
{
    /// min. x coordinate
    float xMin;
    /// max. x coordinate
    float xMax;
    /// min. y coordinate
    float yMin;
    /// max. y coordinate
    float yMax;
    /// initial offset in x dimension
    float offsetX;
    /// initial offset in y dimension
    float offsetY;
    /// grid line distance in x dimension
    float deltaX;
    /// grid line distance in y dimension
    float deltaY;
} MAFAppointmentViewGrid;

@class MAFAppointmentView;
@class MAFAppointmentHandleView;


/**
 @class MAFAppointmentView
 
 @brief View rendering appointments in day and week view.
 
 @author Marc Roettig (c5169253)
 */
@interface MAFAppointmentView : MAFDraggableView<UIGestureRecognizerDelegate,MAFDraggableViewDelegate,UIGestureRecognizerDelegate>
{        
    @private
        UIView* whiteLine;
        MAFCalendarView* parent;
        UIFont* titleFont;
        UIFont* locationFont;
        UIView* container;
        UILabel* lblTitle;
        UILabel* lblLocation;
        BOOL handlesVisible;
        MAFAppointmentHandleView*  topHandle;
        MAFAppointmentHandleView*  bottomHandle;
        NSTimer* lastPositionTimer; 
        NSInteger speed;
        CGRect lastFrame;
        NSInteger xGridIdx; 
        NSInteger yGridIdx;
}

-(id)initWithFrame:(CGRect)frame andParent:(MAFCalendarView*)parent_;

/**
 Helper method to create an empty appointment
*/
+ (id<MAFAppointmentProtocol>) createDummyAppointment;
/**
 Helper method to create an empty appointment with title
 @param title
 */
+ (id<MAFAppointmentProtocol>) createDummyAppointmentWithTitle:(NSString*)title;

/**
 Snaps appointment view origin to nearest defined grid point.
*/
- (void) snapToGrid;
/**
 Snaps appointment view x-coordinate to nearest defined grid point.
 */
- (void) snapToGridX;
/**
 Snaps appointment view y-coordinate to nearest defined grid point.
 */
- (void) snapToGridY;
- (void) updateLastPosition:(id)sender;
/**
 Returns a (quite) unique string representation of a appointment.
 
 @return string id
 */
- (NSString*) getID;

/**
 Turns on resize handles.
*/
- (void) showHandles;

/**
 Turns off resize handles.
*/
- (void) hideHandles;

/**
 Resets the grid dimensions.
 
 @param grid 
*/
- (void) setGridDefinition:(MAFAppointmentViewGrid)grid;
- (void) setClientView:(UIView*)view;

/**
 Turns on drag shadows.
*/
- (void) showShadows;

/**
 Turns off drag shadows.
*/
- (void) hideShadows;
- (void) hideLocation;
-(void)doMAFStyling;


@property (assign,nonatomic) BOOL appointmentShadowController;

/// property holding current grid index in x dimension
@property (assign,readonly) NSInteger xGridIdx;
/// property holding current grid index in y dimension
@property (assign,readonly) NSInteger yGridIdx;
/// property holding appointment to be displayed
@property (retain,nonatomic) NSObject<MAFAppointmentProtocol>* appointment;
/// property holding the shadow on/off flag
@property (assign,readwrite) BOOL shodowController;
/// property holding the delegate
@property (assign,nonatomic) NSObject<MAFAppointmentViewDelegate>* appointmentDelegate;
/// property holding grid offset X value
@property (assign,nonatomic) float offsetX;
/// property holding grid offset Y value
@property (assign,nonatomic) float offsetY;
/// property holding grid deltaX value
@property (assign,nonatomic) float deltaX;
/// property holding grid deltaY value
@property (assign,nonatomic) float deltaY;
/// property holding grid max y dimension value
@property (assign,nonatomic) float yMax;
/// property holding grid min y dimension value
@property (assign,nonatomic) float yMin;
/// property holding grid max x dimension value
@property (assign,nonatomic) float xMax;
/// property holding grid min x dimension value
@property (assign,nonatomic) float xMin;
/// property holding flag whether view shall snap to grid in x dimension after dragging ended
@property (assign,nonatomic) BOOL  snapToXGridAtEnd;
/// property holding flag whether view shall snap to grid in y dimension after dragging ended
@property (assign,nonatomic) BOOL  snapToYGridAtEnd;
/// property holding flag whether view shall listen for "throw away to delete" gesture
@property (assign,nonatomic) BOOL canDelete;
/// property holding title color
@property (retain,nonatomic) UIColor* titleColor;
/// property holding location color
@property (retain,nonatomic) UIColor* locationColor;
/// property holding background color
@property (retain,nonatomic) UIColor* color;
/// property holding border color
@property (retain,nonatomic) UIColor* borderColor;
/// property holding invitation background color
@property (retain,nonatomic) UIColor* invitationColor;
/// property holding invitation border color
@property (retain,nonatomic) UIColor* invitationBorderColor;
/// property holding flag whether labels shall use small fonts (used in small week view)
@property (assign,nonatomic) BOOL useSmallFonts;

@property (retain,nonatomic) NSString* CalendarAppointmentViewStyle ;
@property (retain,nonatomic) NSString* CalendarAppointmentViewInvitationStyle ;
@property (retain,nonatomic) NSString* CalendarAppointmentViewLocationLabelStyle ;
@property (retain,nonatomic) NSString* CalendarAppointmentViewTitleLabelStyle ;

@end
