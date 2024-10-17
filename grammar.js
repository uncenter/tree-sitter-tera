/**
 * @file Tree-sitter grammar for the Tera templating language.
 * @author uncenter <uncenter@uncenter.dev>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "tera",

  rules: {
    source_file: $ => repeat(
      choice(
          $.expression,
          $.statement,
          $.comment,
          $.content
      )
    ),

    bool: $ => token(choice("True", "False", "true", "false")),
    number: $ => token(
      /[\+-]?[0-9\.]+/,
    ),
    string: $ => seq(
      choice(
        seq("'", repeat(/[^']/), "'"),
        seq('"', repeat(/[^"]/), '"'),
        seq('`', repeat(/[`"]/), '`')
      ),
    ),
    literal: $ => choice($.bool, $.number, $.string),
    array: $ => seq("[", repeat($.literal), optional(","), "]"),
    keyword: $ => /[if|else|elif|endif|is|for|continue|endfor|include|macro|endmacro|import|block|endblock|extends]/,
    _ident: $ => /\w+/,
    _expr: $ => seq(choice(
      $.literal,
      $.array,
      $.binary_expression,
      $.unary_expression
    )),
    binary_expression: $ => choice(
      ...['+', '-', '*', '/', '~', "==", "!=", "<", ">", "<=", ">=", 'in', 'and', 'or', 'not'].map((op) => seq(
        op === 'in' ? choice($._expr, $._ident) : $._expr,
        op,
        $._expr,
      ))
    ),
    unary_expression: $ => prec(2, choice(
      seq('-', $._expr),
    )),
    expression: $ => seq(
      "{{", optional("-"), $._expr, optional("-"), "}}"
    ),
    statement: $ => seq(
      "{%", optional("-"), $._expr, optional("-"), "%}"
    ),
    comment: $ => seq(
      "{#", optional("-"), /[^#]+/, optional("-"), "#}"
    ),

    content: $ => /([^{]|[{][^{%#])+/,
  }
});
