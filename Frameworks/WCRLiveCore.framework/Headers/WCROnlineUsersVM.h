//
//  WCROnlineUsersVM.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCROnlineUserModel.h>

/**
 用户列表viewModel回调
 */
@protocol WCROnlineUserVMDelegate<NSObject>

/**
 用户加入

 @param userModel 用户信息model
 @param isACK 为NO时，表明用户进入教室。isACK 为YES时，表明用户已经在教室，自己进入教室时，其它在教室的用户会回复ACK。
 */
- (void)onUserJoined:(WCROnlineUserModel*)userModel isACK:(BOOL)isACK;

/**
 用户退出

 @param userModel 用户信息model
 */
- (void)onUserLeft:(WCROnlineUserModel*)userModel;

/**
 用户状态改变，在线、断线

 @param userModel 用户信息model
 @param status 用户状态
 */
- (void)onUser:(WCROnlineUserModel*)userModel statusChanged:(WCROnlineUserStatus)status;

/**
 在线人数改变（大班课使用）
 
 @param onlineCount 在线用户数量
 */
- (void)onlineCountChanged:(NSUInteger)onlineCount;

@end

/**
 用户列表viewModel
 */
@interface WCROnlineUsersVM : NSObject

/**
 delegate回调
 */
@property(nonatomic, weak) id<WCROnlineUserVMDelegate> delegate;

/**
 在线人数
 */
@property(nonatomic, assign) NSInteger onlineCount;

/**
 房间内的所有在线用户，无序数组
 */
@property(nonatomic, strong, readonly) NSArray<WCROnlineUserModel*>* onlineUsers;

@end
