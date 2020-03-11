//
//  WCRLiveCommonDefine.h
//  直播云Demo
//
//  Created by 周吾昆 on 2018/2/24.
//  Copyright © 2018年 培优在线. All rights reserved.
//



typedef NS_ENUM(NSInteger, WCRLiveReportEnvironment) {
    WCRLiveReportEnvironmentTest,
    WCRLiveReportEnvironmentOnline
};
typedef NS_ENUM(NSInteger, WCRLivePlayerError) {
    // Generic error code
    WCRLivePlayerErrorUnknown = -1,
    WCRLivePlayerErrorNoError = 0,
    WCRLivePlayerErrorInternalError,
    // WCRLivePlayer error code
    WCRLivePlayerErrorConnectStreamFailed,//错误地址
    WCRLivePlayerErrorBadStream,//老师网络不好或者用户网络不好
    WCRLivePlayerErrorEndOfStream,//老师推流结束
    WCRLivePlayerErrorStreamParameterError,//传入参数错误
};

typedef NS_ENUM(NSInteger, WCRLivePlayerStatus) {
    WCRLivePlayerStatusStarted = 0,
    WCRLivePlayerStatusStartBuffering,
    WCRLivePlayerStatusStopBuffering,
    WCRLivePlayerStatusStopped,
    WCRLivePlayerStatusVideoSize,
    WCRLivePlayerStatusNetworkConnected,
    WCRLivePlayerStatusFirstPacket,
};

typedef NS_ENUM(NSInteger, WCRLivePlayerEvent) {
    // Generic error code
    WCRLivePlayerEventUnknown = -1,
    WCRLivePlayerEventSeriousBuffer = 0,//严重卡顿事件
    WCRLivePlayerEventManualChangeLineSuccess,//手动切换线路成功
    WCRLivePlayerEventManualChangeLineTimeout,//手动切换线路超时
    WCRLiveivePlayerEventReplayTimeout,//重连超时
    WCRLivePlayerEventAutoChangeLineStart,//自动切换线路开始
    WCRLivePlayerEventAutoChangeLineSuccess, //自动切换线路成功
    WCRLivePlayerEventAutoChangeLineOverTimes,//自动切换线路前几个线路连接均失败，次数可在configModel里配置，默认为3次
    WCRLivePlayerEventSuggestOpenProxy //开启代理建议: 当前线路不流畅，提醒用户手动开启代理
};

typedef NS_ENUM(NSInteger, WCRLivePlayerAutoChangeLineReason) {
    WCRLivePlayerAutoChangeLineReasonConnectTimeout = 1, //连接服务器超时5s
    WCRLivePlayerAutoChangeLineReasonFirstVideoSizeTimeout, //首帧连接超时2s
    WCRLivePlayerAutoChangeLineReasonUpdateTimeout,//数据更新超时5s
    WCRLivePlayerAutoChangeLineReasonBufferTimeout,//单次卡顿超过5s
    WCRLivePlayerAutoChangeLineReasonConnectStreamFailedError,//播放器错误回调-连接失败
    WCRLivePlayerAutoChangeLineReasonBadStreamError,//播放器错误回调-无效流地址
    WCRLivePlayerAutoChangeLineReasonEndOfStreamError,//播放器错误回调-推流结束
    WCRLivePlayerAutoChangeLineReasonInternalError,//播放器错误回调-内部错误
    WCRLivePlayerAutoChangeLineReasonLastLineParameterError,//自动切换线路时streamLines获取的streamInfo参数错误，自动切换下一条线路
} ;
typedef NS_ENUM(NSInteger, WCRLivePlayerContentMode) {
    WCRLivePlayerContentModeScaleAspectFit = 0,
    WCRLivePlayerContentModeScaleAspectFill,
};

/// 代理连接状态码
typedef NS_ENUM(NSInteger, WCRProxyConnectStatus) {
    WCRProxyConnectStatusUnknown = -1,
    /// 连接成功
    WCRProxyConnectStatusSucceeded = 0,
    /// 连接代理服务器超时
    WCRProxyConnectStatusErrorConnectProxyServerTimeout = 2001,
    /// 用户名/密码认证超时
    WCRProxyConnectStatusErrorAuthUsernamePasswordTimeout,
    /// 连接目标服务器超时
    WCRProxyConnectStatusErrorConnectTargetServerTimeout,
    /// 用户名/密码认证失败: 比如用户名/密码不匹配、错误
    WCRProxyConnectStatusErrorAuthUsernamePasswordFailed,
    /// 数据发送失败
    WCRProxyConnectStatusErrorSendDataFailed,
    /// 代理服务器不支持SOCKS5协议
    WCRProxyConnectStatusErrorProxyServerNotSupportSOCKS5,
    /// 连接目标服务器失败
    WCRProxyConnectStatusErrorConnectTargetServerFailed,
    /// 其他原因: SOCKS内部错误
    WCRProxyConnectStatusErrorOtherReason,
    /// 代理服务器负载已满
    WCRProxyConnectStatusErrorProxyServerLoadFull,
};
