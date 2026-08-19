%{
    #include <stdio.h>
%}

include(`../common/swift_defs.l')

%%

{integer} {
    printf("INTEGER: %s\n", yytext);
}

{double} {
    printf("DOUBLE: %s\n", yytext);
}

{boolean} {
    printf("BOOLEAN: %s\n", yytext);
}

{character} {
    printf("CHARACTER: %s\n", yytext);
}

{string} {
    printf("STRING: %s\n", yytext);
}

%%

int yywrap() {
    return 1;
}

int main() {
    while (yylex());
    return 0;
}