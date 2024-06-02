#include "gscommon.h"


Token *Token_new(enum TokenType type, TokenValue *value) {
    Token *token = malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    return token;
}

void Token_free(Token *token) {
    if (token->value) {
        TokenValue_free(token->value);
    }
    free(token);
}


TokenValue *TokenValue_new(char *string, enum TokenType type) {
    TokenValue *value = malloc(sizeof(TokenValue));
    value->string = string;
    return value;
}

TokenValue *TokenValue_cast(char *string, enum TokenType type) {
    TokenValue *value = malloc(sizeof(TokenValue));
    value->string = string;
    return value;
}

void TokenValue_free(TokenValue *value) {
    free(value);
}


TokenTrie *TokenTrie_new(char *key, enum TokenType type) {
    TokenTrie *trie = malloc(sizeof(TokenTrie));
    trie->key = key;
    trie->type = type;
    trie->next = NULL;
    return trie;
}

void TokenTrie_free(TokenTrie *trie) {
    if (trie->next) {
        TokenTrie_free(trie->next);
    }
    free(trie);
}


TokenTrie *TokenTrie_insert(TokenTrie *trie, char *key, enum TokenType type) {
    TokenTrie *node = TokenTrie_new(key, type);
    node->next = trie;
    return node;
}

TokenTrie *TokenTrie_search(TokenTrie *trie, char *key) {
    TokenTrie *node = trie;
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

