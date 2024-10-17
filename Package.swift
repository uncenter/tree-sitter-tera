// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterTera",
    products: [
        .library(name: "TreeSitterTera", targets: ["TreeSitterTera"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterTera",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                // NOTE: if your language has an external scanner, add it here.
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterTeraTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterTera",
            ],
            path: "bindings/swift/TreeSitterTeraTests"
        )
    ],
    cLanguageStandard: .c11
)
