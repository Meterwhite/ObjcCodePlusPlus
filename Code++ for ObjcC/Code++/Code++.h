//
//  Code++.h
//  Code++ 1.0
//
//  Created by MeterWhite on 2020/6/25.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#ifndef CodePP_h
#define CodePP_h

#import "NSObject+Codepp.h"
#import "CoreConnect.h"
#import "xtuple.h"

#pragma mark - 基本类型
#define xstring         NSString
#define xmstring        NSMutableString
#define xint            NSInteger
#define xuint           NSUInteger
#define xarray          NSArray
#define xmarray         NSMutableArray
#define xcolor          UIColor
#define ximage          UIImage
#define xnumber         NSNumber
#define xdictionary     NSDictionary
#define xmdictionary    NSMutableDictionary

#if TARGET_OS_IPHONE || TARGET_OS_TV

#import <UIKit/UIKit.h>
#define xrect           CGRect
#define xpoint          CGPoint
#define xsize           CGSize

#elif TARGET_OS_MAC

#import <AppKit/AppKit.h>
#define xrect           NSRect
#define xpoint          NSPoint
#define xsize           NSSize

#endif

#pragma mark - LET 语法糖
#define LET_NEW(T, var)  T* var = [T new]
/// 类似swift的let定义
#define LET_LET(var, ...)  typeof((__VA_ARGS__)) var = __VA_ARGS__
/// 赋值
#define LET_PAS(A, B)         A = B
/// init or initWith...
#define LET_INIT(T, var, ...) T *var = [[T alloc] __VA_ARGS__]
#define LET_NEW_NIB(T, var)   T* var = THE_NIB_OBJ(T)
#define LET_NONNULL(...)      ((__VA_ARGS__) ?: [NSNull null])
#define LET_NONSNULL(...)     (([(__VA_ARGS__) isEqual:[NSNull null]]) ? nil : __VA_ARGS__)
/// 字面转字符串
#define LET_STRING(S)         @""#S""
/// 取反
#define LET_TOGGLE(__VA_ARGS__) __VA_ARGS__ = !__VA_ARGS__
/// 拷贝代码
#define LET_CODE_COPY(N, ...)   __CODEPP_COPY##N(__VA_ARGS__)
/// 返回类型,变量名,参数列表...
#define LET_BLOCK(T, var, ...)   TYPE_BLOCK(T,var,__VA_ARGS__) = THE_BLOCK(T,__VA_ARGS__)
/// KVC++
#define LET_KVC(dst,...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
([dst valueForKeyPath:__VA_ARGS__]) \
([dst setValue:CORE_CONNECT_HEAD(__VA_ARGS__) forKeyPath:CORE_CONNECT_TAIL(__VA_ARGS__)])
/// 路径形式
#define LET_KVC_PATH(dst,...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
([dst valueForKeyPath:@__CODEPP_KEYPATH2(dst, __VA_ARGS__)]) \
([dst setValue:CORE_CONNECT_HEAD(__VA_ARGS__) forKeyPath:@__CODEPP_KEYPATH2(dst, CORE_CONNECT_TAIL(__VA_ARGS__))])
/// 懒初始值
#define LET_INIT_KEYS(dst,...) CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_LZLD,;,dst,__VA_ARGS__)
#define LET_INIT_KEYS_PATH(dst,...) CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_LZLDp,;,dst,__VA_ARGS__)
#define LET_INIT_SELF_PATH(...) LET_INIT_KEYS_PATH(self,__VA_ARGS__)
/// 发通知++;VA-LI : name[,object,userInfo]
#define LET_POST(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    \
([NSNotificationCenter.defaultCenter postNotificationName:__CODEPP_ARG_0(__VA_ARGS__) object:nil]) \
(CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    \
([NSNotificationCenter.defaultCenter postNotificationName:__CODEPP_ARG_0(__VA_ARGS__) object:__CODEPP_ARG_1(__VA_ARGS__)])\
([NSNotificationCenter.defaultCenter postNotificationName:__CODEPP_ARG_0(__VA_ARGS__) object:__CODEPP_ARG_1(__VA_ARGS__) userInfo:__CODEPP_ARG_THAN_2(__VA_ARGS__)]))
/// 装箱数加法
#define LET_NB_ADD(NB,value) [[NSDecimalNumber decimalNumberWithString:[NB description]] decimalNumberByAdding:[NSDecimalNumber decimalNumberWithString:LET_STRING(value)]]
/// 装箱数乘法
#define LET_NB_MUT(NB,value) [[NSDecimalNumber decimalNumberWithString:[NB description]] decimalNumberByAdding:[NSDecimalNumber decimalNumberWithString:LET_STRING(value)]]
/// var,PasExp[,VarCondition]
#define LET_IF_VAR(var,...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    (typeof((__VA_ARGS__)) var; if(((var) = (__VA_ARGS__)))) \
    (typeof((CORE_CONNECT_HEAD(__VA_ARGS__))) var = CORE_CONNECT_HEAD(__VA_ARGS__); if(var CORE_CONNECT_TAIL(__VA_ARGS__)))
