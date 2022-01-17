//
//  xtuple.m
//  Code++
//
//  Created by MeterWhite on 2020/7/23.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#import "xtuple.h"
#import "Code++.h"

@interface xtuple ()

@property (nonatomic) NSUInteger count;

@end

@implementation xtuple

id TupleGuard(void) {    
    static id _tuple_guard;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _tuple_guard = [[NSObject alloc] init];
    });
    return _tuple_guard;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _count = 0;
    }
    return self;
}

+ (id)tupleWithObjects:(id)va0, ... {
    xtuple *tp = [xtuple new];
        va_list ap;
        va_start(ap, va0);
        id obj = va0;
        id sentin = TupleGuard();
        xuint i = 0;
        while (obj != sentin && i < 20) {
            [tp setValue:obj forKey:THE_STRING(@"at%ld",i)];
            obj = va_arg(ap, id);
            i++;
        }
        va_end(ap);
        tp.count = i;
    return tp;
}

- (void)unpack:(id  _Nonnull __autoreleasing *)p0, ... {
    va_list ap;
    va_start(ap, p0);
    __autoreleasing id* vp = p0;
    NSInteger i = 0;
    while (vp != nil) {
        *vp = [self valueForKey:THE_STRING(@"at%ld",i)];
        vp = va_arg(ap, __autoreleasing id*);
        i++;
    }
    va_end(ap);
}

- (nullable id)objectAtIndexedSubscript:(NSUInteger)idx {
    NSAssert(idx < 20, @"The number of parameters is limited.");
    return [self valueForKey:THE_STRING(@"at%ld",idx)];
}

- (nullable id)objectAtIndex:(int)idx {
    NSAssert(idx < 20, @"The number of parameters is limited.");
    return [self valueForKey:THE_STRING(@"at%d",idx)];
}
@end
