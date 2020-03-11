#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>
#import <TALRTCMedia/TALRTCEvent.h>
#import <TALRTCMedia/TALStatistics.h>
#import <TALRTCMedia/TALAudioFrame.h>
#import <TALRTCMedia/TALVideoFrame.h>

@class TALContext;
@protocol TALRTCPlayerDelegate;
@protocol TALRTCPlayerAudioSink;
@protocol TALRTCPlayerVideoSink;
@protocol TALRTCPlayerSnapshotSink;

@interface TALRTCPlayer : NSObject

- (instancetype)initWithContext:(TALContext *)context;
- (void)destroy;

- (BOOL)addDelegate:(id<TALRTCPlayerDelegate>)delegate delegateQueue:(dispatch_queue_t)queue;
- (void)removeDelegate:(id<TALRTCPlayerDelegate>)delegate;
- (void)removeAllDelegates;

- (BOOL)setAudioSink:(id<TALRTCPlayerAudioSink>)sink context:(id)context;
- (BOOL)setVideoSink:(id<TALRTCPlayerVideoSink>)sink context:(id)context;

- (BOOL)setSnapshotImageSink:(id<TALRTCPlayerSnapshotSink>) sink context:(id)context;

- (UIView *)createPlayerViewWithFrame:(CGRect)frame;
- (void)destroyPlayerView;
- (UIView *)getPlayerView;
- (void)setPlayerViewContentMode:(TALViewContentMode)mode; // default TALViewContentModeScaleAspectFit
- (void)clearPlayerViewWhenStop:(BOOL)clear; // default YES

- (BOOL)setStreamID:(NSString *)streamID; // The maximum length of the streamID is 100
- (BOOL)setStreamID:(NSString *)streamID confid:(NSString *)confid;
- (BOOL)play;
- (void)stop;
- (BOOL)isPlaying;

- (BOOL)setAudioVolume:(NSInteger)volume; // [0, 100], default 100
- (BOOL)muteStreamAudio:(BOOL)mute;
- (BOOL)muteStreamVideo:(BOOL)mute;
- (BOOL)isStreamAudioMuted;
- (BOOL)isStreamVideoMuted;

- (NSInteger)snapshot:(NSInteger)quality;

- (BOOL)muteAudio:(BOOL)mute OBJC_DEPRECATED("Use muteStreamAudio: instead.");
- (BOOL)isAudioMuted OBJC_DEPRECATED("Use isStreamAudioMuted instead.");
- (BOOL)controlPullAudioOnly:(BOOL)audioOnly OBJC_DEPRECATED("Use muteStreamVideo: instead.");
- (BOOL)isPullAudioOnly OBJC_DEPRECATED("Use isStreamVideoMuted instead.");

// MUST run in a non-main thread
- (NSInteger)getRealTimeVolumeLevel OBJC_DEPRECATED("Use delegate onPlayer:realTimeVolumeLevel: instead."); // [0, 100]--volume level; -1--called by main thread
- (TALMediaPlayerStatistics *)getStatistics OBJC_DEPRECATED("Use delegate onPlayer:mediaStatistics: instead.");

- (void)setExternalAudioSink:(BOOL)enabled;
//samplesPerCall:每次调用返回数据的采样点数，包含所有channel
//samplesPerCall=sampleRate × sampleInterval × channel sampleInterval单位为秒
- (void)setPlaybackAudioFrameParametersSampleRate:(int)sampleRate channels:(int)channels mode:(TALRawAudioFrameOpModeType)mode samplersPerCall:(int)samplesPerCall;

@end

@protocol TALRTCPlayerDelegate <NSObject>
@optional

- (void)onPlayer:(TALRTCPlayer *)player error:(NSError *)error;
- (void)onPlayer:(TALRTCPlayer *)player event:(TALRTCMediaEvent)event args:(TALRTCMediaEventArgs *)args;
- (void)onPlayer:(TALRTCPlayer *)player mediaStatistics:(TALMediaPlayerStatistics *)statistics;
- (void)onPlayer:(TALRTCPlayer *)player realTimeVolumeLevel:(NSInteger)volumeLevel;
- (void)onPlayer:(TALRTCPlayer *)player mediaSideInfo:(NSData *)data;

@end

@protocol TALRTCPlayerAudioSink <NSObject>

- (void)onPlayer:(TALRTCPlayer *)player audioFrame:(TALAudioFrame *)audioFrame context:(id)context;

@end

@protocol TALRTCPlayerVideoSink <NSObject>

- (void)onPlayer:(TALRTCPlayer *)player videoFrame:(TALVideoFrame *)videoFrame context:(id)context;

@end

@protocol TALRTCPlayerSnapshotSink <NSObject>

- (void)onPlayer:(TALRTCPlayer *)player image:(CGImageRef)image snapId:(NSInteger)snapId context:(id)context;

@end
