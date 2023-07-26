Pod::Spec.new do |s|
  s.name          = "KnotAPI"
  s.version       = "0.5.2"
  s.summary       = "Connect to your customers online accounts easily"
  s.description   = "Change Card on File Information, Cancel Subscriptions, Change Passwords, and more via Knot."
  s.homepage      = "https://www.knotapi.com/"
  s.license       = "MIT"
  s.author        = "Tarik"
  s.platform      = :ios, "11.0"
  s.swift_version = "4.2"
  s.source        = { :git => "https://github.com/millionscard/knot-api-ios.git", :tag => "#{s.version}" }
  s.vendored_frameworks = "KnotAPI.xcframework"

end
