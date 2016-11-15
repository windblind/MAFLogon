//
//  MAFAppointmentViewDelegate.h
//  MAFCalendar
//
//  Created by Balogh, Istvan on 5/17/13.
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @brief Context information for dragging a MAFAppointment view.
 */
typedef struct
{
    /// current drag point
    CGPoint point;
    /// last drag point
    CGPoint lastPoint;
} MAFAppointmentViewContext;

/**
 @brief Delegate of MAFAppointmentView handling dragging/resizing.
 */
@protocol MAFAppointmentViewDelegate <NSObject>

@optional

/**
 Called when view will begin dragging (returning false will prevent dragging by user).
 
 @param view the appointment view to be dragged
 @param context drag context
 
 @return drag allowed
 */
-(BOOL)appointmentView:(MAFAppointmentView*)view willBeginDrag:(MAFAppointmentViewContext)context;

/**
 Called when view did begin dragging.
 
 @param view the appointment view to be dragged
 @param context drag context
 
 */
-(void)appointmentView:(MAFAppointmentView*)view didBeginDrag:(MAFAppointmentViewContext)context;

/**
 Called when view is currently dragging.
 
 @param view the appointment view to be dragged
 @param context drag context
 
 */
-(void)appointmentView:(MAFAppointmentView*)view isDragging:(MAFAppointmentViewContext)context;

/**
 Called when view did end dragging.
 
 @param view the appointment view to be dragged
 @param context drag context
 
 */
-(void)appointmentView:(MAFAppointmentView*)view didEndDrag:(MAFAppointmentViewContext)context;

/**
 Called when view will begin resizing (returning false will prevent resizing by user).
 
 @param view the appointment view to be resized
 @param context drag context
 
 @return resize allowed
 */
-(BOOL)appointmentView:(MAFAppointmentView*)view willBeginResizing:(MAFAppointmentViewContext)context;

/**
 Called when view did begin resizing.
 
 @param view the appointment view to be resized
 @param context drag context
 */
-(void)appointmentView:(MAFAppointmentView*)view didBeginResizing:(MAFAppointmentViewContext)context;

/**
 Called when view is currently resizing.
 
 @param view the appointment view to be resized
 @param context drag context
 */
-(void)appointmentView:(MAFAppointmentView*)view isResizing:(MAFAppointmentViewContext)context;

/**
 Called when view did end resizing.
 
 @param view the appointment view to be resized
 @param context drag context
 */
-(void)appointmentView:(MAFAppointmentView*)view didEndResizing:(MAFAppointmentViewContext)context;

/**
 Called when view did receive single tap event.
 
 @param view the appointment view
 @param context drag context
 */
-(void)appointmentView:(MAFAppointmentView*)view didReceiveSingleTap:(MAFAppointmentViewContext)context;

-(void)appointmentView:(MAFAppointmentView *)view appointmentShadow:(BOOL)shadow appointmentPosition:(CGRect)frame appointmentDetails:(NSObject<MAFAppointmentProtocol>*) appointment;
@end

