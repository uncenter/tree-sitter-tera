#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <wchar.h>

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

bool tree_sitter_tera_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    bool found_content = false;
    bool at_possible_tag_start = false;
    bool last_is_whitespace = false;

    if (valid_symbols[CONTENT]) {
        // Loop through characters until we exit early or reach EOF.
        while (lexer->lookahead) {
            // If the last character was a {, meaning possibly the end of the content token and the start of a Tera tag...
            if (at_possible_tag_start) {
                // If the character, combined with the previous {, creates the start of a Tera tag...
                if (lexer->lookahead == '{' || lexer->lookahead == '#' || lexer->lookahead == '%') {
                    // Exit the loop of characters (to either return true if we had found content up to this point or false if not).
                    break;
                } else {
                    // Since the character is not part of the start of a Tera tag, we can reset our possible bracket state and keep adding characters to the content token.
                    at_possible_tag_start = false;
                }
            }

            // If the character is whitespace...
            if (iswspace(lexer->lookahead)) {
                if (!found_content) {
                    // If we have not found any content up to this point, advance and *do not add this character to the token* (trims leading whitespace before the token, if any).
                    lexer->advance(lexer, true);
                } else {
                    // Since we have found content before this whitespace character, we will mark the end of the token here as long as the previous character wasn't also whitespace (which would mean we had already marked the end previously, at the last bit of actual content). We might find content after this whitespace in the future, in which case we will mark the end again later, adding this whitespace as part of the range of content.
                    if (!last_is_whitespace) lexer->mark_end(lexer);
                    // We have marked the end now or on the previous iteration, we will now just advance.
                    lexer->advance(lexer, false);
                }
                // Either way, this character is whitespace so we will set our flag so that the next iteration is aware of this previous whitespace character.
                last_is_whitespace = true;
            // If the character is a {, meaning possibly the end of the content token and the start of a Tera tag...
            } else if (lexer->lookahead == '{') {
                // Mark the end of the token here as long as the last token was content and not whitespace.
                if (!last_is_whitespace) lexer->mark_end(lexer);
                lexer->advance(lexer, false);
                // Set our possible tag flag to true so that we can confirm on the next iteration.
                at_possible_tag_start = true;
            } else {
                // The character isn't whitespace or possibly the start of a Tera tag, so it is actual content. We set the flag to be so.
                found_content = true;
                // We reset the last is whitespace flag since it is not, it is content.
                last_is_whitespace = false;
                // Advance!
                lexer->advance(lexer, false);
            }
        }

        // We have reached the start of a Tera tag or the end of the file. If we have found content in the range, we return true and the range becomes a content token.
        if (found_content) {
            lexer->result_symbol = CONTENT;
            return true;
        }
    }

    // We have either reached the start of a Tera tag or the end of file and *not* found content, or content is not a valid symbol at this time, so we return false to indicate no token here.
    return false;
}
