/* expression.y */

%left LOGICAL_OR
%left LOGICAL_AND
%left EQ NE GT LT GTE LTE
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right LOGICAL_NOT

expression:
      value
    | array_access
    | field_access
    | expression PLUS expression
    | expression MINUS expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | expression MODULO expression
    | expression EQ expression
    | expression NE expression
    | expression GT expression
    | expression LT expression
    | expression GTE expression
    | expression LTE expression
    | expression LOGICAL_AND expression
    | expression LOGICAL_OR expression
    | LOGICAL_NOT expression
    | '(' expression ')'
;

array_access:
      IDENTIFIER '[' expression ']'
;

field_access:
      IDENTIFIER '.' IDENTIFIER
;