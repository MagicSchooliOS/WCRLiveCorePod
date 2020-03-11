#import <Foundation/Foundation.h>

// Codes that specify TALRTCMedia event.
typedef NS_ENUM(NSInteger, TALRTCMediaEvent) {
    // Generic
    TALRTCMediaEventUnknown = 0,
    
    // Signal
    TALRTCMediaEventSignalNegotiationDone,
    TALRTCMediaEventSignalClosed,
    TALRTCMediaEventSignalStreamNotReady,
    TALRTCMediaEventSignalStreamStarted,
    TALRTCMediaEventSignalStreamStopped,
    TALRTCMediaEventSignalForceLogout,
    TALRTCMediaEventSignalConnectionLost,

    // TALRTCPlayer
    TALRTCMediaEventPlayerStarted,
    TALRTCMediaEventPlayerStopped,
    TALRTCMediaEventPlayerConnectSvr,
    TALRTCMediaEventPlayerStartBuffering,
    TALRTCMediaEventPlayerStopBuffering,
    TALRTCMediaEventPlayerStreamNotReady,
    TALRTCMediaEventPlayerStreamReady,
    TALRTCMediaEventPlayerAudioStreamReady,
    TALRTCMediaEventPlayerEndOfStream,
    
    // TALRTCPublisher
    TALRTCMediaEventCameraOpened,
    TALRTCMediaEventCameraChanged,
    TALRTCMediaEventMicrophoneOpened,
    TALRTCMediaEventMicrophoneChanged,
    TALRTCMediaEventMicrophoneMuted,
    TALRTCMediaEventMicrophoneUnmuted,
    TALRTCMediaEventSpeakerOpened,
    TALRTCMediaEventSpeakerChanged,
    TALRTCMediaEventPreviewStarted,
    TALRTCMediaEventPreviewStopped,
    TALRTCMediaEventPublishStarted,
    TALRTCMediaEventPublishStopped,
    TALRTCMediaEventRecordStarted,
    TALRTCMediaEventRecordStopped,
    TALRTCMediaEventOverlayFileOpened,
    TALRTCMediaEventOverlayFileCompleted,
    TALRTCMediaEventOverlayFilePaused,
    TALRTCMediaEventOverlayFileResumed,
    TALRTCMediaEventOverlayFileDeleted,
};

@interface TALRTCMediaEventArgs : NSObject

+ (NSString *)stringFromTALRTCMediaEvent:(TALRTCMediaEvent)event;

@end

@interface TALRTCMediaStreamReadyEventArgs : TALRTCMediaEventArgs

@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

@end
