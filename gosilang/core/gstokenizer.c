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


Token *Tokenizer_peek(Tokenizer *tokenizer) {
    Token *token = Token_new(TOKEN_UNKNOWN, NULL);
    return token;
}
Token *Tokenizer_advance(Tokenizer *tokenizer) {
    Token *token = Token_new(TOKEN_UNKNOWN, NULL);
    return token;
}
Token *Tokenizer_consume(Tokenizer *tokenizer, enum TokenType type) {
    Token *token = Token_new(TOKEN_UNKNOWN, NULL);
    return token;
}

Token *Tokenizer_next(Tokenizer *tokenizer) {
    Token *token = Token_new(TOKEN_UNKNOWN, NULL);
    return token;
}

