#include "gstokenizer.h"

Tokenizer *Tokenizer_new(char *source) {
    Tokenizer *tokenizer = malloc(sizeof(Tokenizer));
    tokenizer->source = source;
    tokenizer->current = source;
    tokenizer->start = source;
    tokenizer->end = source + strlen(source);
    tokenizer->line = 1;
    tokenizer->column = 1;
    tokenizer->trie = NULL;
    return tokenizer;
}

void Tokenizer_free(Tokenizer *tokenizer) {
    free(tokenizer);
}

