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