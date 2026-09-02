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