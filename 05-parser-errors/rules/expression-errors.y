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