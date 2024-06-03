#ifndef GSTOKENIZER_H
#define GSTOKENIZER_H

#define CORE // for debugging purposes

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "gscommon.h"

typedef struct Tokenizer_s Tokenizer;
struct Tokenizer_s {
    char *source;
    char *current;
    char *start;
    char *end;
    int line;
    int column;
    TokenTrie *trie;
};

Tokenizer *Tokenizer_new(char *source);
void Tokenizer_free(Tokenizer *tokenizer);
Token *Tokenizer_next(Tokenizer *tokenizer);
Token *Tokenizer_peek(Tokenizer *tokenizer);
Token *Tokenizer_advance(Tokenizer *tokenizer);
Token *Tokenizer_consume(Tokenizer *tokenizer, enum TokenType type);



#endif // GSTOKENIZER_H


