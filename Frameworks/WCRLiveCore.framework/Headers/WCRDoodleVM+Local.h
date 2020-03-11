//
//  WCRDoodleVM+Local.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2019/7/25.
//  Copyright © 2019 com.100tal. All rights reserved.
//

@interface WCRDoodleVM ()
/**
 传入涂鸦数据，绘制涂鸦
 
 @param data 涂鸦数据
 @param doodleAreaId 涂鸦区域Id
 @return 返回nil表示设置成功，非nil表示失败
 @warning 涂鸦数据来源于回调-doodleViewController:updataDoodleData:withOption:;
 */
- (WCRError *)showDoodle:(NSData *)data inDoodleArea:(NSString *)doodleAreaId;
@end
