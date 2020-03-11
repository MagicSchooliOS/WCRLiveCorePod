//
//  WCRLiveCoreConstants.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 根据SDK使用环境来确定API的Host
 */
extern NSString* const kWCRAPIHost[];

/**
 根据SDK使用环境来确定数据上报服务的host
 */
extern NSString* const kWCRDataReportServerHost[];

/**
 根据SDK使用环境来确定流媒体上报服务的Host
 */
extern NSString* const kWCRTALReportServerHost[];

/**
 根据SDK使用环境来确定回放服务器的Host
 */
extern NSString* const kWCRPlaybackServerHost[];

/**
 用户信息云控接口路径
 */
extern NSString* const kWCRAPIUserInfoPath;

/**
 课程信息云控接口路径
 */
extern NSString* const kWCRAPIClassInfoPath;

/**
 获取信道服务地址接口路径
 */
extern NSString* const kWCRAPIIMInfoPath;

/**
 上报日志信息接口路径
 */
extern NSString* const kWCRAPIUploadLogPath;

/**
 API接口加密串
 */
extern NSString* const kWCRAPISecretKey;

/**
 获取回放相关接口
 */
extern NSString* const kWCRAPIFetchPlaybackPath;

/**
 获取回放准备接口
 */
extern NSString* const kWCRAPIFetchPlaybackStatusPath;

/**
 获取OssToken相关接口
 */
extern NSString* const kWCRAPIOssTockenPath;

/**
 获取OssKey
 */
extern NSString* const kWCROssAppKey[];

/**
 获取日志上传的OssAppId
 */
extern NSString* const kWCROssLogAppId[];

/**
 获取回放数据OssAppId
 */
extern NSString* const kWCROssPlaybackAppId[];

/**
 根据SDK使用环境来确定题库需要的Host
 */
extern NSString* const kWCRQuestionServerHost[];

/**
 题库接口path
 */
extern NSString* const kWCRQuestionPath;

/**
 点名接口
 */
extern NSString* const kWCRRollCallPath;
/**
 点名注册接口
 */
extern NSString* const kWCRAPIRegister;
