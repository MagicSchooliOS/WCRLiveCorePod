#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TALRawAudioFrameOpModeType) {
    TALRawAudioFrameOpReadOnly = 0,
};

@interface TALAudioFrame : NSObject

@property (nonatomic, readonly) int sampleRate;
@property (nonatomic, readonly) int channel;
@property (nonatomic, readonly) int samplesPerChannel;
@property (nonatomic, readonly) int bytesPerSample;
@property (nonatomic, readonly) const uint8_t* data;
@property (nonatomic, readonly) int length;
@property (nonatomic, readonly) long long timestamp;
@property (nonatomic, readonly) long long extraData;

- (instancetype)initWithSampleRate:(int)sampleRate
                           channel:(int)channel
                           samples:(int)samples
                    bytesPerSample:(int)bytesPerSample
                              data:(const uint8_t *)data
                            length:(int)length
                         timestamp:(long long)timestamp
                         extraData:(long long)extraData;

@end
