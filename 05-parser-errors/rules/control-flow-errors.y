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