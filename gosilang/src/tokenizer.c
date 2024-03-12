#include "tokens.h"
#include "tokenizer.h"
#include "indirection.h"

Tokenizer_t *Tokenizer_init(size_t capacity) {
    Tokenizer_t *tokenizer = malloc(sizeof(Tokenizer_t));
    if (tokenizer == NULL) {
        fprintf(stderr, "Failed to allocate memory for Tokenizer");
        return NULL;
    }

    tokenizer->stream = NULL; // Initialize stream to NULL
    
    // Initialize each token
    for (size_t i = 0; i < capacity; i++) {
        tokenizer->tokens[i] = Token_init(TOKEN_UNIDENTIFIED, NULL);
        if (tokenizer->tokens[i] == NULL) {
            // Handle initialization failure
            fprintf(stderr, "Failed to initialize token");
            // Clean up allocated memory
            for (size_t j = 0; j < i; j++) {
                Token_free(tokenizer->tokens[j]);
            }
            Tokenizer_free(tokenizer);
            return NULL;
        }
    }

    tokenizer->capacity = capacity; // Set the capacity

    return tokenizer;
}
void Tokenizer_advance(Tokenizer_t *tokenizer) {
    if (tokenizer == NULL) {
        fprintf(stderr, "Tokenizer does not exist");
        return;
    }

    // Tokenize the stream
    char *token = strtok(tokenizer->stream, " ");
    size_t index = 0;

    while (token != NULL && index < tokenizer->capacity) {
        // Create a new token
        Token_t *new_token = Token_init(TOKEN_UNIDENTIFIED, &(TokenValue){ .data = token });
        if (new_token == NULL) {
            fprintf(stderr, "Failed to initialize token");
            return; // Abort tokenization if initialization fails
        }

        // Store the token
        tokenizer->tokens[index++] = new_token;

        // Get the next token
        token = strtok(NULL, " ");
    }
}



void tokenize(Tokenizer_t *tokenizer, char *stream) {
    if (tokenizer == NULL) {
        fprintf(stderr, "Tokenizer is not initialized");
        return;
    }

    // Store the input stream
    tokenizer->stream = strdup(stream);

    // Tokenize the stream
    Tokenizer_advance(tokenizer);
}


void Tokenizer_free(Tokenizer_t *tokenizer) {
    if (tokenizer != NULL) {
        // Free tokens individually
        for (size_t i = 0; i < tokenizer->capacity; i++) {
            Token_free(tokenizer->tokens[i]);
        }
        // Free dynamically allocated memory
        free(tokenizer->stream);
        free(tokenizer);
    }
}



