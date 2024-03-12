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
    // Check if tokenizer or tokens are NULL
    if (tokenizer == NULL) {
        fprintf(stderr, "Tokenizer  do not exist");
        return;
    }

    int line = 1; // Initialize line number

    // Iterate over tokens
    for (size_t index = 0; index < tokenizer->capacity; index++) {
        TokenType type = TOKEN_UNIDENTIFIED;
        TokenValue val = { .data = TOKEN_UNIDENTIFIED };
        Token_t *token = Token_init(&type, &val); // Initialize token
        tokenizer->tokens[index] = token;

        // Set the line number of the token
        token->line = line;

        // Update line number based on the content of the token (e.g., count newline characters)
        if (tokenizer->tokens[index]->value->data != NULL) {
            char *data = tokenizer->tokens[index]->value->data;
            while (*data != '\0') {
                if (*data == '\n') {
                    line++;
                }
                data++;
            }
        }
    }
}


void tokenize(Tokenizer_t *tokenizer, char *stream) {
    if (tokenizer == NULL) {
        fprintf(stderr, "Tokenizer is not initialized");
        return;
    }

    char *token = strtok(stream, " ");

    // Using Tokenizer_advance, tokenize the stream with tokens
    while (token) {
        // Store the token somewhere, e.g., in tokenizer->tokens
        // Assuming Tokenizer_advance updates tokenizer->tokens appropriately
        Tokenizer_advance(tokenizer); // Advance to the next token
        token = strtok(NULL, " ");
    }

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



