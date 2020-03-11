//
//  WCRPlaybackKeyPointModel.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/11/26.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WCRPlaybackKeyPointModel : NSObject
/**
 打点数据在视频中的时间
 */
@property (nonatomic, assign) NSTimeInterval progressSecond;
/**
 打点数据title
 */
@property (nonatomic, copy) NSString* pointTitle;

@end
