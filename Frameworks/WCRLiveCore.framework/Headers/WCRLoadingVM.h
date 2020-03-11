//
//  WCRLoadingVM.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCRLiveCore/WCRTypedef.h>

/**
 加载状态ViewModel回调
 */
@protocol WCRLoadingVMDelegate<NSObject>

/**
 加载状态发生变化

 @param currentStep 当前加载步骤，@see WCRRoomLoadingStep
 @param result 当前步骤对应的加载结果，@see WCRRoomLoadingStepResult
 */
- (void)onUpdateLoadingStep:(WCRRoomLoadingStep)currentStep loadingResult:(WCRRoomLoadingStepResult)result;
@end


/**
 加载状态ViewModel
 */
@interface WCRLoadingVM : NSObject
/**
 当前加载步骤
 */
@property(nonatomic, assign, readonly) WCRRoomLoadingStep currentStep;

/**
 当前步骤的结果
 */
@property(nonatomic, assign, readonly) WCRRoomLoadingStepResult currentStepResult;

/**
 代理
 */
@property(nonatomic, weak) id<WCRLoadingVMDelegate> delegate;
@end
