#ifndef TOKENS_H
#define TOKENS_H

#include "token.h"

type(TokenKeywordType,
    KW_CONST,
    KW_LET,

    KW_IF,
    KW_ELSE_IF,
    KW_ELSE,
    KW_WHILE,
)

value(TokenKeywordValue,
    char* data; // Common value for most token types
)




#endif // TOKENS_H
