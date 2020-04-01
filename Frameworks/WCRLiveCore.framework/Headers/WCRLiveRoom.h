//
//  WCRLiveRoom.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
//base types
#import <WCRLiveCore/WCRLiveCoreConstants.h>
#import <WCRLiveCore/WCRError.h>
#import <WCRLiveCore/WCRTypedef.h>
//viewmodel
#import <WCRLiveCore/WCRPlayingVM.h>
#import <WCRLiveCore/WCRRecordingVM.h>
#import <WCRLiveCore/WCRLoadingVM.h>
#import <WCRLiveCore/WCROnlineUsersVM.h>
#import <WCRLiveCore/WCRRoomVM.h>
#import <WCRLiveCore/WCRPlaybackVM.h>
#import <WCRLiveCore/WCRDoodleVM.h>
#import <WCRLiveCore/WCRDoodleVM+ThirdPart.h>
#import <WCRLiveCore/WCRDoodleVM+Local.h>
#import <WCRLiveCore/WCRDoodleVM+Document.h>
#import <WCRLiveCore/WCRDocumentVM.h>
#import <WCRLiveCore/WCRDocumentVM+AVDoc.h>
#import <WCRLiveCore/WCRDocumentVM+WebDoc.h>
#import <WCRLiveCore/WCRDocumentVM+Image.h>
#import <WCRLiveCore/WCRDocumentVM+Whiteboard.h>
#import <WCRLiveCore/WCRDocumentVM+QuestionBank.h>
#import <WCRLiveCore/WCRDocumentVM+Interaction.h>
#import <WCRLiveCore/WCRMessageVM.h>
#import <WCRLiveCore/WCRResourceManager.h>
#import <WCRLiveCore/WCRChatChannel.h>
//model
#import <WCRLiveCore/WCRUser.h>
#import <WCRLiveCore/WCRRoomInfo.h>
#import <WCRLiveCore/WCRFeatureConfig.h>
NS_ASSUME_NONNULL_BEGIN

/**
 生命周期:
 1. 创建房间
 2. 加入房间
 3. loading
 4. 加入房间成功或失败
 5. 断线、重连
 6. 主动或被动退出
 */

/**
 WCRLiveRoomDelegate是教室关键事件的回调，主要包括进房成功、失败等
 */
@protocol WCRLiveRoomDelegate<NSObject>
@required

/**
 加入房间的回调

 @param error 进入成功是nil，失败是具体的错误信息
 */
- (void)roomDidJoin:(nullable WCRError*)error;

/**
 即将退出房间的回调

 @param reason 退出房间的原因，@see WCRLeaveRoomReason
 */
- (void)roomWillLeave:(WCRLeaveRoomReason)reason;

/**
 退出房间完成的回调
 */
- (void)roomDidLeave;

@end

/**
 WCRLiveRoom是直播教室的逻辑实体，同时只能存在一个教室，在旧教室退出并销毁之前不能创建新的教室
 */
@interface WCRLiveRoom : NSObject

typedef void (^createRoomBlock)(WCRLiveRoom* room);

/**
 通过房间信息、进房用户信息创建教室

 @param info 房间信息，主要包括机构ID、教室ID、教室名称等房间相关的信息
 如果需要看回放，需要配置info.roomStatus = WCRLiveRoomClassStatusAfterClass;
 @param user 进房用户信息，主要包括用户ID、token、头像等用户相关的信息
 @param completion 创建房间成功的回调block，block参数是创建的room
 @discussion 同时只能存在一个房间，如果在创建房间的回调返回之前创建了新的房间，只会保留最后一次创建的房间信息和并使用最后一次传入的block回调结果
 */
+ (void)createRoomWithInfo:(WCRRoomInfo*)info
                        user:(WCRUser*)user
                completion:(createRoomBlock)completion;


/**
 加入房间，结果会通过delegate回调

 @return 当前状态是否可以join，inRoom为false才能join，并且不能连续多次join
 */
- (BOOL)join;

/**
 离开房间，结果会通过delegate回调
 
 @return 当前状态是否可以leave，即房间是didJoinRoom之后的inRoom状态，不可以连续多次leave
 */
- (BOOL)leave;

/**
 更新房间信息

 @param info 房间信息
 */
- (void)updateRoomInfo:(WCRRoomInfo *)info;

/**
 SDK版本号

 @return SDK版本号
 */
+ (NSString *)getSDKVersion;

/**
 房间信息，初始化时由外部传入的值
 */
@property(nonatomic, strong, readonly) WCRRoomInfo* info;

/**
 用户信息，初始化时由外部传入的值
 */
@property(nonatomic, strong, readonly) WCRUser* user;

/**
 进教室的loading状态,@see WCRLoadingVM
 */
@property(nonatomic, strong) WCRLoadingVM* loadingVM;

/**

 拉流相关viewmodel,@see WCRPlayingVM
 */
@property(nonatomic, strong) WCRPlayingVM* playingVM;

/**
 拉流相关viewmodel,@see WCRRocordingVM
 */
@property(nonatomic, strong) WCRRecordingVM* recordingVM;

/**
 绑定文档课件的涂鸦
 */
@property(nonatomic,strong)  WCRDoodleVM *doodleVM;


/**
 文档相关viewmodel,@see WCRDocumentVM
 */
@property(nonatomic, strong) WCRDocumentVM* documentVM;

/*
 用户列表管理, @see WCROnlineUserModel
 */
@property(nonatomic, strong) WCROnlineUsersVM* onlineUserVM;

/**
 房间管理，@see WCRRoomVM
 */
@property(nonatomic, strong, nullable) WCRRoomVM* roomVM;

/**
 回放房间管理，@see WCRPlaybackVM
 */
@property(nonatomic, strong, nullable) WCRPlaybackVM* playbackVM;

/**
 绑定消息中心
 */
@property(nonatomic,strong)  WCRMessageVM *messageVM;

/**
 教室的delegate，@see WCRLiveRoomDelegate
 */
@property(nonatomic, weak) id<WCRLiveRoomDelegate> delegate;

/**
 是否在房间内
 */
@property(nonatomic, assign, readonly) BOOL inRoom;

/**
 特殊功能配置
 */
@property(nonatomic, strong) WCRFeatureConfig* config;

/**
 错误信息，可能为空，可在出错时获取
 */
@property(nonatomic, strong, readonly) WCRError* error;

/**
 SDK的使用环境，@see WCREnvironmentType，默认是线上环境
 */
@property(nonatomic, assign) WCREnvironmentType envType;

/**
 默认信道，available after roomDidJoin success
 */
@property(nonatomic, strong) WCRChatChannel *defaultChatChannel;

@end

NS_ASSUME_NONNULL_END
