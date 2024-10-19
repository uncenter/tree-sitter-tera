(macro_statement) @local.scope

(macro_statement
  parameter: (identifier) @local.definition)

(assignment_expression
   left: (identifier) @local.definition)

(identifier) @local.reference
