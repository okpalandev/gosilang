#ifndef TOKENS_H
#define TOKENS_H
#include "token.h"

type(TokenKeywordType,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_FOR,
    TOKEN_WHILE
)

value(TokenKeywordValue,
    struct {
        char* keyword;
        int length;
    } info;
)

#endif // TOKENS_H
