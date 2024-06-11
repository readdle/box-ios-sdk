//
//  BOXClient.h
//  BoxContentSDK
//
//  Copyright (c) 2014 Box. All rights reserved.
//
#import "BOXAPIAccessTokenDelegate.h"

@class BOXAbstractSession;
@class BOXUser;
@class BOXUserMini;
@class ServerAuthUser;
@class BOXAPIQueueManager;
@class BOXRequest;
@class BOXSharedLinkHeadersHelper;
@protocol BOXAPIAccessTokenDelegate;
@protocol BOXSharedLinkStorageProtocol;
@protocol BOXContentCacheClientProtocol;
@protocol BOXURLSessionManagerDelegate;
@protocol UniqueSDKUser;

typedef void (^ServerAuthFetchTokenBlock)(NSString *_Null_unspecified, NSDictionary *_Null_unspecified, void (^_Null_unspecified)(NSString *_Null_unspecified, NSDate *_Null_unspecified, NSError *_Null_unspecified));

extern NSString * _Null_unspecified const BOXContentClientBackgroundTempFolder;

@interface BOXContentClient : NSObject <BOXAPIAccessTokenDelegate>

/**
 *  Allows the SDK to associate shared links with Box Items.
 */
@property (nonatomic, readonly, strong) BOXSharedLinkHeadersHelper * _Null_unspecified sharedLinksHeaderHelper;

/**
 *  By setting the cache client, the BOXContentClient will now support caching for BoxRequests.
 */
@property (nonatomic, readwrite, weak) id<BOXContentCacheClientProtocol> cacheClient;

/**
 * The SDK's session instance.
 */
@property (nonatomic, readonly, strong) BOXAbstractSession * _Null_unspecified session;

/**
 *  The custom prefix for the user agent. If set, the prefix will be appended with ; followed by the default Box SDK user agent string.
 */
@property (nonatomic, readwrite, strong) NSString * _Null_unspecified userAgentPrefix;

/**
 *  The client's queue manager. All API calls are scheduled by this queue manager.
 *  The queueManager is shared with the session (for making authorization and refresh
 *  calls) and the filesManager and foldersManager (for making API calls).
 */
@property (nonatomic, readwrite, strong) BOXAPIQueueManager * _Null_unspecified queueManager;

/**
 * This property reflects whether the client should attempt the authentication through the
 * Box app. It's default is NO and has to be set via the +setAppToAppBoxAuthenticationEnabled:
 * because of the associated configuration that has to be done.
 */
@property (nonatomic, readonly, assign) BOOL appToAppBoxAuthenticationEnabled;

/**
 * This property is used to temporarily hold the authentication completion block in the case of
 * App-to-App authentication through the Box app.
 */
@property (nonatomic, readwrite, copy) void (^ _Null_unspecified authenticationCompletionBlock)(BOXUser * _Null_unspecified user, NSError * _Null_unspecified error);

/**
 * The Box user associated with this SDK client. This will be nil if no user has been authenticated yet.
 */
@property (nonatomic, readonly, strong) id<UniqueSDKUser> _Null_unspecified user;

/**
 * The delegate for the BOXContentClient instance. Internally setting the BOXContentClient's delegate
 * will automatically set the BOXAPIQueueManager's delegate and getting the delegate will return the
 * BOXAPIQueueManager's delegate.
 *
 * Allows users to retrieve access tokens in a way that bypasses OAuth2 and uses App Users instead.
 */
@property (nonatomic, readwrite, weak) id<BOXAPIAccessTokenDelegate> accessTokenDelegate;

/**
 * This property is for storing any relevant information needed when your fetchTokenBlock delegate method is invoked
 * to retrieve a new token.  Passed into your fetchTokenBlock delegate method when a new token is required.
 */
@property (nonatomic, nullable, readwrite, copy) NSDictionary *fetchTokenBlockInfo;

/**
 *  The list of Box users that have established a session through the SDK.
 *
 *  @return array of BOXUserMini model objects
 */
+ (NSArray *_Null_unspecified)users;

