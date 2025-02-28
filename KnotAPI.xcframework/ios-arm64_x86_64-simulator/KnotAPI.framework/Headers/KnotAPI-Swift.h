#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.10 (swiftlang-5.10.0.13 clang-1500.3.9.4)
#ifndef KNOTAPI_SWIFT_H
#define KNOTAPI_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="KnotAPI",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)
/// The Knot SDK environment for session instantiation.
typedef SWIFT_ENUM(NSInteger, Environment, open) {
/// KnotAPI’s staging environment
  EnvironmentSandbox = 0,
/// KnotAPI’s production environment
  EnvironmentProduction = 1,
/// KnotAPI’s development environment
  EnvironmentDevelopment = 2,
};

@class KnotConfiguration;
@protocol KnotEventDelegate;
@class UIViewController;
@class NSString;

/// The <code>Knot</code> class is the primary entry point for customers interacting with KnotAPI’s Card Switcher, Mass Switcher, and Transaction Link products.
/// Applications can call its <code>open(configuration:, delegate)</code> function to instantiate a particular KnotAPI product flow,
/// and receive event notifications via a <code>KnotEventDelegate</code>.
SWIFT_CLASS("_TtC7KnotAPI4Knot")
@interface Knot : NSObject
/// Private initializer.
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
/// Start a KnotAPI product flow with the necessary configurations and optionally receive delegate notifications.
/// \param configuration A <code>KnotConfiguration</code> specifiing the product and environment settings.
///
/// \param delegate An optional <code>KnotEventDelegate</code> used to receive merchant related events.
///
+ (void)openWithConfiguration:(KnotConfiguration * _Nonnull)configuration delegate:(id <KnotEventDelegate> _Nullable)delegate;
/// A factory method to create a configured <code>UIViewController</code> that will present the KnotAPI flow within the view controller.
/// Use this factory method if you do not want to want KnotAPI to present the flow modally. You are responsible for presenting and
/// dismissing the flow.
/// <ul>
///   <li>
///     Returns a UIViewController configured for the requested product KnotAPI flow.
///   </li>
/// </ul>
/// \param configuration A <code>KnotConfiguration</code> specifiing the product and environment settings.
///
/// \param delegate An optional <code>KnotEventDelegate</code> used to receive merchant related events.
///
+ (UIViewController * _Nonnull)createKnotViewControllerWithConfiguration:(KnotConfiguration * _Nonnull)configuration delegate:(id <KnotEventDelegate> _Nullable)delegate SWIFT_WARN_UNUSED_RESULT;
/// Dismiss a presented KnotAPI flow.
+ (void)close;
/// Retrieves the KnotAPI SDK version string.
/// <ul>
///   <li>
///     Returns an optional SDK version name string.
///   </li>
/// </ul>
+ (NSString * _Nullable)SDKVersion SWIFT_WARN_UNUSED_RESULT;
@end


enum Product : NSInteger;

/// A configuration used to initialize the KnotAPI SDK flow.
SWIFT_CLASS("_TtC7KnotAPI17KnotConfiguration")
@interface KnotConfiguration : NSObject
/// Session ID. Generally provided by your backend integration.
@property (nonatomic, readonly, copy) NSString * _Nonnull sessionId;
/// The client ID for your organization. This value is dependent on the environment you are intending to use.
@property (nonatomic, readonly, copy) NSString * _Nonnull clientId;
/// The KnotAPI <code>Environment</code> .
@property (nonatomic, readonly) enum Environment environment;
/// The particular KnotAPI <code>Product</code> you intend to use.
@property (nonatomic, readonly) enum Product product;
/// A flag to enable the display of KnotAPI merchant categories in the flow.
@property (nonatomic, readonly) BOOL useCategories;
/// A flag to show, or hide a search bar in the flow.
@property (nonatomic, readonly) BOOL useSearch;
/// Limit the display of merchants to the defined IDs.
@property (nonatomic, readonly, copy) NSArray<NSNumber *> * _Nullable merchantIds;
@property (nonatomic, readonly, copy) NSString * _Nullable entryPoint;
/// Configuration initializer.
/// \param sessionId The session ID used to start the product flow.
///
/// \param clientId The client ID for your organization. This value is dependent on the environment you are intending to use.
///
/// \param environment The KnotAPI environment .
///
/// \param entryPoint A session window entry point.
///
/// \param product The particular KnotAPI product you intend to use.
///
/// \param useCategories A flag to enable the display of KnotAPI merchant categories in the flow.
///
/// \param useSearch A flag to show, or hide a search bar in the flow.
///
/// \param merchantIds Limit the display of merchants to the defined IDs.
///
- (nonnull instancetype)initWithSessionId:(NSString * _Nonnull)sessionId clientId:(NSString * _Nonnull)clientId environment:(enum Environment)environment entryPoint:(NSString * _Nullable)entryPoint product:(enum Product)product useCategories:(BOOL)useCategories useSearch:(BOOL)useSearch merchantIds:(NSArray<NSNumber *> * _Nullable)merchantIds OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