/// 对象类型检查转换，新值
#define LET_OBJ_AS(var,T) T *var##_##T = ((id)var);if([var isKindOfClass:[T class]])
#define LET_AFTER(time,...) \
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{ __VA_ARGS__ });

#pragma mark - THE 定义糖
#define THE_NOTHING

#define THE_WELF  __weak typeof(self) welf = self

/**
 * HEX[,A]
 * R,G,B[,A]
 */
#define THE_COLOR(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_HEX_COLOR(__VA_ARGS__,1.0f))(\
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_HEX_COLOR(__VA_ARGS__))(\
CORE_CONNECT_IF_EQ(3,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_COLOR(__VA_ARGS__,1.0f))(\
CORE_CONNECT_IF_EQ(4,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_COLOR(__VA_ARGS__))(nil))))

/// 弱引用；w_变量名
#define THE_WEAK_PTR(...) __weak typeof((__VA_ARGS__)) w_##__VA_ARGS__ = __VA_ARGS__
// T,var[,EXP]
#define THE_OBJ(T,...) \
    CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    (T *__VA_ARGS__) \
    (T *CORE_CONNECT_HEAD(__VA_ARGS__) = CORE_CONNECT_TAIL(__VA_ARGS__))
#define THE_VAL(T, ...) \
    CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    (T __VA_ARGS__) \
    (T CORE_CONNECT_HEAD(__VA_ARGS__) = CORE_CONNECT_TAIL(__VA_ARGS__))
#define THE_CLASS(...)       ([__VA_ARGS__ class])
#define THE_STRING(...)      ([NSString stringWithFormat:__VA_ARGS__])
/// 数值转字符串
#define THE_NB_STRING(...)   ([THE_BOXED(__VA_ARGS__) stringValue])
/// 字符串转数字对象
#define THE_STRING_NB(...)   ([NSDecimalNumber decimalNumberWithString:__VA_ARGS__])
/// 不及to
#define THE_RANDOM(from, to) (from + (arc4random()%(to - from)))
/// 可变
#define THE_MUTABLE(...)     ([(__VA_ARGS__) mutableCopy])
#define THE_PREDICATE(...)   ([NSPredicate predicateWithFormat:__VA_ARGS__])
#define THE_NIB_OBJ(...)     [NSBundle.mainBundle loadNibNamed:LET_STRING(__VA_ARGS__) owner:nil options:nil].firstObject
#define THE_NIB_VC(T, var)   T* var = [[T alloc] initWithNibName:NSStringFromClass(self) bundle:nil]
/// 三目
#define THE_TRINO(C,A,B)     ((C)?(A):(B))
/// 且的连续
#define THE_TRUES(...)       (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_CAL,&&,,__VA_ARGS__))
/// 其一真
#define THE_SOMETRUE(...)    (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_CAL,||,,__VA_ARGS__))
/// 其一假
#define THE_SOMEFALSE(...)   (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_CAL,||,!,__VA_ARGS__))
/// 非的连续
#define THE_FALSES(...)      (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_CAL,&&,!,__VA_ARGS__))
/// 结对地组合 THE_DUP_PAIR(SRC, > 0 &&, < 100)
#define THE_DUP_PAIR(SRC, ...) CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_ORD,,SRC,__VA_ARGS__)
/// 装箱：数字，结构体，c字符串
#define THE_BOXED(value)     __CodePPBox(@encode(__typeof__((value))), (value))
#define THE_RECT(x,y,w,h)    CGRectMake(x,y,w,h)
#define THE_SIZE(w,h)        CGSizeMake(w,h)
#define THE_POINT(x,y)       CGPointMake(x,y)
#define THE_INSERTS(t,l,b,r) UIEdgeInsetsMake(t,l,b,r)
#define THE_IMAGE(...)       [UIImage imageNamed:LET_STRING(__VA_ARGS__)]
/// 用户交互文本，本地化在此处完成
#define THE_LOC_TXT(...)    (__VA_ARGS__)
/**
 * Effective when renamed
 NSString *UTF8StringPath = @THE_KEYPATH(str.lowercaseString.UTF8String);
 // => @"lowercaseString.UTF8String"

 NSString *versionPath = @THE_KEYPATH(NSObject, version);
 // => @"version"

 NSString *lowercaseStringPath = @THE_KEYPATH(NSString.new, lowercaseString);
 // => @"lowercaseString"
 */
