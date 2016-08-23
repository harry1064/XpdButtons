//
//  XpdButtonContainer.h
//  Button
//
//  Created by Ravi Prakash on 17/08/16.
//  Copyright © 2016 Ravi Prakash. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XpdButtonPageController.h"

/**
    XpdButtonAction is adopted by viewController where XpdButtonsView is gonna be used.
    @see -(UIView *) getXpdButtonsViewForParentViewController:(UIViewController *)parent;
 */
@protocol XpdButtonAction

/**
    Track when Buttons got clicked. Use buttonInfo and title property to track which button get clicked.
    @code 
        - (void) buttonGetClicked:(XpdButton *)button {
            if ([[button.buttonInfo objectForKey:@"key"] isEqualToString:@"value"]) {
                // Do something
            }

            if ([button.title isEqualToString:@"Button 1"]) {
                // Do something
            }
        }
    @endcode
 */
- (void) buttonGetClicked:(XpdButton *)button;
@end
@interface XpdButtonContainer : UIViewController<XpdButtons>

/**
  Button properties is an Array of dictionary.
  Element Dictionary contains keys -> (title, buttonInfo). ButtonInfo a is dictionary(anyKey: anyValue).
  Ex :-
    @code  NSArray *properties = @[
                            @{
                                @"title" : @"button 1",
                                @"buttonInfo" : @{@"key" : @"value"}
                            },
                            @{
                                @"title" : @"button 2",
                                @"buttonInfo" : @{@"key" : @"value"}
                            }];
    @endcode
 */
@property (nonatomic, strong) NSArray *buttonProperties;

/**
  Number of maximum row of buttons in one pageView. It will dynamically set other buttons to diffrent pageView.
 */
@property NSUInteger numberOfMaxRow;

/**
    Delegate to use XpdButtonAction protocol
    @see XpdButtonAction
    @see -(void) buttonGetClicked:(UIButton *)button;
 */
@property (nonatomic, weak) id<XpdButtonAction> delegate;
 
/**
    Get view which contains buttons.
    @param: parent viewController where you gonna use the buttons view.
    @return: UIView view which contains all buttons with multiple page.
    @code
        XpdButtonContainer *buttonPageController = [[XpdButtonContainer alloc] init];
        buttonPageController.delegate = self;
        buttonPageController.buttonProperties = properties;
        UIView *buttonView = [buttonPageController getXpdButtonsViewForParentViewController:self];
    @endcode
    @see buttonProperties
 */
-(UIView *) getXpdButtonsViewForParentViewController:(UIViewController *)parent;
@end
