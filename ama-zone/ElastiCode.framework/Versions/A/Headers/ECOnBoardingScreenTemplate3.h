//
//  ECOnBoardingScreenTemplate.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 2/11/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import "ECOnBoardingScreenTemplate.h"

@interface ECOnBoardingScreenTemplate3 : ECOnBoardingScreenTemplate

// CTA button
@property (nonatomic,strong) ECOnBoardingButtonElement *ctaButton;

// Labels
@property (nonatomic, strong) ECOnBoardingLabelElement* label;
@property (nonatomic, strong) ECOnBoardingLabelElement* label2;
@property (nonatomic, strong) ECOnBoardingLabelElement* label3;

// Image
@property (nonatomic,strong) ECOnBoardingImageElement* image;

// Overlay
@property (nonatomic,strong) UIColor* overlayColor;

// Background
@property (nonatomic,strong) UIColor* backgroundColor;

@end
