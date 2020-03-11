//
//  WCRDocumentModel.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/10/22.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WCRTypedef.h"
#import "WCRDocumentView.h"
NS_ASSUME_NONNULL_BEGIN

@interface WCRDocumentModel : NSObject

/**
 课件名称
 */
@property (nonatomic, copy, readonly)   NSString *documentName;

/**
课件id
*/
@property (nonatomic, copy, readonly)   NSString *documentId;

/**
课件页码
*/
@property (nonatomic, assign, readonly) NSInteger pageIndex;

/**
ppt课件，当前步骤
*/
@property (nonatomic, assign, readonly) NSInteger stepIndex;

/**
课件滚动偏移
*/
@property (nonatomic, assign, readonly) CGPoint offset;

/**
课件内容高度
*/
@property (nonatomic, assign, readonly) CGFloat documentHeight;

/**
课件类型
*/
@property (nonatomic, assign, readonly) WCRDocumentType documentType;

/**
课件内容与涂鸦view
*/
@property (nonatomic, strong, readonly) WCRDocumentView *documentModelView;
@end
NS_ASSUME_NONNULL_END
