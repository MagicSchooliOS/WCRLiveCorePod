#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>
#import <TALRTCMedia/TALLiveEvent.h>
#import <TALRTCMedia/TALLiveStatus.h>
#import <TALRTCMedia/TALStatistics.h>
#import <TALRTCMedia/TALAudioFrame.h>
#import <TALRTCMedia/TALVideoFrame.h>

@class TALContext;
@protocol TALLivePublisherDelegate;
@protocol TALLivePublisherAudioSink;
@protocol TALLivePublisherVideoSink;
@protocol TALLivePublisherSnapshotImageSink;

@interface TALLivePublisher : NSObject

- (instancetype)initWithContext:(TALContext *)context;
- (void)destroy;

- (BOOL)addDelegate:(id<TALLivePublisherDelegate>)delegate delegateQueue:(dispatch_queue_t)queue;
- (void)removeDelegate:(id<TALLivePublisherDelegate>)delegate;
- (void)removeAllDelegates;

- (BOOL)setAudioSink:(id<TALLivePublisherAudioSink>)sink context:(id)context;
- (BOOL)setVideoSink:(id<TALLivePublisherVideoSink>)sink context:(id)context;
- (BOOL)setSnapshotImageSink:(id<TALLivePublisherSnapshotImageSink>) sink context:(id)context;

- (NSUInteger)getCameraCount;

// position: default TALCameraPositionFront
- (BOOL)setCameraPosition:(TALCameraPosition)position;

// resolution: default TALVideoResolution480p
// frameRate: [1, 30], default 15
- (void)setCaptureResolution:(TALVideoResolution)resolution frameRate:(NSUInteger)frameRate;

// resolution: default TALVideoResolution480p
// frameRate: [1, 30], default 15
- (void)setEncodeResolution:(TALVideoResolution)resolution frameRate:(NSUInteger)frameRate;
- (void)setEncodeResolution:(TALVideoResolution)resolution frameRate:(NSUInteger)frameRate orientation:(TALVideoOrientationMode)mode;

// default GOP 4 seconds
- (void)setGOPInterval:(NSUInteger)second;

// default 500000
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

- (BOOL)muteStreamAudio:(BOOL)mute; // default NO
- (BOOL)muteStreamVideo:(NSURL *)url mute:(BOOL)mute; // default NO
- (BOOL)isStreamAudioMuted;
- (BOOL)isStreamVideoMuted:(NSURL *)url;

- (BOOL)muteLocalAudio:(BOOL)mute; // default YES
- (BOOL)isLocalAudioMuted;

- (NSInteger)snapshot:(NSInteger)quality;

// default TALRecordTypeMP4
// MUST call this method before startPush if you want to record.
- (BOOL)setRecordType:(TALRecordType)type;

// support file with the mp4 or flv extension
- (BOOL)setRecordFile:(NSString *)path;
- (BOOL)startRecord;
- (void)stopRecord;

- (BOOL)addPushURL:(NSURL *)url audioOnly:(BOOL)audioOnly;
- (BOOL)removePushURL:(NSURL *)url;
- (void)removeAllPushURLs;
- (BOOL)startPush;
- (void)stopPush;

// SEI
- (BOOL)sendMediaSideInfo:(NSData *)data;

- (BOOL)startShareSourceWith:(id)publisher;

// You can invoke this method while the TALLivePublisher is publishing.
- (BOOL)controlPushURL:(NSURL *)url audioOnly:(BOOL)audioOnly OBJC_DEPRECATED("Use muteStreamVideo:mute: instead.");

// MUST run in a non-main thread
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

@protocol TALLivePublisherDelegate <NSObject>
@optional

- (void)onPublisher:(TALLivePublisher *)publisher error:(NSError *)error;
- (void)onPublisher:(TALLivePublisher *)publisher event:(TALLiveMediaEvent)event;
- (void)onPublisher:(TALLivePublisher *)publisher statusChanged:(TALLiveMediaPublisherStatus)status;
- (void)onPublisher:(TALLivePublisher *)publisher mediaStatistics:(TALMediaPublisherStatistics *)statistics;
- (void)onPublisher:(TALLivePublisher *)publisher realTimeVolumeLevel:(NSInteger)volumeLevel;

@end

@protocol TALLivePublisherAudioSink <NSObject>

- (void)onPublisher:(TALLivePublisher *)publisher audioFrame:(TALAudioFrame *)audioFrame context:(id)context;

@end

@protocol TALLivePublisherVideoSink <NSObject>

- (void)onPublisher:(TALLivePublisher *)publisher videoFrame:(TALVideoFrame *)videoFrame context:(id)context;

@end

@protocol TALLivePublisherSnapshotImageSink <NSObject>

- (void)onPublisher:(TALLivePublisher *)publisher image:(CGImageRef)image snapId:(NSInteger)snapId context:(id)context;

@end
