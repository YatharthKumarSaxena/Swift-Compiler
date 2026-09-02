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