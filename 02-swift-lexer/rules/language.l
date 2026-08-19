{keyword} {
    printf("KEYWORD: %s\n", yytext);
    return KEYWORD;
}

{type} {
    printf("TYPE: %s\n", yytext);
    return TYPE;
}

{identifier} {
    printf("IDENTIFIER: %s\n", yytext);
    return IDENTIFIER;
}