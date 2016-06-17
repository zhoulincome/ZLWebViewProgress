//
//  NJKWebViewProgress.h
//
//  Created by Satoshi Aasano on 4/20/13.
//  Copyright (c) 2013 Satoshi Asano. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#undef njk_weak
#if __has_feature(objc_arc_weak)
#define njk_weak weak
#else
#define njk_weak unsafe_unretained
#endif

extern const float NJKInitialProgressValue;
extern const float NJKInteractiveProgressValue;
extern const float NJKFinalProgressValue;

typedef void (^NJKWebViewProgressBlock)(float progress);
typedef BOOL (^ShouldStartLoadWithRequest)(UIWebView *webView,NSURLRequest *request,UIWebViewNavigationType navigationType);
typedef void (^WebViewDidStartLoad)(UIWebView *webView);
typedef void (^WebViewDidFinishLoad)(UIWebView *webView);
typedef void (^DidFailLoadWithError)(UIWebView *webView,NSError *error);

typedef void (^NJKWebViewProgressBlock)(float progress);
@protocol NJKWebViewProgressDelegate;
@interface NJKWebViewProgress : NSObject<UIWebViewDelegate>
@property (nonatomic, njk_weak) id<NJKWebViewProgressDelegate>progressDelegate;
@property (nonatomic, njk_weak) id<UIWebViewDelegate>webViewProxyDelegate;
@property (nonatomic, copy) NJKWebViewProgressBlock progressBlock;
@property (nonatomic, readonly) float progress; // 0.0..1.0

@property (nonatomic, copy) ShouldStartLoadWithRequest startRquest;
@property (nonatomic, copy) WebViewDidStartLoad didStartLoad;
@property (nonatomic, copy) WebViewDidFinishLoad didFinishLoad;
@property (nonatomic, copy) DidFailLoadWithError didFailLoad;


- (void)reset;
@end

@protocol NJKWebViewProgressDelegate <NSObject>
- (void)webViewProgress:(NJKWebViewProgress *)webViewProgress updateProgress:(float)progress;
@end

