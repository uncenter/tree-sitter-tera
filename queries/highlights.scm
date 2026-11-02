; Variables
;----------

(identifier) @variable

((identifier) @variable.builtin
  (#any-of? @variable.builtin
    "loop"
    "__tera_context"))

; Properties
;-----------

(member_expression
  property: (identifier)? @variable.other.member)

; Literals
;-----------

(string) @string
(escape_sequence) @constant.character.escape

(bool) @constant.builtin
(none) @constant.builtin

(number) @constant.numeric

; Tokens
;-----------

[
  "."
  ","
  ":"
] @punctuation.delimiter

[
  "*"
  "**"
  "/"
  "//"
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
  "?."
  "..."
] @operator

[
  "("
  ")"
  "["
  "?["
  "]"
  "{"
  "}"
  "{%"
  "%}"
  "-%}"
  "{%-"
  "}}"
  "{{"
  "-}}"
  "{{-"
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
  "endset"
  "filter"
  "endfilter"
  "block"
  "endblock"
  "macro"
  "endmacro"
  "component"
  "endcomponent"
  "raw"
  "endraw"
  "as"
] @keyword

; Functions
;-----------

(macro_statement
  name: (identifier) @function
  (parameter_list
    parameter: (identifier) @variable.parameter
    (optional_parameter
      name: (identifier) @variable.parameter)))

(call_expression
  scope: (identifier)? @namespace
  name: (identifier) @function)

(call_expression
  name: (identifier) @function.builtin
  (#any-of? @function.builtin
    ; Functions - https://keats.github.io/tera/docs/#built-in-functions
    "range"
    "now"
    "throw"
    "get_random"
    "get_env"))

; Components
;-----------

(component_call
  [
    "<"
    "/"
    ">"
  ] @punctuation.bracket)

(component_block
  [
    "<"
    "</"
    ">"
  ] @punctuation.bracket)

(component_call
  name: (component_name
    (identifier) @tag))

(component_block
  (component_name
    (identifier) @tag))

(component_statement
  (component_name
    (identifier) @function))

(component_attribute
  name: (identifier) @attribute)

(component_parameter
  name: (identifier) @variable.parameter)

(component_parameter
  type: (identifier) @type)

"@" @punctuation.special

(test_expression
  test: (identifier) @function)

(test_expression
  test: (identifier) @function.builtin
  (#any-of? @function.builtin
    ; Tests - https://keats.github.io/tera/docs/#built-in-tests
    ; v2: https://github.com/Keats/tera/blob/master/tera/src/tera.rs
    "defined"
    "undefined"
    "odd"
    "even"
    "string"
    "number"
    "integer"
    "float"
    "bool"
    "none"
    "array"
    "map"
    "divisible_by"
    "divisibleby"
    "iterable"
    "object"
    "starting_with"
    "ending_with"
    "containing"
    "matching"))

(filter_expression
  filter: (identifier) @function.method)

(filter_call
  name: (identifier) @function.method)

([
  (filter_expression
    filter: (identifier) @function.builtin)
  (filter_call
    name: (identifier) @function.builtin)
]
  (#any-of? @function.builtin
    ; Filters - https://keats.github.io/tera/docs/#built-in-filters
    ; v2 and tera-contrib: https://github.com/Keats/tera/blob/master/tera/src/tera.rs
    "str"
    "escape_html"
    "newlines_to_br"
    "keys"
    "values"
    "pairs"
    "filesize_format"
    "slug"
    "format"
    "regex_replace"
    "b64_encode"
    "b64_decode"
    "shuffle"
    "lower"
    "upper"
    "wordcount"
    "capitalize"
    "replace"
    "addslashes"
    "slugify"
    "title"
    "trim"
    "trim_start"
    "trim_end"
    "trim_start_matches"
    "trim_end_matches"
    "truncate"
    "linebreaksbr"
    "spaceless"
    "indent"
    "striptags"
    "first"
    "last"
    "nth"
    "join"
    "length"
    "reverse"
    "sort"
    "unique"
    "slice"
    "group_by"
    "filter"
    "map"
    "concat"
    "urlencode"
    "urlencode_strict"
    "abs"
    "pluralize"
    "round"
    "filesizeformat"
    "date"
    "escape"
    "escape_xml"
    "safe"
    "get"
    "split"
    "int"
    "float"
    "json_encode"
    "as_str"
    "default"))

; Namespaces
;-----------

(import_statement
  scope: (identifier) @namespace)

