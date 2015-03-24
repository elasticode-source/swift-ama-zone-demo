//
//  OnboardingViewController.h
//  Onboard
//
//  Created by Mike on 8/17/14.
//  Copyright (c) 2014 Mike Amaral. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ECOnBoardingImageElement;
@interface ECOnboardingViewController : UIViewController <UIPageViewControllerDataSource, UIPageViewControllerDelegate, UIScrollViewDelegate>

/**
 *  Fade page control on last page.
 *  If YES page control will be hidden
 */
@property (nonatomic) BOOL fadePageControlOnLastPage;

// Page Control
@property (nonatomic) BOOL hidePageControl;
@property (nonatomic, strong) UIPageControl *pageControl;
/**
 *  Create an onboard with template screens,
 *  and a completion handler that will be attached to the skip buttons
 */
+ (instancetype)onboardWithTemplateScreens:(NSArray *)screens completionHandler:(dispatch_block_t) completionBlock;
- (instancetype)initWithTemplateScreens:(NSArray *)screens completionHandler:(dispatch_block_t) completionBlock;

////////////////////////////////////////////////////////////////////

/**
 *  Page control bottom padding
 */
@property (nonatomic) CGFloat pageControlBottomPadding;

////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
// Delegate methods for internal use.
- (void)moveNextPage;
- (void)movePreviousPage;
- (void)setCurrentPage:(UIViewController *)currentPage;
- (void)setNextPage:(UIViewController *)nextPage;
////////////////////////////////////////////////////////////////////

@end
