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
            url: "https://github.com/millionscard/knot-api-ios/releases/download/0.3.1/KnotAPI.xcframework.zip")
    ]
)

let package = Package(
    name: "Intercom",
    products: [
        .library(
            name: "Intercom",
            targets: ["Intercom"]),
    ],
    targets: [
        .binaryTarget(
            name: "Intercom",
            url: "https://github.com/intercom/intercom-ios/releases/download/15.0.0/Intercom.xcframework.zip",
            checksum: "dc8c092b07debb5189f272a2b242ce8996b06308ecedc4b4f92ec70f3851989a"
        ),
    ]
)