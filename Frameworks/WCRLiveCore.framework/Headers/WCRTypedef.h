//
//  WCRTypedef.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 退出教室原因

 - WCRLeaveRoomReasonNone: 初始值
 - WCRLeaveRoomReasonUserLeave: App主动退出
 - WCRLeaveRoomReasonReconnectFailed: 重连多次失败导致异常退出
 - WCRLeaveRoomReasonLoginOnOnterDevice: 其他设备登录导致异常退出
 - WCRLeaveRoomReasonMax: 不在[WCRLeaveRoomReasonNone,WCRLeaveRoomReasonMax]区间的值都属于异常
 */
typedef NS_ENUM(NSUInteger, WCRLeaveRoomReason) {
    WCRLeaveRoomReasonNone = 0,
    WCRLeaveRoomReasonUserLeave,
    WCRLeaveRoomReasonReconnectFailed,
    WCRLeaveRoomReasonLoginOnOnterDevice,
    WCRLeaveRoomReasonMax
};

/**
 内容的显示模式，目前只支持两种模式
 
 - WCRLiveStreamContentModeAspectFit: AspectFit
 - WCRLiveStreamContentModeAspectFill: AspectFill
 */
typedef NS_ENUM(NSUInteger, WCRLiveStreamContentMode) {
    WCRLiveStreamContentModeAspectFit = 0,
    WCRLiveStreamContentModeAspectFill
};


/**
 流的设备类型

 - StreamDeviceStatusNone: 初始值
 - StreamDeviceStatusOpened: 开启,app从后台转到前台需要发送这个类型。 麦克风被关闭要发送这个+StatusOpened/StatusClosed
 - StreamDeviceStatusClosed: 关闭,如果声音太大，需要发送这个+WCRVideoStreamTypeLoudspeaker
 - StreamDeviceStatusNotFound: 未找到
 - StreamDeviceStatusError: 异常
 - StreamDeviceStatusUnauthorized: 未授权(是指ipad摄像头、麦克风权限没有打开、和老师端约定20170816)
 - StreamDeviceStatusBackground: 在后台，app进入后台需要发送这个
 - StreamDeviceStatusMax: 不在[WCRStreamDeviceStatusNone,WCRStreamDeviceStatusMax]区间的值都属于异常
 */
typedef NS_ENUM(NSUInteger, WCRStreamDeviceStatus) {
    WCRStreamDeviceStatusNone = 0,
    WCRStreamDeviceStatusOpened,
    WCRStreamDeviceStatusClosed,
    WCRStreamDeviceStatusNotFound,
    WCRStreamDeviceStatusError,
    WCRStreamDeviceStatusUnauthorized,
    WCRStreamDeviceStatusBackground,
    WCRStreamDeviceStatusMax
};

/**
 视频播放类型

 - WCRVideoStreamPlayModeNone: 初始值
 - WCRVideoStreamPlayModePrimary: 全屏视频
 - WCRVideoStreamPlayModePreview: 预览视频
 - WCRVideoStreamPlayModeFloat: 浮出视频
 - WCRVideoStreamPlayModeMax: 不在[WCRVideoStreamPlayModeNone,WCRVideoStreamPlayModeMax]区间的值都属于异常
 
 */
typedef NS_ENUM(NSUInteger, WCRVideoStreamPlayMode) {
    WCRVideoStreamPlayModeNone = 0,
    WCRVideoStreamPlayModePrimary, //全屏视频
    WCRVideoStreamPlayModePreview, //预览视频
    WCRVideoStreamPlayModeFloat,//浮出视频
    WCRVideoStreamPlayModeMax
};

/**
 流类型
 
 - WCRVideoStreamTypeNone: 初始值
 - WCRVideoStreamTypeVideo: 只有视频
 - WCRVideoStreamTypeAudio: 只有音频
 - WCRVideoStreamTypeVideoAndAudio: 音频和视频
 - WCRVideoStreamTypeScreen: 屏幕
 - WCRVideoStreamTypeLoudSpeaker: 声音太小
 - WCRVideoStreamTypeScreenAndAudio: 屏幕+音频
 - WCRVideoStreamTypeScreenAndVideo: 屏幕+视频
 */
typedef NS_OPTIONS(NSUInteger, WCRVideoStreamType) {
  WCRVideoStreamTypeNone = 0,
  WCRVideoStreamTypeVideo = 1 << 0,
  WCRVideoStreamTypeAudio = 1 << 1,
  WCRVideoStreamTypeVideoAndAudio = WCRVideoStreamTypeAudio | WCRVideoStreamTypeVideo,
  WCRVideoStreamTypeScreen = 1 << 2,
  WCRVideoStreamTypeLoudSpeaker = 1<<3,
  WCRVideoStreamTypeScreenAndAudio = WCRVideoStreamTypeScreen | WCRVideoStreamTypeAudio,
  WCRVideoStreamTypeScreenAndVideo = WCRVideoStreamTypeScreen | WCRVideoStreamTypeVideo,
  WCRVideoStreamTypeMax = 1<<4
};

