(macro_statement) @local.scope

(macro_statement
  (parameter_list
    (identifier) @local.definition))

(component_statement) @local.scope

(component_parameter
  name: (identifier) @local.definition)

(list_comprehension) @local.scope

(list_comprehension
  left: (identifier) @local.definition)

(set_block_statement
  name: (identifier) @local.definition)

(assignment_expression
   left: (identifier) @local.definition)

(identifier) @local.reference
