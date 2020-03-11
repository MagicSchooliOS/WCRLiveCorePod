//
//  WCRLiveStreamTypedef.h
//  WCRLiveStreamSDK
//
//  Created by 欧阳铨 on 2019/4/15.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 互动音视频使用的分辨率
 @warning 并不是三个sdk都支持以下所有分辨率

 - WCRRTCVideoResolution60x60:  60x60
 - WCRRTCVideoResolution90x90:  90x90
 - WCRRTCVideoResolution120x120:  120x120
 - WCRRTCVideoResolution150x150:  150x150
 - WCRRTCVideoResolution160x90:  160x90
 - WCRRTCVideoResolution160x120:  160x120
 - WCRRTCVideoResolution180x180:  180x180
 - WCRRTCVideoResolution288x288:  288X288
 - WCRRTCVideoResolution320x180:  320x180
 - WCRRTCVideoResolution320x240:  320x240
 - WCRRTCVideoResolution360x360:  360x360
 - WCRRTCVideoResolution480x360:  480x360
 - WCRRTCVideoResolution480x480:  480x480
 - WCRRTCVideoResolution640x360:  640x360
 - WCRRTCVideoResolution640x480:  640x480
 - WCRRTCVideoResolution720x720:  720x720
 - WCRRTCVideoResolution960x540:  960x540
 - WCRRTCVideoResolution960x720:  960x720
 - WCRRTCVideoResolution1280x720:  1280x720
 */
typedef NS_ENUM(NSInteger, WCRRTCVideoResolution) {
    WCRRTCVideoResolution60x60 = 0,
    WCRRTCVideoResolution90x90,
    WCRRTCVideoResolution120x120,
    WCRRTCVideoResolution150x150,
    WCRRTCVideoResolution160x90,
    WCRRTCVideoResolution160x120,
    WCRRTCVideoResolution180x180,
    WCRRTCVideoResolution288x288,
    WCRRTCVideoResolution320x180,
    WCRRTCVideoResolution320x240,
    WCRRTCVideoResolution360x360,
    WCRRTCVideoResolution480x360,
    WCRRTCVideoResolution480x480,
    WCRRTCVideoResolution640x360,
    WCRRTCVideoResolution640x480,
    WCRRTCVideoResolution720x720,
    WCRRTCVideoResolution960x540,
    WCRRTCVideoResolution960x720,
    WCRRTCVideoResolution1280x720
    
};

/**
 设备类型
 
 - WCRLiveStreamDeviceTypeUnknow: 未知
 - WCRLiveStreamDeviceTypeCamera: 摄像头
 - WCRLiveStreamDeviceTypeMicrophone: 麦克风
 - WCRLiveStreamDeviceTypeSpeaker: 扬声器
 */
typedef NS_ENUM(NSInteger, WCRLiveStreamDeviceType) {
    WCRLiveStreamDeviceTypeUnknow = 0,
    WCRLiveStreamDeviceTypeCamera,
    WCRLiveStreamDeviceTypeMicrophone,
    WCRLiveStreamDeviceTypeSpeaker
};

/**
 填充类型
 
 - WCRRTCViewContentModeScaleAspectFit: AspectFit
 - WCRRTCViewContentModeScaleAspectFill: AspectFill
 */
typedef NS_ENUM(NSInteger, WCRRTCViewContentMode) {
    WCRRTCViewContentModeScaleAspectFit = 0,
    WCRRTCViewContentModeScaleAspectFill
};



/**
 使用哪种库播放rtc
 
 - WCRLiveStreamServiceTypeNone: 初始值
 - WCRLiveStreamServiceTypeZego: 使用zego
 - WCRLiveStreamServiceTypeTal: 使用tal rtc库
 - WCRLiveStreamServiceTypeAgora: 使用声网
 - WCRLiveStreamServiceTypeMax: 不在[WCRLiveStreamServiceTypeNone,WCRLiveStreamServiceTypeMax]区间的值都属于异常
 */
typedef NS_ENUM(NSUInteger, WCRLiveStreamServiceType) {
    WCRLiveStreamServiceTypeNone = 0,
#if __has_include("WCRTalLiveStream.h")
    WCRLiveStreamServiceTypeTal,
#endif
#if __has_include("WCRZegoLiveStream.h")
    WCRLiveStreamServiceTypeZego,
#endif
#if __has_include("WCRAgoraLiveStream.h")
    WCRLiveStreamServiceTypeAgora,
#endif
    WCRLiveStreamServiceTypeMax
};


/**
 摄像头位置
 
 - WCRCameraPositionBack: 后置摄像头
 - WCRCameraPositionFront: 前置摄像头
 */
typedef NS_ENUM(NSInteger, WCRCameraPosition) {
    WCRCameraPositionFront  = 0,
    WCRCameraPositionBack
};
