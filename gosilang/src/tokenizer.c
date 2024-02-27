#include "tokenizer.h"
#include "indirection.h"

Tokenizer_t *Tokenizer_init(TokenType *type, TokenValue *value) {
    Tokenizer_t *tokenizer = (Tokenizer_t *)malloc(sizeof(Tokenizer_t));
    if (tokenizer == NULL) {
        fprintf(stderr, "Failed to allocate memory for Tokenizer");
        return NULL;
    }

    tokenizer->stream = NULL; // Initialize stream to NULL

    tokenizer->tokens = malloc(SIZE_MAX * sizeof(Token_t));
    if (tokenizer->tokens == NULL) {
        fprintf(stderr, "Failed to allocate memory for tokens");
        free(tokenizer); // Free tokenizer if token allocation fails
        return NULL;
    }

    // Initialize tokens
    for (int i = 0; i < SIZE_MAX; i++) {
        tokenizer->tokens[i] = *Token_init(type, value);
    }

    return tokenizer;
}

void Tokenizer_advance(Tokenizer_t *tokenizer) {
    strcpy(tokenizer->value->data, );
}

Token_t *tokenize(char *stream) {
    char *token = strtok(stream, " ");
    // Using Tokenizer_advance, tokenize the stream with tokens
    while (token) {
        // Store the token somewhere, e.g., in tokenizer->tokens
        // Tokenizer_advance(tokenizer); // Advance to the next token
        token = strtok(NULL, " ");
    }
    return NULL; // Placeholder return value
}

void Tokenizer_free(Tokenizer_t *tokenizer) {
    if (tokenizer != NULL) {
        free(tokenizer->tokens);
        free(tokenizer->stream);
        free(tokenizer);
    }
}


