/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "tera",

  rules: {
    source_file: $ => repeat(
      choice(
        $.expression_tag,
        $.statement_tag,
        $.comment_tag,
        $.content
      )
    ),

    bool: $ => token(/[Tt]rue|[Ff]alse/),
    number: $ => token(/[\+-]?[0-9]+(\.[0-9]+)?/),
    string: $ => choice(
        seq("'", repeat(/[^']/), "'"),
        seq('"', repeat(/[^"]/), '"'),
        seq('`', repeat(/[`"]/), '`')
      ),
    literal: $ => choice($.bool, $.number, $.string),
    array: $ => seq("[", repeat(seq($.literal, optional(","))), "]"),
    value: $ => choice($.literal, $.array),
    identifier: $ => /\w+/,
    
    member_expression: $ => seq($.identifier, repeat1(seq(".", alias($.identifier, $.property_identifier)))),
    binary_expression: $ => choice(
      ...['*', '/', '%', "|"].map(op => prec.left(2, seq($._expr, op, $._expr))),
      ...['+', '-', '~'].map(op => prec.left(1, seq($._expr, op, $._expr))),
      ...["==", "!=", "<", ">", "<=", ">=", 'in', 'and', 'or', 'is'].map(op => prec.left(seq($._expr, field('operator', op), $._expr)))
    ),
    unary_expression: $ => prec(3, choice(
      seq('-', $._expr),
      seq("not", $._expr)
    )),
    assignment_expression: $ => seq(choice($.identifier, $.member_expression), "=", $._expr),
    call_expression: $ => seq(
      choice($.identifier, seq($.identifier, "::", $.identifier)),
      "(", repeat(seq($.identifier, "=", $.value, optional(","))), ")"
    ),
    _expr: $ => seq(choice(
      $.identifier,
      $.member_expression,

      $.literal,
      $.array,
      $.binary_expression,
      $.unary_expression,
      $.call_expression
    )),

    expression_tag: $ => seq(
      "{{", optional("-"), $._expr, optional("-"), "}}"
    ),
    begin_if_statement: $ => statement(seq("if", $._expr)),
    begin_for_statement: $ => statement(seq(
      "for",
      $.identifier, optional(seq(",", $.identifier)),
      "in",
      $._expr,
    )),
    set_statement: $ => statement(seq(
      choice("set", "set_global"), $.assignment_expression
    )),
    include_statement: $ => statement(seq(
     "include", choice($.string, $.array), optional("ignore missing")
    )),
    import_statement: $ => statement(seq(
      "import", $.string, "as", $.identifier
    )),
    extends_statement: $ => statement(seq(
      "extends", $.string
    )),
    begin_macro_statement: $ => statement(seq(
     "macro", $.identifier,
     "(",
     repeat(seq($.identifier, optional(seq("=", $.literal)), optional(","))),
      ")"
    )),
    generic_named_statement: $ => statement(seq(choice("filter", "block", "endblock", "endmacro"), $.identifier)),
    generic_statement: $ => seq("{%", optional("-"), choice("elif", "else", "endif", "endfor", "endfilter", "break", "continue"), optional("-"), "%}"),
    statement_tag: $ => choice(
      $.begin_if_statement,
      $.begin_for_statement,
      $.set_statement,
      $.include_statement,
      $.import_statement,
      $.extends_statement,
      $.begin_macro_statement,
      $.generic_named_statement,
      $.generic_statement,
    ),
    comment_tag: $ => seq(
      "{#", optional("-"), /[^#]+/, optional("-"), "#}"
    ),

    content: $ => /([^{]|[{][^{%#])+/,
  }
});

function statement(inner) {
  return seq("{%", optional("-"), inner, optional("-"), "%}");
}
