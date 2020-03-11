//
//  WCRAuthorizeChangePageModel.h
//  WCRLiveCore
//
//  Created by juvham on 2019/7/23.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WCRAuthorizeChangePageModel : NSObject


/**
 最大页数
 */
@property (nonatomic, assign) NSInteger docMaxPage;
/**
 当前页数
 */
@property (nonatomic, assign) NSUInteger currentDocPage;
/**
 是否授权
 */
@property (nonatomic, assign, getter=isDocAuthorize) BOOL docAuthorize;

/**
 根据课件id获取课件model
 @param docMaxPage 最大页数
 @param status 授权状态
 @param currentDocPage 当前页数
 @return 当前对象
 */

-(instancetype) initWithStatus:(NSString *)status docMaxPage:(NSUInteger)docMaxPage currentDocPage:(NSUInteger)currentDocPage;


@end

NS_ASSUME_NONNULL_END
