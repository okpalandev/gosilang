#ifndef TOKEN_H
#define TOKEN_H

#include "indirection.h"
// To verify value correctness,it is given a type.
// This module split type and value in two for easier
// computation of a functional turing-machine defined
// using the lambda calculus framework.

#define type(name,...) \
    typedef enum name##t {  \
        __VA_ARGS__ \
    } name;

#define value(name,...) \
    typedef union name##u { \
        __VA_ARGS__ \
    } name;


type(TokenType,
    TOKEN_UNIDENTIFIED,
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_DELIMETER,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
    TOKEN_END
)

value(TokenValue,
    char* data;
    char *name;
)

typedef struct Token_s Token_t;
struct Token_s {
    TokenType *type;
    TokenValue *value;
    int len;
    int line;
};

Token_t* Token_init(TokenType *type,TokenValue *value);
void Token_free(Token_t* token);
void Token_print(Token_t* token);

#endif // TOKEN_H

