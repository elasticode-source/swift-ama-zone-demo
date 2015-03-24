//
//  ElastiCode.h
//  ElastiCode
//
//  Created by Dan Iosub on 10/15/13.
//  Copyright (c) 2013 elasticode. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ECOnboardingViewController;
//Local notifications
#define ELASTICODE_SESSION_STARTED @"ELASTICODE_SESSION_INITIALIZE_SUCCESS"
#define ELASTICODE_SESSION_RESTARTED @"ELASTICODE_SESSION_RESTARTED_SUCCESS"


enum logLevel
{
    elastiCodeLogLevelNone,
    elastiCodeLogLevelErrors,
    elastiCodeLogLevelDetailed,
    elastiCodeLogLevelVerbose
};

typedef enum dObjType
{
    ElastiCodeDObjType_none = 0,
    ElastiCodeDObjType_bool = 1,
    ElastiCodeDObjType_int = 2,
    ElastiCodeDObjType_double = 3,
    ElastiCodeDObjType_string = 4,
    ElastiCodeDObjType_color = 7,
    ElastiCodeDObjType_arrayOfBool = 11,
    ElastiCodeDObjType_arrayOfInt = 12,
    ElastiCodeDObjType_arrayOfDouble = 13,
    ElastiCodeDObjType_arrayOfString = 14,
    ElastiCodeDObjType_arrayOfColor = 17,
} ElastiCodeDObjType;

typedef enum listOfOptionsType
{
    ElastiCodeListOfOptionsType_none = 0,
    ElastiCodeListOfOptionsType_string = 4,
    ElastiCodeListOfOptionsType_image = 5,
    ElastiCodeListOfOptionsType_action = 6,
    ElastiCodeListOfOptionsType_arrayOfInt = 12,
    ElastiCodeListOfOptionsType_arrayOfString = 14,
    ElastiCodeListOfOptionsType_arrayOfImage = 15,
    ElastiCodeListOfOptionsType_arrayOfAction = 16
} ElastiCodeListOfOptionsType;

@interface ElastiCode : NSObject



/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Init
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *  This method serves as the entry point to ElastiCode. It must be
 *  called in the scope of applicationDidFinishLaunching.
 *
 * @code
 *  - (void)applicationDidFinishLaunching:(UIApplication *)application
 {
 //ElastiCode startup method
 [ElastiCode startSession:@"YOUR_ELASTICODE_API_KEY"];
 // ....
 }
 * @endcode
 *
 * @param elastiCodeApiKey The API key for this project.
 */
+(void)startSession:(NSString*)elastiCodeApiKey;


+ (void)startSession:(NSString*)elastiCodeApiKey onBoardingVersion:(NSString*) onBoardingVersion;

/**
 *  Set the connection timeout for the ElastiCode SDK.
 *  Default value is 20 seconds, in case of slow internet connection.
 *  You can change to any positive number.
 *
 *  @param timeout The new timeout in seconds
 */
+(void)setConnectionTimeout:(NSTimeInterval) timeout;

/**
 *  Set the image download timeout for the ElastiCode SDK.
 *  Default value is 5 seconds, in case of slow internet connection.
 *  You can change to any positive number.
 *
 *  @param timeout The new timeout in seconds
 */
+(void)setImageDownloadTimeout:(NSUInteger) timeout;

/**
 *  When you want to force restart the session,
 *  you can call this method to perform a session restart.
 */
+ (void)restartSession;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Share User Info
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *  Update the SDK with info about the user. Please visit the ElastiCode documentation for more info about supported values in this hashmap.
 *
 *  @param userInfo    Provide the server with more about the user. This info will take into consider when choosing the best state for this case.
 */
+(void)shareUserInfo:(NSDictionary*)userInfo;








/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Define Case
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/**
 *  Define a case and the number of possible states.
 *
 *  @param caseName    The case name
 *  @param numOfStates Number of states for this case.
 *  @param multipleVisits Indicate if this case can become visible more than once
 *
 */
+(void)defineCase:(NSString*)caseName withNumOfStates:(NSInteger)numOfStates;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Define Case
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/**
 *  Define a dynamic object.
 *
 *  @param dObjName The dynamic object name.
 *  @param dObjType The dynamic object type.
 *  @param defaultValue default value that will be used in case of error.
 *
 */
+(void)defineDynamicObject:(NSString*)dObjName type:(ElastiCodeDObjType) dObjType defaultValue:(NSObject*) defaultValue;






/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - State Index For Case
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Get the selected state index of a case.
 *
 *  @param caseName    The case name
 *
 *  @return The selected state index. 0 for default.
 */
+(NSInteger)stateIndexForCase:(NSString*)caseName;


/**
 *  Get the selected state index of a case.
 *
 *  In case you going to use the state index later, use this method, 
 *  and when using index call the visitCase method.
 *
 *  @param caseName    The case name
 *
 *  @return The selected state index. 0 for default.
 */
+(NSInteger)stateIndexWithoutVisitForCase:(NSString*)caseName;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - State Index For Case
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Get the selected value of a dynamic object.
 *
 *  @param dObjName    The dynamic object name
 *
 *  @return NSObject with the selected value, 
 *  nil in case of using before defining a dynamic object or default value in case of error.
 */
+(NSObject*)valueForDynamicObject:(NSString*)dObjName;


