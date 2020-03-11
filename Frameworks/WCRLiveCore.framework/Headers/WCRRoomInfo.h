//
//  WCRRoomInfo.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WCRTypedefs.h"
#import "WCRUser.h"

NS_ASSUME_NONNULL_BEGIN
/**
 房间信息，主要包括房间ID、机构ID、房间名、教室信息
 */
@interface WCRRoomInfo : NSObject<NSCopying>

/**
 房间信息
 
 @param roomID 房间ID
 @param appID 机构ID
 @param name 房间名称
 @param teacher 教师信息
 @param type 房间类型，@see WCRRoomType
 @param module 使用的模块, @see WCRLiveRoomModule
 @return 房间信息实例
 */
- (instancetype)initWithRoomID:(NSString*)roomID
                         appID:(NSString*)appID
                      roomName:(nullable NSString*)name
                       teacher:(nullable WCRUser*)teacher
                          type:(WCRRoomType)type
                        status:(WCRLiveRoomClassStatus)status
                        module:(WCRLiveRoomModule)module;

/**
 房间ID，最大32位的数字格式的字符串
 */
@property(nonatomic, copy) NSString* roomID;

/**
 机构ID，直播云后台分配的机构ID
 */
@property(nonatomic, copy) NSString* appID;

/**
 房间名称，可以为空
 */
@property(nonatomic, copy, nullable) NSString* roomName;

/**
 老师信息，教室没有设置老师可以为空
 */
@property(nonatomic, copy, nullable) WCRUser* teacher;

/**
 与当前用户同组的所有用户信息，初始化时由外部传入的值，允许外部修改
 */
@property(nonatomic, strong) NSArray<NSString *> *groupUsersUid;

/**
 房间类型，一对一、小班、大班等
 */
@property(nonatomic, assign) WCRRoomType roomType;

/**
  课堂状态，上课前、上课中、上课后
 */
@property(nonatomic, assign) WCRLiveRoomClassStatus roomStatus;

/**
 使用的模块 音视频、课件、涂鸦、聊天
 */
@property(nonatomic, assign) WCRLiveRoomModule module;

/**
 回放类型
 */
@property (nonatomic, assign) WCRRoomPlaybackType playbackType;

@end
NS_ASSUME_NONNULL_END
