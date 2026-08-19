#ifndef TOKENS_H
#define TOKENS_H

enum TokenType {
    INTEGER_LITERAL = 256,
    STRING_LITERAL,
    DOUBLE_LITERAL,
    BOOLEAN_LITERAL,
    CHARACTER_LITERAL,

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
    OR
};

#endif