\"[^\n"]*   {
    printf("LEXICAL ERROR: Unterminated string: %s\n", yytext);
}

