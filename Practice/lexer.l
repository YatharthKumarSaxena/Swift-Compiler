%{
    #include <stdio.h>
%}

%%

"var"   {
    printf("VAR\n");
    return VAR;
}
"let"   {
    printf("LET\n");
    return LET;
}
"if"    {
    printf("IF");
    return IF;
}
"else"    {
    printf("ELSE");
    return ELSE;
}
"for"   {
    printf("for");
    return FOR;
}
"in"    {
    printf("in");
    return IN;
}
"while" {
    printf("while");
    return WHILE;
}
"=="|">="|"<="|"!="|"<"|">" {
    printf("COMPARISON: %s\n",yytext);
    return COMPARISON;
}
[0-9]+  {
    printf("INTEGER_LITERAL: %s\n",yytext);
    return DIGITS;
}
[a-zA-Z_][a-zA-Z0-9_]*  {
    printf("IDENTIFIER: %s\n",yytext);
    return VARIABLE;
}
"+" {
    printf("PLUS\n");
    return +;
}
"-" {
    printf("MINUS\n")
}
"=" {printf("ASSIGN\n");}
"*" {printf("MULTIPLY\n");}
"/" {printf("DIVIDE\n")}
[ \t\n]+   { /* ignore whitespace */ }
.   {printf("UNKNOWN: %s\n",yytext);}



%%

int yywrap() {
    return 1;
}

int main() {
    while (yylex());
    return 0;
}