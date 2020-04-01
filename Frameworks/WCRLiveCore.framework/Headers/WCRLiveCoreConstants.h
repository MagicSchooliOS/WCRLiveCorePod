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
extern NSString* kWCRAPIHost[];

/**
 根据SDK使用环境来确定数据上报服务的host
 */
extern NSString* kWCRDataReportServerHost[];

/**
 根据SDK使用环境来确定流媒体上报服务的Host
 */
extern NSString* kWCRTALReportServerHost[];

/**
 根据SDK使用环境来确定回放服务器的Host
 */
extern NSString* kWCRPlaybackServerHost[];

/**
 用户信息云控接口路径
 */
extern NSString* kWCRAPIUserInfoPath;

/**
 课程信息云控接口路径
 */
extern NSString* kWCRAPIClassInfoPath;

/**
 获取信道服务地址接口路径
 */
extern NSString* kWCRAPIIMInfoPath;

/**
 上报日志信息接口路径
 */
extern NSString* kWCRAPIUploadLogPath;

/**
 API接口加密串
 */
extern NSString* kWCRAPISecretKey;

/**
 获取回放相关接口
 */
extern NSString* kWCRAPIFetchPlaybackPath;

/**
 获取回放准备接口
 */
extern NSString* kWCRAPIFetchPlaybackStatusPath;

/**
 获取OssToken相关接口
 */
extern NSString* kWCRAPIOssTockenPath;

/**
 获取OssKey
 */
extern NSString* kWCROssAppKey[];

/**
 获取日志上传的OssAppId
 */
extern NSString* kWCROssLogAppId[];

/**
 获取回放数据OssAppId
 */
extern NSString* kWCROssPlaybackAppId[];

/**
 根据SDK使用环境来确定题库需要的Host
 */
extern NSString* kWCRQuestionServerHost[];

/**
 题库接口path
 */
extern NSString* kWCRQuestionPath;

/**
 点名接口
 */
extern NSString* kWCRRollCallPath;
/**
 点名注册接口
 */
extern NSString* kWCRAPIRegister;
