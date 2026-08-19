{boolean} {
    printf("BOOLEAN: %s\n", yytext);
    return BOOLEAN_LITERAL;
}

{double} {
    printf("DOUBLE: %s\n", yytext);
    return DOUBLE_LITERAL;
}

{integer} {
    printf("INTEGER: %s\n", yytext);
    return INTEGER_LITERAL;
}

{character} {
    printf("CHARACTER: %s\n", yytext);
    return CHARACTER_LITERAL;
}

{string} {
    printf("STRING: %s\n", yytext);
    return STRING_LITERAL;
}