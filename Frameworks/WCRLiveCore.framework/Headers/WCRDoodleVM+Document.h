//
//  WCRDoodleVM+Document.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2019/6/21.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <WCRLiveCore/WCRDoodleVM.h>
NS_ASSUME_NONNULL_BEGIN

extern NSString * const kDefaultDocumentDoodleAreaId;
extern NSUInteger const kDefaultDocumentDoodlePageId;

@protocol WCRDoodleVMDocumentDelegate <NSObject>

/**
 更新课件区涂鸦AreaId

 @param doodleAreaId 课件区涂鸦AreaId
 */
- (void)documentDoodleAreaUpdateDoodleAreaId:(NSString *)doodleAreaId;

/**
 更新课件区涂鸦pageId
 
 @param pageId 课件区涂鸦pageId
 */
- (void)documentDoodleAreaUpdateDoodlePageId:(NSUInteger)pageId;

@end

@interface WCRDoodleVM ()

/**
 课件区涂鸦的AreaId，默认为 (@"%@_%@_%@",kDefaultDocumentDoodleAreaId,userId,[NSString stringWithFormat:@"%u",arc4random()])
 */
@property(nonatomic, copy, readonly) NSString *documentDoodleAreaId;

/**
 课件区涂鸦的PageId，默认为kDefaultDocumentDoodlePageId
 */
@property(nonatomic, assign, readonly) NSUInteger documentDoodleAreaPageId;

/**
 设置课件专属涂鸦区域，此涂鸦区域的滚动，翻页等逻辑由内部管理
 默认doodleAreaId和页码 @see documentDoodleAreaId  @see documentDoodleAreaPageId
 
 @param view 涂鸦区域
 */
- (WCRError *)setDocumentDoodleAreaInView:(UIView *)view;

@property (nonatomic, weak) id<WCRDoodleVMDocumentDelegate> doodleVMDocumentDelegate;
@end

NS_ASSUME_NONNULL_END
