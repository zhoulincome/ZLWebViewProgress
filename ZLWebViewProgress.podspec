Pod::Spec.new do |s|
  s.name         = "ZLWebViewProgress"
  s.version      = "0.0.2"
  s.license      = "MIT"
  s.summary      = "UIWebView progress interface."
  s.homepage     = "https://github.com/zhoulincome/ZLWebViewProgress"
  s.authors      = { "zhoulincome" => "359344816@qq.com" }
  s.source       = { :git => "https://github.com/zhoulincome/ZLWebViewProgress.git", :tag => s.version.to_s}
  s.platform     = :ios, "7.0"
  s.requires_arc = true
  s.subspec 'Core' do |ss|
    ss.source_files = 'ZLWebViewProgress/NJKWebViewProgress.{h,m}'
  end
  s.subspec 'ProgressView' do |ss|
    ss.source_files = 'ZLWebViewProgress/NJKWebViewProgressView.{h,m}'
  end
end
