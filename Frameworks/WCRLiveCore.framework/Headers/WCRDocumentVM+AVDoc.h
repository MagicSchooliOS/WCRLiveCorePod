//
//  WCRDocument+WebDoc.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/10/19.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <WCRLiveCore/WCRDocumentVM.h>

NS_ASSUME_NONNULL_BEGIN

/**
 当前音视频课件的状态

 - WCRDocumentVMAVDocPlayStatusNone: 初始值
 - WCRDocumentVMAVDocPlayStatusReadyToPlay: 达到可播放状态
 - WCRDocumentVMAVDocPlayStatusBuffering: 正在缓冲
 - WCRDocumentVMAVDocPlayStatusDidSeek: seek完成
 - WCRDocumentVMAVDocPlayStatusFinish: 正常播放完成
 - WCRDocumentVMAVDocPlayStatusError: 出现错误
 */

typedef NS_ENUM(NSUInteger, WCRDocumentVMAVDocPlayStatus) {
    WCRDocumentVMAVDocPlayStatusNone = 0,
    WCRDocumentVMAVDocPlayStatusReadyToPlay,
    WCRDocumentVMAVDocPlayStatusBuffering,
    WCRDocumentVMAVDocPlayStatusDidSeek,
    WCRDocumentVMAVDocPlayStatusFinish,
    WCRDocumentVMAVDocPlayStatusError
};

@protocol WCRDocumentVMAVDocDelegate <NSObject>
@required
@optional

/**
 课件播放状态改变

 @param documentModel 课件model
 @param playState 播放状态
 */
- (void)document:(WCRDocumentModel *)documentModel didChangePlayState:(WCRDocumentVMAVDocPlayStatus)playState;
@end

@interface WCRDocumentVM()

/**
 音视频课件代理
 */
@property (nonatomic, weak) id<WCRDocumentVMAVDocDelegate>avDocDelegate;

/**
 音视频课件错误消息
 */
@property (nonatomic, strong) WCRError *avDocError;

/**
 根据课件id获取音视频课件播放状态

 @param documentId 课件id
 @return 视频课件播放状态
 */
- (WCRDocumentVMAVDocPlayStatus)playStateWithDocumentId:(NSString *)documentId;

/**
 音视频课件是否正在播放

 @param documentId 课件id
 @return 是否正在播放
 */
- (BOOL)isPlayingWithDocumentId:(NSString *)documentId;

/**
 根据课件id获取音视频课件当前播放时间
 @warning 需要在WCRDocumentVMAVDocPlayStatusReadyToPlay状态回调之后获取 @see WCRDocumentVMAVDocPlayStatus

 @param documentId 课件id
 @return 当前播放时间
 */
- (NSTimeInterval)currentTimeWithDocumentId:(NSString *)documentId;

/**
 根据课件id获取音视频课件总时长
 @warning 需要在WCRDocumentVMAVDocPlayStatusReadyToPlay状态回调之后获取 @see WCRDocumentVMAVDocPlayStatus
 
 @param documentId 课件id
 @return 当前播放时间
 */
- (NSTimeInterval)totalTimeWithDocumentId:(NSString *)documentId;

/**
 根据课件id获取音视频课件当前缓冲时长
 @warning 需要在WCRDocumentVMAVDocPlayStatusReadyToPlay状态回调之后获取 @see WCRDocumentVMAVDocPlayStatus
 
 @param documentId 课件id
 @return 当前播放时间
 */
- (NSTimeInterval)bufferDurationWithDocumentId:(NSString *)documentId;
@end

NS_ASSUME_NONNULL_END
