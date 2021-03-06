//
//  ECOnBoardingScreenTemplate.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 2/11/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import "ECOnBoardingScreenTemplate.h"

@interface ECOnBoardingScreenTemplate8 : ECOnBoardingScreenTemplate

// CTA buttons
@property (nonatomic,strong) ECOnBoardingButtonElement *ctaButton;

// Labels
@property (nonatomic, strong) ECOnBoardingLabelElement* label;
@property (nonatomic, strong) ECOnBoardingLabelElement* label2;

// Background
@property (nonatomic,strong) UIColor* backgroundColor;

@end
