//
//  SSBPCsvIF+SampleMainBundleCsv.m
//  MinistopSdkSample
//
//  SSBPAnalyticsManager loads app_info via SSBPCsvIF.getCsv:, which reads from the
//  framework bundle by default. Redirect app_info to MinistopSdkSample.app bundle so
//  Resources/demo/app_info.csv is picked up.
//

#import <SSBPLite/SSBPLite.h>
#import <objc/runtime.h>

@implementation SSBPCsvIF (SampleMainBundleCsv)

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class cls = [SSBPCsvIF class];
        SEL a = @selector(getCsv:);
        SEL b = @selector(sample_ssbp_csv_getCsv:);
        Method ma = class_getInstanceMethod(cls, a);
        Method mb = class_getInstanceMethod(cls, b);
        if (ma && mb) {
            method_exchangeImplementations(ma, mb);
        }
    });
}

- (NSString *)sample_ssbp_csv_getCsv:(NSString *)fileNameWithoutExtension {
    if ([fileNameWithoutExtension isEqualToString:@"app_info"]) {
        NSBundle *main = [NSBundle mainBundle];
        NSString *path = [main pathForResource:@"app_info" ofType:@"csv" inDirectory:@"demo"];
        if (path.length == 0) {
            path = [main pathForResource:@"app_info" ofType:@"csv"];
        }
        if (path.length > 0) {
            NSData *data = [NSData dataWithContentsOfFile:path];
            if (data.length > 0) {
                return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            }
        }
    }
    return [self sample_ssbp_csv_getCsv:fileNameWithoutExtension];
}

@end
