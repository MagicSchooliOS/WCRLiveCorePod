//
//  WCRMessageVM.h
//  WCRLiveCore
//
//  Created by handd on 2019/2/18.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCRTypedef.h>
#import <WCRLiveCore/WCRMessageChannelTypedef.h>
#import <WCRLiveCore/WCRError.h>

/**
 分发消息给外部业务
 */
@protocol WCRMessageVMDelegate<NSObject>

@optional

/**
 分发出去与外部业务相关的消息
 
 @param message 消息信息
 */
- (void)onReceivedMessage:(NSDictionary *)message;

/**
 当前信道服务器延迟，从发送ping到收到pong的时间差
 首次连接消息信道成功时回调一次，接下来大概30秒回调一次
 
 @param delay 服务器延迟
 */
- (void)updateNetDelay:(NSUInteger)delay;

@end


@interface WCRMessageVM : NSObject

@property (nonatomic, weak) id<WCRMessageVMDelegate> delegate;

/**
 业务层调用此方法发送消息
 普通消息

 @param jsonString 消息信息，只能传入json字符串
 @param uidsArray 消息接收者，不可传空数组
 @return 返回nil表示成功，非nil表示失败
 */
- (WCRError *)sendMessage:(NSString *)jsonString to:(NSArray *)uidsArray;

/**
 业务层调用此方法发送消息
 普通消息
 
 @param jsonString 消息信息，只能传入json字符串
 @param uidsArray  消息接收者，不可传空数组
 @param callback   方法回调
 @return 返回nil表示成功，非nil表示失败
 */
- (WCRError *)sendMessage:(NSString *)jsonString to:(NSArray *)uidsArray withCallback:(WCRMCSendMessageCallback)callback;

 /**
 仅限大班课使用
 
 @param jsonString 消息信息，只能传入json字符串
 @param uidsArray  消息接收者，不可传空数组
  @return 返回nil表示成功，非nil表示失败
 */
- (WCRError *)sendStreamTalkerAckMessage:(NSString *)jsonString to:(NSArray *)uidsArray;;

/**
 业务层调用此方法发送消息
 广播消息
 
 @param jsonString 消息信息，只能传入json字符串
 @return 返回nil表示成功，非nil表示失败
 */
- (WCRError *)broadcastMessage:(NSString *)jsonString;

/**
 业务层调用此方法发送消息
 广播消息
 
 @param jsonString 消息信息，只能传入json字符串
 @param callback    方法回调
 @return 返回nil表示成功，非nil表示失败
 */
- (WCRError *)broadcastMessage:(NSString *)jsonString withCallback:(WCRMCSendMessageCallback)callback;

@end

