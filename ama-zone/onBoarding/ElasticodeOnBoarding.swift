//
//  ElasticodeOnBoarding.swift
//  ama-zone
//
//  Created by Tomer Shkolnik on 3/23/15.
//  Copyright (c) 2015 elasticode. All rights reserved.
//

import UIKit

class ElasticodeOnBoarding: NSObject {
    let onBoardingVersionString:NSString = "1.0"
    
    var window: UIWindow?
    var getAppRootVCClosure: (()->(UIViewController))?
    
    
    func startOnBoradingOnWindow(window: UIWindow!, withElasticodeKey elasticodeKey: String, viewControllerGetterBlock: ()->UIViewController)
    {
        self.window = window
        self.getAppRootVCClosure = viewControllerGetterBlock
        NSNotificationCenter
            .defaultCenter()
            .addObserver(
                self,
                selector: "handleElasticodeSessionStarted:",
                name:ELASTICODE_SESSION_STARTED,
                object: nil)
        var svc: ECSplashScreen = ECSplashScreen()
        self.window?.rootViewController = svc
        self.window?.makeKeyAndVisible()

        ElastiCode.devModeWithLogging(elastiCodeLogLevelDetailed)

        ElastiCode.startSession(elasticodeKey, onBoardingVersion: onBoardingVersionString)
    }
    
    func handleOnboardingCompletion()
    {
        ElastiCode.onBoardingGoalReached(onBoardingVersionString)
        if let vc :UIViewController = self.getAppRootVCClosure?(){
            self.window?.rootViewController = vc;
        }

    }
    
    func handleElasticodeSessionStarted(notification: NSNotification)
    {
        var screens: NSArray;
        //WARNING: Choose a default onBoarding by uncommenting one of the following templates configurations.
//        screens = template1()
//        screens = template2()
//        screens = template3()
//        screens = template4()
        screens = template5()
//        screens = template6()
//        screens = template7()
//        screens = template8()
//        screens = template9()
//        screens = template10()
//        screens = template11()
        let moreActions:NSMutableArray = NSMutableArray()
        moreActions.addObject(ECOnBoardingAction .createWithName("Show video", action: showVideo))
        var onboardingVC:ECOnboardingViewController =
        ElastiCode.createOnBoardingWithScreens(screens, withVersion: onBoardingVersionString, completionHandler: handleOnboardingCompletion, additionalActions: moreActions)
        
        onboardingVC.fadePageControlOnLastPage = true;
        onboardingVC.view.backgroundColor = UIColor(red: 0.684, green: 0.828, blue: 0.827, alpha: 1)
        self.window?.rootViewController = onboardingVC
    }
    
