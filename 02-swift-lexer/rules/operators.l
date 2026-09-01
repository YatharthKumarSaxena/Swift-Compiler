{arrow} {
    printf("ARROW: %s\n", yytext);
    return ARROW;
}

{plus} {
    printf("PLUS: %s\n", yytext);
    yylval.char_val = '+';
    return OPERATOR;
}

{minus} {
    printf("MINUS: %s\n", yytext);
    yylval.char_val = '-';
    return OPERATOR;
}

{multiply} {
    printf("MULTIPLY: %s\n", yytext);
    yylval.char_val = '*';
    return OPERATOR;
}

{divide} {
    printf("DIVIDE: %s\n", yytext);
    yylval.char_val = '/';
    return OPERATOR;
}

{modulo} {
    printf("MODULO: %s\n", yytext);
    yylval.char_val = '%';
    return OPERATOR;
}

{assign} {
    printf("ASSIGN: %s\n", yytext);
    yylval.char_val = '=';
    return ASSIGN;
}

{eq} {
    printf("EQ: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return COMPARISON;
}

{ne} {
    printf("NE: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return COMPARISON;
}

{gte} {
    printf("GTE: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return COMPARISON;
}

{lte} {
    printf("LTE: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return COMPARISON;
}

{gt} {
    printf("GT: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return COMPARISON;
}

{lt} {
    printf("LT: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return COMPARISON;
}

{logical_and} {
    printf("LOGICAL_AND: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return OPERATOR;
}

{logical_or} {
    printf("LOGICAL_OR: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return OPERATOR;
}

{bit_and} {
    printf("Bit AND: %s\n", yytext);
    yylval.char_val = '&';
    return OPERATOR;
}

{bit_or} {
    printf("Bit OR: %s\n", yytext);
    yylval.char_val = '|';
    return OPERATOR;
}

{logical_not} {
    printf("NOT: %s\n", yytext);
    yylval.char_val = '!';
    return OPERATOR;
}