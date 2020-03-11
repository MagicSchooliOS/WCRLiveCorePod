//
//  WCRLivePlayerConfigModel.h
//  WCRLivePlayerSDK
//
//  Created by 周吾昆 on 2018/8/11.
//  Copyright © 2018年 培优在线. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

typedef enum : NSUInteger {
    WCRLivePlayerUseModeIndependent = 0, //独立使用
    WCRLivePlayerUseModeBlend, //融合使用
} WCRLivePlayerUseMode;

@interface WCRLivePlayerConfigModel : NSObject

///是否可以上传卡顿，默认为YES，课前与课后请设置为NO
@property (nonatomic, assign) BOOL bufferReportEnable;
///卡顿时是否自动切换线路,默认为YES
@property (nonatomic, assign) BOOL autoChangeLineEnable;
///是否开启播放器数据（帧率码率等）回传,默认为NO，开启后每秒进行一次数据回传
@property (nonatomic, assign) BOOL playerDataCallbackEnable;
///是否上传TM日志，默认为YES
@property (nonatomic, assign) BOOL autoUploadTMLog;

///播放器数据回传时间间隔，默认为1s
@property (nonatomic, assign) CGFloat playerDataCallbackTimeInterval;

///数据上报心跳时间间隔，默认为30s
@property (nonatomic, assign) CGFloat reportHearbeatTimeInterval;
///数据上报丢包与延时时间间隔，默认为30s
@property (nonatomic, assign) CGFloat reportLossDelayTimeInterval;

/// 数据上报projectId，默认为12
@property (nonatomic, copy) NSString *projectId;
/// 数据上报partyId，默认为100
@property (nonatomic, copy) NSString *partyId;
/// 数据上报cmdId，默认为320
@property (nonatomic, copy) NSString *cmdId;
///player的maxBufferTime，默认为3000
@property (nonatomic, assign) NSUInteger maxBufferTime;
///拉流地址，默认为rtmp://mlive.weclassroom.com/live_apu/
@property (nonatomic, copy) NSString *streamPullUrl;

///自动切换线路之重连超时时长，默认为5s
@property (nonatomic, assign) CGFloat connectTimeout;
///自动切换线路之获取视频首帧超时时长，默认为4s
@property (nonatomic, assign) CGFloat firstVideoSizeTimeout;
///自动切换线路之数据更新超时时长，默认为5s
@property (nonatomic, assign) NSUInteger dataUpdateTimeout;
///自动切换线路之大卡顿超时时长，默认为5s
@property (nonatomic, assign) CGFloat bigBufferTimeout;

///严重卡顿计算周期，默认为30s
@property (nonatomic, assign) CGFloat seriousBufferPeriod;
///严重卡顿最小计算值，小于该值的卡顿忽略计算，最小值默认为0.5s
@property (nonatomic, assign) CGFloat seriousBufferMinBuffer;
///严重卡顿时间阈值，周期类大于最小卡顿值超过该阈值，视为严重卡顿，默认为5s
@property (nonatomic, assign) CGFloat seriousBufferThreshold;

///自动切换线路超过该次数，会进行关键事件的回调，事件类型为WCRLiveLivePlayerEventAutoChangeLineOverTimes，默认为3次
@property (nonatomic, assign) NSUInteger replayFailCallbackTimes;

// 使用模式，默认为独立使用
@property (nonatomic, assign) WCRLivePlayerUseMode playerUseMode;

/**
 方便统一PlayerConfigModel的默认值

 @return 带有默认值的PlayerConfigModel
 */
+ (instancetype)defaultPlayerConfig;

@end
