//
//  MAFDraggable.h
//  MAFCalendar
//
//  Created by Roettig, Marc (external) on 5/6/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef enum
{
  MAFDraggableViewSingleTapTrigger = 0,
  MAFDraggableViewDoubleTapTrigger,  
  MAFDraggableViewLongPressTrigger  
} MAFDraggableViewTrigger;

@protocol MAFDraggableViewDelegate;

typedef struct 
{
    CGPoint point;
    CGPoint lastPoint;
} MAFDraggableViewContext;


@interface MAFDraggableView : UIView
{
    @public
        UIGestureRecognizer* recognizer;
    @protected
        CGPoint point;
        CGPoint lastPoint;
        CGPoint dragPoint;
}

-(id)initWithFrame:(CGRect)frame andTriggerType:(MAFDraggableViewTrigger)triggerType;
-(id)initWithFrame:(CGRect)frame andLongPressTriggerWithTime:(float)triggerTime;

-(void)didBeginDrag:(MAFDraggableViewContext)context;
-(BOOL)willDrag:(MAFDraggableViewContext)context;
-(void)isDragging:(MAFDraggableViewContext)context;
-(void)didEndDrag:(MAFDraggableViewContext)context;
-(void)yieldRecognizer:(UIGestureRecognizer*)recognizer_ fromOwner:(NSObject*)owner withBoundAction:(SEL)selector;

@property (assign,nonatomic) NSObject<MAFDraggableViewDelegate>* delegate;
@property (assign,nonatomic) BOOL fixX;
@property (assign,nonatomic) BOOL fixY;

@property (assign,nonatomic) CGPoint lastPoint;
@property (assign,nonatomic) CGPoint dragPoint;
@property (assign,nonatomic) CGPoint point;

@property (assign,nonatomic) BOOL fixed;

@end

@protocol MAFDraggableViewDelegate

@optional
-(void)draggableView:(MAFDraggableView*)view didBeginDrag:(MAFDraggableViewContext)context;
-(BOOL)draggableView:(MAFDraggableView*)view willDrag:(MAFDraggableViewContext)context;
-(void)draggableView:(MAFDraggableView*)view isDragging:(MAFDraggableViewContext)context;
-(void)draggableView:(MAFDraggableView*)view didEndDrag:(MAFDraggableViewContext)context;

@end
