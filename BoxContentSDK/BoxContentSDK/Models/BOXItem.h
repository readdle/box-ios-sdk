//
//  BOXItem.h
//  BoxContentSDK
//

#import "BOXModel.h"

@class BOXFolderMini;
@class BOXUserMini;
@class BOXSharedLink;
@class BOXCollection;

/**
 *  A compact representation of a Box Item with only a few properties.
 *  Some API requests will return these representations to reduce bandiwdth, especially when many
 *  instances are being returned.
 */
@interface BOXItemMini : BOXModel

/**
 *  A unique ID for use with Events.
 */
@property (nonatomic, readwrite, strong) NSString * _Null_unspecified sequenceID;

/**
 *  Name of the item.
 */
@property (nonatomic, readwrite, strong) NSString * _Null_unspecified name;

/**
 *  A unique string identifying the version of this item.
 */
@property (nonatomic, readwrite, strong) NSString * _Null_unspecified etag;

/**
 *  Convenience method to check if the item is a File.
 */
@property (nonatomic, readonly, assign) BOOL isFile;

/**
 *  Convenience method to check if the item is a Folder.
 */
@property (nonatomic, readonly, assign) BOOL isFolder;

/**
 *  Convenience method to check if the item is a Bookmark.
 */
@property (nonatomic, readonly, assign) BOOL isBookmark;

@end

@interface BOXItem : BOXModel

/**
 *  A unique ID for use with Events.
 */
@property (nonatomic, readwrite, strong) NSString * _Null_unspecified sequenceID;

/**
 *  Name of the item.
 */
@property (nonatomic, readwrite, strong) NSString * _Null_unspecified name;

/**
 *  A unique string identifying the version of this item.
 */
@property (nonatomic, readwrite, strong) NSString * _Null_unspecified etag;

/**
 *  Date the item was created.
 */
@property (nonatomic, readwrite, strong) NSDate * _Null_unspecified createdDate;

/**
 *  Date the item was last modified.
 */
@property (nonatomic, readwrite, strong) NSDate * _Null_unspecified modifiedDate;

/**
 *  Description of the item.
 */
@property (nonatomic, readwrite, strong) NSString * _Null_unspecified itemDescription;

/**
 *  Size of the item. For files, this is simply the file size. For folders, it is the combined size
 *  of all the contents in it.
 */
@property (nonatomic, readwrite, strong) NSNumber * _Null_unspecified size;

/**
 *   An ordered array representing the "path" of the item, starting with the root.
 */
@property (nonatomic, readwrite, strong) NSArray <BOXFolderMini *> * _Null_unspecified pathFolders;

/**
 *  If the item is in the trash, the date in which it was moved to the trash.
 */
@property (nonatomic, readwrite, strong) NSDate * _Null_unspecified trashedDate;

/**
 *  The time the item was purged from the trash.
 */
@property (nonatomic, readwrite, strong) NSDate * _Null_unspecified purgedDate;

/**
 *  The time the item was originally created (according to the uploader).
 */
@property (nonatomic, readwrite, strong) NSDate * _Null_unspecified contentCreatedDate;

/**
 *  The time the item was last modified (according to the uploader).
 */
@property (nonatomic, readwrite, strong) NSDate * _Null_unspecified contentModifiedDate;

/**
 *  The user that created the item.
 */
@property (nonatomic, readwrite, strong) BOXUserMini * _Null_unspecified creator;

/**
 *  The user that last modified the item.
 */
@property (nonatomic, readwrite, strong) BOXUserMini * _Null_unspecified lastModifier;

/**
 *  The user that owns the item.
 */
@property (nonatomic, readwrite, strong) BOXUserMini * _Null_unspecified owner;

/**
 *  The shared link for the item.
 */
@property (nonatomic, readwrite, strong) BOXSharedLink * _Null_unspecified sharedLink;

/**
 *  List of the possible shared link access levels that can be set for a shared link for this item.
 *  Warning: By default, the Box API does not return this value, and it will be nil.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, strong) NSArray <NSString *> * _Null_unspecified allowedSharedLinkAccessLevels;

/**
 *  The folder that contains this item.
 */
@property (nonatomic, readwrite, strong) BOXFolderMini * _Null_unspecified parentFolder;

/**
 *  Whether this item is deleted or not.
 *  Values include "active", "trashed" if the file has been moved to the trash, and "deleted" if the file has been permanently deleted
 */
@property (nonatomic, readwrite, copy, nullable) NSString *status;

/**
 *  The collections that this item belongs to. An array of BoxCollection objects.
 */
@property (nonatomic, readwrite, strong) NSArray <BOXCollection *> * _Null_unspecified collections;

/**
 *  Whether a shared link can be created for the item.
 *  Warning: By default, the Box API does not return this value, and it will be BOXAPIBooleanUnknown.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, assign) BOXAPIBoolean canShare;

/**
 *  Whether the shared link access level can be configured by this user.
 *  Warning: By default, the Box API does not return this value, and it will be BOXAPIBooleanUnknown.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, assign) BOXAPIBoolean canSetShareAccess;

/**
 *  Indicates permission for the current user to rename this folder.
 *  Warning: By default, the Box API does not return this value, and it will be nil.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, assign) BOXAPIBoolean canRename;

/**
 *  Indicates permission for the current user to delete this folder.
 *  Warning: By default, the Box API does not return this value, and it will be nil.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, assign) BOXAPIBoolean canDelete;

/**
 *  Indicates permission for the current user can invite users to the folder/file as collaborators.
 *  Warning: By default, the Box API does not return this value, and it will be nil.
 *  You must request it by setting the "fields" of the request.
 *  This property will always return NO for BOXBookmark because weblinks currently do not support collaborators.
 */
@property (nonatomic, readwrite, assign) BOXAPIBoolean canInviteCollaborator;

/**
 *  Whether this item has at least on collaboration.
 *  Can be synced, not_synced, or partially_synced.
 *  Warning: By default, the Box API does not return this value, and it will be nil.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, assign) BOXAPIBoolean hasCollaborations;

/**
 *  Whether this folder is owned by an external company.
 *  Can be synced, not_synced, or partially_synced.
 *  Warning: By default, the Box API does not return this value, and it will be nil.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, assign) BOXAPIBoolean isExternallyOwned;

/**
 *  The possible roles that can be given to collaborators who are added into this folder.
 *  Warning: By default, the Box API does not return this value, and it will be nil.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, strong) NSArray * _Null_unspecified allowedInviteeRoles;

/**
 *  Metadata values for an item
 *  Warning: By default, the Box API does not return this value, and it will be nil.
 *  You must request it by setting the "fields" of the request.
 */
@property (nonatomic, readwrite, strong) NSArray * _Null_unspecified metadata;

/**
 *  Convenience method to check if the item is a File.
 */
@property (nonatomic, readonly, assign) BOOL isFile;

/**
 *  Convenience method to check if the item is a Folder.
 */
@property (nonatomic, readonly, assign) BOOL isFolder;

/**
 *  Convenience method to check if the item is a Bookmark.
 */
@property (nonatomic, readonly, assign) BOOL isBookmark;

/**
 * Convenience method to retrieve the first available rank in collection
 */
@property (nullable, nonatomic, readonly, assign) NSNumber *availableCollectionRank;

@end
