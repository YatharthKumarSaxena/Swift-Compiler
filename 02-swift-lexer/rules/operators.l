{plus} {
    printf("PLUS: %s\n", yytext);
    return '+';
}

{minus} {
    printf("MINUS: %s\n", yytext);
    return '-';
}

{multiply} {
    printf("MULTIPLY: %s\n", yytext);
    return '*';
}

{divide} {
    printf("DIVIDE: %s\n", yytext);
    return '/';
}

{modulo} {
    printf("MODULO: %s\n", yytext);
    return '%';
}

{assign} {
    printf("ASSIGN: %s\n", yytext);
    return '=';
}

{eq} {
    printf("EQ: %s\n", yytext);
    return EQ;
}

{ne} {
    printf("NE: %s\n", yytext);
    return NE;
}

{gte} {
    printf("GTE: %s\n", yytext);
    return GTE;
}

{lte} {
    printf("LTE: %s\n", yytext);
    return LTE;
}

{gt} {
    printf("GT: %s\n", yytext);
    return '>';
}

{lt} {
    printf("LT: %s\n", yytext);
    return '<';
}

{and} {
    printf("AND: %s\n", yytext);
    return AND;
}

{or} {
    printf("OR: %s\n", yytext);
    return OR;
}

{not} {
    printf("NOT: %s\n", yytext);
    return '!';
}