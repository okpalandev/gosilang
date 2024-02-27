#include "indirection.h"
#include "token.h"


Token_t *Token_init(TokenType *type, TokenValue *value) {
    Token_t *token = malloc(sizeof(Token_t));
    if (token == NULL) {
        fprintf(stderr, "Failed to allocate memory for Token");
        return NULL;
    }
    token->type = *type;
    token->value.data = malloc(strlen(value->data) + 1);
    if (token->value.data == NULL) {
        fprintf(stderr, "Failed to allocate memory for Token value data");
        free(token);
        return NULL;
    }
    strcpy(token->value.data, value->data);
    return token;
}


void Token_free(Token_t *token) {
    if (token != NULL) {
        free(token->value.data);
        free(token);

    }
}