#define THE_KEYPATH(...) \
@CORE_CONNECT_IF_EQ(1, CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_KEYPATH1(__VA_ARGS__))(__CODEPP_KEYPATH2(__VA_ARGS__))

#pragma mark - CAL调用糖
#define CAL_SELF(...)           ([self __VA_ARGS__])
#define CAL_WELF(...)           ([welf __VA_ARGS__])
#define CAL_BLOCK(DST, ...)     (DST ? DST(__VA_ARGS__) : ((void *)0))
/// 函数调用形式；参数列表: TAG, SEL, ARGS...
//#define CAL_MSG(...) \
//((id(*)(id, SEL, ...))objc_msgSend)(__CODEPP_MSGSEND_TLI(__VA_ARGS__))
///// 指定返回类型的，如值类型；
//#define CAL_MSG_T(rT,...) \
//((T(*)(id, SEL, ...))objc_msgSend)(__CODEPP_MSGSEND_TLI(__VA_ARGS__))
///// 函数调用形式；参数列表: TAG, SEL, ARGS...
//#define CAL_IMP(imp, ...) \
//((id(*)(id, SEL, ...))imp)(__CODEPP_MSGSEND_TLI(__VA_ARGS__))
///// 指定返回类型的，如值类型；
//#define CAL_IMP_T(rT, imp, ...) \
//((T(*)(id, SEL, ...))imp)(__CODEPP_MSGSEND_TLI(__VA_ARGS__))

#pragma mark - PAS赋值糖
#define PAS_IF(dst, src, C)     if((C)) { dst = src; }
#define PAS_TRINO(dst, C, A, B) (dst = (C)?(A):(B))
#define PAS_EXT(dst, ...)   if((__VA_ARGS__)!=nil) { dst = (__VA_ARGS__); }

#pragma mark - RET 糖
/// return nil, 0.
#define RET0        return (void *)0);
/// return self
#define RET_SELF    return self;
/// ret[,default] 如果存在则返回
#define RET_EXT(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
(if((__VA_ARGS__)) return __VA_ARGS__) \
(return CORE_CONNECT_HEAD(__VA_ARGS__)?:(CORE_CONNECT_TAIL(__VA_ARGS__)))
/// [ret,]C
#define RET_IF(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    (if((CORE_CONNECT_HEAD(__VA_ARGS__))) return)        \
    (if((CORE_CONNECT_TAIL(__VA_ARGS__))) {return CORE_CONNECT_HEAD(__VA_ARGS__);})

#pragma mark - IF 糖
/// 条件[,...]
#define IF_HAS(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if((__VA_ARGS__)))\
    (if((CORE_CONNECT_HEAD(__VA_ARGS__))) CORE_CONNECT_TAIL(__VA_ARGS__))
/// 条件[,...]
#define IF_NOT(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(!(__VA_ARGS__)))\
    (if(!(CORE_CONNECT_HEAD(__VA_ARGS__))) CORE_CONNECT_TAIL(__VA_ARGS__))
/// C[,ret]
#define IF_RET(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if((CORE_CONNECT_HEAD(__VA_ARGS__))) return) \
    (if((CORE_CONNECT_HEAD(__VA_ARGS__))) {return CORE_CONNECT_TAIL(__VA_ARGS__);})
/// C[,EXP]
#define IF_NSNULL(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([(__VA_ARGS__) isEqual:NSNull.null])) \
    (if([(CORE_CONNECT_HEAD(__VA_ARGS__)) isEqual:NSNull.null]){CORE_CONNECT_TAIL(__VA_ARGS__)})
