Pod::Spec.new do |s|
  s.name          = "KnotAPI"
  s.version       = "1.0.12"
  s.summary       = "The Knot SDK."
  s.description   = "Provide a seamless way for end users to link their merchant accounts to your mobile app."
  s.homepage      = "https://www.knotapi.com/"
  s.license       = "MIT"
  s.author        = "Kieran O'Reilly"
  s.platform      = :ios, "13.0"
  s.swift_version = "4.2"
  s.source        = { :git => "https://github.com/millionscard/knot-api-ios.git", :tag => "#{s.version}" }
  s.vendored_frameworks = "KnotAPI.xcframework"

end
