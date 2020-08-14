//
//  BoxContentSDK.h
//  BoxContentSDK
//
//  Created on 2/19/13.
//  Copyright (c) 2013 Box. All rights reserved.
//

#import <Foundation/Foundation.h>

// constants and logging
#import <BoxContentSDK/BOXContentSDKConstants.h>
#import <BoxContentSDK/BOXLog.h>
#import <BoxContentSDK/BOXContentSDKErrors.h>

// Client
#import <BoxContentSDK/BOXContentClient.h>
#import <BoxContentSDK/BOXContentClient+Authentication.h>
#import <BoxContentSDK/BOXContentClient+Search.h>
#import <BoxContentSDK/BOXContentClient+User.h>
#import <BoxContentSDK/BOXContentClient+Comment.h>
#import <BoxContentSDK/BOXContentClient+Collection.h>
#import <BoxContentSDK/BOXContentClient+Event.h>
#import <BoxContentSDK/BOXContentClient+Collaboration.h>
#import <BoxContentSDK/BOXContentClient+FileVersion.h>
#import <BoxContentSDK/BOXContentClient+SharedLink.h>
#import <BoxContentSDK/BOXContentClient+File.h>
#import <BoxContentSDK/BOXContentClient+Folder.h>
#import <BoxContentSDK/BOXContentClient+Bookmark.h>
#import <BoxContentSDK/BOXContentClient+Metadata.h>
#import <BoxContentSDK/BOXContentClient+RecentItems.h>

// Session
#import <BoxContentSDK/BOXAuthorizationViewController.h>
#import <BoxContentSDK/BOXAbstractSession.h>
#import <BoxContentSDK/BOXAbstractSession_Private.h>
#import <BoxContentSDK/BOXOAuth2Session.h>
#import <BoxContentSDK/BOXParallelOAuth2Session.h>
#import <BoxContentSDK/BOXAppUserSession.h>
#import <BoxContentSDK/BOXURLSessionManager.h>

// Protocols
#import <BoxContentSDK/BOXSharedLinkStorageProtocol.h>
#import <BoxContentSDK/BOXSharedLinkItemSource.h>

// AppToApp
#import <BoxContentSDK/BOXAppToAppAnnotationBuilder.h>
#import <BoxContentSDK/BOXAppToAppAnnotationKeys.h>
#import <BoxContentSDK/BOXAppToAppApplication.h>
#import <BoxContentSDK/BOXAppToAppFileMetadata.h>
#import <BoxContentSDK/BOXAppToAppMessage.h>

// Requests
#import <BoxContentSDK/BOXRequest.h>
#import <BoxContentSDK/BOXRequest+Metadata.h>
#import <BoxContentSDK/BOXUserRequest.h>
#import <BoxContentSDK/BOXUserAvatarRequest.h>
#import <BoxContentSDK/BOXSharedItemRequest.h>
#import <BoxContentSDK/BOXFileRequest.h>
#import <BoxContentSDK/BOXBookmarkRequest.h>
#import <BoxContentSDK/BOXBookmarkCreateRequest.h>
#import <BoxContentSDK/BOXBookmarkDeleteRequest.h>
#import <BoxContentSDK/BOXBookmarkCopyRequest.h>
#import <BoxContentSDK/BOXBookmarkShareRequest.h>
#import <BoxContentSDK/BOXBookmarkUnshareRequest.h>
#import <BoxContentSDK/BOXBookmarkUpdateRequest.h>
#import <BoxContentSDK/BOXBookmarkCommentsRequest.h>
#import <BoxContentSDK/BOXFolderRequest.h>
#import <BoxContentSDK/BOXFileCommentsRequest.h>
#import <BoxContentSDK/BOXFileCollaborationsRequest.h>
#import <BoxContentSDK/BOXFileCopyRequest.h>
#import <BoxContentSDK/BOXFileDeleteRequest.h>
#import <BoxContentSDK/BOXFileDownloadRequest.h>
#import <BoxContentSDK/BOXFileThumbnailRequest.h>
#import <BoxContentSDK/BOXFileUpdateRequest.h>
#import <BoxContentSDK/BOXFileShareRequest.h>
#import <BoxContentSDK/BOXFileUnshareRequest.h>
#import <BoxContentSDK/BOXFileVersionsRequest.h>
#import <BoxContentSDK/BOXFileVersionRequest.h>
#import <BoxContentSDK/BOXFileVersionPromoteRequest.h>
#import <BoxContentSDK/BOXFolderCreateRequest.h>
#import <BoxContentSDK/BOXFolderCopyRequest.h>
#import <BoxContentSDK/BOXFolderDeleteRequest.h>
#import <BoxContentSDK/BOXFolderUpdateRequest.h>
#import <BoxContentSDK/BOXFolderUnshareRequest.h>
#import <BoxContentSDK/BOXFolderShareRequest.h>
#import <BoxContentSDK/BOXFolderCollaborationsRequest.h>
#import <BoxContentSDK/BOXFileUploadRequest.h>
#import <BoxContentSDK/BOXFileUploadNewVersionRequest.h>
#import <BoxContentSDK/BOXPreflightCheckRequest.h>
#import <BoxContentSDK/BOXFolderItemsRequest.h>
#import <BoxContentSDK/BOXFolderPaginatedItemsRequest.h>
#import <BoxContentSDK/BOXFolderPaginatedItemsRequest_Private.h>
#import <BoxContentSDK/BOXCommentRequest.h>
#import <BoxContentSDK/BOXCommentAddRequest.h>
#import <BoxContentSDK/BOXCommentDeleteRequest.h>
#import <BoxContentSDK/BOXCommentUpdateRequest.h>
#import <BoxContentSDK/BOXCollectionItemsRequest.h>
#import <BoxContentSDK/BOXCollectionListRequest.h>
#import <BoxContentSDK/BOXCollectionFavoritesRequest.h>
#import <BoxContentSDK/BOXItemSetCollectionsRequest.h>
#import <BoxContentSDK/BOXEventsRequest.h>
#import <BoxContentSDK/BOXEventsAdminLogsRequest.h>
#import <BoxContentSDK/BOXCollaborationRequest.h>
#import <BoxContentSDK/BOXCollaborationCreateRequest.h>
#import <BoxContentSDK/BOXCollaborationRemoveRequest.h>
#import <BoxContentSDK/BOXCollaborationUpdateRequest.h>
#import <BoxContentSDK/BOXCollaborationPendingRequest.h>
#import <BoxContentSDK/BOXSearchRequest.h>
#import <BoxContentSDK/BOXTrashedItemArrayRequest.h>
#import <BoxContentSDK/BOXTrashedFolderRestoreRequest.h>
#import <BoxContentSDK/BOXTrashedFileRestoreRequest.h>
#import <BoxContentSDK/BOXItemShareRequest.h>
#import <BoxContentSDK/BOXMetadataRequest.h>
#import <BoxContentSDK/BOXMetadataDeleteRequest.h>
#import <BoxContentSDK/BOXMetadataCreateRequest.h>
#import <BoxContentSDK/BOXMetadataUpdateRequest.h>
#import <BoxContentSDK/BOXMetadataTemplateRequest.h>
#import <BoxContentSDK/BOXStreamOperation.h>
#import <BoxContentSDK/BOXRecentItemsRequest.h>
#import <BoxContentSDK/BOXRecentItemsRequest.h>
#import <BoxContentSDK/BOXFileRepresentationDownloadRequest.h>
#import <BoxContentSDK/BOXRepresentationInfoRequest.h>