/// C[,EXP]
#define IF_NONSNULL(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(![(__VA_ARGS__) isEqual:NSNull.null])) \
    (if(![CORE_CONNECT_HEAD(__VA_ARGS__) isEqual:NSNull.null]){CORE_CONNECT_TAIL(__VA_ARGS__)})
/// A,B[,EXP]
#define IF_EQ(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqual:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqual:((id)__CODEPP_ARG_1(__VA_ARGS__))]) {__CODEPP_ARG_THAN_2(__VA_ARGS__)})
#define IF_NOT_EQ(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqual:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqual:((id)__CODEPP_ARG_1(__VA_ARGS__))]) {__CODEPP_ARG_THAN_2(__VA_ARGS__)})
/// A,B[,EXP]
#define IF_EQ_STR(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToString:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToString:((id)__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
#define IF_NOT_EQ_STR(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToString:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToString:((id)__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
/// A,B[,EXP]
#define IF_EQ_NB(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToNumber:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToNumber:((id)__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
#define IF_NOT_EQ_NB(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToNumber:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToNumber:((id)__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
/// VAR,CLZ[,...]
#define IF_AS(...)  \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isKindOfClass:THE_CLASS(__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isKindOfClass:THE_CLASS(__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
#define IF_PAS(C, dst, src) PAS_IF(dst, src, C)
#pragma mark - LOG 糖
/// Log
#if DEBUG
#define DELOG(...)      NSLog(@"调试输出:%@",[NSString stringWithFormat:__VA_ARGS__])
#define DELOG_OBJ(...)  NSLog(@"调试输出:对象:%@", __VA_ARGS__)
#define DELOG_METHOD    NSLog(@"调试输出:%s", __FUNCTION__);
#define DELOG_DEDEALLOC \
-(void)dealloc {NSLog(@"调试输出 销毁: %@ , %p", NSStringFromClass(self.class), self);}

#else
#define DELOG(...)      THE_NOTHING
#define DELOG_OBJ(...)  THE_NOTHING
#define DELOG_METHOD    THE_NOTHING
#define DELOG_DEDEALLOC THE_NOTHING
#endif

#pragma mark - FOR IN糖
/// dst[,T]
#define FOR_IN_ITEM(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
(for(typeof([__VA_ARGS__ firstObject]) item in __VA_ARGS__)) \
(for(CORE_CONNECT_TAIL(__VA_ARGS__) item in CORE_CONNECT_HEAD(__VA_ARGS__)))
/**
 * to
 * [from,]to
 * [from,]to[,var]
 */
#define FOR_INT_I(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
(for(xint i = 0; i < __VA_ARGS__; i++)) \
(CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
(for(xint i = CORE_CONNECT_HEAD(__VA_ARGS__); i < CORE_CONNECT_TAIL(__VA_ARGS__); i++)) \
(for(xint __CODEPP_ARG_THAN_2(__VA_ARGS__) = __CODEPP_ARG_0(__VA_ARGS__); __CODEPP_ARG_THAN_2(__VA_ARGS__) < __CODEPP_ARG_1(__VA_ARGS__); __CODEPP_ARG_THAN_2(__VA_ARGS__) ++))) \

#pragma mark - BLOCK 糖
#define THE_ID_BLOCK(...)     ^id(__CODEPP_BLOCK_TLI(__VA_ARGS__))
#define THE_VOID_BLOCK(...)   ^void(__CODEPP_BLOCK_TLI(__VA_ARGS__))
/// T,args...
#define THE_BLOCK(...)        ^CORE_CONNECT_HEAD(__VA_ARGS__)(__CODEPP_BLOCK_TLI(__VA_ARGS__))

#pragma mark - TYPE 糖
/// 返回类型，变量名，参数列表
#define TYPE_BLOCK(T, ...) T(^CORE_CONNECT_HEAD(__VA_ARGS__))(__CODEPP_BLOCK_TLI(__VA_ARGS__))
#define TYPE_AS(T, var)      ((T)(var))
#define TYPE_ANY(var)        ((id)(var))
#define TYPE_SELF(var)       typeof(self) var
#define TYPE_FROM(dst, var)  typeof(dst) var

