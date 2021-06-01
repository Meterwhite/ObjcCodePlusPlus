//
//  xtuple.h
//  Code++
//
//  Created by MeterWhite on 2020/7/23.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CoreConnect.h"

/// 定义元组接口；Tuple_T0_T1_...Tn
/// 依次输入类型列表
#define TYPE_TUTPLE(...) \
@interface CORE_CONNECT_CONCAT(Tuple_,CORE_JOIN_WITH(_,__VA_ARGS__)) : xtuple   \
CORE_CONNECT_FOREACH_CXT(__TUPLE_PT,,,__VA_ARGS__)\
@end

/// 创建元组;输入变量列表
#define THE_TUPLE(...) \
    [xtuple tupleWithObjects:__VA_ARGS__, TupleGuard()]

/// 元组变量,类型列表;解包为变量名+数字
#define LET_UNPACK_TUPLE(tp,...) \
    CORE_CONNECT_FOREACH_CXT(__TUPLE_UNPACK_ITEM,,tp,__VA_ARGS__)

/// 哨兵参数；
id _Nonnull TupleGuard(void);

@interface xtuple : NSObject <NSObject>
@property (nullable,nonatomic) id at0;
@property (nullable,nonatomic) id at1;
@property (nullable,nonatomic) id at2;
@property (nullable,nonatomic) id at3;
@property (nullable,nonatomic) id at4;
@property (nullable,nonatomic) id at5;
@property (nullable,nonatomic) id at6;
@property (nullable,nonatomic) id at7;
@property (nullable,nonatomic) id at8;
@property (nullable,nonatomic) id at9;
@property (nullable,nonatomic) id at10;
@property (nullable,nonatomic) id at11;
@property (nullable,nonatomic) id at12;
@property (nullable,nonatomic) id at13;
@property (nullable,nonatomic) id at14;
@property (nullable,nonatomic) id at15;
@property (nullable,nonatomic) id at16;
@property (nullable,nonatomic) id at17;
@property (nullable,nonatomic) id at18;
@property (nullable,nonatomic) id at19;

@property (nonatomic,readonly) NSUInteger count;
+ (nonnull __kindof xtuple *)tupleWithObjects:(nullable id)va0, ...;
- (void)unpack:(id _Nonnull *_Nonnull)p0, ...;
- (nullable id)objectAtIndexedSubscript:(NSUInteger)idx;
- (nullable id)objectAtIndex:(int)idx;
@end
/// 遍历性

#pragma mark - 次级定义
#define __TUPLE_PT(INDEX, CONTEXT, VAR) @property (nullable,nonatomic) VAR* at##INDEX;
#define __TUPLE_UNPACK_ITEM(INDEX, CONTEXT, VAR) __unused VAR* CONTEXT##INDEX = ((Xtuple*)CONTEXT).at##INDEX;
