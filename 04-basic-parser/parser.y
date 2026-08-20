%{
    #include <stdio.h>

    int yylex();
    int yyerror(const char *s);
%}

%token INTEGER_LITERAL 256

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