/**
 *  You may use this to retrieve a content client, only if your app allows for only one Box user to be authenticated at a time.
 *  If your app will support multiple Box users, use clientForUser: and clientForNewSession to retrieve content clients for each user.
 *  Treat this method as a singleton accessor.
 *
 *  @return An existing BOXContentClient if it already exists. Otherwise, a new BOXContentClient wil be created.
 */
+ (BOXContentClient *_Null_unspecified)defaultClient;

/**
 *  Use this to refresh the default client based on the user currently stored in the keychain.
 *  If there are no users in the keychain, this will log out the default client's current user.
 *  NOTE: Currently not thread-safe.
 */
+ (void)refreshDefaultClientFromKeychain;

/**
 *  Get a BOXContentClient for a specific user that has an authenticated session.
 *  You can obtain a list of users with through the 'users' method.
 *  NOTE: Unless you want to allow your app to manage multiple Box users at one time, it is simpler to use
 *  'defaultClient' instead of this method.
 *
 *  @param user A user with an existing session
 *
 *  @return BOXContentClient for the specified user
 */
+ (BOXContentClient *_Null_unspecified)clientForUser:(BOXUserMini *_Null_unspecified)user;

/**
 *  Get an unauthenticated BOXContentClient.
 *  NOTE: Unless you want to allow your app to manage multiple Box users at one time, it is simpler to use
 *  'defaultClient' instead of this method.
 *
 *  @return An unauthenticated BOXContentClient
 */
+ (BOXContentClient *_Null_unspecified)clientForNewSession;

/**
 * Get a BOXContentClient that supports server-based auth (App Users or downscoped tokens).
 *
 * @param serverAuthUser A required instance of ServerAuthUser that will be passed to the fetchTokenBlock when a new token is required from the remote server
 * @param token An optional token that you have already retrieved from your remote server; if nil your fetchTokenBlock will be invoked to retrieve a new token
 * @param fetchTokenBlockInfo An optional dictionary of relevant information you may need when your fetchTokenBlock is invoked
 * @param fetchTokenBlock A required code block that will be invoked whenever an expired token is detected.  This is where you will call your secure remote server to generate a new token
 *
 * @return BOXContentClient that is configured for server-based auth
 */
+ (BOXContentClient *_Null_unspecified)clientForServerAuthUser:(nonnull ServerAuthUser *)serverAuthUser
                                 initialToken:(nullable NSString *)token
                          fetchTokenBlockInfo:(nullable NSDictionary *)fetchTokenBlockInfo
                              fetchTokenBlock:(nonnull ServerAuthFetchTokenBlock)fetchTokenBlock;

/**
 * Client ID:
 * The client identifier described in [Section 2.2 of the OAuth2 spec](http://tools.ietf.org/html/rfc6749#section-2.2)
 * This is also known as an API key on Box. See the [Box OAuth2 documentation](http://developers.box.com/oauth/) for
 * information on where to find this value.
 *
 * Client Secret:
 * The client secret. This value is used during the authorization code grant and when refreshing tokens.
 * This value should be a secret. DO NOT publish this value.
 * See the [Box OAuth2 documentation](http://developers.box.com/oauth/) for
 * information on where to find this value.
 */
+ (void)setClientID:(NSString *_Null_unspecified)clientID clientSecret:(NSString *_Null_unspecified)clientSecret;

/**
 * Client ID:
 * The client identifier described in [Section 2.2 of the OAuth2 spec](http://tools.ietf.org/html/rfc6749#section-2.2)
 * This is also known as an API key on Box. See the [Box OAuth2 documentation](http://developers.box.com/oauth/) for
 * information on where to find this value.
 *
 * Client Secret:
 * The client secret. This value is used during the authorization code grant and when refreshing tokens.
 * This value should be a secret. DO NOT publish this value.
 * See the [Box OAuth2 documentation](http://developers.box.com/oauth/) for
 * information on where to find this value.
 *
 * Redirect UR:
 * If you set a custom Redirect URI in your App's developer settings, set it here too.
 */
