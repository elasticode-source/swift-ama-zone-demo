//
//  ECOnBoardingButtonElement.h
//  ElastiCode
//
//  Created by Tomer Shkolnik on 2/27/15.
//  Copyright (c) 2015 Elasticode. All rights reserved.
//

#import "ECOnBoardingElement.h"

/**
 * Call to action types
 */
typedef NS_ENUM(NSInteger, CTAButtonType)
{
    /**
     *  Custom button, allow you to customize the look of the button
     */
    CTAButtonType_custom = 0,
    /**
     *  Facebook login button with image and text.\n
     *  @see CTAButtonType_noText_facebook to use custom text
     */
    CTAButtonType_withText_facebook = 1,
    /**
     *  Google login button with image and text.\n
     *  @see CTAButtonType_noText_google to use custom text
     */
    CTAButtonType_withText_google = 2,
    /**
     *  Linkedin login button with image and text.\n
     *  @see CTAButtonType_noText_linkedin to use custom text
     */
    CTAButtonType_withText_linkedin = 3,
    /**
     *  Twitter login button with image and text.\n
     *  @see CTAButtonType_noText_twitter to use custom text
     */
    CTAButtonType_withText_twitter = 4,
    
    /**
     *  Facebook login button with image.\n
     *  Use custom properties to define the text look
     */
    CTAButtonType_noText_facebook = 5,
    /**
     *  Google login button with image.\n
     *  Use custom properties to define the text look
     */
    CTAButtonType_noText_google = 6,
    /**
     *  Linkedin login button with image.\n
     *  Use custom properties to define the text look
     */
    CTAButtonType_noText_linkedin = 7,
    /**
     *  Twitter login button with image.\n
     *  Use custom properties to define the text look
     */
    CTAButtonType_noText_twitter = 8
};
#define CTAButtonType_noText 5 // anything include and above it without text



/**
 *  On borading button element
 */
@class ECOnBoardingAction;
@interface ECOnBoardingButtonElement : ECOnBoardingElement

/** Show or hide the button, if YES button will appear */
@property (nonatomic,assign) BOOL show;
/** Text to be shown on button label. @note Not available in CTAButtonType_withText types */
@property (nonatomic,strong) NSString* text;
/** Text font size. @note Not available in CTAButtonType_withText types */
@property (nonatomic,assign) NSUInteger fontSize;
/** Text font name. @note Not available in CTAButtonType_withText types*/
@property (nonatomic,strong) NSString* fontName;
/** Text color. @note Not available in CTAButtonType_withText types */
@property (nonatomic,strong) UIColor* textColor;
/** Button background color. @note Only available in CTAButtonType_custom */
@property (nonatomic,strong) UIColor* backgroundColor;
/** Button border color. @note Only available in CTAButtonType_custom */
@property (nonatomic,strong) UIColor* borderColor;
/** Button border width. @note Only available in CTAButtonType_custom */
@property (nonatomic,assign) NSInteger borderWidth;
/** Button use round corners. @note Only available in CTAButtonType_custom */
@property (nonatomic,assign) BOOL useRoundCorners;
/** Button text alignment */
@property (nonatomic,assign) NSTextAlignment textAlignment;
/**
 *  Button type
 *  @see CTAButtonType for options
 */
@property (nonatomic,assign) CTAButtonType type;

/**
 *  Action block for this button
 */
@property (nonatomic,strong) ECOnBoardingAction* actionObject;

// Inner helpers:
@property (nonatomic,strong, readonly) NSString* imageName;
-(UIButton*) buttonFromDictionary:(NSDictionary*) buttons;
+(NSArray*) updateServerAboutElements:(NSArray*) elements group:(int) group;
+(void) updateServerAboutActions:(NSDictionary*) actionObjects elementsData:(NSArray*) elementsData;
+(NSMutableArray*) getElementsWithName:(NSString*) elementName;
-(NSString*) getTextAlignment;
-(void) setTextAlignmentString:(NSString*)textAlignmentString;


@end
