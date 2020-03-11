//
//  WCRDocument+Whiteboard.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/10/22.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <WCRLiveCore/WCRDocumentVM.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WCRDocumentVMWhiteboardDelegate <NSObject>
@optional
/**
 白板被滚动
 
 @param documentModel 课件model
 @param offsetPoint 课件滚动偏移
 */
- (void)document:(WCRDocumentModel *)documentModel whiteboardDidScroll:(CGPoint)offsetPoint;

@end

@interface WCRDocumentVM ()
@property (nonatomic, weak) id<WCRDocumentVMWhiteboardDelegate> whiteboardDelegate;

/**
 白板课件默认背景颜色
 */
@property (nonatomic, strong) UIColor *defaultColor;

/**
 设置白板课件背景颜色

 @param color 背景颜色
 @param documentId 课件id
 @return 为nil时设置成功
 */
- (WCRError * _Nullable)setColor:(UIColor *)color documentId:(NSString *)documentId;
@end

NS_ASSUME_NONNULL_END
