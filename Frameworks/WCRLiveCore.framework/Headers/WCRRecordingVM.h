//
//  WCRRecordingVM.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WCRLiveCore/WCRLiveStreamUser.h>
#import <WCRLiveCore/WCRError.h>
#import <WCRLiveCore/WCRLiveStreamTypedef.h>
#import <WCRLiveCore/WCRLiveStreamNetworkInfo.h>
NS_ASSUME_NONNULL_BEGIN

@protocol WCRRecordingVMDelegate <NSObject>
@optional
/**
 回调是否推流成功
 */
- (void)didPublishSuccess;

/**
 停止推流的回调
 */
- (void)didPublishStop:(nullable WCRError *)error;

/**
 开始服务器录制的回调
 */
//TODO这个还没有实现
- (void)didStartSerivceRecord;

/**
 服务器录制出现错误
 */
//TODO这个还没有实现
- (void)didStopSerivceRecord:(WCRError *)error;

/**
 当前viewModel将要重置
 */
- (void)recordingVMWillReset;

/**
 当前viewModel重置完成
 */
- (void)recordingVMDidReset;

/**
 回调采集的音量变化

 @param volume 音量值
 */
- (void)onUpdateAudioVolume:(NSUInteger)volume;

/**
 某一用户视频状态变化
 
 @param videoStatus 变化后的状态
 */
- (void)onUpdateVideoStatus:(WCRStreamDeviceStatus)videoStatus;

/**
 某一用户音频状态变化
 
 @param audioStatus 变化后的状态
 */
- (void)onUpdateAudioStatus:(WCRStreamDeviceStatus)audioStatus;

/**
 视频播放模式被改变

 @param playMode 视频播放模式 @see WCRVideoStreamPlayMode
 */
- (void)onUpdatePlayMode:(WCRVideoStreamPlayMode)playMode;
/**
 推流网络质量变化
 
 @param networkInfo 流质量
 */
- (void)onUpdatePublishNetWorkInfo:(WCRLiveStreamNetworkInfo *)networkInfo;

@end

/**
 这个类主要处理推流相关
 */
@interface WCRRecordingVM : NSObject
/**
 当前正在推流的用户，默认是进入房间的用户
 */
@property (nonatomic, strong ,readonly) WCRLiveStreamUser *recordUser;

/**
 当前使用的sdk类型
 */
@property(nonatomic, assign, readonly) WCRLiveStreamServiceType streamServiceType;

/**
 类的代理
 @see WCRRecordingVMDelegate
 */
@property (nonatomic, weak)  id<WCRRecordingVMDelegate> delegate;

/**
 开始预览
 
 @param view 需要传入一个view，在此view中显示预览画面
 @param mode 预览画面的显示模式
 @return 返回是否执行成功
 */
- (BOOL)startPreview:(UIView *)view contentMode:(WCRLiveStreamContentMode)mode;

/**
 停止预览
 @warning 停止预览前先停止推流 @see -stopPublish
 @return 返回是否执行成功
 */
- (BOOL)stopPreview;

/**
 开始推流
 
 @return 返回是否执行成功
 @warning 开始推流前请先开始预览 @see -startPreview:contentMode:;
 @see -didPublishWithError:
 */
- (BOOL)startPublish;

/**
 停止推流
 
 @return 返回是否执行成功
 */
- (BOOL)stopPublish;

/**
 设置是否录制音频

 @param audio 是否录制
 */
- (void)setRecordAudio:(BOOL)audio;

/**
 是否录制视频

 @param video 是否录制
 */
- (void)setRecordVideo:(BOOL)video;

/**
 当前是否录制音频

 @return 返回是否录制音频
 */
- (BOOL)isAudioMute;

/**
 当前是否录制视频

 @return 返回是否录制视频
 */
- (BOOL)isVideoMute;

/**
 开始服务器录制
 */
- (BOOL)startServerRecordWithStreamId:(NSString *)streamId;

/**
 停止服务器录制
 */
- (void)stopServerRecord;

/**
 当前是否正在进行服务器录制

 @return 返回是否正在录制
 */
- (BOOL)isServerRecording;
/**
 向学伴与老师发送拉流消息（课堂学生非正常变更时调用）
 */
- (void)sendAddStreamMessage;
/**
 向学伴与老师发送移除流消息（课堂学生非正常变更时调用）
 */
- (void)sendRemoveStreamMessage;
/**
 向学伴与老师发送更新设备消息（课堂学生非正常变更时调用）
 */
- (void)sendUpdateStreamDeviceStatusMessage;


/**
 设置预览摄像头，默认使用前置摄像头
 
 @return 返回是否设置摄像头成功
 */
- (BOOL)setCameraPosition:(WCRCameraPosition)cameraPosition;
/**
 设置预览摄像头分辨率
 */
- (void)setPreviewResolution:(WCRRTCVideoResolution)previewResolution;
/**
 设置预览为默认分辨率
 */
- (void)setPreviewToDefaultResolution;

@end
NS_ASSUME_NONNULL_END