/*
 进房步骤

 - WCRRoomLoadingStepNone: 初始状态
 - WCRRoomLoadingStepLoadRoomConfig: 加载房间信息
 - WCRRoomLoadingStepConnectMessageServer: 连接消息服务器
 - WCRRoomLoadingStepLastStep: 最后一步：连接消息服务器
 */
typedef NS_ENUM(NSUInteger, WCRRoomLoadingStep) {
    WCRRoomLoadingStepNone = 0,
    WCRRoomLoadingStepLoadRoomConfig,
    WCRRoomLoadingStepConnectMessageServer,
    WCRRoomLoadingStepLastStep = WCRRoomLoadingStepConnectMessageServer
};

/**
 当前进房步骤的结果
 - WCRRoomLoadingStepResultOK: 成功
 - WCRRoomLoadingStepResultPending: 加载中
 - WCRRoomLoadingStepResultFailed: 失败
 */
typedef NS_ENUM(NSUInteger, WCRRoomLoadingStepResult) {
    WCRRoomLoadingStepResultOK = 0,
    WCRRoomLoadingStepResultPending,
    WCRRoomLoadingStepResultFailed
};

/**
 房间状态
 
 - WCRLiveRoomStatusNone: 初始值
 - WCRLiveRoomStatusPreparingRoom: 正在准备房间
 - WCRLiveRoomStatusDisconnected: 房间掉线
 - WCRLiveRoomStatusReconnecting: 房间重连，成功后会切换到InRoom状态
 - WCRLiveRoomStatusReconnectFailed: 房间重连失败
 - WCRLiveRoomStatusLeavingRoom: 正在退出房间
 - WCRLiveRoomStatusInRoom: 正在房间中
 - WCRLiveRoomStatusMax: 不在[WCRLiveRoomStatusNone,WCRLiveRoomStatusMax]区间的为异常值
 */

typedef NS_ENUM(NSUInteger, WCRLiveRoomStatus) {
    WCRLiveRoomStatusNone = 0,
    WCRLiveRoomStatusPreparingRoom,
    WCRLiveRoomStatusDisconnected,
    WCRLiveRoomStatusReconnecting,
    WCRLiveRoomStatusReconnectFailed,
    WCRLiveRoomStatusLeavingRoom,
    WCRLiveRoomStatusInRoom,
    WCRLiveRoomStatusMax
};

/**
 音视频模块的状态
 
 - WCRLiveStreamStatusNone: 初始值
 - WCRLiveStreamStatusPreparing: 正在准备音视频模块
 - WCRLiveStreamStatusConnecting: 正在连接音视频模块
 - WCRLiveStreamStatusReconnecting: 正在重新连接音视频模块
 - WCRLiveStreamStatusChangeStreamService: 正在切换音视频模块类型
 - WCRLiveStreamStatusDisconnecting: 正在断开音视频模块的连接
 - WCRLiveStreamStatusReady: 音视频模块准备完成
 - WCRLiveStreamStatusMax: 不在[WCRLiveStreamStatusNone,WCRLiveStreamStatusMax]区间的为异常值
 
 正常音视频模块进入逻辑:
 WCRLiveStreamStatusPreparing->WCRLiveStreamStatusConnecting->WCRLiveStreamStatusReady
 
 正常音视频模块退出逻辑:
 WCRLiveStreamStatusReady->WCRLiveStreamStatusDisconnecting
 
 正常音视频模块重连逻辑:
 WCRLiveStreamStatusPreparing->WCRLiveStreamStatusConnecting->WCRLiveStreamStatusReconnecting*N->WCRLiveStreamStatusReady
 
 正常音视频模块切换线路逻辑:
 WCRLiveStreamStatusReady->WCRLiveStreamStatusChangeStreamService->WCRLiveStreamStatusDisconnecting->WCRLiveStreamStatusConnecting->WCRLiveStreamStatusReady
 
 */
typedef NS_ENUM(NSUInteger, WCRLiveStreamStatus){
    WCRLiveStreamStatusNone = 0,
    WCRLiveStreamStatusPreparing,
    WCRLiveStreamStatusConnecting,
    WCRLiveStreamStatusReconnecting,
    WCRLiveStreamStatusChangeStreamService,
    WCRLiveStreamStatusDisconnecting,
    WCRLiveStreamStatusReady,
    WCRLiveStreamStatusMax
};


