//
//  ViewController.swift
//  MDSOfferViewDemo
//
//  Created by YuAo on 3/16/16.
//  Copyright © 2016 YuAo. All rights reserved.
//

import UIKit
import MDSOfferView

class ViewController: UIViewController {

    @IBOutlet weak var offerView: MDSOfferView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.offerView.actionHandler = { _ in
            self.offerViewTapped()
        }
    }
    
    func offerViewTapped() {
        self.offerView.state = .PendingDownload
        
        Delay(interval: 2.second) {
            
            self.offerView.state = .Downloading
            self.offerView.setProgress(0.1, animated: true)
            
        }.then(Delay(interval: 0.6.second) {
            
            self.offerView.setProgress(0.3, animated: true)
            
        }).then(Delay(interval: 0.5.second) {
            
            self.offerView.setProgress(0.7, animated: true)
            
        }).then(Delay(interval: 0.5.second) {
            
            self.offerView.setProgress(0.75, animated: true)
            
        }).then(Delay(interval: 0.5.second) {
            
            self.offerView.setProgress(1.0, animated: true)
            
        }).then(Delay(interval: 0.5.second) {
            
            self.offerView.state = .Downloaded
            self.offerView.enabled = false
            
        }).run()
    }
}

