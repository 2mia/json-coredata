//
//  AppDelegate.h
//  json-coredata
//
//  Created by Mihai Iancu on 20/2/14.
//  Copyright (c) 2014 Mihai. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

@end
