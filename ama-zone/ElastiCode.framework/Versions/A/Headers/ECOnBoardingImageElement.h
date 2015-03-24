//
//  ECOnBoardingImageElement.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 2/27/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import "ECOnBoardingElement.h"

/**
 *  On boarding image element
 */
@interface ECOnBoardingImageElement : ECOnBoardingElement



@property (nonatomic,strong, readonly) NSArray* imageNameForDevices;

/**
 *  Set image name for each device type.
 *  In case you dont want to show image use @"" - empty string
 *
 *  @param imageNameFor4  Image name for iPhone 4/4S
 *  @param imageNameFor5  Image name for iPhone 5/5S/5C
 *  @param imageNameFor6  Image name for iPhone 6
 *  @param imageNameFor6p Image name for iPhone 6 Plus
 */
-(void) setImageNameForIPhone4:(NSString *)imageNameFor4
                    forIPhone5:(NSString *)imageNameFor5
                    forIPhone6:(NSString *)imageNameFor6
                forIPhone6Plus:(NSString *)imageNameFor6p;

// Inner methods
-(UIImageView*) imageViewFromDictionary:(NSDictionary*) images;
/**
 *  Helper property, setting image with that property will not update server about it.
 *  @b Use: setImageNameForIPhone4:forIPhone5:forIPhone6:forIPhone6Plus: instead
 */
@property (nonatomic,strong) UIImage* image;
+(void) updateServerAboutElements:(NSArray*) elements group:(int) group;
+(NSMutableArray*) getElementsWithName:(NSString*) elementName;
@end
