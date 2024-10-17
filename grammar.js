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
    number: $ => token(/[\+-]?[0-9\.]+/),
    string: $ => choice(
        seq("'", repeat(/[^']/), "'"),
        seq('"', repeat(/[^"]/), '"'),
        seq('`', repeat(/[`"]/), '`')
      ),
    literal: $ => choice($.bool, $.number, $.string),
    array: $ => seq("[", repeat($.literal), optional(","), "]"),
    keyword: $ => choice(
      "if", "else", "elif", "endif", "is", "for", "continue", "endfor",
      "include", "macro", "endmacro", "import", "block", "endblock", "extends"
    ),
    identifier: $ => seq($._ident, repeat(seq(".", $._ident))),
    _ident: $ => /\w+/,
    _expr: $ => choice(
      $.identifier,
      $.literal,
      $.array,
      $.binary_expression,
      $.unary_expression
    ),
    binary_expression: $ => choice(
      ...['*', '/', '%'].map(op => prec.left(2, seq($._expr, op, $._expr))),
      ...['+', '-', '~'].map(op => prec.left(1, seq($._expr, op, $._expr))),
      ...["==", "!=", "<", ">", "<=", ">=", 'in', 'and', 'or', 'not'].map(op => prec.left(seq($._expr, op, $._expr)))
    ),
    unary_expression: $ => prec(3, choice(
      seq('-', $._expr)
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
