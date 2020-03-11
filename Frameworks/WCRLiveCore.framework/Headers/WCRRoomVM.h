//
//  WCRRoomVM.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/23.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCRTypedef.h>
#import <WCRLiveCore/WCRAwardModel.h>
#import <WCRLiveCore/WCRUser.h>
#import <WCRLiveCore/WCRLocationModel.h>

NS_ASSUME_NONNULL_BEGIN
/**
 房间ViewModel回调
 */
@protocol WCRRoomVMDelegate<NSObject>
@optional
/**
 房间状态改变的回调

 @param status 房间当前状态,@see WCRLiveRoomStatus
 */
- (void)onUpdateRoomStatus:(WCRLiveRoomStatus)status;

/**
 房间课程状态改变的回调

 @param status 房间课程状态 @see WCRLiveRoomClassStatus
 @param time 服务器记录的时间 [NSDate dateWithTimeIntervalSince1970:time/1000];
 */
- (void)onUpdateRoomClassStatus:(WCRLiveRoomClassStatus)status time:(NSTimeInterval)time;

/**
 音视频模块状态改变

 @param status 音视频模块的状态, @see WCRLiveStreamStatus
 */
- (void)onUpdateLiveStreamStatus:(WCRLiveStreamStatus)status;

/**
 用户奖励回调
 如果数组里元素awardModel里的awardCount>0，表明是新增的奖励；
 如果awardCount==0，表明不是新的奖励，是奖励的状态同步。
 可以根据上述说明决定上层动画表现

 @param awardModels 奖励模型数组 @see WCRAwardModel
 */
- (void)onAward:(NSArray <WCRAwardModel *>*)awardModels;

/**
 用户拉流位置信息被改变 TODO 位置改变放在拉流VM
 @warning 只有用户处于WCRPreviewStyleFloat状态时，才会有回调
 
 @param user 被改变的用户
 @param locationModel 用户视图位置信息
 */
- (void)onPreviewFloatLocationChanged:(WCRUser *)user locationInfoModel:(WCRLocationModel *)locationModel;

/**
 用户拉流视频预览模式被改变 TODO 模式改变放在拉流VM

 @param previewStyle 预览模式 @see WCRPreviewStyle
 @param user 被改变的用户
 */
- (void)onPreviewStyleChanged:(WCRPreviewStyle)previewStyle user:(WCRUser *)user;

/**
 自适应上讲台模式

 @param users 自适应上讲台用户
 @param isAdaptiveMode 是否是自适应模式
 */
- (void)onPreviewLayoutModeChange:(NSArray <WCRUser *>*)users isAdaptiveMode:(BOOL)isAdaptiveMode;


/**
 用户的课件权限被改变 TODO 课件权限回调放在课件VM

 @param user 被改变的用户
 @param permission 课件权限
 */
- (void)onUser:(WCRUser *)user documentPermissionChanged:(BOOL)permission;

/**
 用户的涂鸦权限被改变 TODO 涂鸦权限回调放在涂鸦VM

 @param user 被改变的用户
 @param permission 涂鸦权限
 @param showBar 是否显示涂鸦工具条
 */
- (void)onUser:(WCRUser *)user doodlePermissionChanged:(BOOL)permission showDoodleToolBar:(BOOL)showBar;

/**
 用户的答题状态被改变 TODO 答题状态改变放在课件VM

 @param user 被改变的用户
 @param permission 是否已经答题
 */
- (void)onUser:(WCRUser *)user answerStateChanged:(BOOL)permission;

/**
 用户的举手状态改变
 
 @param user 被改变的用户
 @param handup 是否举手
 */
- (void)onUser:(WCRUser *)user handupStateChanged:(BOOL)handup;


/**
 加载完成课程级云控回调

 @param classInfoDict 第三方机构配置的云控信息
 */
- (void)onLoadClassInfo:(NSDictionary *)classInfoDict;

/**
 加载完成用户云控回调
 
 @param userInfoDict 第三方机构配置的云控信息
 */
- (void)onLoadUserInfo:(NSDictionary *)userInfoDict;

/**
 老师发起课堂点名功能
 
 用于多人教室中，确认学生是否在挂机，学生对点名需要做出响应。业务层需要在学生做出响应后调用接口:-respondRollCall
 @param duration 学生在此时间内需要做出响应，时间由老师控制
 */
- (void)onRollCallDuration:(NSUInteger)duration;
@end

/**
 房间ViewModel，处理线路切换、发公告等房间相关的业务逻辑
 */
@interface WCRRoomVM : NSObject

/**
 重连

 @return 重连失败后如果还需要继续重连的话调用此方法，仅限重连失败时调用
 */
- (BOOL)reconnect;

/**
 注册学生（点名）
 */
- (void)rollAddStudent;

/**
 回应老师点名
 需要收到回调:-onRollCallDuration:后调用，否则调用无效
 */
- (void)respondRollCall;

/**
 开始举手
 */
- (void)startHandUp;

/**
 结束举手
 */
- (void)stopHandUp;

/**
 当前状态
 */
@property(nonatomic, assign, readonly) WCRLiveRoomStatus status;

/**
 当前课程状态
 */
@property(nonatomic, assign, readonly) WCRLiveRoomClassStatus classStatus;

/**
 当前音视频模块d状态
 */
@property(nonatomic, assign, readonly) WCRLiveStreamStatus liveStreamStatus;

/**
 delegate回调
 */
@property(nonatomic, weak) id<WCRRoomVMDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
