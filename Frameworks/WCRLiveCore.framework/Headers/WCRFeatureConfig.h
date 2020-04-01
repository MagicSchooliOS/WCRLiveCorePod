//
//  WCRFeatureConfig.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/23.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 特殊功能配置
 */
@interface WCRFeatureConfig : NSObject

/**
 是否是51计划
 */
@property(nonatomic, assign, getter=isPlan51) BOOL Plan51;

/**
 51计划中当前房间关联的流ID
 */
@property(nonatomic, copy) NSString* associateStreamID;

/**
 使用同一appid映射不同机构的id，不传或者传入0时无效
 */
@property(nonatomic, copy) NSString* mapAppID;

/**
是否发送广播消息
 */
@property (nonatomic, assign, getter=isDisableBroadcast) BOOL disableBroadcast;

/**
 是否使用docMode判断权限
 */
@property (nonatomic, assign, getter=isUseDocMode) BOOL useDocMode;

/**
 * 是否是口令课，口令课和非口令课内部会有微小的差异
 */
@property (nonatomic, assign, getter=isCodeClass) BOOL codeClass;
@end
