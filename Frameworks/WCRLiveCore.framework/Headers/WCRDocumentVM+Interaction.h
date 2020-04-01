//
//  WCRDocumentVM+Interaction.h
//  WCRLiveCore
//
//  Created by Bill Hu on 2020/3/12.
//  Copyright © 2020 com.100tal. All rights reserved.
//

#import <WCRLiveCore/WCRLiveCore.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WCRDocumentVMInteractionDelegate <NSObject>

- (void)interactionDidLoad;

- (void)interactionWillRemove;

@end

@interface WCRDocumentVM()
@property (nonatomic, weak) id<WCRDocumentVMInteractionDelegate> InteractionDelegate;

@property (nonatomic, strong) UIView *interactionView;

@end

NS_ASSUME_NONNULL_END
