/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
	name: 'tera',

	externals: $ => [$.content],

	rules: {
		source_file: ($) => repeat($._template),

		/* Primitives */
		bool: ($) => token(/[Tt]rue|[Ff]alse/),
		number: ($) => token(/[\+-]?[0-9]+(\.[0-9]+)?/),
		string: ($) =>
			choice(
				seq("'", repeat(/[^']/), "'"),
				seq('"', repeat(/[^"]/), '"'),
				seq('`', repeat(/[^`]/), '`'),
			),
		_literal: ($) => choice($.bool, $.number, $.string),
		array: ($) => seq('[', commaSep($._value), ']'),
		identifier: ($) => /\w+/,

		/* Expressions */
		member_expression: ($) => prec.left(
			seq(
				field('value', choice($.parenthesized_expression, $.member_expression, $.identifier, $.array, $.call_expression)),
				repeat1(choice(seq('.', field('property', $.identifier)), seq('[', field('index', $._value), ']'))),
			)),
		parenthesized_expression: $ => seq('(', $._value, ')'),
		binary_expression: ($) => {
			const exp = (op) =>
				seq(
					field('left', $._value),
					field('operator', op),
					field('right', $._value),
				);
			return choice(
				...['*', '/', '%'].map((op) => prec.left(2, exp(op))),
				...['+', '-', '~'].map((op) => prec.left(1, exp(op))),
				...[
					'==',
					'!=',
					'<',
					'>',
					'<=',
					'>=',
					'in',
					'and',
					'or',
					'is',
				].map((op) => prec.left(exp(op))),
			);
		},
		filter_expression: $ => prec.left(2, seq(field('value', $._value), field('operator', '|'), field('filter', seq($.identifier)), optional(field('arguments', $.argument_list)))),
		unary_expression: ($) =>
			prec(3, choice(seq('-', $._value), seq('not', $._value))),
		assignment_expression: ($) =>
			seq(
				field('left', choice($.identifier, $.member_expression)),
				field('operator', '='),
				field('right', $._value),
			),
		keyword_argument: ($) =>
			seq(field('name', $.identifier), '=', field('value', $._value)),
		argument_list: ($) =>
			seq('(', commaSep(choice($.keyword_argument, $._value)), ')'),
		call_expression: ($) =>
			seq(
				/* Optionally a function name can be preceded by a scope/namespace; from importing, or `self` for custom macros in the current file. */
				optional(seq(field('scope', $.identifier), '::')),
				field('name', $.identifier),
				field('arguments', $.argument_list),
			),

		// Something that can resolve to a value.
		_value: ($) =>
				choice(
					$.identifier,
					$.member_expression,
					$.parenthesized_expression,

					$._literal,
					$.array,
					$.binary_expression,
					$.unary_expression,
					$.call_expression,
					$.filter_expression,
				),

		/* Tags */
		_template: ($) =>
			choice(
				$._statement_tag,
				$.expression_tag,
				$.comment_tag,
				$.content,
			),

		// Comment
		comment_tag: ($) =>
			seq(choice('{#', '{#-'), /[^#]+/, choice('#}', '-#}')),

		// Expression
		expression_tag: ($) =>
			seq(choice('{{', '{{-'), $._value, choice('}}', '-}}')),

		// Statements
		_statement_tag: ($) =>
			choice(
				$.if_statement,
				$.for_statement,
				$.for_break_statement,
				$.for_continue_statement,
				$.set_statement,
				$.include_statement,
				$.import_statement,
				$.extends_statement,
				$.macro_statement,
				$.filter_statement,
				$.block_statement,
			),

		if_statement: ($) =>
			seq(
				statement(field('condition', seq('if', $._value))),
				field('consequence', repeat($._template)),
				optional(field('alternative', repeat($.elif_clause))),
				optional(field('alternative', $.else_clause)),
				statement('endif'),
			),
		elif_clause: ($) =>
			prec.right(
				1,
				seq(
					statement(field('condition', seq('elif', $._value))),
					field('consequence', repeat($._template)),
				),
			),
		else_clause: ($) =>
			prec.right(
				1,
				seq(
					statement('else'),
					field('consequence', repeat($._template)),
				),
			),
		for_statement: ($) =>
			seq(
				statement(
					seq(
						'for',
						field(
							'left',
							seq($.identifier, optional(seq(',', $.identifier))),
						),
						'in',
						field('right', $._value),
					),
				),
				field('body', repeat($._template)),
				optional(field('alternative', $.else_clause)),
				statement('endfor'),
			),
		// Can't only put inside break & continue statements in `for_statement`, as `if_statement`s within `for_statement`s can contain them.
		for_break_statement: ($) => statement('break'),
		for_continue_statement: ($) => statement('continue'),
		set_statement: ($) =>
			statement(
				seq(choice('set', 'set_global'), $.assignment_expression),
			),
		include_statement: ($) =>
			statement(
				seq(
					'include',
					choice($.string, $.array),
					optional('ignore missing'),
				),
			),
		import_statement: ($) =>
			statement(
				seq('import', $.string, 'as', field('scope', $.identifier)),
			),
		extends_statement: ($) => statement(seq('extends', $.string)),
		optional_parameter: ($) =>
			seq(
				field('name', $.identifier),
				'=',
				field('value', $._literal),
			),
		parameter_list: ($) =>
			seq(
				'(',
				commaSep(
					choice(
						field('parameter', $.identifier),
						$.optional_parameter,
					),
				),
				')',
			),
		macro_statement: ($) =>
			seq(
				statement(
					seq(
						'macro',
						field('name', $.identifier),
						field('parameters', $.parameter_list),
					),
				),
				repeat($._template),
				statement(seq('endmacro', optional($.identifier))),
			),
		filter_statement: ($) =>
			seq(
				statement(seq('filter', $.identifier)),
				repeat($._template),
				statement('endfilter'),
			),
		block_statement: ($) =>
			seq(
				statement(seq('block', $.identifier)),
				repeat($._template),
				statement(seq('endblock', $.identifier)),
			),
	},
});

// Helper function to create statements ({% ... %}) without repeating the brackets and the optional whitespace trimming parts.
function statement(inner) {
	return seq(choice('{%', '{%-'), inner, choice('%}', '-%}'));
}

function commaSep(rule) {
	return optional(seq(rule, repeat(seq(',', rule)), optional(',')));
}
