#import <Foundation/Foundation.h>
#import <TALRTCMedia/TALStatistics.h>

typedef NS_ENUM(NSInteger, TALNetQualityType) {
    TALNET_QUALITY_UNKNOWN = -1,
    TALNET_QUALITY_EXCELLENT,
    TALNET_QUALITY_GOOD,
    TALNET_QUALITY_POOR,
    TALNET_QUALITY_BAD,
    TALNET_QUALITY_VBAD,
    TALNET_QUALITY_DOWN,
    TALNET_QUALITY_UNSUPPORTED,
    TALNET_QUALITY_DETECTING
};

@protocol TALInterInfoDelegate <NSObject>
- (void)onLastmileQuality:(TALNetQualityType)rxQuality txQuality:(TALNetQualityType)quality context:(id)context;
@end

@protocol TALCommonInfoDelegate <NSObject>
- (void)onTotalMediaStatisticInfo:(TALMediaTotalStatistics*)info;
@end

// Singleton
@interface TALContext : NSObject

+ (instancetype)sharedInstance;

+ (instancetype)allocWithZone:(struct _NSZone *)zone OBJC_UNAVAILABLE("allocWithZone not available, call sharedInstance instead");
+ (instancetype)alloc OBJC_UNAVAILABLE("alloc not available, call sharedInstance instead");
- (instancetype)init OBJC_UNAVAILABLE("init not available, call sharedInstance instead");
+ (instancetype)new OBJC_UNAVAILABLE("new not available, call sharedInstance instead");
- (instancetype)copy OBJC_UNAVAILABLE("copy not available, call sharedInstance instead");


// 设置日志文件大小需要在InitMediaSdk之前调用 单位：KB TalMedia有五个日志文件如果fileSizeInKBytes设置为1024，则
// SDk最多输出5M的文件，日志超出5M将覆盖之前的日志
- (void)setLogFileSize:(unsigned int) fileSizeInKBytes;

// 设置日志目录，需要确保目录已经创建，在调用 initSDK 之前调用
- (BOOL)setLogPath:(NSString *)logPath;

// 在调用除 setLogPath 之外的任何其它接口前调用
- (void)initSDK;

// 不再使用 SDK 时调用
- (void)unInitSDK;

- (NSString *)getVersion;

// RTC only
// The valid appID/userID/confID character set is 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_
- (BOOL)setAppID:(NSString *)appID;         // The maximum length of the appID is 32
- (BOOL)setUserID:(NSString *)userID;       // The maximum length of the userID is 32
- (BOOL)setConfId:(NSString *)confID;       // The maximum length of the confID is 32

- (BOOL)setUserName:(NSString *)userName;   // The maximum length of the userName is 100

- (void)enalbeDBA:(BOOL)enable; // default: NO
- (void)enableSoftAEC:(BOOL)enable;// default: YES

- (int)enableLastmileTest;
- (int)disableLastmileTest;
//建议在initSDK之后马上调用
- (void)setTalInterInfoDelegate:(id<TALInterInfoDelegate>)interInfoDelegate context:(id)context delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)setTotalCommonInfoDelegate:(id<TALCommonInfoDelegate>)commonInfoDelegate context:(id)context delegateQueue:(dispatch_queue_t)delegateQueue;

// 单位：秒
- (void)setStatisticsInterval:(float) interval;

@end
