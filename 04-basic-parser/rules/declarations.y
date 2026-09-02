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