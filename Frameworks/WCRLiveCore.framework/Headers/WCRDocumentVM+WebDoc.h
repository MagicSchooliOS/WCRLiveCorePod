//
//  WCRDocument+WebDoc.h
//  WCRLiveCore
//
//  Created by 欧阳铨 on 2018/10/19.
//  Copyright © 2018 com.100tal. All rights reserved.
//

#import <WCRLiveCore/WCRDocumentVM.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WCRDocumentVMWebDocDelegate <NSObject>
@optional
/**
 课件被滚动
 
 @param documentModel 课件model
 @param offsetPoint 课件滚动偏移
 */
- (void)document:(WCRDocumentModel *)documentModel didScroll:(CGPoint)offsetPoint;

/**
 课件高度变化，一般是因为课件内容加载引起的高度改变
 回调的是课件内容的高度
 
 @param documentModel 课件model
 @param height 课件高度
 */
- (void)document:(WCRDocumentModel *)documentModel heightChange:(CGFloat)height;

/**
 课件大小变化，一般是容器大小改变引起的大小改变
 回调的是课件容器(webView)的大小
 
 @param documentModel 课件model
 @param size 课件size
 */
- (void)document:(WCRDocumentModel *)documentModel sizeChange:(CGSize)size;

/**
 课件被翻页回调
 
 @param documentModel 课件model
 @param pageIndex 页码
 @param stepIndex 步骤
 */
- (void)document:(WCRDocumentModel *)documentModel didChangePage:(NSInteger)pageIndex step:(NSInteger)stepIndex;

/**
 网页课件消息回调

 @param documentModel 课件model
 @param messageName 消息名称
 @param messageBody 消息体
 @warning 只会回调添加了监听的消息 @see -registerMessageToDocument:withMessageName:;
 */
- (void)document:(WCRDocumentModel *)documentModel receiveMessage:(NSString *)messageName withBody:(NSDictionary *)messageBody;

/**
 是否授权课件翻页
 @param documentModel 课件model
 @param changePageModel 授权信息model
 */
- (void)document:(WCRDocumentModel *)documentModel changePageAuthorizeModel:(WCRAuthorizeChangePageModel *)changePageModel;
@end

@interface WCRDocumentVM()
@property (nonatomic, weak) id<WCRDocumentVMWebDocDelegate>webDocDelegate;

/**
 使用允许用户操作课件
 
 @param documentId 课件id
 @param userEnable 是否可以操作课件。内部实现：设置documentView.userInteractionEnabled。也可以直接设置
 @return 返回是否出现错误
 */
- (WCRError * _Nullable)setUserEnableWithDocumentId:(NSString *)documentId userEnable:(BOOL)userEnable;

/**
 使用允许用户主动滚动，默认为可以滚动
 
 @param documentId 课件id
 @param userScrollEnable 是否可以滚动。内部实现：设置 webView.scrollView.scrollEnabled
 @return 返回是否出现错误
 */
- (WCRError * _Nullable)setUserScrollEnableWithDocumentId:(NSString *)documentId userScrollEnable:(BOOL)userScrollEnable;

/**
 设置课件是否透明，默认为不透明
 
 @param documentId 课件id
 @param documentOpaque 课件是否透明。
 @return 返回是否出现错误
 @warning 只有在-documentWillLoad:代理回调内设置有效
 */
- (WCRError * _Nullable)setDocumentOpaqueWithDocumentId:(NSString *)documentId documentOpaque:(BOOL)documentOpaque;

/**
 学生操作课件翻页，并同步页码到老师端
 
 @param documentId 课件id
 @param pageNum 返回是否出现错误
 @return 课件model
 */
- (WCRError *)setDocumentPageWithDocumentId:(NSString *)documentId  pageNumber:(NSUInteger)pageNum;

/**
 给网页课件发送一个js指令

 @param documentId 课件id
 @param messageName 指令名字
 @param messageBody 消息体
 @param completionHandler 执行完成后回调的block
 @return 返回是否出现错误
 
 消息封装格式
 
 NSString* content = [NSString stringWithFormat:@"{\"msg\":\"%@\", \"body\":%@}", messageName, [WCRUtils jsonWithData:messageBody]];
 NSString* js = [NSString stringWithFormat:@"try{%@(%@);}catch(e){window.WCRDocSDK.log(e);}", callBackJsString, content];
 [webView evaluateJavaScript:js completionHandler:completionHandler];
 
 */
- (WCRError * _Nullable)sendMessageToDocument:(NSString *)documentId withMessageName:(NSString *)messageName body:(NSDictionary *)messageBody completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

/**
 添加消息监听

 @param documentId 课件id
 @param messageName 消息名称
 @return 为nil时添加成功
 */
- (WCRError * _Nullable)registerMessageToDocument:(NSString *)documentId withMessageName:(NSString *)messageName;

/**
 移除消息监听
 
 @param documentId 课件id
 @param messageName 消息名称
 @return 为nil时移除成功
 */
- (WCRError * _Nullable)unregisterMessageToDocument:(NSString *)documentId withMessageName:(NSString *)messageName;

/**
 移除所有消息监听
 
 @param documentId 课件id
 @return 为nil时移除成功
 */
- (WCRError * _Nullable)unregisterAllMessagesWithDocumentId:(NSString *)documentId;

/**
 获取所有监听的消息名称

 @param documentId 课件id
 @return 消息名称数组
 */
- (NSArray * _Nullable)allRegisterMessagesWithDocumentId:(NSString *)documentId;

/**
 开启课件涂鸦区 （只针对网页课件）
 课件涂鸦区的view为当前课件的WCRDocumentModel的documentModelView.doodleView
 涂鸦区的页码，滚动，同步当前课件的页码，滚动
 操作涂鸦区域权限等 参考 @see WCRDoodleVM
 涂鸦区域的doodleAreaId为当前课件的documentId
 
 @param documentId 课件id
 @return 返回是否出现错误
 */
- (WCRError * _Nullable)openWebDocumentDoodleWithDocumentId:(NSString *)documentId;

/**
 关闭某课件区涂鸦
 @param documentId 课件id
 */
- (void)removeWebDocumentDoodleWithDocumentId:(NSString *)documentId;

@end

NS_ASSUME_NONNULL_END
