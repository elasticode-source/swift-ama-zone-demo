//
//  ECSplashScreen.swift
//  ama-zone
//
//  Created by Tomer Shkolnik on 3/23/15.
//  Copyright (c) 2015 elasticode. All rights reserved.
//

import UIKit

class ECSplashScreen: UIViewController,MONActivityIndicatorViewDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        generateView()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func generateView()
    {
        self.view.backgroundColor = UIColor .clearColor()
        var imageName:NSString = splashImageName()!
        let img:UIImage = UIImage(named: imageName)!
        let imgV:UIImageView = UIImageView(image: img)
        imgV.frame = self.view.frame
        self.view.addSubview(imgV)
        var indicatorView:MONActivityIndicatorView = MONActivityIndicatorView();
        indicatorView.delegate = self;
        indicatorView.numberOfCircles = 5;
        indicatorView.radius = 20;
        indicatorView.internalSpacing = 3;
        var centerPoint:CGPoint = self.view.center;
        centerPoint.x -= (CGFloat(indicatorView.numberOfCircles) * (indicatorView.radius + indicatorView.internalSpacing));
        indicatorView.center = centerPoint;
        self.view.addSubview(indicatorView);
        indicatorView.startAnimating();
    }
    
    func splashImageName() -> NSString?
    {
        let viewSize:CGSize = self.view.bounds.size
        let imagesDict:NSArray = NSBundle.mainBundle().infoDictionary?["UILaunchImages"] as NSArray!
        var imageName:NSString?;
        for(dict) in imagesDict
        {
            let imageSizeString:NSString = dict["UILaunchImageSize"] as NSString
            let imageSize:CGSize = CGSizeFromString(imageSizeString)
            if(CGSizeEqualToSize(imageSize, viewSize) && "Portrait" == (dict["UILaunchImageOrientation"] as NSString)){
                imageName = dict["UILaunchImageName"] as? NSString
                break;
            }
        }
        return imageName
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
    func activityIndicatorView(activityIndicatorView: MONActivityIndicatorView!, circleBackgroundColorAtIndex index: UInt) -> UIColor! {
        return UIColor.whiteColor();
    }
}
