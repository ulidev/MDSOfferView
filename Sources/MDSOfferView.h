//
//  MDSDownloadButton.h
//  DownloadButtonDemo
//
//  Created by YuAo on 3/15/16.
//  Copyright © 2016 YuAo. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

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

- (void)setTitle:(nullable NSString *)title forState:(MDSOfferViewState)state;

- (nullable NSString *)titleForState:(MDSOfferViewState)state;

@property (nonatomic, readonly, nullable) NSString *currentTitle;

@property (nonatomic, readonly) UIButton *actionButton;

@property (nonatomic, copy, nullable) void (^actionHandler)(MDSOfferView *offerView);

@end

NS_ASSUME_NONNULL_END