//
//  WCRDocumentView.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2019/9/9.
//  Copyright © 2019 com.100tal. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WCRDocumentView : UIView
/*
 课件内容view
 UIView的具体类型，根据documentType变化
 
WCRDocumentTypePPT,WKWebView
WCRDocumentTypePDF, WKWebView
WCRDocumentTypeImage, UIImageView
WCRDocumentTypeWhiteBoard, UIView
WCRDocumentTypeWebPPT, WKWebView
WCRDocumentTypeWebImage, WKWebView
WCRDocumentTypeVideo, UIView
WCRDocumentTypeAudio, nil
WCRDocumentTypeHtml   WKWebView
*/

/**
 课件内容view
 */
@property (nonatomic, strong, nullable, readonly) UIView *documentView;

/**
课件的涂鸦view
 默认此涂鸦view不能涂鸦，需要调用- openWebDocumentDoodleWithDocumentId:; 开启此涂鸦区域。
 */
@property (nonatomic, strong, readonly) UIView *doodleView;
@end

NS_ASSUME_NONNULL_END
