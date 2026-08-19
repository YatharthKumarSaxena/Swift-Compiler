<COMMENT><<EOF>> {
    printf("LEXICAL ERROR: Unterminated multi-line comment\n");
    BEGIN(INITIAL);
}