#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <wchar.h>

enum TokenType {
    FRONTMATTER_DELIMITER,
    FRONTMATTER_CONTENT,
    CONTENT
};

typedef struct {
	bool started_frontmatter;
	bool ended_frontmatter;
} Scanner;

static bool scan_frontmatter_delimiter(Scanner *scanner, TSLexer *lexer) {
	if (lexer->eof(lexer)) { return false; }
	for (int i = 0; i < 3; i++) {
		if (lexer->lookahead == '-') {
			lexer->advance(lexer, false);
		} else {
			return false;
		}
	}
	if (iswspace(lexer->lookahead)) {
		lexer->mark_end(lexer);
		while (iswspace(lexer->lookahead) && lexer->lookahead != '\n') {
			lexer->advance(lexer, false);
		}
		if (lexer->lookahead == '\n') {
			lexer->advance(lexer, false);
			lexer->result_symbol = FRONTMATTER_DELIMITER;
			return true;
		}
	}
	return false;
}

void *tree_sitter_tera_external_scanner_create() {
Scanner *scanner = calloc(1, sizeof(Scanner));
	scanner->started_frontmatter = false;
	scanner->ended_frontmatter = false;
	return scanner;
}

void tree_sitter_tera_external_scanner_destroy(void *payload) {
	Scanner *scanner = (Scanner *)payload;
	free(scanner);
}

void tree_sitter_tera_external_scanner_reset(void *payload) {}

unsigned tree_sitter_tera_external_scanner_serialize(void *payload, char *buffer) {
	Scanner *scanner = (Scanner *)payload;
	buffer[0] = (char) scanner->started_frontmatter;
	buffer[1] = (char) scanner->ended_frontmatter;
	return 2;
}

void tree_sitter_tera_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
	Scanner *scanner = (Scanner *)payload;
	if (length == 0) {
		scanner->started_frontmatter = false;
		scanner->ended_frontmatter = false;
	} else {
		scanner->started_frontmatter = buffer[0];
		scanner->ended_frontmatter = buffer[1];
	}
}

bool tree_sitter_tera_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
	Scanner *scanner = (Scanner *)payload;

	if (valid_symbols[FRONTMATTER_DELIMITER] && lexer->get_column(lexer) == 0) {
		if (!scanner->started_frontmatter && scan_frontmatter_delimiter(scanner, lexer)) {
			scanner->started_frontmatter = true;
			return true;
		}
		if (!scanner->ended_frontmatter && scan_frontmatter_delimiter(scanner, lexer)) {
			scanner->ended_frontmatter = true;
			return true;
		}
	}

	if (valid_symbols[FRONTMATTER_CONTENT] && scanner->started_frontmatter) {
		bool marked_end = false;
		bool found_content = false;

		while (lexer->lookahead) {
			marked_end = false;

			// If the character is a -, meaning possibly the end of the content token and the start of a delimiter...
			if (lexer->lookahead == '-') {
				lexer->mark_end(lexer);
				marked_end = true;
				lexer->advance(lexer, false);
				if (lexer->lookahead == '-') {
					break;
				} else {
					found_content = true;
				}
			} else {
				found_content = true;
				lexer->advance(lexer, false);
			}
		}
		if (!marked_end) {
			lexer->mark_end(lexer);
		}

		// We have reached the start of a delimiter or the end of the file. We return true and the range becomes a content token.
		if (found_content) {
			lexer->result_symbol = FRONTMATTER_CONTENT;
			return true;
		}
	}

	if (valid_symbols[CONTENT]) {
		bool marked_end = false;
		bool found_content = false;

		while (lexer->lookahead) {
			marked_end = false;

			// If the character is a {, meaning possibly the end of the content token and the start of a Tera tag...
			if (lexer->lookahead == '{') {
				lexer->mark_end(lexer);
				marked_end = true;
				lexer->advance(lexer, false);
				if (lexer->lookahead == '{' || lexer->lookahead == '#' || lexer->lookahead == '%') {
					break;
				} else {
					found_content = true;
				}
			} else {
				found_content = true;
				lexer->advance(lexer, false);
			}
		}
		if (!marked_end) {
			lexer->mark_end(lexer);
		}

		// We have reached the start of a Tera tag or the end of the file. We return true and the range becomes a content token.
		if (found_content) {
			lexer->result_symbol = CONTENT;
			return true;
		}
	}

	// No valid symbols at this time, so we return false to indicate no token here.
	return false;
}
