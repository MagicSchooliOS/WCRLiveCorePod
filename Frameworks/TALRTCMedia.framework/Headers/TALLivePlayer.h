#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>
#import <TALRTCMedia/TALLiveStatus.h>
#import <TALRTCMedia/TALStatistics.h>
#import <TALRTCMedia/TALAudioFrame.h>
#import <TALRTCMedia/TALVideoFrame.h>

@class TALContext;
@protocol TALLivePlayerDelegate;
@protocol TALLivePlayerAudioSink;
@protocol TALLivePlayerVideoSink;
@protocol TALLivePlayerSnapshotSink;

@interface TALLivePlayer : NSObject

- (instancetype)initWithContext:(TALContext *)context;
- (void)destroy;

- (BOOL)addDelegate:(id<TALLivePlayerDelegate>)delegate delegateQueue:(dispatch_queue_t)queue;
- (void)removeDelegate:(id<TALLivePlayerDelegate>)delegate;
- (void)removeAllDelegates;

- (BOOL)setAudioSink:(id<TALLivePlayerAudioSink>)sink context:(id)context;
- (BOOL)setVideoSink:(id<TALLivePlayerVideoSink>)sink context:(id)context;
- (BOOL)setSnapshotImageSink:(id<TALLivePlayerSnapshotSink>) sink context:(id)context;

- (UIView *)createPlayerViewWithFrame:(CGRect)frame;
- (void)destroyPlayerView;
- (UIView *)getPlayerView;
- (void)setPlayerViewContentMode:(TALViewContentMode)mode; // default TALViewContentModeScaleAspectFit
- (void)clearPlayerViewWhenStop:(BOOL)clear; // default YES

- (BOOL)setURL:(NSURL *)url;
- (void)setPresentTime:(NSInteger)milliseconds;
- (void)setBufferTime:(NSInteger)milliseconds;
- (BOOL)play;
- (void)stop;
- (BOOL)isPlaying;

- (BOOL)setAudioVolume:(NSInteger)volume; // [0, 100], default 100
- (BOOL)muteStreamAudio:(BOOL)mute;
- (BOOL)muteStreamVideo:(BOOL)mute;
- (BOOL)isStreamAudioMuted;
- (BOOL)isStreamVideoMuted;

- (NSInteger)snapshot:(NSInteger)quality;

- (BOOL)beginCoexistWithOtherAudioCapturer:(BOOL)stopAudioPlay;
- (BOOL)endCoexistWithOtherAudioCapturer;

- (BOOL)muteAudio:(BOOL)mute OBJC_DEPRECATED("Use muteStreamAudio: instead.");
- (BOOL)isAudioMuted OBJC_DEPRECATED("Use isStreamAudioMuted instead.");

// MUST run in a non-main thread
- (TALMediaPlayerStatistics *)getStatistics OBJC_DEPRECATED("Use delegate onPlayer:mediaStatistics: instead.");

- (void)setExternalAudioSink:(BOOL)enabled;
//samplesPerCall:每次调用返回数据的采样点数，包含所有channel
//samplesPerCall=sampleRate × sampleInterval × channel sampleInterval单位为秒
- (void)setPlaybackAudioFrameParametersSampleRate:(int)sampleRate channels:(int)channels mode:(TALRawAudioFrameOpModeType)mode samplersPerCall:(int)samplesPerCall;
@end

@protocol TALLivePlayerDelegate <NSObject>
@optional

- (void)onPlayer:(TALLivePlayer *)player error:(NSError *)error;
- (void)onPlayer:(TALLivePlayer *)player statusChanged:(TALLiveMediaPlayerStatus)status;
- (void)onPlayer:(TALLivePlayer *)player mediaStatistics:(TALMediaPlayerStatistics *)statistics;
- (void)onPlayer:(TALLivePlayer *)player realTimeVolumeLevel:(NSInteger)volumeLevel;
- (void)onPlayer:(TALLivePlayer *)player mediaSideInfo:(NSData *)data;

@end

@protocol TALLivePlayerAudioSink <NSObject>

- (void)onPlayer:(TALLivePlayer *)player audioFrame:(TALAudioFrame *)audioFrame context:(id)context;

@end

@protocol TALLivePlayerVideoSink <NSObject>

- (void)onPlayer:(TALLivePlayer *)player videoFrame:(TALVideoFrame *)videoFrame context:(id)context;

@end

@protocol TALLivePlayerSnapshotSink <NSObject>

- (void)onPlayer:(TALLivePlayer *)player image:(CGImageRef)image snapId:(NSInteger)snapId context:(id)context;

@end
