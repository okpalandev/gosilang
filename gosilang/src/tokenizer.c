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

    int line = 1; // Initialize line number

    // Iterate over tokens
    for (size_t index = 0; index < tokenizer->capacity; index++) {
        TokenType type = tokenizer->tokens[index]->type;
        TokenValue value = tokenizer->tokens[index]->value;

        // Allocate memory for the current token
        Token_t *current_token = malloc(sizeof(Token_t));
        if (current_token == NULL) {
            fprintf(stderr, "Failed to allocate memory for current_token");
            return;
        }

        // Assign values to the current token
        current_token->type = type;
        current_token->value = value;
        current_token->len = strlen(value.data) + 1;

        // Set the line of the token using token_position
        tokenizer->token_position.row = line;

        // Update line number based on the content of the token (e.g., count newline characters)
        for (size_t i = 0; i < current_token->len; i++) {
            if (current_token->value.data[i] == '\n') {
                line++;
            }
        }

        // Free the memory allocated for the current token
        free(current_token);
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



