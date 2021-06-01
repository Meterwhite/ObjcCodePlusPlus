//
//  NSObject+Code++.m
//  Code++ for ObjcC
//
//  Created by apple on 2021/6/1.
//

#import "NSObject+Codepp.h"
#import <objc/runtime.h>

@implementation NSObject(Codepp)

- (void)cpp_setInitValueForKey:(NSString *)key {
    objc_property_t p;
    Ivar ivar;
    if((p = class_getProperty(self.class, key.UTF8String))) {
        NSString    *attrs = @(property_getAttributes(p));
        NSArray     *attrInfos = [attrs componentsSeparatedByString:@","];
        if([attrInfos containsObject:@"R"]) { //Readonly
            return;
        } else if (![[attrInfos.lastObject substringToIndex:1] isEqualToString:@"V"]) { //void
            return;
        }
        NSString *head = attrInfos.firstObject;
        if(![head hasPrefix:@"T@"] || head.length < 4) return;
        NSString *clz_nam = [head substringWithRange:NSMakeRange(3, head.length - 4)];
        id v = [NSClassFromString(clz_nam) new];
        [self setValue:v forKey:key];
    } else if((ivar = class_getInstanceVariable(self.class, key.UTF8String))) {
        NSString *head = @(ivar_getTypeEncoding(ivar));
        if(![head hasPrefix:@"@\""] || head.length < 3) return;
        NSString *clz_nam = [head substringWithRange:NSMakeRange(2, head.length - 3)];
        id v = [NSClassFromString(clz_nam) new];
        [self setValue:v forKey:key];
    }
}

@end
