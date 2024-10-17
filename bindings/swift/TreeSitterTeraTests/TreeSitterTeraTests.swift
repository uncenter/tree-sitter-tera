import XCTest
import SwiftTreeSitter
import TreeSitterTera

final class TreeSitterTeraTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_tera())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Tera grammar")
    }
}
