//
//  WCRDocumentVM.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/10/19.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WCRLiveCore/WCRError.h>
#import <WCRLiveCore/WCRDocumentModel.h>
#import <WCRLiveCore/WCRAuthorizeChangePageModel.h>
#import <WCRLiveCore/WCRLocationModel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 课件关闭原因

 - WCRDocumentVMCloseReasonRemoteClose: 课件被远程关闭
 - WCRDocumentVMCloseReasonMemoryWarning: 接收到内存警告导致关闭
 */
typedef NS_ENUM(NSUInteger, WCRDocumentVMCloseReason){
    WCRDocumentVMCloseReasonRemoteClose = 0,
    WCRDocumentVMCloseReasonMemoryWarning
};

@protocol WCRDocumentVMDelegate <NSObject>
@optional

/**
 课件即将被加载

 @param documentModel 课件model @see WCRDocumentModel
 @brief 这时候可以取documentModel.documentView 进行课件布局等操作
 */
- (void)documentWillLoad:(WCRDocumentModel *)documentModel;

/**
 课件已经加载完成

 @param documentModel 课件model
 @param error 为nil时加载成功，非nil加载失败
 */
- (void)documentDidLoad:(WCRDocumentModel *)documentModel error:(WCRError * _Nullable)error;

/**
 课件即将被关闭

 @param documentModel 课件model
 @param reason 关闭原因
 @brief 课件在此回调之后开始销毁
 */
- (void)documentWillClose:(WCRDocumentModel *)documentModel reason:(WCRDocumentVMCloseReason)reason;

/**
 课件已经被关闭

 @param documentModel 课件model
 */
- (void)documentDidClose:(WCRDocumentModel *)documentModel;

/**
 课件已经被最小化
 
 @param documentModel 课件model
 */
- (void)documentDidMinimize:(WCRDocumentModel *)documentModel;

/**
 当前课件被改变

 @param documentModel 课件model
 */
- (void)currentDocumentChange:(WCRDocumentModel *)documentModel;

/**
 课件被全屏
 @warning 这个只是全屏回调，具体全屏操作由用户根据documentView自定义处理

 @param documentModel 课件model
 */
- (void)documentFullScreen:(WCRDocumentModel *)documentModel;

/**
 课件位置被刷新

 @param documentModel 课件model
 @param locationModel 被更新的位置
 */
- (void)document:(WCRDocumentModel *)documentModel locationChanged:(WCRLocationModel *)locationModel;
@end

@interface WCRDocumentVM : NSObject

/**
 课件代理
 */
@property (nonatomic, weak) id<WCRDocumentVMDelegate>delegate;

/**
 课件当前权限
 @warning 权限由老师控制，为了保证老师与学生的课件同步，学生无法主动控制课件权限
 */
@property (nonatomic, assign, readonly,getter=isDocumentAuthorized) BOOL documentAuthorized;

/**
 学生打开课件

 @param docID 课件id，不能为空
 @param docName 课件名字
 @param docUrl 课件地址
 @param docType 课件类型 @see WCRDocumentType
 */
- (void)openDocumentWithId:(NSString *)docID documentName:(NSString * _Nullable)docName documentUrl:(NSURL * _Nullable)docUrl documentType:(WCRDocumentType)docType;

/**
 移除某一课件

 @param documentId 课件的documentID
 */
- (void)removeDocumentWithDocumentId:(NSString *)documentId;

/**
 移除所有课件
 */
- (void)removeAllDocument;

/**
 获取当前视频课件model

 @return 当前视频课件model
 */
- (WCRDocumentModel * _Nullable)getCurrentVideoDocumentModel;

/**
 获取当前音频课件model

 @return 当前音频课件model
 */
- (WCRDocumentModel * _Nullable)getCurrentAudioDocumentModel;

/**
 获取当前网页课件model

 @return 网页课件model
 */
- (WCRDocumentModel * _Nullable)getCurrentWebDocumentModel;

/**
 根据课件id获取课件model

 @param documentId 课件id
 @return 课件model
 */
- (WCRDocumentModel * _Nullable)getDocumentModelWithId:(NSString *)documentId;

@end

NS_ASSUME_NONNULL_END
