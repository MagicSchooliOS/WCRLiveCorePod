//
//  WCRLiveStreamLine.h
//  WCRLivePlayerSDK
//
//  Created by WCRLive on 2018/8/9.
//  Copyright © 2018年 培优在线. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 线路供应商常量
typedef NS_ENUM(NSUInteger, WCRLiveStreamSupplier) {
    WCRLiveStreamSupplierNone = 0,
    WCRLiveStreamSupplierWangsu = 1,// 网宿
    WCRLiveStreamSupplierAli = 2,// 阿里
    WCRLiveStreamSupplierBaiYunShan = 3,// 白云山
    WCRLiveStreamSupplierDiLian = 4,// 帝联
    WCRLiveStreamSupplierLanXun = 5,// 蓝讯
    WCRLiveStreamSupplierZiJian = 6,// 自建机房
    WCRLiveStreamSupplierTencent = 7,// 腾讯
    WCRLiveStreamSupplierOther = 8, //其他
};


/**
 线路信息model
 */
@interface WCRLiveStreamInfo : NSObject

/// 流地址
@property (nonatomic,copy) NSURL* _Nullable url;
/// 流id
@property (nonatomic,copy) NSString* _Nullable streamId;
/// 线路id
@property (nonatomic,copy) NSString* _Nullable lineId;
/// 线路的供应商
@property (nonatomic,assign) WCRLiveStreamSupplier supplier;
/// 调度后的流地址 调度逻辑由SDK内根据supplier来处理
@property (nonatomic,copy) NSURL* _Nullable dispatchedUrl;
/// 是否不可用: 默认为NO
@property(nonatomic)BOOL disabled;

/**
 WCRLiveStreamInfo唯一的初始化方法，调用init会报错
 @param url 流地址，与streamId两者设置一个
 @param streamId 流id，与url两者设置一个
 @param lineId 线路的id
 @param supplier 线路的供应商
 @return WCRLiveStreamLine类实例
 @warning 参数中streamId与url两者设置一个
 */
- (instancetype _Nonnull )initLineWithUrl:( NSURL * _Nullable)url streamId:(NSString * _Nullable)streamId lineId:(NSString * _Nullable)lineId supplier:(WCRLiveStreamSupplier )supplier;
@end
NS_ASSUME_NONNULL_END

