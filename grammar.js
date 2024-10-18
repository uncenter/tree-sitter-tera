/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "tera",

  rules: {
    source_file: $ => repeat($._template),

    bool: $ => token(/[Tt]rue|[Ff]alse/),
    number: $ => token(/[\+-]?[0-9]+(\.[0-9]+)?/),
    string: $ => choice(
        seq("'", repeat(/[^']/), "'"),
        seq('"', repeat(/[^"]/), '"'),
        seq('`', repeat(/[`"]/), '`')
      ),
    literal: $ => choice($.bool, $.number, $.string),
    array: $ => seq("[", repeat(seq($._expr, optional(","))), "]"),
    value: $ => choice($.literal, $.array),
    identifier: $ => /\w+/,
    
    member_expression: $ => seq($.identifier, repeat1(seq(".", alias($.identifier, $.property_identifier)))),
    binary_expression: $ => {
      const exp = (op) => seq(field('left', $._expr), field('operator', op), field('right', $._expr));
      return choice(
        ...['*', '/', '%', "|"].map(op => prec.left(2, exp(op))),
        ...['+', '-', '~'].map(op => prec.left(1, exp(op))),
        ...["==", "!=", "<", ">", "<=", ">=", 'in', 'and', 'or', 'is'].map(op => prec.left(exp(op)))
      );
    },
    unary_expression: $ => prec(3, choice(
      seq('-', $._expr),
      seq("not", $._expr)
    )),
    assignment_expression: $ => seq(choice($.identifier, $.member_expression), "=", $._expr),
    call_expression: $ => seq(
      choice(field('name', $.identifier), seq(field('scope', $.identifier), "::", field('name', $.identifier))),
      "(", field('arguments', repeat(seq($.identifier, "=", $.value, optional(",")))), ")"
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

    if_statement: $ => seq(
      statement(seq("if", $._expr)),
      choice(repeat($._template), statement("else"), statement(seq("elif", $._expr))),
      statement("endif")
    ),
    for_statement: $ => seq(
      statement(seq(
        "for",
        $.identifier, optional(seq(",", $.identifier)),
        "in",
        $._expr,
      )),
      choice(repeat($._template), statement("break"), statement("continue")),
      statement(
        "endfor"
      )
    ),
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
    macro_statement: $ => seq(
      statement(seq(
       "macro", field('name', $.identifier),
       "(",
       field('arguments', repeat(seq($.identifier, optional(seq("=", $.literal)), optional(",")))),
        ")"
      )),
      repeat($._template),
      statement(seq("endmacro", $.identifier))
    ),
    filter_statement: $ => seq(
      statement(seq(
        "filter", $.identifier
      )),
      repeat($._template),
      statement("endfilter")
    ),
    block_statement: $ => seq(
      statement(seq(
        "block", $.identifier
      )),
      repeat($._template),
      statement(seq("endblock", $.identifier))
    ),
    _statement_tag: $ => choice(
      $.if_statement,
      $.for_statement,
      $.set_statement,
      $.include_statement,
      $.import_statement,
      $.extends_statement,
      $.macro_statement,
      $.filter_statement,
      $.block_statement
    ),
    comment_tag: $ => seq(
      "{#", optional("-"), /[^#]+/, optional("-"), "#}"
    ),

    content: $ => /([^{]|[{][^{%#])+/,
    _template: $ => choice(
      $._statement_tag,
      $.expression_tag,
      $.comment_tag,
      $.content
    ),
  }
});

function statement(inner) {
  return seq("{%", optional("-"), inner, optional("-"), "%}");
}
