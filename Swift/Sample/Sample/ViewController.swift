//
//  ViewController.swift
//  Sample
//
//  Created by Arun Kumar on 26/03/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        let str:String? = nil
        if str != nil {
            print(str!);
        }
        else {
            print("it has nil value");
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