/// Represents possible errors that can occur in the SDK.
typedef SWIFT_ENUM(NSInteger, KnotError, open) {
/// Indicates that the session is invalid.
  KnotErrorInvalidSession = 0,
/// Indicates that the session has expired.
  KnotErrorExpiredSession = 1,
/// Indicates that the client ID is invalid or missing.
  KnotErrorInvalidClientId = 2,
/// Represents an internal or unknown error.
  KnotErrorInternalError = 3,
};
static NSString * _Nonnull const KnotErrorDomain = @"KnotAPI.KnotError";


/// Intended as a base class that reflects its public properties in a dictionary. It is primarily used for React Native compliance.
SWIFT_CLASS("_TtC7KnotAPI11Reflectable")
@interface Reflectable : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSDictionary;

/// Represents a Knot event received during user interaction within the Knot SDK.
SWIFT_CLASS("_TtC7KnotAPI9KnotEvent")
@interface KnotEvent : Reflectable
/// The environment the event originated from.
@property (nonatomic, readonly) enum Environment environment;
/// The product the event originated from.
@property (nonatomic, readonly) enum Product product;
/// The primary event code.
@property (nonatomic, readonly, copy) NSString * _Nonnull event;
/// The merchant associated with the event (if applicable).
@property (nonatomic, readonly, copy) NSString * _Nullable merchant;
/// Addional metadata related to the event, stored as an Objective-C compatible dictionary.
@property (nonatomic, readonly, strong) NSDictionary * _Nonnull metaData;
/// The identifier associated with this event.
@property (nonatomic, readonly, copy) NSString * _Nullable taskId;
/// Initializes a <code>KnotEvent</code> object.
/// \param event The event code.
///
/// \param merchant The merchant name.
///
/// \param metaData Additional metadata in dictionary format.
///
/// \param taskId The associated task identifier.
///
- (nonnull instancetype)initWithEnvironment:(enum Environment)environment product:(enum Product)product event:(NSString * _Nonnull)event merchant:(NSString * _Nullable)merchant metaData:(NSDictionary * _Nonnull)metaData taskId:(NSString * _Nullable)taskId OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// KnotAPI delegate to receive event callbacks.
SWIFT_PROTOCOL("_TtP7KnotAPI17KnotEventDelegate_")
@protocol KnotEventDelegate
/// Notified in the event a merchant has successfully authenticated.
/// \param merchant The merchant name.
///
- (void)onSuccessWithMerchant:(NSString * _Nonnull)merchant;
/// Notified when a error has occurred while interacting with the merchant.
/// \param error A <code>KnotError</code> describing the error experienced while interacting with the merchant.
///
- (void)onErrorWithError:(enum KnotError)error;
/// Notifies the listerner regarding various merchant interaction events.
/// \param event A <code>KnotEvent</code> describing merchant interaction events.
///
- (void)onEventWithEvent:(KnotEvent * _Nonnull)event;
/// Notified when the KnotAPI webview has been dismissed by user of SDK action.
- (void)onExit;
@end

/// Knot Link products available for SDK session instantiation.
typedef SWIFT_ENUM(NSInteger, Product, open) {
/// Knot Card Switcher product.
  ProductCard_switcher = 0,
/// Knot Transaction Link product.
  ProductTransaction_link = 1,
};










