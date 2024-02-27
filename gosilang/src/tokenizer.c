#include "tokenizer.h"
#include "indirection.h"

Tokenizer_t *Tokenizer_init(TokenType *type, TokenValue *value, size_t capacity) {
    Tokenizer_t *tokenizer = (Tokenizer_t *)malloc(sizeof(Tokenizer_t));
    if (tokenizer == NULL) {
        fprintf(stderr, "Failed to allocate memory for Tokenizer");
        return NULL;
    }

    tokenizer->stream = NULL; // Initialize stream to NULL

    tokenizer->tokens = malloc(capacity * sizeof(Token_t)); // Allocate memory for tokens
    if (tokenizer->tokens == NULL) {
        fprintf(stderr, "Failed to allocate memory for tokens");
        free(tokenizer);
        return NULL;
    }

    // Initialize tokens (assuming capacity is provided as a parameter)
    for (size_t i = 0; i < capacity; i++) {
        tokenizer->tokens[i] = Token_init(type, value);
    }

    tokenizer->capacity = capacity; // Set the capacity

    return tokenizer;
}

void Tokenizer_advance(Tokenizer_t *tokenizer) {
    // Check if tokenizer or tokens are NULL
    if (tokenizer == NULL || tokenizer->tokens == NULL) {
        fprintf(stderr, "Tokenizer or tokens in Tokenizer does not exist");
        return;
    }

    // Iterate over tokens
    for (int index = 0; index < tokenizer->capacity; index++) {
        // Process each token (for example, print its type)
        TokenType type = tokenizer->tokens[index]->type;
        TokenValue value = tokenizer->tokens[index]->value;
        Token_t current_token = {.type=type,.value = value};
        memcpy(tokenizer->current_token,current_token,sizeof(current_token));
    }
}


Token_t *tokenize(Tokenizer_t *tokenizer, char *stream) {
    if (tokenizer == NULL) {
        fprintf(stderr, "Tokenizer is not initialized");
        return NULL;
    }

    char *token = strtok(stream, " ");

    // Using Tokenizer_advance, tokenize the stream with tokens
    while (token) {
        // Store the token somewhere, e.g., in tokenizer->tokens
        Tokenizer_advance(tokenizer); // Advance to the next token
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



