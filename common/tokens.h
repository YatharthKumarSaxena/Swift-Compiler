#ifndef TOKENS_H
#define TOKENS_H

enum TokenType {
    INTEGER_LITERAL = 256,
    STRING_LITERAL,
    DOUBLE_LITERAL,
    BOOLEAN_LITERAL,
    CHARACTER_LITERAL,

    /* Operators */
    OPERATOR,
    ASSIGN,
    COMPARISON,

    IDENTIFIER,
    TYPE,
    KEYWORD,

    EQ,
    NE,
    GT,
    LT,
    GTE,
    LTE,

    AND,
    OR,

    ARROW
};

typedef union {
    int int_val;
    int bool_val;
    double double_val;
    char char_val;
    char* str_val;
} YYSTYPE;

extern YYSTYPE yylval;

#endif