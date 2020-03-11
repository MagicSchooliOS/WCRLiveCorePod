//
//  WCRResourceManager.h
//  WeClassRoomSDK
//
//  Created by 周吾昆 on 2018/6/22.
//  Copyright © 2018年 WeClassRoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCRTypedefs.h>
#import "WCRTypedef.h"
NSString* WCRResourceCacheDirectory(void);
typedef NS_ENUM(NSInteger,WCRResourceDownloadStatus){
    WCRResourceDownloadStatusSuccess = 0, //下载成功
    WCRResourceDownloadStatusInvalidParameter, //传参错误
    WCRResourceDownloadStatusDownloadFail, //网络下载失败
    WCRResourceDownloadStatusDownloadCancel, //下载取消
    WCRResourceDownloadStatusNoStorageSpace,//存储空间不足
    WCRResourceDownloadStatusLowStorageSpace,//存储空间小于100M
    WCRResourceDownloadStatusUnzipFail, //zip解压缩失败
    WCRResourceDownloadStatusFileInvalid, //解压缩文件失效,md5不匹配
    WCRResourceDownloadStatusFileDownloading //下载中
};
typedef NS_ENUM(NSUInteger,WCRCacheResourceType) {
    WCRCacheResourceTypeCocos = 0,  //cocos引擎
    WCRCacheResourceTypeCourse,      //课件
    WCRCacheResourceTypeMedia         //mp4,mp3等音视频文件
};


@interface WCRDownloadResourceModel : NSObject
@property (nonatomic, copy) NSString *downloadUrl;
@property (nonatomic, copy) NSString *remoteUrl;
@property (nonatomic, assign) WCRCacheResourceType fileType;

- (instancetype)initWithDownloadUrl:(NSString *)downloadUrl remoteUrl:(NSString *)remoteUrl fileType:(WCRCacheResourceType)fileType;
@end

@interface WCRDownloadConfigModel : NSObject
@property (nonatomic, copy) NSString *classId;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *institutionId;
@property (nonatomic, strong) WCRDownloadResourceModel *courseModel;
@property (nonatomic, strong) WCRDownloadResourceModel *cocosModel;
@property (nonatomic, copy) NSArray<WCRDownloadResourceModel *> *mediaResourceModels;
@property (nonatomic, assign) NSUInteger maxResourceSpace;
@property (nonatomic, assign) WCREnvironmentType env;

- (instancetype)initWithClassId:(NSString *)classId userId:(NSString *)userId userName:(NSString *)userName institutionId:(NSString *)institutionId courseModel:(WCRDownloadResourceModel *)courseModel cocosModel:(WCRDownloadResourceModel *)cocosModel mediaResourceModels:(NSArray<WCRDownloadResourceModel *>*)mediaResourceModels maxResourceSpace:(NSUInteger)maxResourceSpace env:(WCREnvironmentType)env;
@end

@protocol WCRResourceManagerDelegate <NSObject>
@optional

/**
 开始下载

 @param totalCount 总文件个数
 @param currentIndex 当前下载第几个
 @param model 当前下载资源的信息
 */
- (void)downloadStartWithTotalResourceCount:(NSInteger)totalCount currentResourceIndex:(NSInteger)currentIndex resource:(WCRDownloadResourceModel *)model;

/**
 下载失败

 @param error 失败原因
 @param model 当前下载资源的信息
 */
- (void)downloadFailedWithError:(WCRResourceDownloadStatus)error resource:(WCRDownloadResourceModel *)model;

/**
 下载进度

 @param progress 进度
 @param model 当前下载资源的信息
 */
- (void)downloadWithProgress:(float)progress resource:(WCRDownloadResourceModel *)model;

/**
 下载完成
 */
- (void)downloadFinished;
@end


@interface WCRResourceManager : NSObject
@property (nonatomic, weak) id<WCRResourceManagerDelegate> delegate;

/**
 下载课件资源

 @param configModel 资源配置信息
 */
- (void)downloadWithConfigModel:(WCRDownloadConfigModel *)configModel;

/**
 停止下载
 */
- (void)stopDownload;

/**
 清除所有缓存数据
 */
- (void)clearAllCache;

/**
 所有缓存文件大小，单位kb
 */
- (NSInteger)allCacheFileSize;
@end