// API Operation queues
#import <BoxContentSDK/BOXAPIQueueManager.h>
#import <BoxContentSDK/BOXSerialAPIQueueManager.h>
#import <BoxContentSDK/BOXParallelAPIQueueManager.h>
#import <BoxContentSDK/BOXAPIAccessTokenDelegate.h>

// API Operations
#import <BoxContentSDK/BOXAPIOperation.h>
#import <BoxContentSDK/BOXAPIOperation_Private.h>
#import <BoxContentSDK/BOXAPIOAuth2ToJSONOperation.h>
#import <BoxContentSDK/BOXAPIAuthenticatedOperation.h>
#import <BoxContentSDK/BOXAPIJSONOperation.h>
#import <BoxContentSDK/BOXAPIMultipartToJSONOperation.h>
#import <BoxContentSDK/BOXAPIDataOperation.h>
#import <BoxContentSDK/BOXAPIJSONPatchOperation.h>
#import <BoxContentSDK/BOXAPIAppUsersAuthOperation.h>

// API models
#import <BoxContentSDK/BOXItem.h>
#import <BoxContentSDK/BOXFile.h>
#import <BoxContentSDK/BOXFolder.h>
#import <BoxContentSDK/BOXFileLock.h>
#import <BoxContentSDK/BOXSharedLink.h>
#import <BoxContentSDK/BOXUser.h>
#import <BoxContentSDK/BOXUser_Private.h>
#import <BoxContentSDK/BOXBookmark.h>
#import <BoxContentSDK/BOXComment.h>
#import <BoxContentSDK/BOXRecentItem.h>

#import <BoxContentSDK/BOXCollection.h>
#import <BoxContentSDK/BOXEvent.h>
#import <BoxContentSDK/BOXCollaboration.h>
#import <BoxContentSDK/BOXGroup.h>
#import <BoxContentSDK/BOXFileVersion.h>
#import <BoxContentSDK/BOXMetadata.h>
#import <BoxContentSDK/BOXMetadataKeyValue.h>
#import <BoxContentSDK/BOXMetadataUpdateTask.h>
#import <BoxContentSDK/BOXMetadataTemplate.h>
#import <BoxContentSDK/BOXMetadataTemplateField.h>
#import <BoxContentSDK/BOXRepresentation.h>

// Catagories
#import <BoxContentSDK/NSString+BOXContentSDKAdditions.h>
#import <BoxContentSDK/NSError+BOXContentSDKAdditions.h>
#import <BoxContentSDK/UIApplication+ExtensionSafeAdditions.h>
#import <BoxContentSDK/UIDevice+BOXContentSDKAdditions.h>
#import <BoxContentSDK/NSString+BOXContentSDKAdditions.h>
#import <BoxContentSDK/NSURL+BOXURLHelper.h>
#import <BoxContentSDK/NSJSONSerialization+BOXContentSDKAdditions.h>
#import <BoxContentSDK/NSDate+BOXContentSDKAdditions.h>

// External
#import <BoxContentSDK/BOXHashHelper.h>
#import <BoxContentSDK/BOXKeychainItemWrapper.h>
#import <BoxContentSDK/BOXISO8601DateFormatter.h>

// Others
#import <BoxContentSDK/BOXSharedLinkHeadersDefaultManager.h>
#import <BoxContentSDK/BOXDispatchHelper.h>
#import <BoxContentSDK/BOXUserAvatarImageView.h>
