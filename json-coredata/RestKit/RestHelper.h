//
//  RestHelper.h
//  mobile
//
//  Created by Mihai Iancu on 5/25/13.
//  Copyright (c) 2013 eugenol. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RestKit/RestKit.h>

@interface RestHelper : NSObject

+ (RKObjectManager*)manager;
+ (void)setupRestKit;
+ (void)loadIssues;

@end
