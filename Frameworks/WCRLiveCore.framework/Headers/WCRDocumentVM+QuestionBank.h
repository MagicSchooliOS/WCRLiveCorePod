//
//  WCRDocumentVM+QuestionBank.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2019/4/23.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <WCRLiveCore/WCRDocumentVM.h>

NS_ASSUME_NONNULL_BEGIN
@protocol WCRDocumentVMQuestionBankDelegate <NSObject>
@optional
/**
 答题器即将显示
 */
- (void)questionBankWillLoad;
/**
 答题器显示完成
 */
- (void)questionBankDidLoad:(WCRError *)error;
/**
 答题器即将关闭
 */
- (void)questionBankWillCloseReason:(WCRDocumentVMCloseReason)reason;
/**
 答题器关闭完成
 */
- (void)questionBankDidClose;
/**
 答题器被老师开始
 @warning 收到此回调之后，需要设置`questionBankView`的frame，答题器才会开始加载
 */
- (void)questionBankStart:(UIView *)questionBankView;
/**
 答题器被老师停止
 */
- (void)questionBankStop;
/**
 答题器显示答案
 */
- (void)questionBankRereport:(id)data;
/**
 答题器学生提交答案
 */
- (void)questionBankSubmitQuestion:(id)data;
/**
 答题器改变frame
 */
- (void)questionBankChangeFrame:(CGSize)size;


@end

@interface WCRDocumentVM ()

/**
 答题器代理
 */
@property (nonatomic, weak) id<WCRDocumentVMQuestionBankDelegate>questionBankDelegate;

/**
 答题器的view
 */
@property (nonatomic, weak) UIView *questionBankView;

/**
 加载答题器失败时调用此接口进行重新加载
 @see -questionBankDidLoad:
 */
- (void)reloadQuestionBank;
@end

NS_ASSUME_NONNULL_END
