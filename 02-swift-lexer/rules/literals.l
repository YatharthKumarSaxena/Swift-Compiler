{boolean} {
    printf("BOOLEAN: %s\n", yytext);
    yylval.bool_val = (strcmp(yytext, "true") == 0);
    return BOOLEAN_LITERAL;
}

{double} {
    printf("DOUBLE: %s\n", yytext);
    yylval.double_val = atof(yytext);
    return DOUBLE_LITERAL;
}

{integer} {
    printf("INTEGER: %s\n", yytext);
    yylval.int_val = atoi(yytext);
    return INTEGER_LITERAL;
}

{character} {
    printf("CHARACTER: %s\n", yytext);
    yylval.char_val = yytext[1];
    return CHARACTER_LITERAL;
}

{string} {
    printf("STRING: %s\n", yytext);
    yylval.str_val = strdup(yytext);
    return STRING_LITERAL;
}