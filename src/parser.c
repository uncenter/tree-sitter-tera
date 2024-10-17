#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 72
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 55
#define ALIAS_COUNT 0
#define TOKEN_COUNT 38
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_bool = 1,
  sym_number = 2,
  anon_sym_SQUOTE = 3,
  aux_sym_string_token1 = 4,
  anon_sym_DQUOTE = 5,
  aux_sym_string_token2 = 6,
  anon_sym_BQUOTE = 7,
  aux_sym_string_token3 = 8,
  anon_sym_LBRACK = 9,
  anon_sym_COMMA = 10,
  anon_sym_RBRACK = 11,
  anon_sym_DOT = 12,
  sym__ident = 13,
  anon_sym_STAR = 14,
  anon_sym_SLASH = 15,
  anon_sym_PERCENT = 16,
  anon_sym_PLUS = 17,
  anon_sym_DASH = 18,
  anon_sym_TILDE = 19,
  anon_sym_EQ_EQ = 20,
  anon_sym_BANG_EQ = 21,
  anon_sym_LT = 22,
  anon_sym_GT = 23,
  anon_sym_LT_EQ = 24,
  anon_sym_GT_EQ = 25,
  anon_sym_in = 26,
  anon_sym_and = 27,
  anon_sym_or = 28,
  anon_sym_not = 29,
  anon_sym_LBRACE_LBRACE = 30,
  anon_sym_RBRACE_RBRACE = 31,
  anon_sym_LBRACE_PERCENT = 32,
  anon_sym_PERCENT_RBRACE = 33,
  anon_sym_LBRACE_POUND = 34,
  aux_sym_comment_token1 = 35,
  anon_sym_POUND_RBRACE = 36,
  sym_content = 37,
  sym_source_file = 38,
  sym_string = 39,
  sym_literal = 40,
  sym_array = 41,
  sym_identifier = 42,
  sym__expr = 43,
  sym_binary_expression = 44,
  sym_unary_expression = 45,
  sym_expression = 46,
  sym_statement = 47,
  sym_comment = 48,
  aux_sym_source_file_repeat1 = 49,
  aux_sym_string_repeat1 = 50,
  aux_sym_string_repeat2 = 51,
  aux_sym_string_repeat3 = 52,
  aux_sym_array_repeat1 = 53,
  aux_sym_identifier_repeat1 = 54,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_bool] = "bool",
  [sym_number] = "number",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token2] = "string_token2",
  [anon_sym_BQUOTE] = "`",
  [aux_sym_string_token3] = "string_token3",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [anon_sym_DOT] = ".",
  [sym__ident] = "_ident",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_TILDE] = "~",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_in] = "in",
  [anon_sym_and] = "and",
  [anon_sym_or] = "or",
  [anon_sym_not] = "not",
  [anon_sym_LBRACE_LBRACE] = "{{",
  [anon_sym_RBRACE_RBRACE] = "}}",
  [anon_sym_LBRACE_PERCENT] = "{%",
  [anon_sym_PERCENT_RBRACE] = "%}",
  [anon_sym_LBRACE_POUND] = "{#",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_POUND_RBRACE] = "#}",
  [sym_content] = "content",
  [sym_source_file] = "source_file",
  [sym_string] = "string",
  [sym_literal] = "literal",
  [sym_array] = "array",
  [sym_identifier] = "identifier",
  [sym__expr] = "_expr",
  [sym_binary_expression] = "binary_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_expression] = "expression",
  [sym_statement] = "statement",
  [sym_comment] = "comment",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_string_repeat2] = "string_repeat2",
  [aux_sym_string_repeat3] = "string_repeat3",
  [aux_sym_array_repeat1] = "array_repeat1",
  [aux_sym_identifier_repeat1] = "identifier_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_bool] = sym_bool,
  [sym_number] = sym_number,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym_string_token3] = aux_sym_string_token3,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym__ident] = sym__ident,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_LBRACE_LBRACE] = anon_sym_LBRACE_LBRACE,
  [anon_sym_RBRACE_RBRACE] = anon_sym_RBRACE_RBRACE,
  [anon_sym_LBRACE_PERCENT] = anon_sym_LBRACE_PERCENT,
  [anon_sym_PERCENT_RBRACE] = anon_sym_PERCENT_RBRACE,
  [anon_sym_LBRACE_POUND] = anon_sym_LBRACE_POUND,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_POUND_RBRACE] = anon_sym_POUND_RBRACE,
  [sym_content] = sym_content,
  [sym_source_file] = sym_source_file,
  [sym_string] = sym_string,
  [sym_literal] = sym_literal,
  [sym_array] = sym_array,
  [sym_identifier] = sym_identifier,
  [sym__expr] = sym__expr,
  [sym_binary_expression] = sym_binary_expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_expression] = sym_expression,
  [sym_statement] = sym_statement,
  [sym_comment] = sym_comment,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_string_repeat2] = aux_sym_string_repeat2,
  [aux_sym_string_repeat3] = aux_sym_string_repeat3,
  [aux_sym_array_repeat1] = aux_sym_array_repeat1,
  [aux_sym_identifier_repeat1] = aux_sym_identifier_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_bool] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym__ident] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE_POUND] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_POUND_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_content] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_array] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__expr] = {
    .visible = false,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_array_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 8,
  [36] = 9,
  [37] = 11,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 47,
  [53] = 53,
  [54] = 54,
  [55] = 49,
  [56] = 56,
  [57] = 51,
  [58] = 58,
  [59] = 50,
  [60] = 48,
  [61] = 53,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(30);
      ADVANCE_MAP(
        '!', 9,
        '"', 38,
        '#', 23,
        '%', 56,
        '\'', 35,
        '*', 54,
        '+', 57,
        ',', 44,
        '-', 58,
        '.', 46,
        '/', 55,
        '<', 64,
        '=', 10,
        '>', 65,
        'F', 11,
        'T', 18,
        '[', 43,
        ']', 45,
        '`', 41,
        'a', 15,
        'f', 11,
        'i', 16,
        'n', 17,
        'o', 19,
        't', 18,
        '{', 5,
        '}', 25,
        '~', 61,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 38,
        '%', 24,
        '\'', 35,
        '+', 27,
        '-', 59,
        '.', 34,
        'F', 47,
        'T', 50,
        '[', 43,
        '`', 41,
        'f', 47,
        't', 50,
        '}', 25,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 38,
        '\'', 35,
        ',', 44,
        'F', 11,
        'T', 18,
        ']', 45,
        '`', 41,
        'f', 11,
        't', 18,
        '+', 27,
        '-', 27,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(38);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(40);
      if (lookahead != 0) ADVANCE(39);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(42);
      if (lookahead == '`') ADVANCE(41);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(76);
      if (lookahead == '%') ADVANCE(74);
      if (lookahead == '{') ADVANCE(72);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(76);
      if (lookahead == '%') ADVANCE(74);
      if (lookahead == '{') ADVANCE(72);
      if (lookahead != 0) ADVANCE(82);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(35);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(37);
      if (lookahead != 0) ADVANCE(36);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(60);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(79);
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(63);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(62);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(14);
      END_STATE();
    case 12:
      if (lookahead == 'd') ADVANCE(69);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(31);
      END_STATE();
    case 14:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(68);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(21);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(22);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(70);
      END_STATE();
    case 20:
      if (lookahead == 's') ADVANCE(13);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 22:
      if (lookahead == 'u') ADVANCE(13);
      END_STATE();
    case 23:
      if (lookahead == '}') ADVANCE(80);
      END_STATE();
    case 24:
      if (lookahead == '}') ADVANCE(75);
      END_STATE();
    case 25:
      if (lookahead == '}') ADVANCE(73);
      END_STATE();
    case 26:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(78);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(79);
      END_STATE();
    case 27:
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 28:
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '{') ADVANCE(82);
      END_STATE();
    case 29:
      if (eof) ADVANCE(30);
      if (lookahead == '{') ADVANCE(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(81);
      if (lookahead != 0) ADVANCE(82);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_bool);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_bool);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_string_token1);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(36);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_string_token2);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(40);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(39);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_string_token3);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym__ident);
      if (lookahead == 'a') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym__ident);
      if (lookahead == 'e') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym__ident);
      if (lookahead == 'l') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym__ident);
      if (lookahead == 'r') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym__ident);
      if (lookahead == 's') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym__ident);
      if (lookahead == 'u') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym__ident);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '}') ADVANCE(75);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(79);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(66);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(67);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_not);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_LBRACE_PERCENT);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_PERCENT_RBRACE);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_LBRACE_POUND);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '-') ADVANCE(60);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(79);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(78);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(79);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_POUND_RBRACE);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_content);
      if (lookahead == '{') ADVANCE(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(81);
      if (lookahead != 0) ADVANCE(82);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_content);
      if (lookahead == '{') ADVANCE(28);
      if (lookahead != 0) ADVANCE(82);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 29},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 29},
  [34] = {.lex_state = 29},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 29},
  [39] = {.lex_state = 29},
  [40] = {.lex_state = 29},
  [41] = {.lex_state = 29},
  [42] = {.lex_state = 29},
  [43] = {.lex_state = 29},
  [44] = {.lex_state = 29},
  [45] = {.lex_state = 29},
  [46] = {.lex_state = 29},
  [47] = {.lex_state = 3},
  [48] = {.lex_state = 7},
  [49] = {.lex_state = 3},
  [50] = {.lex_state = 7},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 3},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 3},
  [55] = {.lex_state = 3},
  [56] = {.lex_state = 7},
  [57] = {.lex_state = 4},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 7},
  [60] = {.lex_state = 7},
  [61] = {.lex_state = 4},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 8},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 26},
  [70] = {.lex_state = 4},
  [71] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_bool] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [aux_sym_string_token3] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [anon_sym_not] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_LBRACE_PERCENT] = ACTIONS(1),
    [anon_sym_PERCENT_RBRACE] = ACTIONS(1),
    [anon_sym_LBRACE_POUND] = ACTIONS(1),
    [anon_sym_POUND_RBRACE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(66),
    [sym_expression] = STATE(33),
    [sym_statement] = STATE(33),
    [sym_comment] = STATE(33),
    [aux_sym_source_file_repeat1] = STATE(33),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(5),
    [anon_sym_LBRACE_PERCENT] = ACTIONS(7),
    [anon_sym_LBRACE_POUND] = ACTIONS(9),
    [sym_content] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(13), 1,
      anon_sym_DOT,
    STATE(3), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(17), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(15), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [29] = 4,
    ACTIONS(13), 1,
      anon_sym_DOT,
    STATE(4), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(21), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(19), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [58] = 4,
    ACTIONS(23), 1,
      anon_sym_DOT,
    STATE(4), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(28), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(26), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [87] = 2,
    ACTIONS(28), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(26), 16,
      anon_sym_DOT,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [111] = 4,
    ACTIONS(32), 1,
      anon_sym_PERCENT,
    ACTIONS(30), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(36), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(34), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [138] = 2,
    ACTIONS(36), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(34), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [161] = 2,
    ACTIONS(40), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(38), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [184] = 2,
    ACTIONS(44), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(42), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [207] = 2,
    ACTIONS(48), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(46), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [230] = 2,
    ACTIONS(52), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(50), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [253] = 2,
    ACTIONS(56), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(54), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [276] = 2,
    ACTIONS(60), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(58), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [299] = 5,
    ACTIONS(32), 1,
      anon_sym_PERCENT,
    ACTIONS(30), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(36), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(62), 3,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
    ACTIONS(34), 10,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [328] = 2,
    ACTIONS(66), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(64), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
      anon_sym_PERCENT_RBRACE,
  [351] = 2,
    ACTIONS(56), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(54), 15,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_RBRACE_RBRACE,
  [373] = 2,
    ACTIONS(56), 3,
      anon_sym_PERCENT,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(54), 14,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
      anon_sym_PERCENT_RBRACE,
  [395] = 7,
    ACTIONS(32), 1,
      anon_sym_PERCENT,
    ACTIONS(68), 1,
      anon_sym_DASH,
    ACTIONS(74), 1,
      anon_sym_PERCENT_RBRACE,
    ACTIONS(30), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(62), 2,
      anon_sym_PLUS,
      anon_sym_TILDE,
    ACTIONS(72), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(70), 8,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
  [427] = 6,
    ACTIONS(76), 1,
      anon_sym_DASH,
    ACTIONS(78), 1,
      anon_sym_RBRACE_RBRACE,
    ACTIONS(62), 2,
      anon_sym_PLUS,
      anon_sym_TILDE,
    ACTIONS(72), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(30), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(70), 8,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_in,
      anon_sym_and,
      anon_sym_or,
      anon_sym_not,
  [457] = 10,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(92), 1,
      anon_sym_DASH,
    ACTIONS(94), 1,
      anon_sym_PERCENT_RBRACE,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(6), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [494] = 10,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(92), 1,
      anon_sym_DASH,
    ACTIONS(96), 1,
      anon_sym_RBRACE_RBRACE,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(6), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [531] = 9,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(98), 1,
      anon_sym_DASH,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(19), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [565] = 9,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(92), 1,
      anon_sym_DASH,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(17), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [599] = 9,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(92), 1,
      anon_sym_DASH,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(7), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [633] = 9,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(92), 1,
      anon_sym_DASH,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(12), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [667] = 9,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(92), 1,
      anon_sym_DASH,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(6), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [701] = 9,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(100), 1,
      anon_sym_DASH,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(18), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [735] = 9,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(92), 1,
      anon_sym_DASH,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(14), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [769] = 9,
    ACTIONS(82), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(86), 1,
      anon_sym_BQUOTE,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 1,
      sym__ident,
    ACTIONS(92), 1,
      anon_sym_DASH,
    STATE(8), 1,
      sym_string,
    ACTIONS(80), 2,
      sym_bool,
      sym_number,
    STATE(16), 6,
      sym_literal,
      sym_array,
      sym_identifier,
      sym__expr,
      sym_binary_expression,
      sym_unary_expression,
  [803] = 8,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(106), 1,
      anon_sym_DQUOTE,
    ACTIONS(108), 1,
      anon_sym_BQUOTE,
    ACTIONS(110), 1,
      anon_sym_COMMA,
    ACTIONS(112), 1,
      anon_sym_RBRACK,
    STATE(35), 1,
      sym_string,
    ACTIONS(102), 2,
      sym_bool,
      sym_number,
    STATE(31), 2,
      sym_literal,
      aux_sym_array_repeat1,
  [830] = 8,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(106), 1,
      anon_sym_DQUOTE,
    ACTIONS(108), 1,
      anon_sym_BQUOTE,
    ACTIONS(114), 1,
      anon_sym_COMMA,
    ACTIONS(116), 1,
      anon_sym_RBRACK,
    STATE(35), 1,
      sym_string,
    ACTIONS(102), 2,
      sym_bool,
      sym_number,
    STATE(32), 2,
      sym_literal,
      aux_sym_array_repeat1,
  [857] = 7,
    ACTIONS(121), 1,
      anon_sym_SQUOTE,
    ACTIONS(124), 1,
      anon_sym_DQUOTE,
    ACTIONS(127), 1,
      anon_sym_BQUOTE,
    STATE(35), 1,
      sym_string,
    ACTIONS(118), 2,
      sym_bool,
      sym_number,
    ACTIONS(130), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    STATE(32), 2,
      sym_literal,
      aux_sym_array_repeat1,
  [882] = 6,
    ACTIONS(5), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(7), 1,
      anon_sym_LBRACE_PERCENT,
    ACTIONS(9), 1,
      anon_sym_LBRACE_POUND,
    ACTIONS(132), 1,
      ts_builtin_sym_end,
    ACTIONS(134), 1,
      sym_content,
    STATE(34), 4,
      sym_expression,
      sym_statement,
      sym_comment,
      aux_sym_source_file_repeat1,
  [904] = 6,
    ACTIONS(136), 1,
      ts_builtin_sym_end,
    ACTIONS(138), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(141), 1,
      anon_sym_LBRACE_PERCENT,
    ACTIONS(144), 1,
      anon_sym_LBRACE_POUND,
    ACTIONS(147), 1,
      sym_content,
    STATE(34), 4,
      sym_expression,
      sym_statement,
      sym_comment,
      aux_sym_source_file_repeat1,
  [926] = 1,
    ACTIONS(38), 7,
      sym_bool,
      sym_number,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [936] = 1,
    ACTIONS(42), 7,
      sym_bool,
      sym_number,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [946] = 1,
    ACTIONS(50), 7,
      sym_bool,
      sym_number,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [956] = 2,
    ACTIONS(150), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(152), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [966] = 2,
    ACTIONS(154), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(156), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [976] = 2,
    ACTIONS(158), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(160), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [986] = 2,
    ACTIONS(162), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(164), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [996] = 2,
    ACTIONS(166), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(168), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [1006] = 2,
    ACTIONS(170), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(172), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [1016] = 2,
    ACTIONS(174), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(176), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [1026] = 2,
    ACTIONS(178), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(180), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [1036] = 2,
    ACTIONS(182), 2,
      ts_builtin_sym_end,
      sym_content,
    ACTIONS(184), 3,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_PERCENT,
      anon_sym_LBRACE_POUND,
  [1046] = 3,
    ACTIONS(186), 1,
      anon_sym_DQUOTE,
    ACTIONS(188), 1,
      aux_sym_string_token2,
    STATE(54), 1,
      aux_sym_string_repeat2,
  [1056] = 3,
    ACTIONS(190), 1,
      anon_sym_SQUOTE,
    ACTIONS(192), 1,
      aux_sym_string_token1,
    STATE(56), 1,
      aux_sym_string_repeat1,
  [1066] = 3,
    ACTIONS(194), 1,
      anon_sym_DQUOTE,
    ACTIONS(196), 1,
      aux_sym_string_token2,
    STATE(52), 1,
      aux_sym_string_repeat2,
  [1076] = 3,
    ACTIONS(194), 1,
      anon_sym_SQUOTE,
    ACTIONS(198), 1,
      aux_sym_string_token1,
    STATE(48), 1,
      aux_sym_string_repeat1,
  [1086] = 3,
    ACTIONS(200), 1,
      anon_sym_BQUOTE,
    ACTIONS(202), 1,
      aux_sym_string_token3,
    STATE(53), 1,
      aux_sym_string_repeat3,
  [1096] = 3,
    ACTIONS(188), 1,
      aux_sym_string_token2,
    ACTIONS(190), 1,
      anon_sym_DQUOTE,
    STATE(54), 1,
      aux_sym_string_repeat2,
  [1106] = 3,
    ACTIONS(204), 1,
      anon_sym_BQUOTE,
    ACTIONS(206), 1,
      aux_sym_string_token3,
    STATE(58), 1,
      aux_sym_string_repeat3,
  [1116] = 3,
    ACTIONS(208), 1,
      anon_sym_DQUOTE,
    ACTIONS(210), 1,
      aux_sym_string_token2,
    STATE(54), 1,
      aux_sym_string_repeat2,
  [1126] = 3,
    ACTIONS(213), 1,
      anon_sym_DQUOTE,
    ACTIONS(215), 1,
      aux_sym_string_token2,
    STATE(47), 1,
      aux_sym_string_repeat2,
  [1136] = 3,
    ACTIONS(217), 1,
      anon_sym_SQUOTE,
    ACTIONS(219), 1,
      aux_sym_string_token1,
    STATE(56), 1,
      aux_sym_string_repeat1,
  [1146] = 3,
    ACTIONS(222), 1,
      anon_sym_BQUOTE,
    ACTIONS(224), 1,
      aux_sym_string_token3,
    STATE(61), 1,
      aux_sym_string_repeat3,
  [1156] = 3,
    ACTIONS(226), 1,
      anon_sym_BQUOTE,
    ACTIONS(228), 1,
      aux_sym_string_token3,
    STATE(58), 1,
      aux_sym_string_repeat3,
  [1166] = 3,
    ACTIONS(213), 1,
      anon_sym_SQUOTE,
    ACTIONS(231), 1,
      aux_sym_string_token1,
    STATE(60), 1,
      aux_sym_string_repeat1,
  [1176] = 3,
    ACTIONS(186), 1,
      anon_sym_SQUOTE,
    ACTIONS(192), 1,
      aux_sym_string_token1,
    STATE(56), 1,
      aux_sym_string_repeat1,
  [1186] = 3,
    ACTIONS(206), 1,
      aux_sym_string_token3,
    ACTIONS(233), 1,
      anon_sym_BQUOTE,
    STATE(58), 1,
      aux_sym_string_repeat3,
  [1196] = 2,
    ACTIONS(235), 1,
      anon_sym_DASH,
    ACTIONS(237), 1,
      anon_sym_POUND_RBRACE,
  [1203] = 2,
    ACTIONS(239), 1,
      anon_sym_DASH,
    ACTIONS(241), 1,
      anon_sym_POUND_RBRACE,
  [1210] = 2,
    ACTIONS(243), 1,
      anon_sym_DASH,
    ACTIONS(245), 1,
      aux_sym_comment_token1,
  [1217] = 1,
    ACTIONS(116), 1,
      anon_sym_RBRACK,
  [1221] = 1,
    ACTIONS(247), 1,
      ts_builtin_sym_end,
  [1225] = 1,
    ACTIONS(249), 1,
      anon_sym_POUND_RBRACE,
  [1229] = 1,
    ACTIONS(241), 1,
      anon_sym_POUND_RBRACE,
  [1233] = 1,
    ACTIONS(251), 1,
      aux_sym_comment_token1,
  [1237] = 1,
    ACTIONS(253), 1,
      sym__ident,
  [1241] = 1,
    ACTIONS(255), 1,
      anon_sym_RBRACK,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 58,
  [SMALL_STATE(5)] = 87,
  [SMALL_STATE(6)] = 111,
  [SMALL_STATE(7)] = 138,
  [SMALL_STATE(8)] = 161,
  [SMALL_STATE(9)] = 184,
  [SMALL_STATE(10)] = 207,
  [SMALL_STATE(11)] = 230,
  [SMALL_STATE(12)] = 253,
  [SMALL_STATE(13)] = 276,
  [SMALL_STATE(14)] = 299,
  [SMALL_STATE(15)] = 328,
  [SMALL_STATE(16)] = 351,
  [SMALL_STATE(17)] = 373,
  [SMALL_STATE(18)] = 395,
  [SMALL_STATE(19)] = 427,
  [SMALL_STATE(20)] = 457,
  [SMALL_STATE(21)] = 494,
  [SMALL_STATE(22)] = 531,
  [SMALL_STATE(23)] = 565,
  [SMALL_STATE(24)] = 599,
  [SMALL_STATE(25)] = 633,
  [SMALL_STATE(26)] = 667,
  [SMALL_STATE(27)] = 701,
  [SMALL_STATE(28)] = 735,
  [SMALL_STATE(29)] = 769,
  [SMALL_STATE(30)] = 803,
  [SMALL_STATE(31)] = 830,
  [SMALL_STATE(32)] = 857,
  [SMALL_STATE(33)] = 882,
  [SMALL_STATE(34)] = 904,
  [SMALL_STATE(35)] = 926,
  [SMALL_STATE(36)] = 936,
  [SMALL_STATE(37)] = 946,
  [SMALL_STATE(38)] = 956,
  [SMALL_STATE(39)] = 966,
  [SMALL_STATE(40)] = 976,
  [SMALL_STATE(41)] = 986,
  [SMALL_STATE(42)] = 996,
  [SMALL_STATE(43)] = 1006,
  [SMALL_STATE(44)] = 1016,
  [SMALL_STATE(45)] = 1026,
  [SMALL_STATE(46)] = 1036,
  [SMALL_STATE(47)] = 1046,
  [SMALL_STATE(48)] = 1056,
  [SMALL_STATE(49)] = 1066,
  [SMALL_STATE(50)] = 1076,
  [SMALL_STATE(51)] = 1086,
  [SMALL_STATE(52)] = 1096,
  [SMALL_STATE(53)] = 1106,
  [SMALL_STATE(54)] = 1116,
  [SMALL_STATE(55)] = 1126,
  [SMALL_STATE(56)] = 1136,
  [SMALL_STATE(57)] = 1146,
  [SMALL_STATE(58)] = 1156,
  [SMALL_STATE(59)] = 1166,
  [SMALL_STATE(60)] = 1176,
  [SMALL_STATE(61)] = 1186,
  [SMALL_STATE(62)] = 1196,
  [SMALL_STATE(63)] = 1203,
  [SMALL_STATE(64)] = 1210,
  [SMALL_STATE(65)] = 1217,
  [SMALL_STATE(66)] = 1221,
  [SMALL_STATE(67)] = 1225,
  [SMALL_STATE(68)] = 1229,
  [SMALL_STATE(69)] = 1233,
  [SMALL_STATE(70)] = 1237,
  [SMALL_STATE(71)] = 1241,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 2, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [32] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, 0, 0),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1, 0, 0),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1, 0, 0),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2, 0, 0),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 2, 0, 0),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2, 0, 0),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3, 0, 0),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3, 0, 0),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 4, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 4, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [124] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [127] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [138] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [141] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [144] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [147] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 3, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 3, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 4, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 4, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 4, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 4, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 4, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 4, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 5, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 5, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 5, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 5, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 5, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 5, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 3, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 3, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [190] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [194] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [206] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0),
  [210] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0), SHIFT_REPEAT(54),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [219] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [224] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_repeat3, 2, 0, 0),
  [228] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat3, 2, 0, 0), SHIFT_REPEAT(58),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [243] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [247] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_tera(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
