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
        token->type = type;
    } else {
        // Handle the case when type pointer is NULL
        token->type = TOKEN_INVALID; // Or set to a default value
    }

    if (value != NULL) {
        token->value->data = malloc(strlen(value->data) + 1);
        if (token->value->data == NULL) {
            fprintf(stderr, "Failed to allocate memory for Token value data");
            Token_free(token);
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
        free(token->value->data);
        free(token);

    }
}
