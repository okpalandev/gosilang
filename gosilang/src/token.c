#include "indirection.h"
#include "token.h"

Token_t* Token_init(TokenType *type, TokenValue *value) {
    Token_t *token = malloc(sizeof(Token_t));
    if (token == NULL) {
        fprintf(stderr, "Failed to allocate memory for Token");
        return NULL;
    }
    token->type = type;

    if (value != NULL && value->data != NULL) {
        token->value = malloc(sizeof(TokenValue)); // Allocate memory for token->value
        if (token->value == NULL) {
            fprintf(stderr, "Failed to allocate memory for Token value");
            Token_free(token);
            return 0;
        }
        token->value->data = malloc(strlen(value->data) + 1); // Allocate memory for data
        if (token->value->data == NULL) {
            fprintf(stderr, "Failed to allocate memory for Token value data");
            Token_free(token);

        }
        strcpy(token->value->data, value->data);
    } else {
        token->value = NULL; // Set token->value to NULL if value is NULL or value->data is NULL
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

void Token_print(Token_t *token) {
    if (token != NULL) {
        if (token->value != NULL) {
            printf(" - %s\n", token->value->data);
        } else {
            printf("\n");
        }
    }
}