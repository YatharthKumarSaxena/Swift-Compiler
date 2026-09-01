{keyword} {
    printf("KEYWORD: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return KEYWORD;
}

{type} {
    printf("TYPE: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return TYPE;
}

{identifier} {
    printf("IDENTIFIER: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return IDENTIFIER;
}