//
//  BOXFileShareRequest.h
//  BoxContentSDK
//

#import <BoxContentSDK/BOXItemShareRequest.h>

@interface BOXFileShareRequest : BOXItemShareRequest

@property (nonatomic, readonly, copy) NSString *fileID;

- (instancetype)initWithFileID:(NSString *)fileID;
- (void)performRequestWithCompletion:(BOXFileBlock)completionBlock;

@end
