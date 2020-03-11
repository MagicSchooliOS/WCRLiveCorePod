//
//  WCRLivePlayerProxyConfiguration.h
//  WCRLivePlayerSDK
//
//  Created by zhuxuhong on 2019/4/22.
//  Copyright © 2019 juvham. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WCRLiveCommonDefine.h"

#pragma mark - Consts

#pragma mark - Protocol

@interface WCRLivePlayerProxyConfiguration : NSObject

#pragma mark - Properties
/// 是否需要认证: 默认=YES
@property(nonatomic)BOOL needsAuth;
/// 代理服务器IP地址
@property(nonatomic, copy)NSString *IP;
/// 代理服务器端口
@property(nonatomic)NSInteger port;
/// 认证用户名
@property(nonatomic, copy)NSString *authUserName;
/// 认证密码
@property(nonatomic, copy)NSString *authPassword;
/// 代理服务器所在地区
@property(nonatomic, copy, readonly)NSString *region;
/// 代理服务器状态: 0关闭（默认） 1开启
@property(nonatomic, readonly)NSInteger status;
/// 代理连接状态: 默认是unknown
@property(nonatomic, readonly)WCRProxyConnectStatus connectStatus;

#pragma mark - Methods

@end
