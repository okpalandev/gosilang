#include "indirection.h"
#include "token.h"

Token_t* Token_init(TokenType *type,TokenValue *value) {
    Token_t *token = malloc(sizeof(Token_t));
    if (token == NULL) {
        fprintf(stderr, "Failed to allocate memory for Token");
        return NULL;
    }

    // Initialize the type to a default value

    if(type == NULL) token->type = TOKEN_UNIDENTIFIED;

    // Initialize the value if the parameter
    // is not NULL
    if (value != NULL) {
        token->value->data = malloc(strlen(value->data) + 1);
        if (token->value->data == NULL) {
            fprintf(stderr, "Failed to allocate memory for Token value data");
            free(token);
            return NULL;
        }
        strcpy(token->value->data, value->data);
    } else {
        // Handle the case when value pointer is NULL
        // For example, set token->value->data to NULL
        token->value->data = NULL;
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
