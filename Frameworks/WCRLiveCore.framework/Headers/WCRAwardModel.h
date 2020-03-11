//
//  WCRAwardModel.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/11/19.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCRUser.h>

@interface WCRAwardModel : NSObject
/**
 用户新增的奖励数量
 */
@property (nonatomic, assign) NSInteger awardCount;
/**
 用户所有的奖励数量
 */
@property (nonatomic, assign) NSInteger totalCount;
/**
 当前用户
 */
@property (nonatomic, strong) WCRUser *user;
@end
