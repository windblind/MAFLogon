//
//  UIControl+Extension.h
//  MAFSettingScreen
//
//  Copyright 2012 SAP. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIControl (Extension)

@property (nonatomic, retain, getter=mafControlKey, setter=setMAFControlKey:) NSString* mafControlKey;

@end
