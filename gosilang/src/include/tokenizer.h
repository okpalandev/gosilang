#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "indirection.h"
#include "token.h"

typedef struct Tokenizer_s Tokenizer_t;
struct Tokenizer_s {
    Token_t **tokens;
    Token_t *current_token;
    char *stream;
    size_t capacity;

};

Tokenizer_t *Tokenizer_init(TokenType *type, TokenValue *value,size_t capacity);
Token_t *tokenize(Tokenizer_t *tokenizer, char *stream);
void Tokenizer_free(Tokenizer_t *tokenizer);

#endif // TOKENIZER_H