/**
 *  Get the selected value of a dynamic object.
 *
 *  In case you going to use the value later, use this method,
 *  and when using the value, call the visitDynamicObject method.
 *
 *  @param dObjName    The dynamic object name
 *
 *  @return NSObject with the selected value,
 *  nil in case of using before defining a dynamic object or default value in case of error.
 */
+(NSObject*)valueWithoutVisitForDynamicObject:(NSString*)dObjName;



/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Visit case
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Signal the SDK when a case becomes visible to the user.
 *
 *  @param caseName    The case name
 */
+(void)visitCase:(NSString*)caseName;





///**
// *  Signal the SDK when a case becomes visible to the user.
// *
// *  @param caseName    The case name
// *  @param visitInfo    Provide the server with more info to consider when choosing the best state for this case. Please visit the ElastiCode iOS documentation for more info about supported values in this array.
// */
//+(void)visitCase:(NSString*)caseName withInfo:(NSArray*)visitInfo;



/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Visit case
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Signal the SDK when a dynamic object becomes visible to the user.
 *
 *  @param dObjName    The dynamic object name
 */
+(void)visitDynamicObject:(NSString*)dObjName;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Event
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Signal the SDK on events, other then cases.
 *
 *  @param eventName    The event name
 */
+(void)event:(NSString*)eventName;

/**
 *  Signal the SDK on events, other then cases.
 *  With attributes relevant to the event
 *  @param eventName The event name
 *  @param attributes The attributes relevant to the event
 */
 +(void)event:(NSString*)eventName attributes:(NSDictionary*) attributes;




/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Goal Reached
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *  Indicate when the goal of the case is reached.
 *
 *  @param caseName The case name
 */
+(void)goalReached:(NSString*)caseName;

/**
 *  Indicate when the goal for the dynamic object is reached.
 *
 *  @param dObjName The dynamic object name
 */
+(void)dynamicObjectGoalReached:(NSString*)dObjName;




/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - On boarding
/////////////////////////////////////////////////////////////////////////////////////////////////////////

+(ECOnboardingViewController*) createOnBoardingWithScreens:(NSArray*) onBoardingScreens
                                               WithVersion:(NSString *)onBoardingVersion
                                         completionHandler:(dispatch_block_t) completionBlock
                                         additionalActions:(NSArray*) additionalActions;
+(void) defineOnBoardingWithVersion:(NSString*) onBoardingVersion templateIndex:(int) templateIndex;
+(int) onBoardingTemplateTypeForVersion:(NSString*) onBoardingVersion;
+(void) visitOnBoarding:(NSString*) onBoardingVersion;
+(void) onBoardingGoalReached:(NSString *)onBoardingVersion;

+(void) onBoardingDObject:(NSString*) dObjName type:(ElastiCodeDObjType) type elementGroup:(NSUInteger) elementGrpup defaultValues:(NSArray*) dObjArray;
+(void) onBoardingText:(NSString*) textName elementGroup:(NSUInteger) elementGrpup defaultValues:(NSArray*) textArray;
+(void) onBoardingImage:(NSString*) imageName elementGroup:(NSUInteger) elementGrpup defaultValues:(NSArray*) imageArray listOfOptions:(NSArray*) imagesNames;
+(void) onBoardingColor:(NSString*) colorName elementGroup:(NSUInteger) elementGrpup defaultValues:(NSArray*) colorArray;
+(void) onBoardingAction:(NSString*) actionName elementGroup:(NSUInteger) elementGrpup defaultValues:(NSArray*) actionNamesArray listOfOptions:(NSDictionary*) namesAndActions;
+(void) onBoardingDObject:(NSString*) dObjName type:(ElastiCodeListOfOptionsType) type elementGroup:(NSUInteger) elementGrpup defaultValues:(NSArray*) dObjArray listOfOptions:(NSArray*) optionsNames;

+(NSArray*) getOnBoardingDObject:(NSString*) dObjName;
+(NSArray*) getOnBoardingText:(NSString*) textName;
+(NSArray*) getOnBoardingImage:(NSString*) imageName; 
+(NSArray*) getOnBoardingColor:(NSString*) colorName;
+(NSArray*) getOnBoardingAction:(NSString*) action;

+(NSString*) getDeviceType;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Logging
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/**
 *  Set the log level of the ElastiCode SDK.
 Logs can show errors only (default): elastiCodeLogLevelErrors,
 or detailed log: elastiCodeLogLevelDetailed.
 *
 *  @param logLevel The log level: elastiCodeLogLevelErrors, elastiCodeLogLevelDetailed.
 */
+(void)setLogLevel:(enum logLevel)logLevel;



/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Debugging
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 *  Activate debug mode
 */
+(void)activateDebugMode __deprecated_msg("Use devModeWithLogging: method instead");

/**
 *  Activate SDK in debug mode.
 *  SDK analytics will be ignored, and the SDK will get all draft segments
 */
+(void)devModeWithLogging:(enum logLevel) logLevel;

/**
 *  Take case/dynamic object snapshot.
 *  Only available in debug mode, take a screen shot of the visible screen and upload it to MC.
 *  Case must be visited first with 'stateIndexForCase' or 'visitCase'
 *  Dynamic object must be visited first with 'valueForDynamicObject' or 'visitDynamicObject'
 */
+(void)takeSnapShot:(NSString*) caseName;


@end
