//
//  DetailViewController.h
//  json-coredata
//
//  Created by Mihai Iancu on 20/2/14.
//  Copyright (c) 2014 Mihai. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController <UISplitViewControllerDelegate>

@property (strong, nonatomic) id detailItem;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;
@end
