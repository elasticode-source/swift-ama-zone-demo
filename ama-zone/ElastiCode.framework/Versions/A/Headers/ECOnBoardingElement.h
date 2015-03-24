//
//  ECOnBoardingElement.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 2/27/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ElastiCode.h"

#define kMinimumFontSize 14.0

@interface ECOnBoardingElement : NSObject

@property (nonatomic,strong) NSString* elementName;

-(instancetype) initWithName:(NSString*) name;

+(NSUInteger) _numberOfScreens:(NSArray*) countPerArray;

+(CGRect) getRectFromDictionary:(NSDictionary*) dict;

+(CGFloat) getOffsetYRatioForDeviceType;
+(CGFloat) getXRatioForDeviceType;
@end
