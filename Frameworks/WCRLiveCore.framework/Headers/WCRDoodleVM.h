//
//  WCRDoodleVM.h
//  WCRDoodleAPP
//
//  Created by zhangshuai on 2018/11/8.
//  Copyright © 2018 zhangshuai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WCRLiveCore/WCRTypedef.h>
#import <WCRLiveCore/WCRError.h>
#import <WCRLiveCore/WCRDoodlePointObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, WCRDoodleVMDoodleOption) {
    WCRDoodleVMDoodleOptionNone = 0,
    WCRDoodleVMDoodleOptionNetWork = 1 << 0,
    WCRDoodleVMDoodleOptionUserInteraction = 1 << 1,
    WCRDoodleVMDoodleOptionLocalData = 1 << 2,
    WCRDoodleVMDoodleOptionThirdPart = 1 << 3,
    WCRDoodleVMDoodleOptionAll = WCRDoodleVMDoodleOptionNetWork|WCRDoodleVMDoodleOptionUserInteraction|WCRDoodleVMDoodleOptionLocalData|WCRDoodleVMDoodleOptionThirdPart
};

@protocol WCRDoodleVMDelegate <NSObject>
@optional

/**
 涂鸦区域可撤销涂鸦数量

 @param doodleAreaId 涂鸦区域Id
 @param revocableCount 可撤销涂鸦数量
 */
- (void)doodleArea:(NSString *)doodleAreaId revocableCountChange:(NSUInteger)revocableCount;

/**
 涂鸦区域可反撤销涂鸦数量
 
 @param doodleAreaId 涂鸦区域Id
 @param unRevocableCount 可反撤销涂鸦数量
 */
- (void)doodleArea:(NSString *)doodleAreaId unRevocableCountChange:(NSUInteger)unRevocableCount;

/**
 回调当前涂鸦数据

 @param doodleAreaId 涂鸦区域Id
 @param data 涂鸦数据
 @param option 涂鸦来源
 @warning 之后回调涂鸦区域当前页面的数据
 */
- (void)doodleArea:(NSString *)doodleAreaId updataData:(NSData *)data option:(WCRDoodleVMDoodleOption)option;

/**
 回调当前涂鸦位置

 @param doodleAreaId 涂鸦区域Id
 @param pointObject 涂鸦位置
 @param option 涂鸦来源
 @warning 之后回调涂鸦区域当前页面的数据
 */
- (void)doodleArea:(NSString *)doodleAreaId updataPointObject:(WCRDoodlePointObject *)pointObject option:(WCRDoodleVMDoodleOption)option;

/**
 同步当前页涂鸦数据完成
 
 @param doodleAreaId 涂鸦区域Id
 */
- (void)doodleAreaDidSync:(NSString *)doodleAreaId;

/**
 涂鸦区域涂鸦总数量

 @param doodleAreaId 涂鸦区域Id
 @param allLineCount 涂鸦总数量
 */

- (void)doodleArea:(NSString *)doodleAreaId allLineCountChange:(NSUInteger)allLineCount;

/**
 涂鸦区域当前页面显示涂鸦数量
 
 @param doodleAreaId 涂鸦区域Id
 @param currentPageLineCount 当前页面显示涂鸦数量
 */
- (void)doodleArea:(NSString *)doodleAreaId currentPageLineCountChange:(NSUInteger)currentPageLineCount;

/**
涂鸦区域当前页面绘制区域大小
 调用方法
- (WCRError *)setDoodleArea:(NSString *)doodleAreaId contentSize:(CGSize)contentSize;
 如果new contentSize 和 old contentSize 不一致则走此回调
 
@param doodleAreaId 涂鸦区域Id
@param contentSize 当前页面绘制区域大小
*/
- (void)doodleArea:(NSString *)doodleAreaId contentSizeChange:(CGSize)contentSize;

