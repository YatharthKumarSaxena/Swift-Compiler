%{
    #include <stdio.h>

    int yylex();
    int yyerror(const char *s);
%}

%token INTEGER_LITERAL    256
%token STRING_LITERAL     257
%token DOUBLE_LITERAL     258
%token BOOLEAN_LITERAL    259
%token CHARACTER_LITERAL  260

%token IDENTIFIER         261
%token TYPE               262
%token KEYWORD            263

%token EQ                 264
%token NE                 265
%token GT                 266
%token LT                 267
%token GTE                268
%token LTE                269

%token AND                270
%token OR                 271

value: 
    INTEGER_LITERAL
  | STRING_LITERAL
  | BOOLEAN_LITERAL
  | DOUBLE_LITERAL
  | CHARACTER_LITERAL
  | IDENTIFIER
;
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
array_elements:
      expression
    | array_elements ',' expression
;

array:
      '[' array_elements ']'
;

array_assignment:
      array_access ASSIGN expression
;
struct_declaration:
      STRUCT IDENTIFIER '{' struct_members '}'
;

struct_members:
      struct_member
    | struct_members struct_member
;

struct_member:
      VAR IDENTIFIER ':' TYPE
    | LET IDENTIFIER ':' TYPE
;

struct_initialization:
      IDENTIFIER '(' arguments ')'
;

arguments:
      argument
    | arguments ',' argument
;

argument:
      IDENTIFIER ':' expression
    | expression
;
declaration:
      LET IDENTIFIER ASSIGN expression
    | VAR IDENTIFIER ASSIGN expression
    | LET IDENTIFIER ':' TYPE ASSIGN expression
    | VAR IDENTIFIER ':' TYPE ASSIGN expression

    | LET IDENTIFIER ASSIGN array
    | VAR IDENTIFIER ASSIGN array
    | LET IDENTIFIER ':' TYPE ASSIGN array
    | VAR IDENTIFIER ':' TYPE ASSIGN array

    | LET IDENTIFIER ASSIGN struct_initialization
    | VAR IDENTIFIER ASSIGN struct_initialization
    | LET IDENTIFIER ':' TYPE ASSIGN struct_initialization
    | VAR IDENTIFIER ':' TYPE ASSIGN struct_initialization

    | LET IDENTIFIER ASSIGN function_call
    | VAR IDENTIFIER ASSIGN function_call
    | LET IDENTIFIER ':' TYPE ASSIGN function_call
    | VAR IDENTIFIER ':' TYPE ASSIGN function_call
;
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
while_statement:
      WHILE expression '{' statements '}'
;

repeat_while_statement:
      REPEAT '{' statements '}' WHILE expression
;

for_in_statement:
      FOR IDENTIFIER IN expression '{' statements '}'
;
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
statement:
      declaration
    | assignment
    | array_assignment
    | function_call
    | return_statement
    | expression
    | if_statement
    | switch_statement
    | while_statement
    | repeat_while_statement
    | for_in_statement
;
program: expression

/* declaration-errors.y */

declaration_error:
      LET
      {
          printf("Parser Error: Missing identifier after 'let'.\n");
      }
    | VAR
      {
          printf("Parser Error: Missing identifier after 'var'.\n");
      }
    | LET IDENTIFIER
      {
          printf("Parser Error: Missing '=' or type annotation in declaration.\n");
      }
    | VAR IDENTIFIER
      {
          printf("Parser Error: Missing '=' or type annotation in declaration.\n");
      }
    | LET IDENTIFIER ASSIGN
      {
          printf("Parser Error: Missing expression in 'let' declaration.\n");
      }
    | VAR IDENTIFIER ASSIGN
      {
          printf("Parser Error: Missing expression in 'var' declaration.\n");
      }
    | LET IDENTIFIER ':' 
      {
          printf("Parser Error: Missing type after ':'.\n");
      }
    | VAR IDENTIFIER ':'
      {
          printf("Parser Error: Missing type after ':'.\n");
      }
;
/* expression-errors.y */

expression_error:
      expression PLUS
      {
          printf("Parser Error: Missing expression after '+'.\n");
      }
    | expression MINUS
      {
          printf("Parser Error: Missing expression after '-'.\n");
      }
    | expression MULTIPLY
      {
          printf("Parser Error: Missing expression after '*'.\n");
      }
    | expression DIVIDE
      {
          printf("Parser Error: Missing expression after '/'.\n");
      }
    | expression MODULO
      {
          printf("Parser Error: Missing expression after '%%'.\n");
      }
    | expression EQ
      {
          printf("Parser Error: Missing expression after '=='.\n");
      }
    | expression NE
      {
          printf("Parser Error: Missing expression after '!='.\n");
      }
    | expression GT
      {
          printf("Parser Error: Missing expression after '>'.\n");
      }
    | expression LT
      {
          printf("Parser Error: Missing expression after '<'.\n");
      }
    | expression GTE
      {
          printf("Parser Error: Missing expression after '>='.\n");
      }
    | expression LTE
      {
          printf("Parser Error: Missing expression after '<='.\n");
      }
    | expression LOGICAL_AND
      {
          printf("Parser Error: Missing expression after '&&'.\n");
      }
    | expression LOGICAL_OR
      {
          printf("Parser Error: Missing expression after '||'.\n");
      }
    | LOGICAL_NOT
      {
          printf("Parser Error: Missing expression after '!'.\n");
      }