#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#elif defined(__x86_64__) && __x86_64__
// Generated by Apple Swift version 5.10 (swiftlang-5.10.0.13 clang-1500.3.9.4)
#ifndef KNOTAPI_SWIFT_H
#define KNOTAPI_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="KnotAPI",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)
/// The Knot SDK environment for session instantiation.
typedef SWIFT_ENUM(NSInteger, Environment, open) {
/// KnotAPI’s staging environment
  EnvironmentSandbox = 0,
/// KnotAPI’s production environment
  EnvironmentProduction = 1,
/// KnotAPI’s development environment
  EnvironmentDevelopment = 2,
};

@class KnotConfiguration;
@protocol KnotEventDelegate;
@class UIViewController;
@class NSString;

/// The <code>Knot</code> class is the primary entry point for customers interacting with KnotAPI’s Card Switcher, Mass Switcher, and Transaction Link products.
/// Applications can call its <code>open(configuration:, delegate)</code> function to instantiate a particular KnotAPI product flow,
/// and receive event notifications via a <code>KnotEventDelegate</code>.
SWIFT_CLASS("_TtC7KnotAPI4Knot")
@interface Knot : NSObject
/// Private initializer.
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
/// Start a KnotAPI product flow with the necessary configurations and optionally receive delegate notifications.
/// \param configuration A <code>KnotConfiguration</code> specifiing the product and environment settings.
///
/// \param delegate An optional <code>KnotEventDelegate</code> used to receive merchant related events.
///
+ (void)openWithConfiguration:(KnotConfiguration * _Nonnull)configuration delegate:(id <KnotEventDelegate> _Nullable)delegate;
/// A factory method to create a configured <code>UIViewController</code> that will present the KnotAPI flow within the view controller.
/// Use this factory method if you do not want to want KnotAPI to present the flow modally. You are responsible for presenting and
/// dismissing the flow.
/// <ul>
///   <li>
///     Returns a UIViewController configured for the requested product KnotAPI flow.
///   </li>
/// </ul>
/// \param configuration A <code>KnotConfiguration</code> specifiing the product and environment settings.
///
/// \param delegate An optional <code>KnotEventDelegate</code> used to receive merchant related events.
///
+ (UIViewController * _Nonnull)createKnotViewControllerWithConfiguration:(KnotConfiguration * _Nonnull)configuration delegate:(id <KnotEventDelegate> _Nullable)delegate SWIFT_WARN_UNUSED_RESULT;
/// Dismiss a presented KnotAPI flow.
+ (void)close;
/// Retrieves the KnotAPI SDK version string.
/// <ul>
///   <li>
///     Returns an optional SDK version name string.
///   </li>
/// </ul>
+ (NSString * _Nullable)SDKVersion SWIFT_WARN_UNUSED_RESULT;
@end


enum Product : NSInteger;

/// A configuration used to initialize the KnotAPI SDK flow.
SWIFT_CLASS("_TtC7KnotAPI17KnotConfiguration")
@interface KnotConfiguration : NSObject
/// Session ID. Generally provided by your backend integration.
@property (nonatomic, readonly, copy) NSString * _Nonnull sessionId;
/// The client ID for your organization. This value is dependent on the environment you are intending to use.
@property (nonatomic, readonly, copy) NSString * _Nonnull clientId;
/// The KnotAPI <code>Environment</code> .
@property (nonatomic, readonly) enum Environment environment;
/// The particular KnotAPI <code>Product</code> you intend to use.
@property (nonatomic, readonly) enum Product product;
/// A flag to enable the display of KnotAPI merchant categories in the flow.
@property (nonatomic, readonly) BOOL useCategories;
/// A flag to show, or hide a search bar in the flow.
@property (nonatomic, readonly) BOOL useSearch;
/// Limit the display of merchants to the defined IDs.
@property (nonatomic, readonly, copy) NSArray<NSNumber *> * _Nullable merchantIds;
@property (nonatomic, readonly, copy) NSString * _Nullable entryPoint;
/// Configuration initializer.
/// \param sessionId The session ID used to start the product flow.
///
/// \param clientId The client ID for your organization. This value is dependent on the environment you are intending to use.
///
/// \param environment The KnotAPI environment .
///
/// \param entryPoint A session window entry point.
///
/// \param product The particular KnotAPI product you intend to use.
///
/// \param useCategories A flag to enable the display of KnotAPI merchant categories in the flow.
///
/// \param useSearch A flag to show, or hide a search bar in the flow.
///
/// \param merchantIds Limit the display of merchants to the defined IDs.
///
- (nonnull instancetype)initWithSessionId:(NSString * _Nonnull)sessionId clientId:(NSString * _Nonnull)clientId environment:(enum Environment)environment entryPoint:(NSString * _Nullable)entryPoint product:(enum Product)product useCategories:(BOOL)useCategories useSearch:(BOOL)useSearch merchantIds:(NSArray<NSNumber *> * _Nullable)merchantIds OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

