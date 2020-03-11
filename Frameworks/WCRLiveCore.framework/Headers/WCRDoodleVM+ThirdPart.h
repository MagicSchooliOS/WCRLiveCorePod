//
//  WCRDoodleVM+ThirdPart.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2019/7/25.
//  Copyright © 2019 com.100tal. All rights reserved.
//

@interface WCRDoodleVM ()
/**
 设置point对应的区域大小
 
 @param doodleAreaId 涂鸦区域Id
 @param originSize 区域大小
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)setDoodleArea:(NSString *)doodleAreaId originSize:(CGSize)originSize;

/**
 自定义绘制涂鸦，传入数据点，绘制涂鸦
 
 @param doodleAreaId 涂鸦区域
 @param beganPoint 开始点
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)drawInDoodleArea:(NSString *)doodleAreaId withLineBegan:(CGPoint)beganPoint;

/**
 自定义绘制涂鸦，传入数据点，绘制涂鸦
 
 @param doodleAreaId 涂鸦区域
 @param movedPoint 过程点
 @return 返回nil表示设置成功，非nil表示失败
 @warning 在调用touchesMoved之前，需要保证touchesBegan先被调用
 */
- (WCRError *)drawInDoodleArea:(NSString *)doodleAreaId withLineMoved:(CGPoint)movedPoint;

/**
 自定义绘制涂鸦，传入数据点，绘制涂鸦
 
 @param doodleAreaId 涂鸦区域
 @param endedPoint 结束点
 @return 返回nil表示设置成功，非nil表示失败
 @warning 如果touchesMoved被调用，需要保证touchesEnded被调用
 */
- (WCRError *)drawInDoodleArea:(NSString *)doodleAreaId withLineEnded:(CGPoint)endedPoint;

/**
 自定义展示激光笔数据
 
 @param doodleAreaId 涂鸦区域
 @param point 数据点
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)showLaserInDoodleArea:(NSString *)doodleAreaId withPoint:(CGPoint)point;

/**
 自定义隐藏激光笔数据
 
 @param doodleAreaId 涂鸦区域
 @param point 数据点
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)hiddenLaserInDoodleArea:(NSString *)doodleAreaId withPoint:(CGPoint)point;
@end