/**
 涂鸦信道连接状态

 - WCRDoodleConnectStatusNone: 初始值
 - WCRDoodleConnectStatusConnected: 已连接
 - WCRDoodleConnectStatusConnecting: 正在连接
 - WCRDoodleConnectStatusDisconnected: 断开连接
 - WCRDoodleConnectStatusReconnected: 重连完成
 - WCRDoodleConnectStatusMax: 不在[WCRDoodleConnectStatusNone,WCRDoodleConnectStatusMax]区间的为异常值
 */
typedef NS_ENUM(NSUInteger, WCRDoodleConnectStatus) {
    WCRDoodleConnectStatusNone = 0,
    WCRDoodleConnectStatusConnected,
    WCRDoodleConnectStatusConnecting,
    WCRDoodleConnectStatusDisconnected,
    WCRDoodleConnectStatusReconnected,
    WCRDoodleConnectStatusMax
};


/**
 SDK使用的环境

 - WCREnvironmentTypeOnline: 线上环境
 - WCREnvironmentTypePreOnline: 预上线环境
 - WCREnvironmentTypeTest: 测试环境
 - WCREnvironmentTypeDevelop: 开发环境
 */
typedef NS_ENUM(NSUInteger, WCREnvironmentType) {
    WCREnvironmentTypeOnline = 0,
    WCREnvironmentTypePreOnline = 1,
    WCREnvironmentTypeTest = 2,
    WCREnvironmentTypeDevelop = 3
};

/**
 小黑板 状态

 - WCRBlackBoardStateBeforeSetup: 小黑板创建之前
 - WCRBlackBoardStateReadyToOpen: 小黑板等待打开
 - WCRBlackBoardStateBeforeDistribute: 小黑板分发之前
 - WCRBlackBoardStateDuringDistribute: 小黑板分发中
 - WCRBlackBoardStatePermissionWithDraw:  小黑板绘被收回
 */
typedef NS_ENUM(NSUInteger, WCRBlackBoardState) {
    WCRBlackBoardStateBeforeSetup = 0,
    WCRBlackBoardStateReadyToOpen,
    WCRBlackBoardStateBeforeDistribute,
    WCRBlackBoardStateDuringDistribute,
    WCRBlackBoardStatePermissionWithDraw
};


/**
 课件的类型

 - WCRDocumentTypePPT: PPT课件
 - WCRDocumentTypePDF: PDF课件
 - WCRDocumentTypeImage: 图片课件
 - WCRDocumentTypeWhiteBoard: 白板课件
 - WCRDocumentTypeOtherWeb: 网页课件
 - WCRDocumentTypeTALQS: 网页课件
 - WCRDocumentTypeAudio: 音频课件
 - WCRDocumentTypeVideo: 视频课件
 - WCRDocumentTypeNova: Nova课件
 @warning 顺序与数目跟信道绑定，不能任意添加删除移动顺序
 */
typedef NS_ENUM(NSUInteger, WCRDocumentType){
    WCRDocumentTypeNone = 0,
    WCRDocumentTypePPT,
    WCRDocumentTypePDF,
    WCRDocumentTypeImage,
    WCRDocumentTypeWhiteBoard,
    WCRDocumentTypeOtherWeb,
    WCRDocumentTypeTALQS,
    WCRDocumentTypeVideo,
    WCRDocumentTypeAudio,
    WCRDocumentTypeNova
};


/**
 获取回放地址的状态

 - WCRPlaybackStatusNone: 初始值
 - WCRPlaybackStatusFetching: 正在获取回放地址
 - WCRPlaybackStatusFetched: 获取回放地址成功
 - WCRPlaybackStatusFetched: 获取回放地址失败
 - WCRPlaybackStatusMax: 不在[WCRPlaybackStatusNone,WCRPlaybackStatusMax]区间的为异常值
 */
typedef NS_ENUM(NSUInteger, WCRPlaybackStatus){
    WCRPlaybackStatusNone = 0,
    WCRPlaybackStatusFetching,
    WCRPlaybackStatusFetched,
    WCRPlaybackStatusFailed,
    WCRPlaybackStatusMax
};

/**
 用户拉流视频的预览模式

 - WCRPreviewStyleNone: 初始值
 - WCRPreviewStyleStable: 固定模式
 - WCRPreviewStyleFloat: 浮动模式
 - WCRPreviewStyleMax: 不在[WCRPreviewStyleNone,WCRPreviewStyleMax]区间的为异常值
 */
typedef NS_ENUM(NSUInteger, WCRPreviewStyle){
    WCRPreviewStyleNone = 0,
    WCRPreviewStyleStable,
    WCRPreviewStyleFloat,
    WCRPreviewStyleMax
};
