//
//  ECOnBoardingScreenTemplate.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 2/11/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import "ECOnBoardingScreenTemplate.h"

@interface ECOnBoardingScreenTemplate11 : ECOnBoardingScreenTemplate

// CTA buttons
@property (nonatomic,strong) ECOnBoardingButtonElement *ctaButton;
@property (nonatomic,strong) ECOnBoardingButtonElement *ctaButton2;

// Labels
@property (nonatomic, strong) ECOnBoardingLabelElement* label;
@property (nonatomic, strong) ECOnBoardingLabelElement* label2;

/** Screen background image */
@property (nonatomic,strong) ECOnBoardingImageElement* image;


@end
