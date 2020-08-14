//
//  BOXBookmarkShareRequest.h
//  BoxContentSDK
//

#import <BoxContentSDK/BOXItemShareRequest.h>

@interface BOXBookmarkShareRequest : BOXItemShareRequest

@property (nonatomic, readonly, copy) NSString *bookmarkID;

- (instancetype)initWithBookmarkID:(NSString *)bookmarkID;
- (void)performRequestWithCompletion:(BOXBookmarkBlock)completionBlock;

@end
