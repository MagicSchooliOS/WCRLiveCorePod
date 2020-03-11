//
//  WCRPlayingVM.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WCRLiveCore/WCRLiveStreamUser.h>
#import <WCRLiveCore/WCRLiveStreamNetworkInfo.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WCRPlayingVMDelegate<NSObject>
@optional
/**
 正在播放的用户拉流成功

 @param playingUser 成功的用户
 */
- (void)didPlayingUserSuccess:(WCRLiveStreamUser *)playingUser;

/**
 停止播放某一用户流

 @param playingUser 停止播放的用户
 */
- (void)onPlayingStop:(WCRLiveStreamUser *)playingUser error:(WCRError * _Nullable)error;

/**
 某一用户被添加

 @param user 被添加的用户
 */
- (void)onAddPlayingUser:(WCRLiveStreamUser *)user;

/**
 某一用户被移除

 @param user 被移除的用户
 */
- (void)onRemovePlayingUser:(WCRLiveStreamUser *)user;

/**
 某一用户视频状态变化

 @param user 状态变化的用户
 @param videoStatus 变化后的状态
 */
- (void)onUpdatePlayingUser:(WCRLiveStreamUser *)user videoStatus:(WCRStreamDeviceStatus)videoStatus;

/**
 某一用户音频状态变化
 
 @param user 状态变化的用户
 @param audioStatus 变化后的状态
 */
- (void)onUpdatePlayingUser:(WCRLiveStreamUser *)user audioStatus:(WCRStreamDeviceStatus)audioStatus;

/**
 视频播放模式被改变
 
 @param user 状态变化的用户
 @param playMode 视频播放模式 @see WCRVideoStreamPlayMode
 */
- (void)onUpdatePlayingUser:(WCRLiveStreamUser *)user playMode:(WCRVideoStreamPlayMode)playMode;

/**
 某一用户的播放音量发生变化

 @param user 发生变化的用户
 @warning 这个回调每0.2秒回调一次当前正在播放的所有用户的音量
 @param volume 变化后的音量
 */
- (void)onUpdatePlayingUser:(WCRLiveStreamUser *)user audioVolume:(NSUInteger)volume;

/**
 当前viewModel将要重置
 */
- (void)playingVMWillReset;

/**
 当前viewModel重置完成
 */
- (void)playingVMDidReset;

/**
 拉流用户网络质量变化
 
 @param user 网络质量变化的用户
 @param networkInfo 网络质量
 */
- (void)onUpdatePlayingUser:(WCRLiveStreamUser *)user downNetworkInfo:(WCRLiveStreamNetworkInfo * _Nullable)networkInfo;

/**
 拉流用户的推流网络质量变化，即这个用户的上行网络质量
 注：这个方法会保证定时返回数据。但是拉流用户的上行网络质量是无法直接通过获取到，是通过其他人定时同步过来的，如果长时间收不到不能判断是当前用户的网络问题还是其他用户的网络问题，所以返回的可能是上次收到的数据。
 
 @param user 网络质量变化的用户
 @param networkInfo 网络质量
 */
- (void)onUpdatePlayingUser:(WCRLiveStreamUser *)user upNetworkInfo:(WCRLiveStreamNetworkInfo * _Nullable)networkInfo;

@end

/**
 这个类主要处理拉流相关
 */
@interface WCRPlayingVM : NSObject

/**
 当前正在播放的用户数组
 */
@property (nonatomic, strong, readonly) NSArray<WCRLiveStreamUser *> *playingUsers;

/**
 所有可播放的用户数组
 */
@property (nonatomic, strong, readonly) NSArray<WCRLiveStreamUser *> *users;

/**
 类的代理
 @see WCRPlayingVMDelegate
 */
@property (nonatomic, weak)  id<WCRPlayingVMDelegate> delegate;

/**
 开始拉流

 @param user 需要拉流的用户
 @param view 拉流的视频显示在这个view中
 @param mode 显示模式
 */
- (void)startPlaying:(WCRLiveStreamUser *)user inView:(UIView * _Nullable)view contentMode:(WCRLiveStreamContentMode)mode;

/**
 停止拉流

 @param user 需要停止拉流的用户
 */
- (void)stopPlaying:(WCRLiveStreamUser *)user;

/**
 开始拉流（大班课连麦状态下专用）
 
 @param user 需要拉流的用户
 @param teacherView 老师的拉流视频显示在这个view中
 @param screenView 课件区的拉流视频显示在这个view中
 @param mode 显示模式
 */
- (void)startPlayingWithUser:(WCRLiveStreamUser *)user teacherView:(UIView * _Nullable)teacherView  screenView:(UIView *_Nullable)screenView contentMode:(WCRLiveStreamContentMode)mode;

/**
 停止拉流（大班课专用）
 
 @param streamId 需要停止拉流的流地址
 */
- (void)stopPlayingWithStreamId:(NSString *)streamId;

/**
 设置是否拉某个用户的视频流

 @param user 需要设置的用户
 @param mute 是否拉视频流
 @return 返回是否设置成功
 */
- (BOOL)setPlayingUser:(WCRLiveStreamUser *)user videoMute:(BOOL)mute;

/**
 设置是否拉某个用户的音频流

 @param user 需要设置的用户
 @param mute 是否拉音频流
 @return 返回是否设置成功
 */
- (BOOL)setPlayingUser:(WCRLiveStreamUser *)user audioMute:(BOOL)mute;

/**
 设置是否拉某个用户的视频流(大班课)
 
 @param streamId 需要设置的用户流ID
 @param mute 是否拉视频流
 @return 返回是否设置成功
 */
- (BOOL)setPlayingWithStreamId:(NSString *)streamId videoMute:(BOOL)mute;

/**
 设置是否拉某个用户的音频流(大班课)
 
 @param streamId 需要设置的用户streamId
 @param mute 是否拉音频流
 @return 返回是否设置成功
 */

- (BOOL)setPlayingWithStreamId:(NSString *)streamId audioMute:(BOOL)mute;

NS_ASSUME_NONNULL_END
@end
