/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// Operator precedence rules, from loosest to tightest, based on Tera's (v2) parser.
const PREC = {
	ternary: 1,
	or: 2,
	and: 3,
	not: 4,
	test: 5,
	compare: 6,
	add: 7,
	multiply: 8,
	power: 9,
	filter: 10,
	negate: 11,
	member: 12,
};

export default grammar({
	name: 'tera',

	externals: ($) => [$.frontmatter_delimiter, $.content, $.raw_content],

	// Following a branch's `%}`, `{%` either starts a nested tag or the next branch
	// (`{% elif %}`, `{% else %}`, `{% endif %}`), only the keyword itself can distinguish.
	conflicts: ($) => [[$.elif_clause], [$.else_clause]],

	rules: {
		source_file: ($) => seq(optional($.frontmatter), repeat($._template)),
		frontmatter: ($) =>
			seq(
				$.frontmatter_delimiter,
				repeat($._template),
				$.frontmatter_delimiter,
			),

		/* Primitives */
		bool: ($) => token(/[Tt]rue|[Ff]alse/),
		none: (_) => choice('none', 'None', 'null'),
		number: ($) => token(/[\+-]?[0-9]+(\.[0-9]+)?/),
		string: ($) =>
			choice(
				...["'", '"', '`'].map((quote) =>
					seq(
						quote,
						repeat(
							choice(
								token.immediate(prec(1, new RegExp(`[^${quote}\\\\]+`))),
								$.escape_sequence,
							),
						),
						token.immediate(quote),
					),
				),
			),
		escape_sequence: (_) => token.immediate(/\\./),
		_literal: ($) => choice($.bool, $.none, $.number, $.string),
		spread_element: ($) => seq('...', $._value),
		array: ($) =>
			seq('[', commaSep(choice($._value, $.spread_element)), ']'),
		list_comprehension: ($) =>
			seq(
				'[',
				field('body', $._value),
				'for',
				field('left', seq($.identifier, optional(seq(',', $.identifier)))),
				'in',
				field('right', $._value),
				optional(seq('if', field('condition', $._value))),
				']',
			),
		pair: ($) =>
			seq(field('key', $._literal), ':', field('value', $._value)),
		map: ($) => seq('{', commaSep(choice($.pair, $.spread_element)), '}'),
		identifier: ($) => /\w+/,

		/* Expressions */
		member_expression: ($) =>
			prec.left(
				PREC.member,
				seq(
					field('value', $._value),
					choice('.', '?.'),
					field('property', $.identifier),
				),
			),
		subscript_expression: ($) =>
			prec.left(
				PREC.member,
				seq(
					field('value', $._value),
					choice('[', '?['),
					field('index', choice($._value, $.slice)),
					']',
				),
			),
		slice: ($) =>
			seq(
				optional(field('start', $._value)),
				':',
				optional(field('stop', $._value)),
				optional(seq(':', optional(field('step', $._value)))),
			),
		parenthesized_expression: ($) => seq('(', $._value, ')'),
		binary_expression: ($) => {
			const exp = (op) =>
				seq(
					field('left', $._value),
					field('operator', op),
					field('right', $._value),
				);
			return choice(
				prec.right(PREC.power, exp('**')),
				...['*', '/', '//', '%', '~'].map((op) =>
					prec.left(PREC.multiply, exp(op)),
				),
				...['+', '-'].map((op) => prec.left(PREC.add, exp(op))),
				...['==', '!=', '<', '>', '<=', '>='].map((op) =>
					prec.left(PREC.compare, exp(op)),
				),
				...['in', seq('not', 'in')].map((op) =>
					prec.left(PREC.test, exp(op)),
				),
				prec.left(PREC.and, exp('and')),
				prec.left(PREC.or, exp('or')),
			);
		},
		ternary_expression: ($) =>
			prec.right(
				PREC.ternary,
				seq(
					field('consequence', $._value),
					'if',
					field('condition', $._value),
					'else',
					field('alternative', $._value),
				),
			),
		filter_expression: ($) =>
			prec.left(
				PREC.filter,
				seq(
					field('value', $._value),
					field('operator', '|'),
					field('filter', seq($.identifier)),
					optional(field('arguments', $.argument_list)),
				),
			),
		unary_expression: ($) =>
			choice(
				prec(PREC.negate, seq('-', $._value)),
				prec(PREC.not, seq('not', $._value)),
			),
		assignment_expression: ($) =>
			seq(
				field('left', $.identifier),
				field('operator', '='),
				field('right', $._value),
			),
		keyword_argument: ($) =>
			seq(field('name', $.identifier), '=', field('value', $._value)),
		// Tera only takes keyword arguments, except for tests in v1.
		argument_list: ($) =>
			seq('(', commaSep(choice($.keyword_argument, $._value)), ')'),
		call_expression: ($) =>
			seq(
				/* Optionally a function name can be preceded by a scope/namespace; from importing, or `self` for custom macros in the current file (v1). Global funtions can exist without a scope. */
				optional(seq(field('scope', $.identifier), '::')),
				field('name', $.identifier),
				field('arguments', $.argument_list),
			),
		test_expression: ($) =>
			prec.left(
				PREC.test,
				seq(
					field('value', $._value),
					'is',
					optional('not'),
					field('test', $.identifier),
					optional(field('arguments', $.argument_list)),
				),
			),

		/* Components */
		component_name: ($) => seq($.identifier, repeat(seq('.', $.identifier))),
		// `name="string"`, `name={expression}`, `name` (shorthand for `name={name}`), or `{...spread}`.
		component_attribute: ($) =>
			choice(
				seq(
					field('name', $.identifier),
					optional(
						seq(
							'=',
							choice(
								field('value', $.string),
								seq('{', field('value', $._value), '}'),
							),
						),
					),
				),
				seq('{', $.spread_element, '}'),
			),
		component_call: ($) =>
			seq(
				'<',
				field('name', $.component_name),
				repeat($.component_attribute),
				'/',
				'>',
			),

		// Something that can resolve to a value.
		_value: ($) =>
			choice(
				$.identifier,
				$.member_expression,
				$.subscript_expression,
				$.parenthesized_expression,

				$._literal,
				$.array,
				$.list_comprehension,
				$.map,
				$.binary_expression,
				$.unary_expression,
				$.ternary_expression,
				$.call_expression,
				$.filter_expression,
				$.test_expression,
				$.component_call,
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
		comment_tag: (_) => token(seq('{#', /[^#]*#+([^#}][^#]*#+)*/, '}')),

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
				$.set_block_statement,
				$.include_statement,
				$.import_statement,
				$.extends_statement,
				$.macro_statement,
				$.component_statement,
				$.component_block,
				$.filter_statement,
				$.block_statement,
				$.raw_statement,
			),

		if_statement: ($) =>
			seq(
				statement(seq('if', field('condition', $._value))),
				field('consequence', repeat($._template)),
				optional(field('alternative', repeat($.elif_clause))),
				optional(field('alternative', $.else_clause)),
				statement('endif'),
			),
		elif_clause: ($) =>
			seq(
				statement(field('condition', seq('elif', $._value))),
				field('consequence', repeat($._template)),
			),
		else_clause: ($) =>
			seq(
				statement('else'),
				field('consequence', repeat($._template)),
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
		// A filter applied to a section or `set` block's body, without a value.
		filter_call: ($) =>
			seq(
				field('name', $.identifier),
				optional(field('arguments', $.argument_list)),
			),
		set_block_statement: ($) =>
			seq(
				statement(
					seq(
						choice('set', 'set_global'),
						field('name', $.identifier),
						repeat(seq('|', field('filter', $.filter_call))),
					),
				),
				field('body', repeat($._template)),
				statement('endset'),
			),
		include_statement: ($) =>
			statement(
				seq(
					'include',
					choice($.string, $.array),
					optional(seq('ignore', 'missing')),
				),
			),
		import_statement: ($) =>
			statement(
				seq('import', $.string, 'as', field('scope', $.identifier)),
			),
		extends_statement: ($) => statement(seq('extends', $.string)),
		optional_parameter: ($) =>
			seq(field('name', $.identifier), '=', field('value', $._literal)),
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
				field('body', repeat($._template)),
				statement(seq('endmacro', optional($.identifier))),
			),
		// `name: type = default`, `@name` (implicit, read from the caller's context) or `...rest`.
		component_parameter: ($) =>
			choice(
				seq(
					optional('@'),
					field('name', $.identifier),
					optional(seq(':', field('type', $.identifier))),
					optional(
						seq('=', field('default', choice($._literal, $.array, $.map))),
					),
				),
				seq('...', field('name', $.identifier)),
			),
		component_parameters: ($) =>
			seq('(', commaSep($.component_parameter), ')'),
		component_statement: ($) =>
			seq(
				statement(
					seq(
						'component',
						field('name', $.component_name),
						field('parameters', $.component_parameters),
						optional(field('metadata', $.map)),
					),
				),
				field('body', repeat($._template)),
				statement(seq('endcomponent', optional($.component_name))),
			),
		// A component call with a body: `{% <name attr="x"> %}...{% </name> %}`.
		component_block: ($) =>
			seq(
				statement(
					seq(
						'<',
						field('name', $.component_name),
						repeat($.component_attribute),
						'>',
					),
				),
				field('body', repeat($._template)),
				statement(seq('</', $.component_name, '>')),
			),
		filter_statement: ($) =>
			seq(
				statement(
					seq(
						'filter',
						field('filter', $.filter_call),
						repeat(seq('|', field('filter', $.filter_call))),
					),
				),
				repeat($._template),
				statement('endfilter'),
			),
		block_statement: ($) =>
			seq(
				statement(seq('block', $.identifier)),
				repeat($._template),
				statement(seq('endblock', optional($.identifier))),
			),
		raw_statement: ($) =>
			seq(
				statement('raw'),
				optional(field('body', $.raw_content)),
				statement('endraw'),
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
