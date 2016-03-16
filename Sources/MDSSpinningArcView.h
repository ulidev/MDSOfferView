//
//  MDSCirclePendingView
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface MDSSpinningArcView : UIView

@property (nonatomic) IBInspectable CGFloat lineWidth;
@property (nonatomic) IBInspectable CGFloat emptyAngle;
@property (nonatomic) IBInspectable NSTimeInterval spinDuration;

@property (nonatomic,readonly) BOOL isSpinning;

- (void)startSpinning;
- (void)stopSpinning;

@end
