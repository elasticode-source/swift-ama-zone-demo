//
//  ECOnBoardingScreenTemplate.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 2/11/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ECOnBoardingElements.h"
#import "ECOnBoardingAction.h"
@class ECOnboardingViewController;
@class ECOnBoardingButtonElement;
@class ECOnBoardingSync;

/**
 *  Basic on boarding template object
 */
@interface ECOnBoardingScreenTemplate : UIViewController
{
    NSDictionary* _template;
}

@property (nonatomic, weak) ECOnboardingViewController *delegate;
@property (nonatomic,strong) NSDictionary* templateFormat;

/** Skip button */
@property (nonatomic,strong) ECOnBoardingButtonElement *skipButton;

/**
 *  Get updated screens from server, based on elasticode information
 *
 *  @return Array of screens
 */
+(NSArray*) getScreensFromServer;

/**
 *  Update server about information in the given array of screens, 
 * to be set as default value for this onboarding
 *
 *  @param obSync            on boarding sync object.
 *  @param onBoardingScreens array of on boarding array screens.
 *
 *  @return YES if the on borading sync object managed to sync the screens with server,
 *  NO if something was missing
 */
-(BOOL) updateOBSync:(ECOnBoardingSync*) obSync WithScreens:(NSArray*) onBoardingScreens;

// // // // Inner methods // // // //
-(void) moveToNextScreen;
-(void) moveToPreviousScreen;
-(NSString*) templateName;
- (void)handleSkipButtonPressed;
// // // // // // // // // // // //
@end
