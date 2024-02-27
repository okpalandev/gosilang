#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "indirection.h"
#include "token.h"

typedef struct Tokenizer_s Tokenizer_t;
struct Tokenizer_s {
    Token_t *tokens;
    char *stream;
};

Tokenizer_t *Tokenizer_init(TokenType *type, TokenValue *value);
Token_t *tokenize(char *stream);
void Tokenizer_free(Tokenizer_t *tokenizer);

#endif // TOKENIZER_H

