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