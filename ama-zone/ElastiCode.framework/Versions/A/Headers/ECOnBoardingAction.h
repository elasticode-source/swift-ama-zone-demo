//
//  ECOnBoardingAction.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 3/23/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, ECActionType)
{
    ECActionType_noop = 0,
    ECActionType_nextScreen = 1,
    ECActionType_previousScreen = 2,
    ECActionType_endOnBoarding = 3,
};

@interface ECOnBoardingAction : NSObject
@property (strong, nonatomic) NSString* name;
@property (strong, nonatomic) dispatch_block_t action;

-(NSString*) getSelectorStringForButton:(NSInteger) buttonIndex;

+ (ECOnBoardingAction*)createWithName:(NSString*) name action:(dispatch_block_t) action;
+ (ECOnBoardingAction*)createWithType:(ECActionType) type;
@end
