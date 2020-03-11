#import <Foundation/Foundation.h>

// Constant to identify the TALRoom error domain.
FOUNDATION_EXPORT NSString* const TALRoomErrorDomain;

// Keys in the user info dictionary in errors TALRoom creates.
FOUNDATION_EXPORT NSString* const TALRoomErrorReasonKey;

// TALRoom error codes
typedef NS_ENUM(NSInteger, TALRoomError) {
    TALRoomErrorUnknown = -1,       // 未知错误
    TALRoomErrorNoError,            // 成功
    
    // Join room error code
    TALRoomErrorTimeout,            // 进入房间超时，内部会自动重试
    
    // Leave room error code
    TALRoomErrorForceLeave,         // 同一个用户在其它设备上进入同一个房间，当前用户被挤掉
    TALRoomErrorServerDisconnected, // 与服务器断开连接，内部会自动重试
};

@interface TALRoomStream : NSObject

@property (nonatomic, copy) NSString* streamId;
@property (nonatomic, assign) BOOL isAudioPublished;
@property (nonatomic, assign) BOOL isVideoPublished;

@end

@interface TALRoomUser : NSObject

@property (nonatomic, copy) NSString* userId;
@property (nonatomic, assign) BOOL isMicrophoneOpened;
@property (nonatomic, assign) BOOL isCameraOpened;
@property (nonatomic, copy) NSArray<TALRoomStream *>* streams;

@end

@class TALContext;
@protocol TALRoomDelegate;

@interface TALRoom : NSObject

- (instancetype)initWithContext:(TALContext *)context;
- (void)destroy;

- (BOOL)addDelegate:(id<TALRoomDelegate>)delegate delegateQueue:(dispatch_queue_t)queue;
- (void)removeDelegate:(id<TALRoomDelegate>)delegate;
- (void)removeAllDelegates;

- (void)joinRoom;
- (void)leaveRoom;
- (NSArray<TALRoomUser *> *)getAllUser;

@end

@protocol TALRoomDelegate <NSObject>

- (void)onRoom:(TALRoom *)room selfJoinWithError:(NSError *)error;
- (void)onRoom:(TALRoom *)room selfLeaveWithError:(NSError *)error;
- (void)onRoom:(TALRoom *)room joinWithUserId:(NSString *)userId;
- (void)onRoom:(TALRoom *)room leaveWithUserId:(NSString *)userId;
- (void)onRoom:(TALRoom *)room startPublishWithUserId:(NSString *)userId streamId:(NSString *)streamId;
- (void)onRoom:(TALRoom *)room stopPublishWithUserId:(NSString *)userId streamId:(NSString *)streamId;
- (void)onRoom:(TALRoom *)room userId:(NSString *)userId microphoneOpened:(BOOL)opened;
- (void)onRoom:(TALRoom *)room userId:(NSString *)userId cameraOpened:(BOOL)opened;
- (void)onRoom:(TALRoom *)room userId:(NSString *)userId streamId:(NSString *)streamId audioPublished:(BOOL)published;
- (void)onRoom:(TALRoom *)room userId:(NSString *)userId streamId:(NSString *)streamId videoPublished:(BOOL)published;

@end
