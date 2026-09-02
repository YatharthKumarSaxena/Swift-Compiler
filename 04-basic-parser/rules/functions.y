function:
      FUNC IDENTIFIER '(' parameters ')' ARROW TYPE '{' statements '}'
    | FUNC IDENTIFIER '(' parameters ')' '{' statements '}'
;

parameters:
      required_parameters
    | required_parameters ',' default_parameters
    | default_parameters
;

required_parameters:
      parameter
    | required_parameters ',' parameter
;

default_parameters:
      default_parameter
    | default_parameters ',' default_parameter
;

parameter:
      IDENTIFIER ':' TYPE
;

default_parameter:
      IDENTIFIER ':' TYPE ASSIGN expression
;

function_call:
      IDENTIFIER '(' arguments ')'
;