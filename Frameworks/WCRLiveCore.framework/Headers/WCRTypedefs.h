//
//  WCRTypedefs.h
//  test
//
//  Created by 欧阳铨 on 2019/3/15.
//  Copyright © 2019 com.100tal. All rights reserved.
//
#ifndef WCRTypedefs_h
#define WCRTypedefs_h

/**
 用户角色
 
 - WCRUserRoleNone: 初始值
 - WCRUserRoleStudent: 学生
 - WCRUserRoleTeacher: 老师
 - WCRUserRoleCounselor: 辅讲老师
 - WCRUserRoleAssistant: 助教/监课
 - WCRUserRoleMax: 不在[WCRUserRoleNone,WCRUserRoleMax]区间的值都属于异常
 */
typedef NS_ENUM(NSUInteger, WCRUserRole) {
    WCRUserRoleNone = 0,
    WCRUserRoleStudent,
    WCRUserRoleTeacher,
    WCRUserRoleCounselor,
    WCRUserRoleAssistant,
    WCRUserRoleMax
};

/**
 房间类型
 
 - WCRRoomTypeNone: 初始值
 - WCRRoomTypeOneToOne: 一对一
 - WCRRoomTypeSmallClass: 小班
 - WCRRoomTypeLargeClass: 大班
 - WCRRoomTypeIBL: IBL
 - WCRRoomTypeMax: 不在[WCRRoomTypeNone,WCRRoomTypeMax]区间的值都属于异常
 */
typedef NS_ENUM(NSUInteger, WCRRoomType) {
    WCRRoomTypeNone = 0,
    WCRRoomTypeOneToOne,
    WCRRoomTypeSmallClass,
    WCRRoomTypeLargeClass,
    WCRRoomTypeIBL,
    WCRRoomTypeMax
};

/**
 课堂状态
 
 - WCRLiveRoomClassStatusNone: 初始值
 - WCRLiveRoomClassStatusBeforeClass 课前
 - WCRLiveRoomClassStatusInClass: 课中
 - WCRLiveRoomClassStatusAfterClass: 课后
 - WCRLiveRoomClassStatusMax: 不在[WCRLiveRoomClassStatusNone,WCRLiveRoomClassStatusMax]区间的为异常值
 */
typedef NS_ENUM(NSUInteger, WCRLiveRoomClassStatus) {
    WCRLiveRoomClassStatusNone = 0,
    WCRLiveRoomClassStatusBeforeClass,
    WCRLiveRoomClassStatusInClass,
    WCRLiveRoomClassStatusAfterClass,
    WCRLiveRoomClassStatusMax
};


/**
 课堂模块
 
 - WCRLiveRoomModuleNone: 初始值，不使用模块
 - WCRLiveRoomModuleStream: 音视频模块
 - WCRLiveRoomModuleDocument: 文档模块
 - WCRLiveRoomModuleDoodle: 涂鸦模块
 - WCRLiveRoomModuleChat: 聊天模块（未实现）
 - WCRLiveRoomModuleAll: 使用全部模块
 - WCRLiveRoomModuleMax: 不在[WCRLiveRoomModuleNone,WCRLiveRoomModuleMax]区间的为异常值
 */
typedef NS_OPTIONS(NSUInteger, WCRLiveRoomModule){
    WCRLiveRoomModuleNone = 0,
    WCRLiveRoomModuleStream = 1 << 0,
    WCRLiveRoomModuleDocument = 1 << 1,
    WCRLiveRoomModuleDoodle = 1 << 2,
    WCRLiveRoomModuleChat = 1 << 3,
    WCRLiveRoomModuleAll = WCRLiveRoomModuleStream | WCRLiveRoomModuleDocument | WCRLiveRoomModuleDoodle | WCRLiveRoomModuleChat,
    WCRLiveRoomModuleMax = 1 << 5
};

/**
 用户使用的设备/端类型
 
 - WCRUserDeviceNone: 初始值
 - WCRUserDeviceWindows: windows设备
 - WCRUserDevicePCWeb: PC web
 - WCRUserDeviceAndroid: 安卓
 - WCRUserDeviceMobileWeb: 手机web
 - WCRUserDeviceMacOS: MAC
 - WCRUserDeviceiPhone: iPhone
 - WCRUserDeviceiPad: iPad
 - WCRUserDeviceMax: 不在[WCRUserDeviceNone,WCRUserDeviceMax]区间的值都属于异常
 */
typedef NS_ENUM(NSUInteger, WCRUserDevice) {
    WCRUserDeviceNone = 0,
    WCRUserDeviceWindows,
    WCRUserDevicePCWeb,
    WCRUserDeviceAndroid,
    WCRUserDeviceMobileWeb,
    WCRUserDeviceMacOS,
    WCRUserDeviceiPhone,
    WCRUserDeviceiPad,
    WCRUserDeviceMax
};

/**
 回放类型
 
 - WCRRoomPlaybackTypeVideo: 视频回放，原理为播放视频
 - WCRRoomPlaybackTypeAction: 事件回放，原理为模拟上课的所有事件
 */
typedef NS_ENUM(NSUInteger, WCRRoomPlaybackType) {
    WCRRoomPlaybackTypeVideo = 0,
    WCRRoomPlaybackTypeAction = 1
};
#endif /* WCRTypedefs_h */
