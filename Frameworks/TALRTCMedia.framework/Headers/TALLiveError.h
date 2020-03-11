#import <Foundation/Foundation.h>

// Constant to identify the TALMedia error domain.
FOUNDATION_EXPORT NSString* const TALLiveMediaErrorDomain;

// Keys in the user info dictionary in errors TALMedia creates.
FOUNDATION_EXPORT NSString* const TALLiveMediaErrorReasonKey;

// Codes that specify an error. These may appear in NSError objects returned by various TALMedia methods.
typedef NS_ENUM(NSInteger, TALLiveMediaError) {
    // Generic error code
    TALLiveMediaErrorUnknown = -1,
    TALLiveMediaErrorNoError = 0,
    TALLiveMediaErrorInternalError,
    
    // TALLivePlayer error code
    TALLiveMediaErrorConnectStreamFailed,
    TALLiveMediaErrorBadStream,
    TALLiveMediaErrorEndOfStream,
    
    // TALLivePublisher error code
    TALLiveMediaErrorPublisherNetworkError, // automatically reconnect handled by the framework
    TALLiveMediaErrorPublisherNetworkResume,
    TALLiveMediaErrorResolutionInvalid,
    TALLiveMediaErrorVideoCodecInitError,
    TALLiveMediaErrorCameraDeviceIDInvalid,
    TALLiveMediaErrorMicrophoneDeviceIDInvalid,
    TALLiveMediaErrorSpeakerDeviceIDInvalid,
    TALLiveMediaErrorScreenParameterInvalid,
    TALLiveMediaErrorOpenCameraFailed,
    TALLiveMediaErrorOpenMicrophoneFailed,
    TALLiveMediaErrorOpenRecordFileFailed,
    TALLiveMediaErrorDiskFull,
};
