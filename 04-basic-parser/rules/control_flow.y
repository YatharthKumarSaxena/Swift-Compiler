if_statement:
      IF expression '{' statements '}'
    | IF expression '{' statements '}' ELSE '{' statements '}'
;

switch_statement:
      SWITCH expression '{' cases '}'
;

cases:
      case
    | cases case
;

case:
      CASE expression ':' statements
    | DEFAULT ':' statements
;