#pragma mark - IS糖
#define IS_NOT(...)          THE_FALSES(__VA_ARGS__)
#define IS_TRUE(...)         THE_TRUES(__VA_ARGS__)
#define IS_BETWEEN(dst, L, R) (L < dst && dst < R)
#define IS_BETWEEN_LR(dst, L, R) (L <= dst && dst <= R)
#define IS_BETWEEN_L(dst, L, R) (L <= dst && dst < R)
#define IS_BETWEEN_R(dst, L, R) (L < dst && dst <= R)
#define IS_BIGGER(dst, num) (dst > num)
#define IS_BIGGER_EQ(dst, num) (dst >= num)
#define IS_SMALLER(dst, num) (dst < num)
#define IS_SMALLER_EQ(dst, num) (dst <= num)

#pragma mark - 二级定义

#define __CODEPP_COLOR(R,G,B,A)  \
[UIColor colorWithRed:TYPE_AS(CGFloat,R)/255.0f \
    green:TYPE_AS(CGFloat,G)/255.0f \
    blue:TYPE_AS(CGFloat,B)/255.0f \
    alpha:TYPE_AS(CGFloat,A)]

#define __CODEPP_HEX_COLOR(HEX,A) \
[UIColor colorWithRed:TYPE_AS(CGFloat,(HEX & 0XFF0000) >> 16)/255.0f \
    green:TYPE_AS(CGFloat,(HEX & 0XFF00) >> 8)/255.0f \
    blue:TYPE_AS(CGFloat,(HEX & 0XFF))/255.0f \
    alpha:TYPE_AS(CGFloat,A)]

