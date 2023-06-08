// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "KnotAPI",
    platforms: [
        .iOS(.v13)      // specify your platform and version
    ],
    products: [
        .library(
            name: "KnotAPI",
            targets: ["KnotAPI"]),
    ],
    targets: [
        .binaryTarget(
            name: "KnotAPI",
            url: "https://github.com/millionscard/knot-api-ios/releases/download/0.3.1/KnotAPI.xcframework.zip",
            checksum: "97345884150a7efb973bea99d0769aee75e54ec6e3b705a5b42e4c9e9daa41e1")
    ]
)