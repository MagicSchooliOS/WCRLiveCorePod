//
//  WCRPlaybackVM.h
//  WCRLiveCore
//
//  Created by Bo Hu on 2019/7/24.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCRPlaybackKeyPointModel.h>
#import <WCRLiveCore/WCRTypedef.h>
#import <CoreGraphics/CGBase.h>
#import <WCRLiveCore/WCRError.h>

NS_ASSUME_NONNULL_BEGIN

@class WCRPlaybackVM;

@protocol WCRPlaybackVMDelegate <NSObject>

/**
 课程回放数据
 
 @param playbackVM self
 @param playbackUrl 回放的地址
 @param backupUrls 回放备用地址
 @param keyPointDatas 回放打点数据
 */
- (void)playbackVM:(WCRPlaybackVM*)playbackVM onPlayback:(NSString *)playbackUrl backupUrls:(NSArray <NSString *>* _Nullable)backupUrls keyPointDatas:(NSArray <WCRPlaybackKeyPointModel *>* _Nullable)keyPointDatas;

/**
 获取回放数据状态改变
 
 @param playbackVM self
 @param status 回放状态 @see WCRPlaybackStatus
 */
- (void)playbackVM:(WCRPlaybackVM*)playbackVM onUpdatePlaybackStatus:(WCRPlaybackStatus)status;

/**
 回放播放遇到错误
 
 @param playbackVM self
 @param error 错误码
 */
- (void)playbackVM:(WCRPlaybackVM*)playbackVM error:(WCRError *)error;

/// 开始卡顿
/// @param playbackVM self
- (void)playbackVMStartBuffering:(WCRPlaybackVM*)playbackVM;

/// 结束卡顿
/// @param playbackVM self
- (void)playbackVMStopBuffering:(WCRPlaybackVM*)playbackVM;

/// 播放结束
/// @param playbackVM self
- (void)playbackVMPlayEnded:(WCRPlaybackVM*)playbackVM;

/// 当前播放时间
/// @param playbackVM self
/// @param currentTime 当前播放时间, 单位: 秒
- (void)playbackVM:(WCRPlaybackVM*)playbackVM onTimeEvent:(NSTimeInterval)currentTime;

@end

@interface WCRPlaybackVM : NSObject

/**
 当前回放状态
 */
@property(nonatomic, assign, readonly) WCRPlaybackStatus playbackStatus;

/// 当前是否播放
@property(nonatomic, assign, readonly, getter=isPlaying) BOOL playing;

/**
 当前时间，单位：秒
 */
@property(nonatomic, assign, readonly) NSTimeInterval currentTime;

/**
 总时间，单位：秒
 */
@property(nonatomic, assign, readonly) NSTimeInterval totalTime;

/**
 delegate回调
 */
@property(nonatomic, weak) id<WCRPlaybackVMDelegate> delegate;

/// 播放
- (void)play;

/// 暂停
- (void)pause;

/// seek开始 在用户开始拖动进度时调用，注:调用后内部会自动暂停
- (void)seekBegin;

/// seek中 在用户拖动进度条时调用
/// @param rate 取值范围 0-1
- (void)seek:(CGFloat)rate;

/// seek结束 在用户开始拖动进度结束时调用，注:调用后内部会自动开始播放，如果需要seek后暂停，请调用pause接口
/// @param rate 取值范围 0-1
- (void)seekEnd:(CGFloat)rate;

/// 重置播放 可在播放结束后调用, 以便重新播放
- (void)restart;

@end

NS_ASSUME_NONNULL_END
