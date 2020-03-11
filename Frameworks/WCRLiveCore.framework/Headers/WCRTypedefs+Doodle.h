//
//  WCRTypedefs+Doodle.h
//  test
//
//  Created by 欧阳铨 on 2019/3/15.
//  Copyright © 2019 com.100tal. All rights reserved.
//
#ifndef WCRTypedefs_Doodle_h
#define WCRTypedefs_Doodle_h

/**
 涂鸦绘制状态

 - WCRDoodleStatusNone: 初始值
 - WCRDoodleStatusBegin: 涂鸦绘制开始
 - WCRDoodleStatusProcess: 涂鸦正在绘制
 - WCRDoodleStatusEnd: 涂鸦绘制结束
 - WCRDoodleStatusFloat: 指示器/激光笔正在指示
 - WCRDoodleStatusLeave: 指示器/激光笔关闭
 - WCRDoodleStatusMax: 不在[WCRDoodleStatusNone,WCRDoodleStatusMax]区间的值都属于异常
 */
typedef NS_ENUM(NSUInteger, WCRDoodleStatus) {
    WCRDoodleStatusNone = 0,
    WCRDoodleStatusBegin,
    WCRDoodleStatusProcess,
    WCRDoodleStatusEnd,
    WCRDoodleStatusFloat,
    WCRDoodleStatusLeave,
    WCRDoodleStatusMax
};
#endif /* WCRTypedefs_Doodle_h */
