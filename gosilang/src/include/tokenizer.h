#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "indirection.h"
#include "token.h"

typedef struct Tokenizer_s Tokenizer_t;
struct Tokenizer_s {
    Token_t **tokens;
    Token_t *current_token;
    // An effiecently way to compute
    // the line of token given a row and a col.
    union {
        int row;
        int col;
    } token_position;
    char *stream;
    size_t capacity;

};

Tokenizer_t *Tokenizer_init(size_t capacity);
Token_t *tokenize(Tokenizer_t *tokenizer, char *stream);
void Tokenizer_free(Tokenizer_t *tokenizer);

#endif // TOKENIZER_H

