#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum TokenType {
    CONTENT
};

void *tree_sitter_tera_external_scanner_create() {
    return NULL;
}

void tree_sitter_tera_external_scanner_destroy(void *payload) {}

void tree_sitter_tera_external_scanner_reset(void *payload) {}

unsigned tree_sitter_tera_external_scanner_serialize(void *payload, char *buffer) {
    return 0;
}

void tree_sitter_tera_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

static bool is_whitespace(int32_t codepoint) {
    return codepoint == 0x20    // Space
        || codepoint == 0x09    // Tab
        || codepoint == 0x0A    // Newline
        || codepoint == 0x0B    // Vertical Tab
        || codepoint == 0x0C    // Form Feed
        || codepoint == 0x0D;   // Carriage Return
}

bool tree_sitter_tera_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    bool found_content = false;

    // Skip leading whitespace
    while (lexer->lookahead && is_whitespace(lexer->lookahead)) {
        lexer->advance(lexer, true);
    }

    // Scan content between template markers
    while (lexer->lookahead) {
        if (lexer->lookahead == '{') {
            lexer->advance(lexer, false);
            if (lexer->lookahead == '{' || lexer->lookahead == '%' || lexer->lookahead == '#') {
                lexer->mark_end(lexer);
                break;
            } else {
                // It's not a template marker, so it's content
                lexer->advance(lexer, false);
            }
        } else if (is_whitespace(lexer->lookahead)) {
            lexer->advance(lexer, true);
        } else {
            found_content = true;
            lexer->advance(lexer, false);
        }
    }

    if (found_content) {
        lexer->result_symbol = CONTENT;
        return true;
    }

    return false;
}
