//
//  WCRLiveUser.h
//  WCRLivePlayerBirdge
//
//  Created by Sanji on 16/8/22.
//  Copyright © 2016年 Sanji. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WCRLiveClassInfoModel : NSObject
///学生id
@property (nonatomic, copy) NSString *uid;
///老师id
@property (nonatomic, copy) NSString *teacher_master_id;
///助教id
@property (nonatomic, copy) NSString *teacher_assist_id;
///课程id
@property (nonatomic, copy) NSString *course_id;
///课节id
@property (nonatomic, copy) NSString *class_id;
///章节id
@property (nonatomic, copy) NSString *chapter_id;
///与听云绑定的学员id 闪退时根据听云日志里的userId找到对应的SDK日志
@property (nonatomic, copy) NSString *student_id;
///其他私有数据上报
@property (nonatomic, strong) NSDictionary *privateData;


/**
 方便统一ClassInfoModel的默认值

 @return ClassInfoModel
 */
+ (instancetype)defaultClassInfo;

@end
