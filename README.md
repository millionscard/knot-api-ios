# KnotAPI iOS SDK

### Reference for integrating with the KnotAPI Card Switcher iOS SDK

## Overview

KnotAPI for iOS is an embeddable framework that is bundled and distributed with your application used to create an easy and accessible experience for your customers to update their old saved cards across the web to your new card.

![](https://files.readme.io/693cdf3-Real.svg 'Real.svg')

## Install iOS SDK

We recommend using CocoaPods to obtain the necessary files and keep them up-to-date.

### CocoaPods

1. If you haven’t already, install the latest version of CocoaPods.

2. If you don’t have an existing Podfile, run the following command to create one:

```ruby
pod init
```

3. Add this line to your Podfile:

```ruby
pod 'KnotAPI', '0.2.5'
```

4. Run the following command:

```ruby
pod install
```

### Swift Package Manager

To integrate KnotAPI using Swift Package Manager, you'll need Swift version 5.3 or later. Follow these steps within your Xcode project:

1. Go to File, Add Packages.
2. In the top right corner of the dialog box, you'll see a search bar. Enter the KnotAPI package URL: <https://github.com/millionscard/knot-api-ios>.
3. From the results, choose the knot-api-ios package.
4. Decide on your Dependency Rule. We suggest opting for Up to Next Major Version.
5. Choose the project you want to integrate with KnotAPI, and then click on Add Package.
6. Pick the KnotAPI package product and click on Add Package.
7. Confirm that LinkKit Swift package was added as a package dependency to your project successfully.

## Import SDK

To open the Card on File Switcher first you must import the SDK

### Import KnotAPI

```swift
import KnotAPI
```

```objectivec
#import "KnotAPI/KnotAPI-Swift.h"
```

### Create a user

Now, create a [user](/docs/user) and obtain the `knot_access_token`. We recommend, saving this `knot_access_token` for future debugging, logging, and connecting.

### Create a session

Next, create a [session](/docs/session) and obtain the `session ID`. We recommend, saving this `session ID` for future debugging, logging, and connecting.

## Card on file switcher

### Initialize a session

To initialize a session, you can use the following:

```swift
let session = CardOnFileSwitcherSession(sessionId: "SESSION_ID", clientId: "CLIENT_ID", environment: .sandbox)
```

```objectivec
CardOnFileSwitcherSession * session = [[CardOnFileSwitcherSession alloc] initWithSessionId:@"SessionId" clientId:@"ClientID" environment: EnvironmentSandbox];
```

### Open Card on File Switcher

To open the Card on File Switcher, you can use the following:

```swift
session.openCardOnFileSwitcher()
```

```objectivec
[session openOnCardFileSwitcherWithMerchants:@[]];
```

### Open with specific merchants

To open the Card on File Switcher with specific merchants, first contact sales@knotapi.com to receive the list of merchantIds and names. Pass in the ids or merchant names in the session instance as an array of numbers or strings.

```swift
session.setMerchantIds(merchantIds: [44, 16])
```

```objectivec
[session setMerchantIdsWithMerchantIds:@[@44, @16]];
```

```swift
session.setMerchantNames(merchantNames: ["Netflix"])
```

```objectivec
[session setMerchantNamesWithMerchantNames:@[@"Amazon"]];
```

## Environment

### Sandbox

The Sandbox is one of the KnotAPI environments on which you can run your code, Sandbox is a test environment in which no real data can be used.

> 📘 Test Credentials
>
> To test a merchant you can use the login:
>
> username/email: **user_good**  
> password: **pass_good**

## Events

Events provide your application real time feedback on the user's journey. These events can be used for in app function, or logging purposes.

To handle events you can create an instance of CardSwitcherConfiguration and set it on the session instance:

```swift ViewController.swift
class ViewController: UIViewController  {
  let session = CardOnFileSwitcherSession(sessionId: "SESSION_ID")
	let config = CardSwitcherConfiguration()
  session.setConfiguration(configuration: config)
```

```objectivec ViewController.m
CardOnFileSwitcherSession * session = [[CardOnFileSwitcherSession alloc] initWithSessionId:@"SESSION_ID"];
CardSwitcherConfiguration *config = [[CardSwitcherConfiguration alloc] init];
[session setConfigurationWithConfig:config];
```

Then you can set closures on the config instance

### onSuccess

The closure is called when a user successfully updates payment info on an account. It takes a single argument, containing the Merchant name.

```swift
config.setOnSuccess { merchant in
            print("cardSwitcher onSuccess Merchant: \(merchant)")
        }
```

```objectivec
[config setOnSuccessOnSuccess:^(NSString *merchant) {
         // handle success event
      }];
```

### onError

This closure is called when an error occurs during the Account Updater initialization or if an account has an issue updating payment info. It takes two String arguments errorCode and errorMessage.

```swift
config.setOnError { error, message in
            print("cardSwitcher Error: \(error), Message: \(message)")
        }
```

```objectivec
[config setOnErrorOnError:^(NSString * error, NSString * message) {
          // handle error event
      }];
```

### onExit

This optional closure is called when a user exits the Account updater without successfully updating all selected merchants, or if an unhandled error occurs during the Account updater initialization or an account has an issue updating payment info.

```swift
config.setOnExit {
            print("cardSwitcher onExit")
        }
```

```objectivec
[config setOnExitOnExit:^{
          // handle exit event
      }];
```

### onEvent

This closure is called when certain events in the Account updater flow have occurred, for example, when the user start updating payment info of an account. This enables your application to gain further insight into what is going on as the user goes through the Account Updater flow. It should take a two String arguments eventName and merchantName.

```swift
config.setOnEvent(onEvent: { event, merchant in
            print("cardSwitcher Event: \(event), Merchant: \(merchant)")
        })
```

```objectivec
[config setOnEventOnEvent:^(NSString * event, NSString * message) {
          // handle event
      }];
```

##### Events

###### login started

When the Card on File Switcher starts to login into an account.

###### login success

When the Card on File Switcher successfully logs into an account.

###### require otp

When the Card on File Switcher requires the user to enter an OTP.

###### card error

When the Card on File Switcher encounters an error related the card info when updating the card.

###### error

When the Card on File Switcher encounters an error when updating the card.
