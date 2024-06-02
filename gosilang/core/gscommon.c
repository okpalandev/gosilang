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

Token *TokenValue_new( enum TokenType type, TokenValue *value) {
    Token *token = malloc(sizeof(Token));
    token->type = type;
    token->value =  value;
    return token;
}

TokenValue *TokenValue_cast( char *string, enum TokenType type){
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

const char *TokenTrie_strnode(TokenTrie *trie, char *key) {
    TokenTrie *node = trie;
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->key;
        }
        node = node->next;
    }
    return NULL;
}


Map *Map_new(char *key, TokenValue *value) {
    Map *map = malloc(sizeof(Map));
    map->key = key;
    map->value = value;
    map->next = NULL;
    return map;
}

void Map_free(Map *map) {
    if (map->next) {
        Map_free(map->next);
    }
    free(map);
}

Map *Map_insert(Map *map, char *key, TokenValue *value) {
    Map *node = Map_new(key, value);
    node->next = map;
    return node;
}

TokenValue *Map_search(Map *map, char *key) {
    Map *node = map;
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}