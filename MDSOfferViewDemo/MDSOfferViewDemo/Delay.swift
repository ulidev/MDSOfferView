//
//  Delay.swift
//  MDSOfferViewDemo
//
//  Created by YuAo on 3/16/16.
//  Copyright © 2016 YuAo. All rights reserved.
//

import Foundation

public class Delay {
    private var previousDelay: Delay?
    private var thenDelay: Delay?
    private var action: () -> Void
    private var interval: NSTimeInterval = 0
    init(interval: NSTimeInterval, action: () -> Void) {
        self.interval = interval
        self.action = action
    }
    func then(thenDelay: Delay) -> Delay {
        self.thenDelay = thenDelay
        thenDelay.previousDelay = self
        return thenDelay
    }
    private func start() {
        delay(self.interval, closure: {
            self.action()
            self.thenDelay?.start()
        })
    }
    func run() {
        if self.previousDelay != nil {
            var starter = self.previousDelay!
            while starter.previousDelay != nil {
                starter = starter.previousDelay!
            }
            starter.start()
        } else {
            self.start()
        }
    }
}

public func delay(aDelay:NSTimeInterval, closure: () -> Void) {
    delay(aDelay, queue: dispatch_get_main_queue(), closure: closure)
}

public func delay(aDelay:NSTimeInterval, queue: dispatch_queue_t!, closure: () -> Void) {
    let delayTime = dispatch_time(DISPATCH_TIME_NOW, Int64(aDelay * Double(NSEC_PER_SEC)))
    dispatch_after(delayTime, queue, closure)
}

public extension Double {
    var second: NSTimeInterval { return self }
    var seconds: NSTimeInterval { return self }
    var minute: NSTimeInterval { return self * 60 }
    var minutes: NSTimeInterval { return self * 60 }
    var hour: NSTimeInterval { return self * 3600 }
    var hours: NSTimeInterval { return self * 3600 }
}