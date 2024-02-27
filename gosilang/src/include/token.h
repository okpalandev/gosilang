#ifndef TOKEN_H
#define TOKEN_H

#include "indirection.h"

#define type(name,...) \
    typedef enum name##t {  \
        __VA_ARGS__ \
    } name;

#define value(name,...) \
    typedef union name##u { \
        __VA_ARGS__ \
    } name;

type(TokenType,
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_DELIMETER,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
    TOKEN_INVALID,
    TOKEN_END
)
value(TokenValue,
    char* data;
)

typedef struct Token_s Token_t;
struct Token_s {
    TokenType type;
    TokenValue value;
    int len;
    int line;
};

Token_t *Token_init(TokenType *type, TokenValue *value);
void Token_free(Token_t* token);

#endif // TOKEN_H

