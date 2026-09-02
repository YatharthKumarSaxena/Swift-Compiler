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