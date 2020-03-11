//
//  WCRChatChannel.h
//  WCRLiveCore
//
//  Created by meng on 2019/3/21.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WCRError;
@class WCRUser;
@class WCRRoomInfo;

/**
 发送消息的结果，非WCRCHCSendMessageResultOK为发送失败
 
 - WCRCHCSendMessageResultOK: 成功
 - WCRCHCSendMessageResultTimeout: 超时
 - WCRCHCSendMessageResultBusy: 服务繁忙或消息发送间隔过短
 - WCRCHCSendMessageResultError: 出错
 */
typedef NS_ENUM(NSUInteger, WCRCHCSendMessageResult) {
    WCRCHCSendMessageResultOK = 0,
    WCRCHCSendMessageResultTimeout,
    WCRCHCSendMessageResultBusy,
    WCRCHCSendMessageResultError
};

/**
 发送消息的回调
 
 @param result 结果，@see WCRCHCSendMessageResult
 @param callbackInfo 回调信息数组，一般取firstObject
 */
typedef void(^WCRCHCSendMessageCallback)(WCRCHCSendMessageResult result, NSArray *_Nullable callbackInfo);

/**
 获取公告的回调
 
 @param result 结果，@see WCRCHCSendMessageResult
 @param notice 通知文案
 */
typedef void(^WCRCHCRequestNoticeCallback)(WCRCHCSendMessageResult result, NSString *_Nullable notice);

/**
 获取历史消息的回调
 
 @param result 结果，@see WCRCHCSendMessageResult
 @param haveMore 是否还有更多消息
 @param messageList 历史消息数组
 @param lastMsgId 上一组数据消息锚点ID，下次获取更多历史消息的时候以最新的lastMsgId为锚点请求
 */
typedef void(^WCRCHCRequestHistoryMessageCallback)(WCRCHCSendMessageResult result,BOOL haveMore, NSArray *_Nullable messageList,NSString *_Nullable lastMsgId);

/**
 获取自己禁言状态的回调
 
 @param result 结果，@see WCRCHCSendMessageResult
 @param unspeaked 自己是否被禁言，true被禁言，false：没有被禁言
 */
typedef void(^WCRCHCRequestCurrentUserUnspeakStatusCallback)(WCRCHCSendMessageResult result,BOOL unspeaked);

NS_ASSUME_NONNULL_BEGIN


/**
 聊天信道的回调
 */
@class WCRChatChannel;
@protocol WCRChatChannelDelegate <NSObject>

@optional
/**
 进入房间的回调
 
 @param error 成功进入error为nil，否则是详细的错误信息
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel didJoinRoom:(nullable WCRError *)error;

/**
 离开房间的回调
 
 */
- (void)chatChannelDidLeaveRoom:(WCRChatChannel *)chatChannel;

/**
 信道断线的回调
 
 @param error 信道断线的详细错误信息
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel disconnected:(WCRError *)error;

/**
 断线重连成功的回调
 */
- (void)chatChannelReconnected:(WCRChatChannel *)chatChannel ;

/**
 断线重连中的回调
 */
- (void)chatChannelReconnecting:(WCRChatChannel *)chatChannel ;

/**
 断线重连失败的回调
 
 @param error 重连失败的详细错误信息
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel reconnectFailed:(WCRError *)error;

/////////////以上连接方面回调///////////以下首发消息相关回调//////////////
/**
 有用户进入教室
 
 @param user 用户信息
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel userJoinRoom:(WCRUser *)user;

/**
 用户退出教室
 
 @param user 用户信息
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel userLeaveRoom:(WCRUser *)user;

/**
 用户离线
 
 @param user 用户信息
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel userOffline:(WCRUser *)user;

/**
 用户被禁言回调
 
 @param unspeaked 禁言状态，true:被禁言  false:未e被禁言
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel currentUserBeUnspeaked:(BOOL)unspeaked;

/**
 收到公告消息
 
 @param notice 收到的公告文案
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel receiveNoticeMessage:(NSString *)notice;

/**
 收到聊天消息
 示例：
 {
 avatar = "";//头像
 index = 2;
 message = "";//消息,文字消息为字符串直接使用，  图片消息为json串@{@"name":@"",@"url":@"",@"width":@"",@"height":@""}
 mtype = message;//mtype:message为文字消息，‘picture’为图片消息；大班课会有“authorizemic”广播某某开始连麦
 role = 1;
 unixtime = 1554274665818;
 userid = 123090;
 username = mxpTeacher;
 }

 
 @param message 收到的聊天消息
 */
- (void)chatChannel:(WCRChatChannel *)chatChannel receivedChatMessage:(nullable id)message;

@end

@interface WCRChatChannel : NSObject

/**
 初始化传入的服务器地址
 */
@property(nonatomic,copy,readonly) NSString *serverUrl;

/**
 初始化传入的房间信息
 */
@property(nonatomic,copy,readonly) WCRRoomInfo *roomInfo;

/**
 初始化传入的用户信息
 */
@property(nonatomic,copy,readonly) WCRUser *user;

/**
 log日志打印路径，默认为 Library/Caches/WCRChatChannelSDKLogs
 */
@property(nonatomic,copy) NSString *logFilePath;

/**
 聊天信道关键事件代理
 */
@property(nonatomic,weak) id<WCRChatChannelDelegate> delegate;

/**
 创建聊天信道实例
 
 @param serverUrl 消息信道服务器地址
 @param info 房间信息
 @param user 用户信息
 @return 聊天信道实例
 */
+ (instancetype)channelWithServer:(NSString *)serverUrl
                         roomInfo:(WCRRoomInfo *)info
                             user:(WCRUser *)user;

/**
 加入房间
 */
- (void)joinRoom;

/**
 离开房间
 */
- (void)leaveRoom;

/**
 重连
 
 @return 当前状态是否可以重连
 */
- (BOOL)reconnect;

/**
 获取公告-通常进入房间后获取
 
 @param callback  获取公告的回调
 */
- (void)requestNoticeWithCallback:(WCRCHCRequestNoticeCallback)callback;

/**
 获取自己是否被禁言-通常进入房间后获取
 
 @param callback  获取自己是否被禁言的回调
 */
- (void)requestCurrentUserUnSpeakStatusWithCallback:(WCRCHCRequestCurrentUserUnspeakStatusCallback)callback;

/**
 获取历史消息-进入教室获取
 
 @param messageId 请求历史数据的锚点，第一次请求使用@“”，之后的获取更早数据使用callback返回的lastMsgId作为新的锚点
 @param callback  获取自己是否被禁言的回调
 */
- (void)requestHistoryMessageWithMessageId:(NSString *)messageId callback:(WCRCHCRequestHistoryMessageCallback)callback;

/**
 发送消息方法
 
 @param info 发送的消息结构体
 示例：
 NSDictionary *chatInfoDic = @{@"index":@"1",
 @"mtype":@"message",//mtype:message为文字消息，‘picture’为图片消息   后续可以根据需要自行扩展
 @"message":@"hello world!!!", //消息,文字消息为字符串，  图片消息为json串@{@"name":@"",@"url":@"",@"width":@"",@"height":@""}
 @"save":@"1",
 @"targetid":@""
 };
 @param callback  发送消息回调
 */
- (void)sendMessageWithInfo:(NSDictionary *)info withCallback:(WCRCHCSendMessageCallback)callback;



@end

NS_ASSUME_NONNULL_END
