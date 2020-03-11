#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TALRecordingCmd) {
    TALRecordingCmdStart = 0,
    TALRecordingCmdStop,
    TALRecordingCmdPause,
    TALRecordingCmdResume,
};

typedef NS_ENUM(NSUInteger, TALRecordingRes) {
    TALRecordingResOK = 0,
    TALRecordingResFail,
    TALRecordingResInvalid,
};

@interface TALRtmpRecordingMsg : NSObject

@property (nonatomic, assign) TALRecordingCmd recCmd;
@property (nonatomic, copy) NSString* confId;
@property (nonatomic, copy) NSString* streamId;
@property (nonatomic, assign) BOOL rtmpPublishAll;
@property (nonatomic, copy) NSArray<NSString *>* rtmpUrlArr;

@end

@interface TALMp4RecordingMsg : NSObject

@property (nonatomic, assign) TALRecordingCmd recCmd;
@property (nonatomic, copy) NSString* confId;
@property (nonatomic, copy) NSString* streamId;
@property (nonatomic, copy) NSString* seqNum;

@end

@interface TALRecordingMsgRsp : NSObject

@property (nonatomic, assign) TALRecordingCmd recCmd;
@property (nonatomic, assign) TALRecordingRes recRes;
@property (nonatomic, copy) NSString* confId;
@property (nonatomic, copy) NSString* streamId;

/**** 下面字段仅用于SDK内部测试，业务层请勿使用 ****/
@property (nonatomic, copy) NSString* pushRelaySvr;
@property (nonatomic, copy) NSString* pullRelaySvr;
@property (nonatomic, copy) NSString* recordingSvr;
@property (nonatomic, copy) NSString* resMsg;

@end

@interface TALRecording : NSObject

+ (NSString *)getCmdRes:(TALRecordingRes)recRes;
+ (NSString *)getCmd:(TALRecordingCmd)recCmd;

@end
