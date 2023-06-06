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
            path: "KnotAPI.xcframework")
    ]
)
