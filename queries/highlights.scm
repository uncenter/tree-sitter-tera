; Syntax highlighting scopes for Helix: https://docs.helix-editor.com/themes.html.

; Variables
;----------

(identifier) @variable

; Properties
;-----------

(member_expression
  property: (identifier) @property)

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

; Functions

(macro_statement
  name: (identifier) @function
  (parameter_list
    parameter: (identifier) @variable.parameter
    (optional_parameter
      name: (identifier) @variable.parameter)))

(call_expression
  scope: (identifier)? @namespace
  name: (identifier) @function)

(filter_expression
  filter: (identifier) @function.method)

; Namespaces

(import_statement
  scope: (identifier) @namespace)

