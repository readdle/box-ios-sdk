//
//  BOXFolderCreateRequest.h
//  BoxContentSDK
//

#import "BOXRequestWithSharedLinkHeader.h"

@interface BOXFolderCreateRequest : BOXRequestWithSharedLinkHeader

@property (nonatomic, readwrite, strong) NSString * _Null_unspecified folderName;
@property (nonatomic, readwrite, strong) NSString *_Null_unspecified parentFolderID;
@property (nonatomic, readwrite, assign) BOOL requestAllFolderFields;

/**
 Caller provided directory path for the result payload of the background operation to be written to.
 */
@property (nonatomic, readwrite, copy) NSString *_Null_unspecified requestDirectoryPath;

- (instancetype _Nonnull )initWithFolderName:(NSString *_Null_unspecified)folderName
                    parentFolderID:(NSString *_Null_unspecified)parentFolderID;

- (instancetype _Nonnull )initWithFolderName:(NSString *_Null_unspecified)folderName
                    parentFolderID:(NSString *_Null_unspecified)parentFolderID
                       associateId:(nullable NSString *)associateId;

- (void)performRequestWithCompletion:(BOXFolderBlock _Null_unspecified )completionBlock;

@end