#define __CODEPP_KEYPATH1(PATH) \
    (((void)(NO && ((void)PATH, NO)), strchr(# PATH, '.') + 1))

#define __CODEPP_KEYPATH2(OBJ, PATH) \
    (((void)(NO && ((void)OBJ.PATH, NO)), # PATH))


#define __CODEPP_FOREACH_CAL(INDEX, CONTEXT, VAR) CONTEXT(VAR)

#define __CODEPP_FOREACH_ORD(INDEX, CONTEXT, VAR) CONTEXT VAR

#define __CODEPP_COPY0(...)
#define __CODEPP_COPY1(...)  __VA_ARGS__
#define __CODEPP_COPY2(...)  __VA_ARGS__ __CODEPP_COPY1(__VA_ARGS__)
#define __CODEPP_COPY3(...)  __VA_ARGS__ __CODEPP_COPY2(__VA_ARGS__)
#define __CODEPP_COPY4(...)  __VA_ARGS__ __CODEPP_COPY3(__VA_ARGS__)
#define __CODEPP_COPY5(...)  __VA_ARGS__ __CODEPP_COPY4(__VA_ARGS__)
#define __CODEPP_COPY6(...)  __VA_ARGS__ __CODEPP_COPY5(__VA_ARGS__)
#define __CODEPP_COPY7(...)  __VA_ARGS__ __CODEPP_COPY6(__VA_ARGS__)
#define __CODEPP_COPY8(...)  __VA_ARGS__ __CODEPP_COPY7(__VA_ARGS__)
#define __CODEPP_COPY9(...)  __VA_ARGS__ __CODEPP_COPY8(__VA_ARGS__)
#define __CODEPP_COPY10(...) __VA_ARGS__ __CODEPP_COPY9(__VA_ARGS__)
#define __CODEPP_COPY11(...) __VA_ARGS__ __CODEPP_COPY10(__VA_ARGS__)
#define __CODEPP_COPY12(...) __VA_ARGS__ __CODEPP_COPY11(__VA_ARGS__)
#define __CODEPP_COPY13(...) __VA_ARGS__ __CODEPP_COPY12(__VA_ARGS__)
#define __CODEPP_COPY14(...) __VA_ARGS__ __CODEPP_COPY13(__VA_ARGS__)
#define __CODEPP_COPY15(...) __VA_ARGS__ __CODEPP_COPY14(__VA_ARGS__)
#define __CODEPP_COPY16(...) __VA_ARGS__ __CODEPP_COPY15(__VA_ARGS__)
#define __CODEPP_COPY17(...) __VA_ARGS__ __CODEPP_COPY16(__VA_ARGS__)
#define __CODEPP_COPY18(...) __VA_ARGS__ __CODEPP_COPY17(__VA_ARGS__)
#define __CODEPP_COPY19(...) __VA_ARGS__ __CODEPP_COPY18(__VA_ARGS__)
#define __CODEPP_COPY20(...) __VA_ARGS__ __CODEPP_COPY19(__VA_ARGS__)

#define __CODEPP_MSGSEND_TLI(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (__CODEPP_ARG_0(__VA_ARGS__),__CODEPP_ARG_1(__VA_ARGS__))\
    (__CODEPP_ARG_0(__VA_ARGS__),__CODEPP_ARG_1(__VA_ARGS__),__CODEPP_ARG_THAN_2(__VA_ARGS__))
// 第一个抛弃的参数+参数列表的输入后取得返回类型
#define __CODEPP_BLOCK_TLI(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(void)(CORE_CONNECT_TAIL(__VA_ARGS__))

#define __CODEPP_ARG_0(_0, ...) _0
#define __CODEPP_ARG_1(_0, _1, ...) _1
#define __CODEPP_ARG_THAN_2(_0, _1, ...) __VA_ARGS__

#define __CODEPP_FOREACH_LZLDp(INDEX, CONTEXT, VAR) [CONTEXT cpp_setInitValueForKey:@__CODEPP_KEYPATH2(CONTEXT, VAR)]
#define __CODEPP_FOREACH_LZLD(INDEX, CONTEXT, VAR) [CONTEXT cpp_setInitValueForKey:VAR]

NS_INLINE __kindof NSValue * __CodePPBox(const char *type, ...) {
    va_list v;
    va_start(v, type);
    id obj = nil;
    if (strcmp(type, @encode(id)) == 0) {
        id actual = va_arg(v, id);
        obj = actual;
    } else if (strcmp(type, @encode(char*)) == 0 ||
               (type[0] == '[' && type[strlen(type) - 2] == 'c')) {
        char *actual = (char*)va_arg(v, char*);
        obj = [NSString stringWithUTF8String:actual];
    } else if (strcmp(type, @encode(double)) == 0) {
        double actual = (double)va_arg(v, double);
        obj = [NSNumber numberWithDouble:actual];
    } else if (strcmp(type, @encode(float)) == 0) {
        float actual = (float)va_arg(v, double);
        obj = [NSNumber numberWithFloat:actual];
    } else if (strcmp(type, @encode(int)) == 0) {
        int actual = (int)va_arg(v, int);
        obj = [NSNumber numberWithInt:actual];
    } else if (strcmp(type, @encode(long)) == 0) {
        long actual = (long)va_arg(v, long);
        obj = [NSNumber numberWithLong:actual];
    } else if (strcmp(type, @encode(long long)) == 0) {
        long long actual = (long long)va_arg(v, long long);
        obj = [NSNumber numberWithLongLong:actual];
    } else if (strcmp(type, @encode(short)) == 0) {
        short actual = (short)va_arg(v, int);
        obj = [NSNumber numberWithShort:actual];
    } else if (strcmp(type, @encode(char)) == 0) {
        char actual = (char)va_arg(v, int);
        obj = [NSNumber numberWithChar:actual];
    } else if (strcmp(type, @encode(bool)) == 0) {
        bool actual = (bool)va_arg(v, int);
        obj = [NSNumber numberWithBool:actual];
    } else if (strcmp(type, @encode(unsigned char)) == 0) {
        unsigned char actual = (unsigned char)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedChar:actual];
    } else if (strcmp(type, @encode(unsigned int)) == 0) {
        unsigned int actual = (unsigned int)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedInt:actual];
    } else if (strcmp(type, @encode(unsigned long)) == 0) {
        unsigned long actual = (unsigned long)va_arg(v, unsigned long);
        obj = [NSNumber numberWithUnsignedLong:actual];
    } else if (strcmp(type, @encode(unsigned long long)) == 0) {
        unsigned long long actual = (unsigned long long)va_arg(v, unsigned long long);
        obj = [NSNumber numberWithUnsignedLongLong:actual];
    } else if (strcmp(type, @encode(unsigned short)) == 0) {
        unsigned short actual = (unsigned short)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedShort:actual];
    } else if (strcmp(type, @encode(xrect)) == 0) {
        xrect actual = (xrect)va_arg(v, xrect);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(xpoint)) == 0) {
        xpoint actual = (xpoint)va_arg(v, xpoint);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(xsize)) == 0) {
        xsize actual = (xsize)va_arg(v, xsize);
        obj = [NSValue value:&actual withObjCType:type];
    }
    va_end(v);
    return obj;
}

#endif /* CodePP_h */
