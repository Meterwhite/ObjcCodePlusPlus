//
//  CoreConnect.h
//  CoreConnect
//
//  Created by MeterWhite on 2020/6/29.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#ifndef CoreConnect_h
#define CoreConnect_h

/**
 * 关键字方式
 */
#if DEBUG
#define CORE_CONNECT_KEYWORD_DEF                 autoreleasepool {}
#define CORE_CONNECT_KEYWORD_DEF_INNER(...)      autoreleasepool {__VA_ARGS__}
#else
#define CORE_CONNECT_KEYWORD_DEF                 try {} @catch (...) {}
#endif

#define CORE_CONNECT_CONCAT_(A, B) A ## B
/// 拼接宏
#define CORE_CONNECT_CONCAT(A, B) \
CORE_CONNECT_CONCAT_(A, B)
/// 索引取参数 N总数
#define CORE_CONNECT_AT(N, ...) \
CORE_CONNECT_CONCAT(CORE_CONNECT_AT, N)(__VA_ARGS__)
/// 参数数目，最少返回一个
#define CORE_CONNECT_ARGCOUNT(...) \
CORE_CONNECT_AT(20, __VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
///
#define CORE_CONNECT_FOREACH(MACRO, SEP, ...) \
CORE_CONNECT_FOREACH_CXT(CORE_CONNECT_FOREACH_ITER, SEP, MACRO, __VA_ARGS__)
/// MACRO(索引,分隔符,内容,参数)
#define CORE_CONNECT_FOREACH_CXT(MACRO, SEP, CONTEXT, ...) \
CORE_CONNECT_CONCAT(CORE_CONNECT_FOREACH_CXT, CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(MACRO, SEP, CONTEXT, __VA_ARGS__)
/// 数字相等(执行是)(执行否)
#define CORE_CONNECT_IF_EQ(A, B) \
CORE_CONNECT_CONCAT(CORE_CONNECT_IF_EQ, A)(B)

#define CORE_CONNECT_HEAD_(FIRST, ...) FIRST
#define CORE_CONNECT_TAIL_(FIRST, ...) __VA_ARGS__
/// 第一个参数
#define CORE_CONNECT_HEAD(...) CORE_CONNECT_HEAD_(__VA_ARGS__, 0)
/// 除了第一个参数
#define CORE_CONNECT_TAIL(...) CORE_CONNECT_TAIL_(__VA_ARGS__)

#define CORE_CONNECT_DEC(VAL) \
CORE_CONNECT_AT(VAL, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19)

#define CORE_CONNECT_CONSUME_(...)

#define CORE_CONNECT_EXPAND_(...) __VA_ARGS__
/// 连接；SEP,args...
#define CORE_JOIN_WITH(SEP,...) CORE_CONNECT_CONCAT(CORE_JOIN_WITH,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(SEP,__VA_ARGS__)
//AADD_CORE_JOIN_WITH1
// CORE_CONNECT_AT expansions
#define CORE_CONNECT_AT0(...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT1(_0, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT2(_0, _1, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT3(_0, _1, _2, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT4(_0, _1, _2, _3, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT5(_0, _1, _2, _3, _4, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT6(_0, _1, _2, _3, _4, _5, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT7(_0, _1, _2, _3, _4, _5, _6, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT8(_0, _1, _2, _3, _4, _5, _6, _7, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT9(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...) CORE_CONNECT_HEAD(__VA_ARGS__)
#define CORE_CONNECT_AT20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) CORE_CONNECT_HEAD(__VA_ARGS__)


#define CORE_CONNECT_IF_EQ0(VALUE) \
CORE_CONNECT_CONCAT(CORE_CONNECT_IF_EQ0_, VALUE)

#define CORE_CONNECT_IF_EQ0_0(...) __VA_ARGS__ CORE_CONNECT_CONSUME_
#define CORE_CONNECT_IF_EQ0_1(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_2(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_3(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_4(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_5(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_6(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_7(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_8(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_9(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_10(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_11(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_12(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_13(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_14(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_15(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_16(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_17(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_18(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_19(...) CORE_CONNECT_EXPAND_
#define CORE_CONNECT_IF_EQ0_20(...) CORE_CONNECT_EXPAND_

#define CORE_CONNECT_IF_EQ1(VALUE) CORE_CONNECT_IF_EQ0(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ2(VALUE) CORE_CONNECT_IF_EQ1(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ3(VALUE) CORE_CONNECT_IF_EQ2(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ4(VALUE) CORE_CONNECT_IF_EQ3(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ5(VALUE) CORE_CONNECT_IF_EQ4(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ6(VALUE) CORE_CONNECT_IF_EQ5(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ7(VALUE) CORE_CONNECT_IF_EQ6(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ8(VALUE) CORE_CONNECT_IF_EQ7(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ9(VALUE) CORE_CONNECT_IF_EQ8(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ10(VALUE) CORE_CONNECT_IF_EQ9(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ11(VALUE) CORE_CONNECT_IF_EQ10(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ12(VALUE) CORE_CONNECT_IF_EQ11(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ13(VALUE) CORE_CONNECT_IF_EQ12(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ14(VALUE) CORE_CONNECT_IF_EQ13(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ15(VALUE) CORE_CONNECT_IF_EQ14(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ16(VALUE) CORE_CONNECT_IF_EQ15(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ17(VALUE) CORE_CONNECT_IF_EQ16(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ18(VALUE) CORE_CONNECT_IF_EQ17(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ19(VALUE) CORE_CONNECT_IF_EQ18(CORE_CONNECT_DEC(VALUE))
#define CORE_CONNECT_IF_EQ20(VALUE) CORE_CONNECT_IF_EQ19(CORE_CONNECT_DEC(VALUE))

#define CORE_CONNECT_FOREACH_ITER(INDEX, MACRO, ARG) MACRO(INDEX, ARG)

#pragma mark - FOREACH CXT
#define CORE_CONNECT_FOREACH_CXT0(MACRO, SEP, CONTEXT)
#define CORE_CONNECT_FOREACH_CXT1(MACRO, SEP, CONTEXT, _0) MACRO(0, CONTEXT, _0)

#define CORE_CONNECT_FOREACH_CXT2(MACRO, SEP, CONTEXT, _0, _1) \
    CORE_CONNECT_FOREACH_CXT1(MACRO, SEP, CONTEXT, _0) \
    SEP \
    MACRO(1, CONTEXT, _1)

#define CORE_CONNECT_FOREACH_CXT3(MACRO, SEP, CONTEXT, _0, _1, _2) \
    CORE_CONNECT_FOREACH_CXT2(MACRO, SEP, CONTEXT, _0, _1) \
    SEP \
    MACRO(2, CONTEXT, _2)

#define CORE_CONNECT_FOREACH_CXT4(MACRO, SEP, CONTEXT, _0, _1, _2, _3) \
    CORE_CONNECT_FOREACH_CXT3(MACRO, SEP, CONTEXT, _0, _1, _2) \
    SEP \
    MACRO(3, CONTEXT, _3)

#define CORE_CONNECT_FOREACH_CXT5(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4) \
    CORE_CONNECT_FOREACH_CXT4(MACRO, SEP, CONTEXT, _0, _1, _2, _3) \
    SEP \
    MACRO(4, CONTEXT, _4)

#define CORE_CONNECT_FOREACH_CXT6(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5) \
    CORE_CONNECT_FOREACH_CXT5(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4) \
    SEP \
    MACRO(5, CONTEXT, _5)

#define CORE_CONNECT_FOREACH_CXT7(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6) \
    CORE_CONNECT_FOREACH_CXT6(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5) \
    SEP \
    MACRO(6, CONTEXT, _6)

#define CORE_CONNECT_FOREACH_CXT8(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7) \
    CORE_CONNECT_FOREACH_CXT7(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6) \
    SEP \
    MACRO(7, CONTEXT, _7)

#define CORE_CONNECT_FOREACH_CXT9(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    CORE_CONNECT_FOREACH_CXT8(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7) \
    SEP \
    MACRO(8, CONTEXT, _8)

#define CORE_CONNECT_FOREACH_CXT10(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    CORE_CONNECT_FOREACH_CXT9(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    SEP \
    MACRO(9, CONTEXT, _9)

#define CORE_CONNECT_FOREACH_CXT11(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    CORE_CONNECT_FOREACH_CXT10(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    SEP \
    MACRO(10, CONTEXT, _10)

#define CORE_CONNECT_FOREACH_CXT12(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    CORE_CONNECT_FOREACH_CXT11(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    SEP \
    MACRO(11, CONTEXT, _11)

#define CORE_CONNECT_FOREACH_CXT13(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    CORE_CONNECT_FOREACH_CXT12(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    SEP \
    MACRO(12, CONTEXT, _12)

#define CORE_CONNECT_FOREACH_CXT14(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    CORE_CONNECT_FOREACH_CXT13(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    SEP \
    MACRO(13, CONTEXT, _13)

#define CORE_CONNECT_FOREACH_CXT15(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    CORE_CONNECT_FOREACH_CXT14(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    SEP \
    MACRO(14, CONTEXT, _14)

#define CORE_CONNECT_FOREACH_CXT16(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    CORE_CONNECT_FOREACH_CXT15(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    SEP \
    MACRO(15, CONTEXT, _15)

#define CORE_CONNECT_FOREACH_CXT17(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    CORE_CONNECT_FOREACH_CXT16(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    SEP \
    MACRO(16, CONTEXT, _16)

#define CORE_CONNECT_FOREACH_CXT18(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    CORE_CONNECT_FOREACH_CXT17(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    SEP \
    MACRO(17, CONTEXT, _17)

#define CORE_CONNECT_FOREACH_CXT19(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    CORE_CONNECT_FOREACH_CXT18(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    SEP \
    MACRO(18, CONTEXT, _18)

#define CORE_CONNECT_FOREACH_CXT20(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
    CORE_CONNECT_FOREACH_CXT19(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    SEP \
    MACRO(19, CONTEXT, _19)


#define CORE_JOIN_WITH1(SEP,head)      head
#define CORE_JOIN_WITH2(SEP,head,...)  CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH1(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH3(SEP,head,...)  CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH2(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH4(SEP,head,...)  CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH3(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH5(SEP,head,...)  CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH4(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH6(SEP,head,...)  CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH5(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH7(SEP,head,...)  CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH6(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH8(SEP,head,...)  CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH7(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH9(SEP,head,...)  CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH8(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH10(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH9(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH11(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH10(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH12(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH11(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH13(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH12(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH14(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH13(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH15(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH14(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH16(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH15(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH17(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH16(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH18(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH17(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH19(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH18(SEP,__VA_ARGS__))
#define CORE_JOIN_WITH20(SEP,head,...) CORE_CONNECT_CONCAT(CORE_CONNECT_CONCAT(head,SEP),CORE_JOIN_WITH19(SEP,__VA_ARGS__))

#endif /* CoreConnect_h */