/**
涂鸦区域当前页面绘制区域滚动偏移
  调用方法
 - (WCRError *)scrollDoodleArea:(NSString *)doodleAreaId offset:(CGPoint)offset;
  如果new offset 和 old offset 不一致则走此回调
 
@param doodleAreaId 涂鸦区域Id
@param contentOffset 当前页面绘制滚动偏移
*/
- (void)doodleArea:(NSString *)doodleAreaId contentOffsetChange:(CGPoint)contentOffset;

@end

/**
 自定义涂鸦区域的三大要素
 1.doodleAreaId：涂鸦区域Id，用于区分每个涂鸦区域。
 2.pageId：当前页码，用于区分每个涂鸦区域的当前页码。
 3.contentSize：涂鸦区域大小，用于设置当前可显示涂鸦的区域大小。默认值为-createDocumentDoodleArea:inView:;的view参数的bounds.size;
 
 老师与学生在同一区域Id，同一页码下的涂鸦，能相互实时显示。
 */
@interface WCRDoodleVM : NSObject

/**
 涂鸦信道连接状态
 */
@property(nonatomic, assign) WCRDoodleConnectStatus doodleStatus;

/**
 涂鸦VM代理
 */
@property(nonatomic, weak) id<WCRDoodleVMDelegate> delegate;

/**
 默认涂鸦线宽
 */
@property(nonatomic, assign) NSUInteger defaultPenWidth;

/**
 默认涂鸦颜色
 */
@property(nonatomic, assign) NSInteger defaultPenColor;

/**
 创建自定义涂鸦区域

 @param doodleAreaId 涂鸦区域Id
 @param pageId 涂鸦区域页码
 @param view 涂鸦区域
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)createDoodleArea:(NSString *)doodleAreaId pageId:(NSUInteger)pageId inView:(UIView *)view option:(WCRDoodleVMDoodleOption)option;

/**
 更换涂鸦区域Id

 @param doodleAreaId 旧涂鸦区域Id
 @param newDoodleAreaId 新涂鸦区域Id
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)changeDoodleArea:(NSString *)doodleAreaId withDoodleAreaId:(NSString *)newDoodleAreaId;

/**
 销毁自定义涂鸦区域
 
 @param doodleAreaId 涂鸦区域Id
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)destoryDoodleArea:(NSString *)doodleAreaId;

/**
 刷新涂鸦区域当前页

 @param doodleAreaId 涂鸦区域Id
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)refreshDoodleArea:(NSString *)doodleAreaId;

/**
 设置涂鸦区域页码
 
 @param doodleAreaId 涂鸦区域Id
 @param pageId 涂鸦区域页码
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)setDoodleArea:(NSString *)doodleAreaId pageId:(NSUInteger)pageId;

/**
 设置涂鸦区域大小

 @param doodleAreaId 涂鸦区域Id
 @param contentSize 区域大小，当设置的区域大小>涂鸦区域的view的bounds.size，涂鸦区域可上下滚动
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)setDoodleArea:(NSString *)doodleAreaId contentSize:(CGSize)contentSize;

/**
 设置涂鸦区域画笔宽度

 @param doodleAreaId 涂鸦区域Id
 @param penWidth 画笔宽度
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)setDoodleArea:(NSString *)doodleAreaId penWidth:(NSUInteger)penWidth;

/**
 设置涂鸦区域画笔颜色
 
 @param doodleAreaId 涂鸦区域Id
 @param penColor 画笔颜色
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)setDoodleArea:(NSString *)doodleAreaId penColor:(NSInteger)penColor;

/**
 设置涂鸦区域用户涂鸦权限
 内部实现：
  1.设置涂鸦view的userInteractionEnabled = NO
2.抛弃WCRDoodleVM+ThirdPart中传入的数据
 
 @param doodleAreaId 涂鸦区域Id
 @param enable 用户是否能进行涂鸦
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)setDoodleArea:(NSString *)doodleAreaId userEnable:(BOOL)enable;

/**
 设置涂鸦区域线宽计算规则
 
 @param doodleAreaId 涂鸦区域Id
 @param absoluteLineWidth 绝对线宽
 
 相对线宽：线宽不固定，会根据绘制区域大小(contentSize)计算出实际绘制的线宽。绘制线宽 = penWidth * (contentSize.width / 涂鸦时contentSize.width)。当contentSize变化时，所有涂鸦的线宽会发生变化，即绘制线宽 = penWidth * (变化后contentSize.width / 涂鸦时contentSize.width)
 绝对线宽：线宽固定，不会根据绘制区域大小变化 绘制线宽 = penWidth
 
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)setDoodleArea:(NSString *)doodleAreaId absoluteLineWidth:(BOOL)absoluteLineWidth;

/**
 获取涂鸦区域页码
 
 @param doodleAreaId 涂鸦区域Id
 @param error nil表示设置成功，非nil表示失败
 @return 页码
 */
