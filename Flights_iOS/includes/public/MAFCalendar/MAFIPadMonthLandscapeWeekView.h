
#import <UIKit/UIKit.h>
#import "MAFIPadMonthLandscapeMonthView.h"
#import "MAFIPadMonthContainer.h"
@interface MAFIPadMonthLandscapeWeekView : UIView<MAFIPadMonthLandscapeMonthViewDelegate>

@property (assign, nonatomic) MAFIpadMainMonthView* parent;

-(void)updateTimeMarker:(float)y;
-(id) initWithFrame:(CGRect)frame;
@end
