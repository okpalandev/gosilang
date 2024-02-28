#include "indirection.h"
#include "token.h"

Token_t* Token_init(TokenType *type, TokenValue *value) {
    Token_t *token = malloc(sizeof(Token_t));
    if (token == NULL) {
        fprintf(stderr, "Failed to allocate memory for Token");
        return NULL;
    }

    // Initialize type and value if pointers are not NULL
    if (type != NULL) {
        token->type = type; // Dereference the pointer to access the enum value
    } else {
        // Handle the case when type pointer is NULL;
        token->type = TOKEN_INVALID; // set to a default value.
    }

    if (value != NULL) {
        // Allocate memory for token->value and token->value->data
        token->value = malloc(sizeof(TokenValue));
        if (token->value == NULL) {
            fprintf(stderr, "Failed to allocate memory for Token value");
            free(token);
            return NULL;
        }
        token->value->data = malloc(strlen(value->data) + 1);
        if (token->value->data == NULL) {
            fprintf(stderr, "Failed to allocate memory for Token value data");
            free(token->value); // Free allocated memory before returning NULL
            free(token);
            return NULL;
        }
        strcpy(token->value->data, value->data);
    } else {
        // Handle the case when value pointer is NULL
        // For example, set token->value->data to NULL
        token->value = NULL;
    }

    return token;
}

void Token_free(Token_t *token) {
    if (token != NULL) {
        // Free allocated memory for token->value and token->value->data
        if (token->value != NULL) {
            free(token->value->data);
            free(token->value);
        }
        free(token);
    }
}