- (NSUInteger)getDoodleAreaPageId:(NSString *)doodleAreaId error:(WCRError *_Nullable*_Nullable)error;

/**
 获取涂鸦区域画笔宽度

 @param doodleAreaId 涂鸦区域Id
 @param error nil表示设置成功，非nil表示失败
 @return 画笔宽度
 */
- (NSUInteger)getDoodleAreaPenWidth:(NSString *)doodleAreaId error:(WCRError *_Nullable*_Nullable)error;

/**
 获取涂鸦区域画笔颜色
 
 @param doodleAreaId 涂鸦区域Id
 @param error nil表示设置成功，非nil表示失败
 @return 画笔颜色
 */
- (NSUInteger)getDoodleAreaPenColor:(NSString *)doodleAreaId error:(WCRError *_Nullable*_Nullable)error;

/**
 获取涂鸦区域大小
 
 @param doodleAreaId 涂鸦区域Id
 @param error nil表示设置成功，非nil表示失败
 @return 区域大小
 */
- (CGSize)getDoodleAreaContentSize:(NSString *)doodleAreaId error:(WCRError *_Nullable*_Nullable)error;

/**
 获取涂鸦区域用户涂鸦权限
 
 @param doodleAreaId 涂鸦区域Id
 @param error nil表示设置成功，非nil表示失败
 @return 用户涂鸦权限
 */
- (BOOL)getDoodleAreaUserEnable:(NSString *)doodleAreaId error:(WCRError *_Nullable*_Nullable)error;

/**
获取涂鸦区域可撤销涂鸦数量
当出现错误时返回0
 
@param doodleAreaId 涂鸦区域Id
@param error nil表示设置成功，非nil表示失败
@return 撤销涂鸦数量
*/
- (NSUInteger)getDoodleAreaRevocableCount:(NSString *)doodleAreaId error:(WCRError *_Nullable*_Nullable)error;

/**
 获取涂鸦区域可反撤销涂鸦数量
 当出现错误时返回0
 
 @param doodleAreaId 涂鸦区域Id
 @param error nil表示设置成功，非nil表示失败
 @return 反撤销涂鸦数量
 */
- (NSUInteger)getDoodleAreaUnRevocableCount:(NSString *)doodleAreaId error:(WCRError *_Nullable*_Nullable)error;

/**
 设置涂鸦滚动，目前只支持上下滚动

 @param doodleAreaId 涂鸦区域Id
 @param offset 滚动offset
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)scrollDoodleArea:(NSString *)doodleAreaId offset:(CGPoint)offset;

/**
 撤销
 
 @param doodleAreaId 涂鸦区域Id
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)revokeInDoodleArea:(NSString *)doodleAreaId;

/**
 反撤销
 
 @param doodleAreaId 涂鸦区域Id
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)unrevokeInDoodleArea:(NSString *)doodleAreaId;

/**
 清除所有涂鸦
 
 @param doodleAreaId 涂鸦区域Id
 @return 返回nil表示设置成功，非nil表示失败
 */
- (WCRError *)clearAllLinesInDoodleArea:(NSString *)doodleAreaId;
@end

NS_ASSUME_NONNULL_END