/// Represents possible errors that can occur in the SDK.
typedef SWIFT_ENUM(NSInteger, KnotError, open) {
/// Indicates that the session is invalid.
  KnotErrorInvalidSession = 0,
/// Indicates that the session has expired.
  KnotErrorExpiredSession = 1,
/// Indicates that the client ID is invalid or missing.
  KnotErrorInvalidClientId = 2,
/// Represents an internal or unknown error.
  KnotErrorInternalError = 3,
};
static NSString * _Nonnull const KnotErrorDomain = @"KnotAPI.KnotError";


/// Intended as a base class that reflects its public properties in a dictionary. It is primarily used for React Native compliance.
SWIFT_CLASS("_TtC7KnotAPI11Reflectable")
@interface Reflectable : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSDictionary;

/// Represents a Knot event received during user interaction within the Knot SDK.
SWIFT_CLASS("_TtC7KnotAPI9KnotEvent")
@interface KnotEvent : Reflectable
/// The environment the event originated from.
@property (nonatomic, readonly) enum Environment environment;
/// The product the event originated from.
@property (nonatomic, readonly) enum Product product;
/// The primary event code.
@property (nonatomic, readonly, copy) NSString * _Nonnull event;
/// The merchant associated with the event (if applicable).
@property (nonatomic, readonly, copy) NSString * _Nullable merchant;
/// Addional metadata related to the event, stored as an Objective-C compatible dictionary.
@property (nonatomic, readonly, strong) NSDictionary * _Nonnull metaData;
/// The identifier associated with this event.
@property (nonatomic, readonly, copy) NSString * _Nullable taskId;
/// Initializes a <code>KnotEvent</code> object.
/// \param event The event code.
///
/// \param merchant The merchant name.
///
/// \param metaData Additional metadata in dictionary format.
///
/// \param taskId The associated task identifier.
///
- (nonnull instancetype)initWithEnvironment:(enum Environment)environment product:(enum Product)product event:(NSString * _Nonnull)event merchant:(NSString * _Nullable)merchant metaData:(NSDictionary * _Nonnull)metaData taskId:(NSString * _Nullable)taskId OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// KnotAPI delegate to receive event callbacks.
SWIFT_PROTOCOL("_TtP7KnotAPI17KnotEventDelegate_")
@protocol KnotEventDelegate
/// Notified in the event a merchant has successfully authenticated.
/// \param merchant The merchant name.
///
- (void)onSuccessWithMerchant:(NSString * _Nonnull)merchant;
/// Notified when a error has occurred while interacting with the merchant.
/// \param error A <code>KnotError</code> describing the error experienced while interacting with the merchant.
///
- (void)onErrorWithError:(enum KnotError)error;
/// Notifies the listerner regarding various merchant interaction events.
/// \param event A <code>KnotEvent</code> describing merchant interaction events.
///
- (void)onEventWithEvent:(KnotEvent * _Nonnull)event;
/// Notified when the KnotAPI webview has been dismissed by user of SDK action.
- (void)onExit;
@end

/// Knot Link products available for SDK session instantiation.
typedef SWIFT_ENUM(NSInteger, Product, open) {
/// Knot Card Switcher product.
  ProductCard_switcher = 0,
/// Knot Transaction Link product.
  ProductTransaction_link = 1,
};










#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif
