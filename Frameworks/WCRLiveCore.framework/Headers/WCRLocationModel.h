//
//  WCRLocationModel.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/11/27.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIkit.h>

@interface WCRLocationModel : NSObject
/**
 用户视频rect
 */
@property (nonatomic, assign) CGRect frame;

/**
 老师端可移动区域
 */
@property (nonatomic, assign) CGSize size;

/**
 课件标题栏高度
 */
@property (nonatomic, assign) CGFloat titleHeight;

- (instancetype)initWithFrame:(CGRect)frame teacherMoveSize:(CGSize)moveSize;
@end
