//
//  WCRLiveStreamNetworkInfo.h
//  WCRInteractiveLiveStream
//
//  Created by 欧阳铨 on 2018/8/16.
//  Copyright © 2018年 欧阳铨. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, WCRNetQuality) {
    WCRNetQualityUnknown = 0,
    WCRNetQualityExcellent = 1,
    WCRNetQualityGood = 2,
    WCRNetQualityPoor = 3,
    WCRNetQualityBad = 4,
    WCRNetQualityVBad = 5,
    WCRNetQualityDown = 6
};

@interface WCRLiveStreamNetworkInfo : NSObject <NSCopying>
/**
 推拉流速率,值为-1表示无法获取数据
 */
@property (nonatomic, assign) double bitrate;
/**
 丢包率，值为-1表示无法获取数据
 */
@property (nonatomic, assign) NSInteger lostRate;
/**
 延迟，值为-1表示无法获取数据
 */
@property (nonatomic, assign) NSInteger delay;
/**
 网络质量，值为WCRNetQualityUnknown表示无法获取数据
 */
@property (nonatomic, assign) WCRNetQuality netQuality;
/**
 推拉流fps，值为-1表示无法获取数据
 */
@property (nonatomic, assign) double fps;
@end
