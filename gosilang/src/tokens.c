#ifndef TOKENS_H
#define TOKENS_H

#include "token.h"

// Define additional contextual types for keywords with associated data
type(TokenKeywordType,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_FOR,
    TOKEN_WHILE
)

// Define additional values for keyword tokens with associated data
value(TokenKeywordValue,
    union {
        char* keyword;
        int length;
    } info;
)

#endif // TOKENS_H

