//
//  UIColor+Relations.h
//  SSBPSdk
//
//  Created by vfa on 8/2/21.
//  Copyright © 2021 Togashi Ayumi. All rights reserved.
//

#ifndef UIColor_Relations_h
#define UIColor_Relations_h

@interface UIColor(Relations)

// Dark mode color with string hex color ex @"#123456"
+ (UIColor *)darkModeColorWithLight:(NSString *)light dark:(NSString *)dark;

// Dark mode color with string hex color ex "#123456" and alpha
+ (UIColor *)darkModeColorWithLight:(NSString *)light withLightAlpha:(CGFloat)lightAlpha dark:(NSString *)dark withDarkAlpha:(CGFloat)darkAlpha;
// Color with hex 0x123456
+ (UIColor *)colorWithHex:(UInt32)col;

// Color with hex 0x123456 and alpha
+ (UIColor *)colorWithHex:(UInt32)col withAlpha:(CGFloat)alpha;

// Color with hex string @"#123456"
+ (UIColor *)colorWithHexString:(NSString *)str;

// Color with hex string @"#123456" and alpha
+ (UIColor *)colorWithHexString:(NSString *)str withAlpha:(CGFloat)alpha;

@end

#endif /* UIColor_Relations_h */