;
/* control-flow-errors.y */

if_error:
      IF
      {
          printf("Parser Error: Missing condition after 'if'.\n");
      }
    | IF expression
      {
          printf("Parser Error: Missing '{' after if condition.\n");
      }
    | IF expression '{' statements
      {
          printf("Parser Error: Missing '}' in if statement.\n");
      }
;

switch_error:
      SWITCH
      {
          printf("Parser Error: Missing expression after 'switch'.\n");
      }
    | SWITCH expression
      {
          printf("Parser Error: Missing '{' after switch expression.\n");
      }
    | SWITCH expression '{'
      {
          printf("Parser Error: Switch statement must contain a case or default.\n");
      }
;
/* loop-errors.y */

while_error:
      WHILE
      {
          printf("Parser Error: Missing condition after 'while'.\n");
      }
    | WHILE expression
      {
          printf("Parser Error: Missing '{' after while condition.\n");
      }
    | WHILE expression '{' statements
      {
          printf("Parser Error: Missing '}' in while statement.\n");
      }
;

for_in_error:
      FOR
      {
          printf("Parser Error: Missing loop variable after 'for'.\n");
      }
    | FOR IDENTIFIER
      {
          printf("Parser Error: Missing 'in' after loop variable.\n");
      }
    | FOR IDENTIFIER IN
      {
          printf("Parser Error: Missing sequence expression after 'in'.\n");
      }
    | FOR IDENTIFIER IN expression
      {
          printf("Parser Error: Missing '{' after for-in expression.\n");
      }
    | FOR IDENTIFIER IN expression '{' statements
      {
          printf("Parser Error: Missing '}' in for-in statement.\n");
      }
;

repeat_while_error:
      REPEAT
      {
          printf("Parser Error: Missing '{' after 'repeat'.\n");
      }
    | REPEAT '{' statements '}'
      {
          printf("Parser Error: Missing 'while' after repeat block.\n");
      }
    | REPEAT '{' statements '}' WHILE
      {
          printf("Parser Error: Missing condition after 'while'.\n");
      }
;
/* function-errors.y */

function_error:
      FUNC
      {
          printf("Parser Error: Missing function name after 'func'.\n");
      }
    | FUNC IDENTIFIER
      {
          printf("Parser Error: Missing '(' after function name.\n");
      }
    | FUNC IDENTIFIER '('
      {
          printf("Parser Error: Missing ')' in function parameter list.\n");
      }
    | FUNC IDENTIFIER '(' parameters
      {
          printf("Parser Error: Missing ')' after function parameters.\n");
      }
    | FUNC IDENTIFIER '(' parameters ')' ARROW
      {
          printf("Parser Error: Missing return type after '->'.\n");
      }
    | FUNC IDENTIFIER '(' parameters ')' '{'
      {
          printf("Parser Error: Missing '}' at end of function body.\n");
      }
;

function_call_error:
      IDENTIFIER '('
      {
          printf("Parser Error: Missing argument or ')' in function call.\n");
      }
    | IDENTIFIER '(' arguments
      {
          printf("Parser Error: Missing ')' after function arguments.\n");
      }
;
array_error:
      '[' ']'
      {
          printf("Parser Error: Empty array is not allowed.\n");
      }
    | '[' array_elements
      {
          printf("Parser Error: Missing closing ']' in array.\n");
      }
    | '[' expression expression ']'
      {
          printf("Parser Error: Missing ',' between array elements.\n");
      }
    | '[' array_elements ','
      {
          printf("Parser Error: Trailing ',' in array.\n");
      }
;

array_access_error:
      IDENTIFIER '[' ']'
      {
          printf("Parser Error: Array index is missing.\n");
      }
    | IDENTIFIER '[' expression
      {
          printf("Parser Error: Missing closing ']' in array access.\n");
      }
;
/* struct-errors.y */

struct_error:
      STRUCT
      {
          printf("Parser Error: Missing struct name after 'struct'.\n");
      }
    | STRUCT IDENTIFIER
      {
          printf("Parser Error: Missing '{' after struct name.\n");
      }
    | STRUCT IDENTIFIER '{'
      {
          printf("Parser Error: Struct must contain members.\n");
      }
    | STRUCT IDENTIFIER '{' struct_members
      {
          printf("Parser Error: Missing '}' at end of struct.\n");
      }
;

struct_member_error:
      VAR IDENTIFIER
      {
          printf("Parser Error: Missing ':' and type in struct member.\n");
      }
    | LET IDENTIFIER
      {
          printf("Parser Error: Missing ':' and type in struct member.\n");
      }
    | VAR IDENTIFIER ':'
      {
          printf("Parser Error: Missing type in struct member.\n");
      }
    | LET IDENTIFIER ':'
      {
          printf("Parser Error: Missing type in struct member.\n");
      }
;

struct_initialization_error:
      IDENTIFIER '('
      {
          printf("Parser Error: Missing struct initialization arguments or ')'.\n");
      }
    | IDENTIFIER '(' arguments
      {
          printf("Parser Error: Missing ')' after struct initialization arguments.\n");
      }
;

field_access_error:
      IDENTIFIER '.'
      {
          printf("Parser Error: Missing field name after '.'.\n");
      }
;

%%

program:
    INTEGER_LITERAL
;

%%

int yyerror(const char *s) {
    printf("Syntax Error: %s\n", s);
    return 0;
}

int main() {
    return yyparse();
}