#import <Foundation/Foundation.h>

// Codes that specify TALLivePlayer status.
typedef NS_ENUM(NSInteger, TALLiveMediaPlayerStatus) {
    TALLiveMediaPlayerStatusStarted = 0,
    TALLiveMediaPlayerStatusStartBuffering,
    TALLiveMediaPlayerStatusStopBuffering,
    TALLiveMediaPlayerStatusStopped,
    TALLiveMediaPlayerStatusVideoSize,
    TALLiveMediaPlayerStatusAudioStreamReady,
    TALLiveMediaPlayerStatusNetworkConnected,
    TALLiveMediaPlayerStatusFirstPacket,
};

// Codes that specify TALLivePublisher status.
typedef NS_ENUM(NSInteger, TALLiveMediaPublisherStatus) {
    TALLiveMediaPublisherStatusPreviewStarted = 0,
    TALLiveMediaPublisherStatusPreviewStopped,
    
    TALLiveMediaPublisherStatusPublishStarted,
    TALLiveMediaPublisherStatusPublishStopped,
    
    TALLiveMediaPublisherStatusRecordStarted,
    TALLiveMediaPublisherStatusRecordStopped,
};
