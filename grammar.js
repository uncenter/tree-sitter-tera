/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
	name: 'tera',

	rules: {
		source_file: ($) => repeat($._template),
		content: ($) => /([^{]|[{][^{%#])+/,

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
		array: ($) => seq('[', repeat(seq($._value, optional(','))), ']'),
		identifier: ($) => /\w+/,

		/* Expressions */
		member_expression: ($) =>
			seq(
				$.identifier,
				repeat1(seq('.', alias($.identifier, $.property_identifier))),
			),
		binary_expression: ($) => {
			const exp = (op) =>
				seq(
					field('left', $._value),
					field('operator', op),
					field('right', $._value),
				);
			return choice(
				...['*', '/', '%', '|'].map((op) => prec.left(2, exp(op))),
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
		unary_expression: ($) =>
			prec(3, choice(seq('-', $._value), seq('not', $._value))),
		assignment_expression: ($) =>
			seq(
				field('left', choice($.identifier, $.member_expression)),
				field('operator', '='),
				field('right', $._value),
			),
		call_expression: ($) =>
			seq(
				/* Optionally a function name can be preceded by a scope/namespace; from importing, or `self` for custom macros in the current file. */
				optional(seq(field('scope', $.identifier), '::')),
				field('name', $.identifier),
				'(',
				repeat(
					// Kwarg sequence (var=) is optional since built-in tests *do* accept positional arguments, unlike macros/user-defined functions.
					seq(optional(seq($.identifier, '=')), $._value, optional(','))
				),
				')',
			),

		// Something that can resolve to a value.
		_value: ($) =>
			seq(
				choice(
					$.identifier,
					$.member_expression,

					$._literal,
					$.array,
					$.binary_expression,
					$.unary_expression,
					$.call_expression,
				),
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
			seq('{#', optional('-'), /[^#]+/, optional('-'), '#}'),

		// Expression
		expression_tag: ($) =>
			seq('{{', optional('-'), $._value, optional('-'), '}}'),

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
		macro_statement: ($) =>
			seq(
				statement(
					seq(
						'macro',
						field('name', $.identifier),
						'(',
						repeat(
							seq(
								field('parameter', $.identifier),
								optional(seq('=', $._literal)),
								optional(','),
							),
						),
						')',
					),
				),
				repeat($._template),
				statement(seq('endmacro', $.identifier)),
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
	return seq('{%', optional('-'), inner, optional('-'), '%}');
}
