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
    number: $ => token(/[\+-]?[0-9]+(\.[0-9]+)?/),
    string: $ => choice(
        seq("'", repeat(/[^']/), "'"),
        seq('"', repeat(/[^"]/), '"'),
        seq('`', repeat(/[`"]/), '`')
      ),
    literal: $ => choice($.bool, $.number, $.string),
    array: $ => seq("[", repeat($.literal), optional(","), "]"),
    keyword: $ => choice(
     "is", "continue",
    ),
    identifier: $ => seq($._ident, repeat(seq(".", $._ident))),
    _ident: $ => /\w+/,
    _expr: $ => seq(choice(
      $.identifier,
      $.literal,
      $.array,
      $.binary_expression,
      $.unary_expression
    )),
    binary_expression: $ => choice(
      ...['*', '/', '%', "|"].map(op => prec.left(2, seq($._expr, op, $._expr))),
      ...['+', '-', '~'].map(op => prec.left(1, seq($._expr, op, $._expr))),
      ...["==", "!=", "<", ">", "<=", ">=", 'in', 'and', 'or', 'not'].map(op => prec.left(seq($._expr, field('operator', op), $._expr)))
    ),
    unary_expression: $ => prec(3, choice(
      seq('-', $._expr)
    )),
    expression: $ => seq(
      "{{", optional("-"), $._expr, optional("-"), "}}"
    ),
    begin_if_statement: $ => seq("{%", optional("-"), "if", $._expr, optional("-"), "%}"),
    begin_for_statement: $ => seq(
      "{%", optional("-"), "for",
      choice(
        seq($._ident, "in", $._expr), // Items in array
        seq($._ident, ",", $._ident, "in", $._expr) // Key, value of object
      ),
      optional("-"), "%}",
    ),
    set_statement: $ => seq(
      "{%", optional("-"), choice("set", "set_global"), $.identifier, "=", $._expr, optional("-"), "%}",
    ),
    begin_filter_statement: $ => seq(
      "{%", optional("-"), "filter", $._ident, optional("-"), "%}",
    ),
    begin_block_statement: $ => seq(
      "{%", optional("-"), "block", $._ident, optional("-"), "%}",
    ),
    end_block_statement: $ => seq(
      "{%", optional("-"), "endblock", $._ident, optional("-"), "%}"
    ),
    include_statement: $ => seq(
      "{%", optional("-"), "include", choice($.string, $.array), optional("ignore missing"), optional("-"), "%}",
    ),
    import_statement: $ => seq(
      "{%", optional("-"), "import", $.string, "as", $._ident, optional("-"), "%}",
    ),
    extends_statement: $ => seq(
      "{%", optional("-"), "extends", $.string, optional("-"), "%}",
    ),
    begin_macro_statement: $ => seq(
      "{%", optional("-"), "macro", $._ident, optional("-"), "%}",
    ),
    end_macro_statement: $ => seq(
      "{%", optional("-"), "endmacro", $._ident, optional("-"), "%}"
    ),
    generic_statement: $ => seq("{%", optional("-"), alias(choice("elif", "else", "endif", "endfor", "endfilter", "break", "continue"), 'keyword'), optional("-"), "%}"),
    statement: $ => choice(
      $.begin_if_statement,
      $.begin_for_statement,
      $.set_statement,
      $.begin_filter_statement,
      $.begin_block_statement,
      $.end_block_statement,
      $.include_statement,
      $.import_statement,
      $.extends_statement,
      $.begin_macro_statement,
      $.end_macro_statement,
      $.generic_statement,
    ),
    comment: $ => seq(
      "{#", optional("-"), /[^#]+/, optional("-"), "#}"
    ),

    content: $ => /([^{]|[{][^{%#])+/,
  }
});
