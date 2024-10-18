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

(number) @number

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
]  @punctuation.bracket

; Tags
;-----------

(comment_tag) @comment

; Keywords
;-----------

[
  "in"
  "and"
  "or"
  "not"
  "is"

  "if"
  "elif"
  "else"
  "endif"
  "endfor"
  "endfilter"
  "break"
  "continue"
  "for"
  "in"
  "set"
  "set_global"
  "include"
  "import"
  "extends"
  "filter"
  "block"
  "endblock"
  "macro"
  "endmacro"
] @keyword

((identifier) @variable.builtin
 (#match? @variable.builtin "^(loop)$")
 (#is-not? local))

; ((identifier) @function.builtin
;  (#eq? @function.builtin "")
;  (#is-not? local))
