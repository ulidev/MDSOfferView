//
//  MDSDownloadButton.h
//  DownloadButtonDemo
//
//  Created by YuAo on 3/15/16.
//  Copyright © 2016 YuAo. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, MDSOfferViewState) {
    MDSOfferViewStateNormal,
    MDSOfferViewStatePendingDownload,
    MDSOfferViewStateDownloading,
    MDSOfferViewStateDownloaded
};

IB_DESIGNABLE
@interface MDSOfferView : UIView

@property (nonatomic) MDSOfferViewState state;

@property (nonatomic) double progress;

- (void)setProgress:(double)progress animated:(BOOL)animated;

@property (nonatomic) BOOL enabled;


- (void)setTitle:(NSString *)title forState:(MDSOfferViewState)state;

- (NSString *)titleForState:(MDSOfferViewState)state;

@property (nonatomic,copy,readonly) NSString *currentTitle;


@property (nonatomic,readonly) UIButton *actionButton;

- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;

- (void)removeTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;

@end
