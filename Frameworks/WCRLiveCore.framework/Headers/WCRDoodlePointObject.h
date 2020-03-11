//
//  WCRDoodlePointObject.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2019/6/24.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WCRLiveCore/WCRUser.h>
#import <WCRLiveCore/WCRTypedefs+Doodle.h>

NS_ASSUME_NONNULL_BEGIN

@interface WCRDoodlePointObject : NSObject
@property (nonatomic, strong) WCRUser *user;
@property (nonatomic, assign) CGPoint point;
@property (nonatomic, assign) WCRDoodleStatus status;
- (instancetype)initWithUser:(WCRUser *)user point:(CGPoint)point status:(WCRDoodleStatus)status;

@end

NS_ASSUME_NONNULL_END
