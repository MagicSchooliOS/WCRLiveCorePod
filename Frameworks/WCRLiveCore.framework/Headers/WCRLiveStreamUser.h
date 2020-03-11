//
//  WCRLiveStreamUser.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/12/19.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCRUser.h>
#import <WCRLiveCore/WCRError.h>
#import <WCRLiveCore/WCRTypeDef.h>

NS_ASSUME_NONNULL_BEGIN

@interface WCRLiveStreamUser : NSObject
/**
 初始化方法

 @param user d当前用户
 @warning videoDeviceStatus默认值为WCRStreamDeviceStatusOpened
          audioDeviceStatus默认值为WCRStreamDeviceStatusOpened
          playMode默认值为WCRVideoStreamPlayModePreview
 @return liveStream用户实例
 */
- (instancetype)initWithUser:(WCRUser *)user;

- (instancetype)initWithUser:(WCRUser *)user
           videoDeviceStatus:(WCRStreamDeviceStatus)videoDeviceStatus
           audioDeviceStatus:(WCRStreamDeviceStatus)audioDeviceStatus
                    playMode:(WCRVideoStreamPlayMode)playMode;
/**
 当前用户
 */
@property (nonatomic, strong, readonly) WCRUser *user;

/**
 用户的流地址（大班课特指非连麦状态下教室的流地址）
 */
@property (nonatomic, copy) NSString *streamId;

/**
 课件区的流地址(大班课连麦状态下)
 */
@property (nonatomic, copy) NSString *screenStreamId;

/**
 老师的流地址(大班课连麦状态下)
 */
@property (nonatomic, copy, nullable) NSString *teacherStreamId;

/**
 用户的视频状态
 */
@property (nonatomic, assign) WCRStreamDeviceStatus videoDeviceStatus;

/**
 用户的音频状态
 */
@property (nonatomic, assign) WCRStreamDeviceStatus audioDeviceStatus;

/**
 用户的视频播放模式
 */
@property (nonatomic, assign, readonly) WCRVideoStreamPlayMode playMode;
/**
 用户的视频播放类型
 */
@property (nonatomic, assign, readonly) WCRVideoStreamType streamType;
/**
 当前用户音量
 */
@property (nonatomic, assign, readonly) float volume;

/**
 用户推拉流错误的error
 */
@property (nonatomic, strong, nullable, readonly) WCRError *error;
@end

NS_ASSUME_NONNULL_END
