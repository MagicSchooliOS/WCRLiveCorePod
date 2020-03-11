//
//  WCRError.h
//  WCRLiveCore
//
//  Created by wenssh on 2018/8/8.
//  Copyright © 2018年 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WCRError : NSError

- (instancetype)initWithDomain:(NSErrorDomain)domain code:(NSInteger)code userInfo:(nullable NSDictionary<NSErrorUserInfoKey,id> *)dict;

+ (instancetype)errorWithDomain:(NSErrorDomain)domain code:(NSInteger)code userInfo:(nullable NSDictionary<NSErrorUserInfoKey,id> *)dict;

@end
NS_ASSUME_NONNULL_END
