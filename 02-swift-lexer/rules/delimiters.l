{lparen} {
    printf("LPAREN: %s\n", yytext);
    return '(';
}

{rparen} {
    printf("RPAREN: %s\n", yytext);
    return ')';
}

{lbrace} {
    printf("LBRACE: %s\n", yytext);
    return '{';
}

{rbrace} {
    printf("RBRACE: %s\n", yytext);
    return '}';
}

{lbracket} {
    printf("LBRACKET: %s\n", yytext);
    return '[';
}

{rbracket} {
    printf("RBRACKET: %s\n", yytext);
    return ']';
}

{comma} {
    printf("COMMA: %s\n", yytext);
    return ',';
}

{dot} {
    printf("DOT: %s\n", yytext);
    return '.';
}

{semicolon} {
    printf("SEMICOLON: %s\n", yytext);
    return ';';
}

{colon} {
    printf("COLON: %s\n", yytext);
    return ':';
}