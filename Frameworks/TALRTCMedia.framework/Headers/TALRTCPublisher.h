#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>
#import <TALRTCMedia/TALRTCEvent.h>
#import <TALRTCMedia/TALStatistics.h>
#import <TALRTCMedia/TALRTCRec.h>
#import <TALRTCMedia/TALAudioFrame.h>
#import <TALRTCMedia/TALVideoFrame.h>

@class TALContext;
@protocol TALRTCPublisherDelegate;
@protocol TALRTCPublisherAudioSink;
@protocol TALRTCPublisherVideoSink;
@protocol TALRTCPublisherSnapshotImageSink;

@interface TALRTCPublisher : NSObject

- (instancetype)initWithContext:(TALContext *)context;
- (void)destroy;

- (BOOL)addDelegate:(id<TALRTCPublisherDelegate>)delegate delegateQueue:(dispatch_queue_t)queue;
- (void)removeDelegate:(id<TALRTCPublisherDelegate>)delegate;
- (void)removeAllDelegates;

- (BOOL)setAudioSink:(id<TALRTCPublisherAudioSink>)sink context:(id)context;
- (BOOL)setVideoSink:(id<TALRTCPublisherVideoSink>)sink context:(id)context;

- (BOOL)setSnapshotImageSink:(id<TALRTCPublisherSnapshotImageSink>) sink context:(id)context;

- (NSUInteger)getCameraCount;

// position: default TALCameraPositionFront
- (BOOL)setCameraPosition:(TALCameraPosition)position;

// resolution: default TALVideoResolutionWide360p
// frameRate: [1, 30], default 15
- (void)setCaptureResolution:(TALVideoResolution)resolution frameRate:(NSUInteger)frameRate;

// resolution: default TALVideoResolutionWide360p
// frameRate: [1, 30], default 15
- (void)setEncodeResolution:(TALVideoResolution)resolution frameRate:(NSUInteger)frameRate;
- (void)setEncodeResolution:(TALVideoResolution)resolution frameRate:(NSUInteger)frameRate orientation:(TALVideoOrientationMode)mode;

// default 400000
- (void)setBitRate:(NSUInteger)bitRate;

// default false
- (void)enableBeauty:(BOOL)enable;

- (UIView *)createPreviewViewWithFrame:(CGRect)frame;
- (void)destroyPreviewView;
- (UIView *)getPreviewView;
- (void)setPreviewViewContentMode:(TALViewContentMode)mode; // default TALViewContentModeScaleAspectFit

- (void)setMirrorMode:(TALVideoMirrorMode)mode; //default TALVideoMirrorNone
- (void)setPreviewMute:(BOOL)mute; // default YES
- (BOOL)isPreviewMuted;
- (BOOL)startPreview;
- (void)stopPreview;

- (BOOL)setStreamID:(NSString *)streamID; // The maximum length of the streamID is 100
- (BOOL)startPush;
- (void)stopPush;

// SEI
- (BOOL)sendMediaSideInfo:(NSData *)data;

- (BOOL)muteStreamAudio:(BOOL)mute; // default NO
- (BOOL)muteStreamVideo:(BOOL)mute; // default NO
- (BOOL)isStreamAudioMuted;
- (BOOL)isStreamVideoMuted;

- (BOOL)muteLocalAudio:(BOOL)mute; // default YES
- (BOOL)muteLocalVideo:(BOOL)mute; // default NO
- (BOOL)isLocalAudioMuted;
- (BOOL)isLocalVideoMuted;

- (NSInteger)snapshot:(NSInteger)quality;

// For recording
- (BOOL)sendRtmpRecordingMsg:(TALRtmpRecordingMsg *)pMsg;
- (BOOL)sendMp4RecordingMsg:(TALMp4RecordingMsg *)pMsg;

- (BOOL)startShareSourceWith:(id)publisher;

- (BOOL)setMicrophoneMute:(BOOL)mute OBJC_DEPRECATED("Use muteStreamAudio: instead.");
- (BOOL)isMicrophoneMuted OBJC_DEPRECATED("Use isStreamAudioMuted instead.");
- (BOOL)controlPushAudioOnly:(BOOL)audioOnly OBJC_DEPRECATED("Use muteStreamVideo: instead.");
- (BOOL)isPushAudioOnly OBJC_DEPRECATED("Use isStreamVideoMuted instead.");

// MUST run in a non-main thread
- (NSInteger)getRealTimeVolumeLevel OBJC_DEPRECATED("Use delegate onPublisher:realTimeVolumeLevel: instead."); // [0, 100]--volume level; -1--called by main thread
- (TALMediaPublisherStatistics *)getStatistics OBJC_DEPRECATED("Use delegate onPublisher:mediaStatistics: instead.");

- (int)setExternalVideoSourceEnable:(BOOL)enabled;
- (void)pushExternalVideoFrame:(TALVideoFrame *)videoFrame;

//samplesPerCall:每次调用返回数据的采样点数，包含所有channel
//samplesPerCall=sampleRate × sampleInterval × channel sampleInterval单位为秒
- (void)setAudioRecordParametersSampleRate:(int)sampleRate channel:(int)channel mode:(TALRawAudioFrameOpModeType)mode samplesPerCall:(int)samplesPerCall;

// 设置外部音频采集参数
- (int) setExternalAudioSourceEnable:(bool)enabled sampleRate:(int)sampleRate channels:(int)channels;
- (int) pushAudioFrame:(TALAudioFrame*)frame;
@end

@protocol TALRTCPublisherDelegate <NSObject>
@optional

- (void)onPublisher:(TALRTCPublisher *)publisher error:(NSError *)error;
- (void)onPublisher:(TALRTCPublisher *)publisher event:(TALRTCMediaEvent)event args:(TALRTCMediaEventArgs *)args;
- (void)onPublisher:(TALRTCPublisher *)publisher recordingRes:(TALRecordingMsgRsp *)res;
- (void)onPublisher:(TALRTCPublisher *)publisher mediaStatistics:(TALMediaPublisherStatistics *)statistics;
- (void)onPublisher:(TALRTCPublisher *)publisher realTimeVolumeLevel:(NSInteger)volumeLevel;

@end

@protocol TALRTCPublisherAudioSink <NSObject>

- (void)onPublisher:(TALRTCPublisher *)publisher audioFrame:(TALAudioFrame *)audioFrame context:(id)context;

@end

@protocol TALRTCPublisherVideoSink <NSObject>

- (void)onPublisher:(TALRTCPublisher *)publisher videoFrame:(TALVideoFrame *)videoFrame context:(id)context;

@end

@protocol TALRTCPublisherSnapshotImageSink <NSObject>

- (void)onPublisher:(TALRTCPublisher *)player image:(CGImageRef)image snapId:(NSInteger)snapId context:(id)context;

@end
