#import <Foundation/Foundation.h>

// Codes that specify TALVideoFrame type.
typedef NS_ENUM(NSInteger, TALVideoFrameType) {
    TALVideoFrameTypeYV21 = 0, // Player
    TALVideoFrameTypeNV12,     // Publisher
};

typedef NS_ENUM(NSInteger, TALVideoFrameRotateType) {
    TALVideoFrameRotate0 = 0,
    TALVideoFrameRotate90,
    TALVideoFrameRotate180,
    TALVideoFrameRotate270,
};

@interface TALVideoFrame : NSObject

@property (nonatomic, readonly) TALVideoFrameType type;
@property (nonatomic, readonly) int width;
@property (nonatomic, readonly) int height;
@property (nonatomic, readonly) const uint8_t* dataY;
@property (nonatomic, readonly) const uint8_t* dataU;
@property (nonatomic, readonly) const uint8_t* dataV;
@property (nonatomic, readonly) int strideY;
@property (nonatomic, readonly) int strideU;
@property (nonatomic, readonly) int strideV;
@property (nonatomic, readonly) long long timestamp;
@property (nonatomic, readonly) TALVideoFrameRotateType rotate;

- (instancetype)initWithType:(TALVideoFrameType)type
                       width:(int)width
                      height:(int)height
                        data:(const uint8_t *)data //first use data,contains Y U V three planes;if this is nullptr,then use dataY dataU dataV
                       dataY:(const uint8_t *)dataY
                       dataU:(const uint8_t *)dataU
                       dataV:(const uint8_t *)dataV
                     strideY:(int)strideY
                     strideU:(int)strideU
                     strideV:(int)strideV
                   timestamp:(long long)timestamp
                      rotate:(TALVideoFrameRotateType)rotate;

@end
