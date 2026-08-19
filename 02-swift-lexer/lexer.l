%{
    #include <stdio.h>
    #include "../common/tokens.h"
%}

%x COMMENT

include(`../common/swift_defs.l')
include(`../common/operators.l')
include(`../common/delimiters.l')
include(`language_tokens.l')

%%

include(`rules/comments.l')
include(`rules/whitespace.l')
include(`rules/operators.l')
include(`rules/delimiters.l')
include(`rules/literals.l')
include(`rules/language.l')

include(`../03-lexical-errors/lexical_errors.l')

%%

int yywrap() {
    return 1;
}

int main() {
    while (yylex());
    return 0;
}