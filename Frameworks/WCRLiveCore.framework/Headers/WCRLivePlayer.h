//
//  WCRLivePlayerWrap.h
//  WCRLivePlayerBirdge
//
//  Created by Sanji on 16/8/4.
//  Copyright © 2016年 Sanji. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WCRLiveCommonDefine.h"
#import "WCRLiveStreamInfo.h"
#import "WCRLiveClassInfoModel.h"
#import "WCRLivePlayerConfigModel.h"
#import "WCRLivePlayerProxyConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

@class WCRLivePlayer;

/**
 播放器代理协议，处理播放器的回调
 */
@protocol WCRLivePlayerDelegate <NSObject>
@optional
/**
 播放器状态回调
 @param player 播放器
 @param status 播放器状态
 */
- (void)onLivePlayer:(WCRLivePlayer *_Nonnull)player statusChanged:(WCRLivePlayerStatus)status;
/**
 播放器错误回调
 @param player 播放器
 @param error 播放器错误类型
 */
- (void)onLivePlayer:(WCRLivePlayer *_Nonnull)player error:(WCRLivePlayerError )error;
/**
 播放器数据关键数据回调，每秒执行一次回调
 @param player 播放器
 @param videoFps fps
 @param videoPacketLostRate 视频丢包率
 @param downloadSpeed 下载速度 单位KB/s
 */
- (void)onLivePlayer:(WCRLivePlayer *_Nonnull)player videoFps:(NSInteger)videoFps videoPacketLostRate:(NSInteger)videoPacketLostRate downloadSpeed:(CGFloat)downloadSpeed;
/**
 播放器关键性事件回调
 @param player 播放器
 @param event 关键性事件
 */
- (void)onLivePlayer:(WCRLivePlayer *_Nonnull)player event:(WCRLivePlayerEvent)event currentStreamInfo:(WCRLiveStreamInfo *_Nonnull)currentStreamInfo currentIndex:(NSInteger)currentIndex;


/**
 播放器自动换线事件回调

 @param player 播放器
 @param reason 自动换线的原因
 @param currentStreamInfo 将要切换的线路
 @param lastStreamInfo 上一条线路
 */
- (void)onLivePlayer:(WCRLivePlayer *_Nonnull)player autoChangeLineForReason:(WCRLivePlayerAutoChangeLineReason)reason currentStreamInfo:(WCRLiveStreamInfo *_Nonnull)currentStreamInfo currentIndex:(NSInteger)currentIndex lastStreamInfo:(WCRLiveStreamInfo*_Nonnull) lastStreamInfo lastIndex:(NSInteger)lastIndex;


/**
 开启代理回调
 @param player 播放器
 @param status 状态码
 */
- (void)onLivePlayer: (WCRLivePlayer *)player openProxyFinishedWithStatus:(WCRProxyConnectStatus)status;

@end

@interface WCRLivePlayer : NSObject
/**
 播放器代理，处理播放器事件回调
 */
@property (nonatomic, weak) id<WCRLivePlayerDelegate> _Nullable delegate;
/**
 当前播放线路信息
 */
@property (nonatomic, strong, readonly)WCRLiveStreamInfo * _Nullable currentStreamInfo;
/**
 播放器播放的线路数组
 */
@property (nonatomic, strong) NSArray<WCRLiveStreamInfo*> * _Nullable streamLines;
/**
 当前班级的信息
 */
@property (nonatomic, strong) WCRLiveClassInfoModel  * _Nullable classInfo;
/**
 播放器配置model
 */
@property (nonatomic, strong) WCRLivePlayerConfigModel * _Nullable configModel;
/**
 数据上报环境
 @warning 测试环境下请设置该值为WCRLiveReportEnvironmentTest
 */
@property (nonatomic, assign) WCRLiveReportEnvironment env;
/// 允许多个播放器同时创建，默认是NO
@property(nonatomic, class)BOOL allowsMultiInit;

/// 代理是否开启中
@property(nonatomic, readonly)BOOL isProxyOpening;

/**
 实例化播放器
 @param containerView 播放器容器视图
 */
- (instancetype _Nonnull )initWithContainerView:(UIView *_Nonnull)containerView;

/**
 播放视频
 @param streamInfo 视频流信息，其中streamInfo的streamId与url两者设置一个
 */
- (void)playWithStreamInfo:(WCRLiveStreamInfo *_Nonnull)streamInfo;

/**
 手动切换线路
 @param streamInfo 视频流信息，其中streamInfo的streamId与url两者设置一个
 */
- (void)changeLineWithStreamInfo:(WCRLiveStreamInfo *_Nonnull)streamInfo;

/**
 直播恢复
 @return 视频是否成功恢复
 */
- (BOOL)resume;
- (void)rePlay;
/**
 直播停止
 */
- (void)stop;

/**
 获取播放器是否播放
 @return 是否播放
 */
- (BOOL)isPlaying;

/**
 设置播放器填充模式
 @param mode 填充模式 默认WCRLivePlayerContentModeScaleAspectFit
 */
- (void)setPlayerViewContentMode:(WCRLivePlayerContentMode)mode;

/**
 设置播放器静音
 @param mute 是否静音
 */
- (void)muteAudio:(BOOL)mute;

/**
 获取播放器是否静音
 @return 是否静音
 */
- (BOOL)isAudioMuted;

/**
 设置播放器音量
 @param volume 音量
 */
- (void)setAudioVolume:(NSInteger)volume;

/**
 播放器销毁
 */
- (void)destroy;

/**
 获取SDK版本号
 */
- (NSString * _Nonnull)getPlayerSDKVersion;

/// 获取代理服务器配置列表
- (void)getProxyConfigurationListWithCompletion: (void(^)(NSArray<WCRLivePlayerProxyConfiguration *> *list, NSError * error))handler;

/// 开启代理
- (void)openProxyWithConfiguration: (WCRLivePlayerProxyConfiguration * _Nonnull)config;

/// 关闭代理
- (void)closeProxy;

/// 更新线路的不可用状态，便于切换线路时自动跳过不可用的
- (void)updateStreamLines: (nonnull NSArray<WCRLiveStreamInfo *> *)lines;

@end
NS_ASSUME_NONNULL_END