+ (void)setClientID:(NSString *_Null_unspecified)clientID clientSecret:(NSString *_Null_unspecified)clientSecret redirectURIString:(NSString *_Null_unspecified)redirectURIString;

/**
 * This property controls whether clients should attempt authentication through the Box app
 * The default is NO and has to be set here because of the associated configuration that
 * has to be done.
 *
 *  @param enabled  Whether the client should attempt using the Box app for authenticating.
 *
 */
+ (void)setAppToAppBoxAuthenticationEnabled:(BOOL)enabled;

/**
 *  Resource bundle for loading images, etc.
 *
 *  @return NSBundle
 */
+ (NSBundle *_Null_unspecified)resourcesBundle;

/**
 *  Overides the default sharedLink delegate with the provided object.
 *  By default the SDK persists shared link information in memory only. Override this to implement your own custom persistence logic.
 *  @param delegate The object that will receive the BOXSharedLinkStorageProtocol delegate callbacks.
 **/
- (void)setSharedLinkStorageDelegate:(id <BOXSharedLinkStorageProtocol>_Null_unspecified)delegate;

/**
 * This method needs to be called once in main app to be ready to
 * support background upload/download tasks.
 * If this method has not been called, all background task creations will fail
 *
 * @param delegate          used for encrypting/decrypting metadata cached for background session tasks
 * @param rootCacheDir      root directory for caching background session tasks' data
 * @param completionBlock   block to execute upon completion of setup, indicating background tasks can be provided
 */
+ (void)oneTimeSetUpInAppToSupportBackgroundTasksWithDelegate:(id<BOXURLSessionManagerDelegate>_Null_unspecified)delegate
                                                 rootCacheDir:(NSString *_Nonnull)rootCacheDir
                                                   completion:(void (^_Null_unspecified)(NSError * _Null_unspecified error))completionBlock;

/**
 * This method needs to be called once in app extensions to be ready to
 * support background upload/download tasks.
 * If this method has not been called, all background task creations will fail
 *
 * @param delegate          used for encrypting/decrypting metadata cached for background session tasks
 * @param rootCacheDir      root directory for caching background session tasks' data. Should be the same
 *                          as rootCacheDir for main app to allow main app takes over background session
 *                          tasks created from extensions
 * @param completionBlock   block to execute upon completion of setup, indicating background tasks can be provided
 */
+ (void)oneTimeSetUpInExtensionToSupportBackgroundTasksWithDelegate:(id<BOXURLSessionManagerDelegate>_Null_unspecified)delegate
                                                       rootCacheDir:(NSString *_Nonnull)rootCacheDir
                                          sharedContainerIdentifier:(NSString *_Null_unspecified)sharedContainerIdentifier
                                                         completion:(void (^_Null_unspecified)(NSError * _Null_unspecified error))completionBlock;

/**
 * This method needs to be called in the main app to allow it reconnecting to background session tasks created by
 * background session started from extension
 *
 * @param backgroundSessionId   Id of background session from extension
 * @param completionBlock       block to execute upon completion of reconnecting to background session
 */
+ (void)reconnectWithBackgroundSessionIdFromExtension:(NSString *_Null_unspecified)backgroundSessionId
                                           completion:(void (^_Null_unspecified)(NSError * _Null_unspecified error))completionBlock;

/**
 *  API base URLs.
 **/
+ (NSString *_Null_unspecified)APIBaseURL;
+ (NSString *_Null_unspecified)APIBaseURLWithoutVersion;
+ (NSString *_Null_unspecified)OAuth2BaseURL;
+ (NSString *_Null_unspecified)APIAuthBaseURL;
+ (NSString *_Null_unspecified)APIUploadBaseURL;
+ (void)setAPIBaseURL:(NSString *_Null_unspecified)APIBaseURL;
+ (void)setOAuth2BaseURL:(NSString *_Null_unspecified)OAuth2BaseURL;
+ (void)setAPIAuthBaseURL:(NSString *_Null_unspecified)APIAuthBaseURL;
+ (void)setAPIUploadBaseURL:(NSString *_Null_unspecified)APIUploadBaseURL;

@end
