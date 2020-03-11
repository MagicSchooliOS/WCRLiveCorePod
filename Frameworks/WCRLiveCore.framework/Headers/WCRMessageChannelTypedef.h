//
//  WCRMessageChannelTypedef.h
//  WCRMessageChannelSDK
//
//  Created by juvham on 2019/3/15.
//  Copyright © 2019 juvham. All rights reserved.
//

#ifndef WCRMessageChannelTypedef_h
#define WCRMessageChannelTypedef_h

/**
 发送消息的结果,非WCRSendMessageResultOK为发送失败
 
 - WCRSendMessageResultOK: 成功
 - WCRSendMessageResultTimeout: 超时
 - WCRSendMessageResultBusy: 服务繁忙
 - WCRSendMessageResultError: 出错
 */
typedef NS_ENUM(NSUInteger, WCRMCSendMessageResult) {
    WCRMCSendMessageResultOK = 0,
    WCRMCSendMessageResultTimeout,
    WCRMCSendMessageResultBusy,
    WCRMCSendMessageResultError
};

/**
 发送消息的回调
 
 @param result 结果，@see WCRSendMessageResult
 @param callbackInfo 回调信息数组，一般取firstObject
 */
typedef void(^WCRMCSendMessageCallback)(WCRMCSendMessageResult result, NSArray *_Nullable callbackInfo);




#endif /* WCRMessageChannelTypedef_h */
