//
//  ECOnBoardingScreenTemplate.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 2/11/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import "ECOnBoardingScreenTemplate.h"

@interface ECOnBoardingScreenTemplate1 : ECOnBoardingScreenTemplate

/**
 *  Call to action button element
 */
@property (nonatomic, strong) ECOnBoardingButtonElement *ctaButton;

// Label
@property (nonatomic, strong) ECOnBoardingLabelElement* label;

// Image
@property (nonatomic, strong) ECOnBoardingImageElement* image;

// Background
@property (nonatomic, strong) UIColor* backgroundColor;

@end
