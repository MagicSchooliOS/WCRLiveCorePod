//
//  WCROnlineUserModel.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/22.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCRUser.h>


/**
 在线用户的状态

 - WCROnlineUserStatusOnline: 在线
 - WCROnlineUserStatusOffline: 断线
 */
typedef NS_ENUM(NSUInteger, WCROnlineUserStatus) {
    WCROnlineUserStatusOnline = 0,
    WCROnlineUserStatusOffline,
};

@interface WCROnlineUserModel : NSObject
@property(nonatomic, copy) WCRUser* user;
@property(nonatomic, assign) WCROnlineUserStatus status;
@end
