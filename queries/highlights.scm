; Variables
;----------

(identifier) @variable

; Properties
;-----------

(property_identifier) @property

; Literals
;-----------

(string) @string

(bool) @constant.builtin

(number) @constant.numeric

; Tokens
;-----------

[
  "."
  ","
] @punctuation.delimiter

[
  "*"
  "/"
  "%"
  "|"
  "+"
  "-"
  "~"
  "="
  "=="
  "!="
  "<"
  ">"
  "<="
  ">="
] @operator

[
  "("
  ")"
  "["
  "]"
  "{%"
  "%}"
  "}}"
  "{{"
  "::"
] @punctuation.bracket

; Tags
;-----------

(comment_tag) @comment

; Keywords
;-----------

[
  "if"
  "elif"
  "else"
  "endif"
] @keyword.control.conditional

[
  "for"
  "endfor"
] @keyword.control.repeat

[
  "include"
  "import"
  "extends"
] @keyword.control.import

[
  "in"
  "and"
  "or"
  "not"
  "is"
] @keyword.operator

[
  "break"
  "continue"
] @keyword.control.return

[
  "set"
  "set_global"
  "filter"
  "endfilter"
  "block"
  "endblock"
  "macro"
  "endmacro"
] @keyword

(macro_statement
  name: (identifier) @function
  parameter: (identifier) @variable.parameter)

(call_expression
  scope: (identifier) @namespace
  name: (identifier) @function)

(import_statement
  scope: (identifier) @namespace)

(binary_expression
  operator: "|"
  right: (identifier) @function.method)