    func showVideo() -> Void
    {
        var av:UIAlertView = UIAlertView(title: "Video preview", message: "Here you would add logic to display video content", delegate: nil, cancelButtonTitle: "OK")
        av.show()
    }
    
    
    func template1() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate1 = ECOnBoardingScreenTemplate1()
        screen1.label.text = "Every thing you ever... \n Thought about retail apps \n Is about to change!"
        screen1.label.textColor = UIColor(red:1.000, green:1.000, blue:1.000, alpha:1)
        screen1.label.fontName = "TimeNewRomanPS-ItalicMT"
        screen1.label.fontSize = 15
        screen1.ctaButton.show = true
        screen1.ctaButton.type = CTAButtonType.withText_google
        screen1.image.setImageNameForIPhone4("", forIPhone5: "", forIPhone6: "", forIPhone6Plus: "")
        screen1.backgroundColor = UIColor(red:0.000, green:0.384, blue:0.627, alpha:1)
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Show video", action: showVideo)
//            ECOnBoardingAction .createWithName("Continue", action: { () -> Void in self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
    func template2() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate2 = ECOnBoardingScreenTemplate2()
        screen1.label.text = "Are You Ready?"
        screen1.label.textColor = UIColor(red:0.349, green:0.341, blue:0.341, alpha:1)
        screen1.ctaButton.show = true
        screen1.ctaButton.type = CTAButtonType.withText_facebook
        screen1.image.setImageNameForIPhone4("", forIPhone5: "", forIPhone6: "", forIPhone6Plus: "")
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: { self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
    func template3() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate3 = ECOnBoardingScreenTemplate3()
        screen1.label.text = "Are You Ready?"
        screen1.label.textColor = UIColor(red:0.349, green:0.341, blue:0.341, alpha:1)
        screen1.label2.text = "Calendar Madness!"
        screen1.label2.textColor = UIColor(red:1.000, green:1.000, blue:1.000, alpha:1)
        screen1.label2.fontName = "HelveticaNeue-Bold"
        screen1.label2.fontSize = 16
        screen1.label3.text = "So, Are you ready to get your calendar get more organized ?"
        screen1.label3.textColor = UIColor(red:0.486, green:0.408, blue:0.408, alpha:1)
        screen1.label3.fontName = "HelveticaNeue-BoldItalic"
        screen1.ctaButton.show = true
        screen1.ctaButton.type = CTAButtonType.withText_google
        screen1.image.setImageNameForIPhone4("", forIPhone5: "", forIPhone6: "", forIPhone6Plus: "")
        screen1.overlayColor = UIColor(red:1.000, green:1.000, blue:1.000, alpha:1)
        screen1.backgroundColor = UIColor(red:0.878, green:0.882, blue:0.886, alpha:1)
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: { () -> Void in self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
    func template4() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate4 = ECOnBoardingScreenTemplate4()
        screen1.label.text = "Are you ready? \n Cause we are! \n Let's get this one started:)"
        screen1.label.textColor = UIColor(red:0.400, green:0.322, blue:0.322, alpha:1)
        screen1.label.fontName = "Palatino-Italic"
        screen1.label.fontSize = 18
        screen1.ctaButton.show = true
        screen1.ctaButton.type = CTAButtonType.withText_facebook
        screen1.ctaButton2.show = true
        screen1.ctaButton2.type = CTAButtonType.withText_google
        screen1.ctaButton3.show = false
        screen1.backgroundColor = UIColor(red:1.000, green:0.976, blue:0.976, alpha:1)
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: handleOnboardingCompletion)
        return NSArray(object: screen1)
    }
    func template5() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate5 = ECOnBoardingScreenTemplate5()
        screen1.label.text = "Transform your Amazon\nBuying experience\nFrom Just \"Buy\" to\n\"Get The Best Deal\""
        screen1.label.textColor = UIColor.whiteColor()
        screen1.label.fontName = "Helvetica-Light"
        screen1.label.fontSize = 25
        screen1.label.textOffsetY = 312
        screen1.ctaButton.show = false
        screen1.ctaButton2.show = false
        screen1.ctaButton3.show = true
        screen1.ctaButton3.type = CTAButtonType.custom
        screen1.ctaButton3.text = "Let's get started";
        screen1.ctaButton3.textColor = UIColor(red: 0.051, green: 0.212, blue: 0.337, alpha: 1)
        screen1.ctaButton3.backgroundColor = UIColor.whiteColor()
        screen1.ctaButton3.fontSize = 30
        screen1.ctaButton3.fontName = "HelveticaNeue-light"
        screen1.image.setImageNameForIPhone4("", forIPhone5: "", forIPhone6: "ScreenDeals_clean.jpg", forIPhone6Plus: "")
        screen1.ctaButton3.actionObject = ECOnBoardingAction .createWithName("Continue", action: handleOnboardingCompletion)
        return [screen1]
    }
    func template6() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate6 = ECOnBoardingScreenTemplate6()
        screen1.label.textColor = UIColor(red:0.969, green:0.773, blue:0.624, alpha:1)
        screen1.label.fontName = "HoeflerText-BlackItalic"
        screen1.label.fontSize = 30
        screen1.ctaButton.show = true
        screen1.ctaButton.type = CTAButtonType.withText_twitter
        screen1.ctaButton2.show = true
        screen1.ctaButton2.fontName = "HoeflerText-Black"
        screen1.ctaButton2.textColor = UIColor(red:0.165, green:0.196, blue:0.294, alpha:1)
        screen1.ctaButton2.backgroundColor = UIColor(red:0.882, green:0.898, blue:0.933, alpha:1)
        screen1.ctaButton2.fontSize = 20
        screen1.ctaButton2.text = "Sign up"
        screen1.ctaButton3.show = true
        screen1.ctaButton3.fontName = "HoeflerText-Black"
        screen1.ctaButton3.textColor = UIColor(red:0.165, green:0.196, blue:0.294, alpha:1)
        screen1.ctaButton3.backgroundColor = UIColor(red:0.780, green:0.800, blue:0.859, alpha:1)
        screen1.ctaButton3.fontSize = 20
        screen1.ctaButton3.text = "Sign in"
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: { () -> Void in self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
    func template7() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate7 = ECOnBoardingScreenTemplate7()
        screen1.label.text = "Are You Ready?"
        screen1.label.textColor = UIColor(red:0.349, green:0.341, blue:0.341, alpha:1)
        screen1.ctaButton.show = true
        screen1.ctaButton.type = CTAButtonType.withText_facebook
        screen1.ctaButton2.show = true
        screen1.ctaButton2.textColor = UIColor(red:0.180, green:0.075, blue:0.063, alpha:1)
        screen1.ctaButton2.backgroundColor = UIColor(red:0.859, green:0.792, blue:0.651, alpha:1)
        screen1.ctaButton2.fontSize = 20
        screen1.ctaButton2.text = "Sign up"
        screen1.ctaButton3.show = true
        screen1.ctaButton3.textColor = UIColor(red:0.180, green:0.075, blue:0.063, alpha:1)
        screen1.ctaButton3.backgroundColor = UIColor(red:0.859, green:0.792, blue:0.651, alpha:1)
        screen1.ctaButton3.fontSize = 20
        screen1.ctaButton3.text = "Sign in"
        screen1.image.setImageNameForIPhone4("", forIPhone5: "", forIPhone6: "", forIPhone6Plus: "")
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: { () -> Void in self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
    func template8() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate8 = ECOnBoardingScreenTemplate8()
        screen1.label.textColor = UIColor(red:0.188, green:0.910, blue:0.451, alpha:1)
        screen1.label.fontSize = 30
        screen1.label2.textColor = UIColor(red:0.329, green:0.220, blue:0.863, alpha:1)
        screen1.label2.fontSize = 20
        screen1.ctaButton.show = true
        screen1.ctaButton.type = CTAButtonType.withText_twitter
        screen1.backgroundColor = UIColor(red:0.698, green:0.298, blue:0.388, alpha:1)
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: { () -> Void in self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
    func template9() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate9 = ECOnBoardingScreenTemplate9()
        screen1.label.text = "Are You Ready?"
        screen1.label.textColor = UIColor(red:0.349, green:0.341, blue:0.341, alpha:1)
        screen1.label.fontName = "Helvetica"
        screen1.label2.text = "Get ready to get the best out of your new app"
        screen1.label2.textColor = UIColor(red:0.259, green:0.153, blue:0.118, alpha:1)
        screen1.label2.fontName = "HelveticaNeue-Bold"
        screen1.label2.fontSize = 20
        screen1.ctaButton.show = true
        screen1.ctaButton.type = CTAButtonType.withText_facebook
        screen1.image.setImageNameForIPhone4("", forIPhone5: "", forIPhone6: "", forIPhone6Plus: "")
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: { () -> Void in self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
    func template10() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate10 = ECOnBoardingScreenTemplate10()
        screen1.label.textColor = UIColor(red:0.490, green:0.631, blue:0.443, alpha:1)
        screen1.label.fontName = "Menlo-Bold"
        screen1.label.fontSize = 30
        screen1.label2.textColor = UIColor(red:0.490, green:0.631, blue:0.443, alpha:1)
        screen1.label2.fontName = "Menlo-Bold"
        screen1.label2.fontSize = 20
        screen1.ctaButton.show = true
        screen1.ctaButton.fontName = "Menlo-Bold"
        screen1.ctaButton.textColor = UIColor(red:0.314, green:0.137, blue:0.098, alpha:1)
        screen1.ctaButton.backgroundColor = UIColor(red:0.922, green:0.745, blue:0.608, alpha:1)
        screen1.ctaButton.useRoundCorners = false
        screen1.ctaButton.fontSize = 20
        screen1.ctaButton.text = "Sign up"
        screen1.ctaButton2.show = true
        screen1.ctaButton2.fontName = "Menlo-Bold"
        screen1.ctaButton2.textColor = UIColor(red:0.314, green:0.137, blue:0.098, alpha:1)
        screen1.ctaButton2.backgroundColor = UIColor(red:0.906, green:0.659, blue:0.467, alpha:1)
        screen1.ctaButton2.fontSize = 20
        screen1.ctaButton2.text = "Sign in"
        screen1.backgroundColor = UIColor(red:0.314, green:0.137, blue:0.098, alpha:1)
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: { () -> Void in self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
    func template11() -> (NSArray)
    {
        var screen1:ECOnBoardingScreenTemplate11 = ECOnBoardingScreenTemplate11()
        screen1.label.textColor = UIColor(red:0.490, green:0.631, blue:0.443, alpha:1)
        screen1.label.fontName = "Menlo-Bold"
        screen1.label.fontSize = 30
        screen1.label2.textColor = UIColor(red:0.490, green:0.631, blue:0.443, alpha:1)
        screen1.label2.fontName = "Menlo-Bold"
        screen1.label2.fontSize = 20
        screen1.label2.textOffsetY = 150
        screen1.ctaButton.show = true
        screen1.ctaButton.fontName = "Menlo-Bold"
        screen1.ctaButton.textColor = UIColor(red:0.314, green:0.137, blue:0.098, alpha:1)
        screen1.ctaButton.backgroundColor = UIColor(red:0.922, green:0.745, blue:0.608, alpha:1)
        screen1.ctaButton.useRoundCorners = false
        screen1.ctaButton.fontSize = 20
        screen1.ctaButton.text = "Sign up"
        screen1.ctaButton2.show = true
        screen1.ctaButton2.fontName = "Menlo-Bold"
        screen1.ctaButton2.textColor = UIColor(red:0.314, green:0.137, blue:0.098, alpha:1)
        screen1.ctaButton2.backgroundColor = UIColor(red:0.906, green:0.659, blue:0.467, alpha:1)
        screen1.ctaButton2.fontSize = 20
        screen1.ctaButton2.text = "Sign in"
        screen1.image.setImageNameForIPhone4("", forIPhone5: "", forIPhone6: "", forIPhone6Plus: "")
        screen1.ctaButton.actionObject = ECOnBoardingAction .createWithName("Continue", action: { () -> Void in self.handleOnboardingCompletion() })
        return NSArray(object: screen1)
    }
}
