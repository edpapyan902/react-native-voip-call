#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CallKit/CallKit.h>
#import <Intents/Intents.h>
//#import <AVFoundation/AVAudioSession.h>

#import <React/RCTEventEmitter.h>
#import <UserNotifications/UserNotifications.h>

@interface RNVoipCall : RCTEventEmitter <CXProviderDelegate>

@property (nonatomic, strong) CXCallController *callKeepCallController;
@property (nonatomic, strong) CXProvider *callKeepProvider;


+ (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options NS_AVAILABLE_IOS(9_0);

+ (BOOL)application:(UIApplication *)application
continueUserActivity:(NSUserActivity *)userActivity
  restorationHandler:(void(^)(NSArray * __nullable restorableObjects))restorationHandler;

+ (void)reportNewIncomingCall:(NSString *)uuidString
                       handle:(NSString *)handle
                   handleType:(NSString *)handleType
                     hasVideo:(BOOL)hasVideo
          localizedCallerName:(NSString * _Nullable)localizedCallerName
                  fromPushKit:(BOOL)fromPushKit
                      payload:(NSDictionary * _Nullable)payload;

+ (void)reportNewIncomingCall:(NSString *)uuidString
                       handle:(NSString *)handle
                   handleType:(NSString *)handleType
                     hasVideo:(BOOL)hasVideo
          localizedCallerName:(NSString * _Nullable)localizedCallerName
                  fromPushKit:(BOOL)fromPushKit
                      payload:(NSDictionary * _Nullable)payload
        withCompletionHandler:(void (^_Nullable)(void))completion;

+ (void)endCallWithUUID:(NSString *)uuidString
                 reason:(int)reason;

+ (BOOL)isCallActive:(NSString *)uuidString;

+ (void)showMissedCallNotification:(NSString *)title
                              body:(NSString *)body
                              uuid:(NSString *)uuid;

@end
