#import <Foundation/Foundation.h>
#import <TALRTCMedia/TALBase.h>

typedef NS_ENUM(NSInteger, TALMediaNetworkQuality) {
    TALMediaNetworkQualityUnknown = -1,
    TALMediaNetworkQualityGood,
    TALMediaNetworkQualityGeneral,
    TALMediaNetworkQualityPoor,
};

@interface TALMediaTotalStatistics : NSObject

@property (nonatomic, strong) NSNumber* txAudioBytes;        // int
@property (nonatomic, strong) NSNumber* txVideoBytes;        // int
@property (nonatomic, strong) NSNumber* rxAudioBytes;        // int
@property (nonatomic, strong) NSNumber* rxVideoBytes;        // int
@property (nonatomic, strong) NSNumber* txAudioKBitRate;     // int
@property (nonatomic, strong) NSNumber* rxAudioKBitRate;     // int
@property (nonatomic, strong) NSNumber* txVideoKBitRate;     // int
@property (nonatomic, strong) NSNumber* rxVideoKBitRate;     // int
@property (nonatomic, strong) NSNumber* cpuTotalUsage;       // float([0-100])
@property (nonatomic, strong) NSNumber* cpuAppUsage;         // float([0-100])

@end


@interface TALMediaPlayerStatistics : NSObject

@property (nonatomic, strong) NSNumber* audioChannel;           // int
@property (nonatomic, strong) NSNumber* audioSampleRate;        // int
@property (nonatomic, strong) NSNumber* audioTransitBitRate;    // float
@property (nonatomic, strong) NSNumber* audioDecodeBitRate;     // float
@property (nonatomic, strong) NSNumber* audioDecodeFrameRate;   // float
@property (nonatomic, strong) NSNumber* audioRenderFrameRate;   // float
@property (nonatomic, strong) NSNumber* audioJitter;            // unsigned int, millisecond
@property (nonatomic, strong) NSNumber* audioPacketLostCount;   // unsigned int
@property (nonatomic, strong) NSNumber* audioPacketLostRate;    // unsigned int
@property (nonatomic, strong) NSNumber* audioSSRC;              // unsigned int
@property (nonatomic, strong) NSNumber* audioTotalTransKBytes;  // unsigned int(KB)

@property (nonatomic, strong) NSNumber* videoWidth;             // int
@property (nonatomic, strong) NSNumber* videoHeight;            // int
@property (nonatomic, strong) NSNumber* videoTransitBitRate;    // float
@property (nonatomic, strong) NSNumber* videoDecodeBitRate;     // float
@property (nonatomic, strong) NSNumber* videoDecodeFrameRate;   // float
@property (nonatomic, strong) NSNumber* videoRenderFrameRate;   // float
@property (nonatomic, strong) NSNumber* videoJitter;            // unsigned int, millisecond
@property (nonatomic, strong) NSNumber* videoPacketLostCount;   // unsigned int
@property (nonatomic, strong) NSNumber* videoPacketLostRate;    // unsigned int
@property (nonatomic, strong) NSNumber* videoSSRC;              // unsigned int
@property (nonatomic, strong) NSNumber* videoTotalTransKBytes;  // unsigned int(KB)

@property (nonatomic, strong) NSNumber* cpuTotalUsage;          // float([0-100])
@property (nonatomic, strong) NSNumber* cpuAppUsage;            // float([0-100])

@property (nonatomic, copy) NSString* relayServer;
@property (nonatomic, assign) TALMediaNetworkQuality networkQuality;

@end

@interface TALMediaPublisherStatistics : NSObject

@property (nonatomic, strong) NSNumber* audioChannel;           // int
@property (nonatomic, strong) NSNumber* audioSampleRate;        // int
@property (nonatomic, strong) NSNumber* audioCaptureFrameRate;  // float
@property (nonatomic, strong) NSNumber* audioEncodeBitRate;     // float
@property (nonatomic, strong) NSNumber* audioEncodeFrameRate;   // float
@property (nonatomic, strong) NSNumber* audioTransitBitRate;    // float
@property (nonatomic, strong) NSNumber* audioJitter;            // unsigned int, millisecond
@property (nonatomic, strong) NSNumber* audioPacketLostCount;   // unsigned int
@property (nonatomic, strong) NSNumber* audioPacketLostRate;    // unsigned int
@property (nonatomic, strong) NSNumber* audioSSRC;              // unsigned int
@property (nonatomic, strong) NSNumber* audioTotalTransKBytes;  // unsigned int(KB)

@property (nonatomic, strong) NSNumber* videoCaptureWidth;      // int
@property (nonatomic, strong) NSNumber* videoCaptureHeight;     // int
@property (nonatomic, strong) NSNumber* videoCaptureFrameRate;  // float
@property (nonatomic, strong) NSNumber* videoEncodeWidth;       // int
@property (nonatomic, strong) NSNumber* videoEncodeHeight;      // int
@property (nonatomic, strong) NSNumber* videoEncodeBitRate;     // float
@property (nonatomic, strong) NSNumber* videoEncodeFrameRate;   // float
@property (nonatomic, strong) NSNumber* videoTransitBitRate;    // float
@property (nonatomic, strong) NSNumber* videoJitter;            // unsigned int, millisecond
@property (nonatomic, strong) NSNumber* videoPacketLostCount;   // unsigned int
@property (nonatomic, strong) NSNumber* videoPacketLostRate;    // unsigned int
@property (nonatomic, strong) NSNumber* videoSSRC;              // unsigned int
@property (nonatomic, strong) NSNumber* videoTotalTransKBytes;  // unsigned int(KB)

@property (nonatomic, strong) NSNumber* cpuTotalUsage;          // float([0-100])
@property (nonatomic, strong) NSNumber* cpuAppUsage;            // float([0-100])

@property (nonatomic, copy) NSString* relayServer;
@property (nonatomic, assign) TALMediaNetworkQuality networkQuality;

@end
