%{
    #include <stdio.h>

    int yylex();
    int yyerror(const char *s);
%}

include(`../common/parser_tokens.y')

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