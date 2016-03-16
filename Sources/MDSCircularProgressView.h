//
//  MDSCircleProgressView
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface MDSCircularProgressView : UIView

@property (nonatomic) IBInspectable double progress;
@property (nonatomic) IBInspectable CGFloat filledLineWidth;
@property (nonatomic) IBInspectable CGFloat emptyLineWidth;

- (void)setProgress:(double)progress animated:(BOOL)animated;

@end
