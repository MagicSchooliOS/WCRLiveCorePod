#import <Foundation/Foundation.h>

// Constant to identify the TALRTCMedia error domain.
FOUNDATION_EXPORT NSString* const TALRTCMediaErrorDomain;

// Keys in the user info dictionary in errors TALRTCMedia creates.
FOUNDATION_EXPORT NSString* const TALRTCMediaErrorReasonKey;

// Codes that specify an error. These may appear in NSError objects returned by various TALRTCMedia methods.
typedef NS_ENUM(NSInteger, TALRTCMediaError) {
    // Generic
    TALRTCMediaErrorUnknown = 0,
    TALRTCMediaErrorNoError,
    TALRTCMediaErrorInternalError,
    TALRTCMediaErrorNetworkError,
    TALRTCMediaErrorNetworkResume,
    TALRTCMediaErrorNetworkDisconnected,
    TALRTCMediaErrorScheduleServer,
    TALRTCMediaErrorRelayServer,
    TALRTCMediaErrorNoAvailableRelayServer,
    TALRTCMediaErrorRelayServerResourceLow,
    
    // TALRTCPlayer
    TALRTCMediaErrorBadStream,
    
    // TALRTCPublisher
    TALRTCMediaErrorResolutionInvalid,
    TALRTCMediaErrorVideoCodecInitError,
    TALRTCMediaErrorCameraDeviceIDInvalid,
    TALRTCMediaErrorMicrophoneDeviceIDInvalid,
    TALRTCMediaErrorSpeakerDeviceIDInvalid,
    TALRTCMediaErrorScreenParameterInvalid,
    TALRTCMediaErrorOpenCameraFailed,
    TALRTCMediaErrorCameraError,
    TALRTCMediaErrorOpenMicrophoneFailed,
    TALRTCMediaErrorMicrophoneError,
    TALRTCMediaErrorOpenRecordFileFailed,
    TALRTCMediaErrorOpenOverlayFileFailed,
    TALRTCMediaErrorDiskFull,
};
