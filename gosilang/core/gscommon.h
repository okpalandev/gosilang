#ifndef  GSCOMMON_H
#define GSCOMMON_H
#define CORE // for debugging purposes

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


// To verify value correctness, it is given a type.
// For compile time safety, we seperate the declarations
// the tokens, and types.
enum TokenType {
    TOKEN_UNKNOWN,
    TOKEN_COMMENT,
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_DELIMITER,
    TOKEN_OPERATOR,
    TOKEN_LITERAL,
    TOKEN_PUNCTUATOR
};

enum TokenComment {
  TOKEN_COMMENT_INLINE,
  TOKEN_COMMENT_MULTILINE
};


enum TokenKeyword {
  TOKEN_KEYWORD_CONST,
  TOKEN_KEYWORD_LET,
  TOKEN_KEYWORD_FUNC
};


typedef struct  TokenTrie_s TokenTrie;
struct TokenTrie_s {
    char *key;
    enum TokenType type;
    TokenTrie *next;
};

typedef struct Token_s Token;
struct Token_s {
    enum TokenType type;
    union TokenValue *value;
};


typedef union TokenValue TokenValue;
union TokenValue {
    char *data;
};


typedef struct Map_s Map;
struct Map_s {
    char *key;
    TokenValue *value;
    Map *next;
};

Token *Token_new(enum TokenType type, TokenValue *value);
void Token_free(Token *token);



Token *TokenValue_new( enum TokenType type, TokenValue *value);
Token *TokenValue_cast( enum TokenType type, TokenValue *value);
void TokenValue_free(TokenValue *value);

TokenTrie *TokenTrie_new(char *key, enum TokenType type);
void TokenTrie_free(TokenTrie *trie);
TokenTrie *TokenTrie_insert(TokenTrie *trie, char *key, enum TokenType type);
TokenTrie *TokenTrie_search(TokenTrie *trie, char *key);
const char *TokenTrie_strnode(TokenTrie *trie, char *key);

Map *Map_new(char *key, TokenValue *value);
void Map_free(Map *map);
Map *Map_insert(Map *map, char *key, TokenValue *value);
TokenValue *Map_search(Map *map, char *key);




#endif // GSCOMMON_H
