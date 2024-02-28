#include "indirection.h"
#include "token.h"


// Function to initialize a token
Token_t* Token_init(TokenType *type, TokenValue *value) {
    // Allocate memory for the token
    Token_t *token = (Token_t*)malloc(sizeof(Token_t));
    if (token == NULL) {
        fprintf(stderr, "Failed to allocate memory for Token");
        return NULL;
    }

    // Initialize type and value if pointers are not NULL
    if (type != NULL) {
        token->type = type;
    } else {
        token->type = TOKEN_UNIDENTIFIED;
    }

    if (value != NULL) {
        // Allocate memory for value.data and copy the provided data
        // token->value->data = malloc(strlen(value->data) + 1);
        if (token->value->data == NULL) {
            fprintf(stderr, "Failed to allocate memory for Token value data");
            free(token);
            return NULL;
        }
        strcpy(token->value->data, value->data);
    } else {
        // Handle the case when value pointer is NULL
        // For example, set token->value.data to an empty string
        token->value->data = "";
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
