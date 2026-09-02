%{
    #include <stdio.h>

    int yylex();
    int yyerror(const char *s);
%}

include(`../common/parser_tokens.y')

include(`../04-basic-parser/rules/values.y')
include(`../04-basic-parser/rules/expressions.y')
include(`../04-basic-parser/rules/arrays.y')
include(`../04-basic-parser/rules/structs.y')
include(`../04-basic-parser/rules/declarations.y')
include(`../04-basic-parser/rules/control_flow.y')
include(`../04-basic-parser/rules/loops.y')
include(`../04-basic-parser/rules/functions.y')
include(`../04-basic-parser/rules/statements.y')
include(`../04-basic-parser/rules/program.y')

include(`../05-parser-errors/parser_errors.y')

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