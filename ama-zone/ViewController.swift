//
//  ViewController.swift
//  ama-zone
//
//  Created by Tomer Shkolnik on 3/23/15.
//  Copyright (c) 2015 elasticode. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        let img:UIImage = UIImage(named: "signUp")!
        let imgV:UIImageView = UIImageView(image: img)
        imgV.frame = self.view.frame
        self.view.addSubview(imgV)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

