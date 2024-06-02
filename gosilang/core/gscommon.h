#ifndef  GSCOMMON_H
#define GSCOMMON_H
#define CORE // for debugging purposes

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define max(a,b) ((a>b)? a : b)
#define min(a,b) ((a<b)? a : b)
// To verify value correctness, it is given a type.
// For compile time safety, we seperate the declarations
// the tokens, and types.
enum TokenType {
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
    char *string;
    int integer;
    double decimal;
    bool boolean;
};

TokenTrie *TokenTrie_new(char *key, enum TokenType type);
void TokenTrie_free(TokenTrie *trie);
TokenTrie *TokenTrie_insert(TokenTrie *trie, char *key, enum TokenType type);
TokenTrie *TokenTrie_search(TokenTrie *trie, char *key);

Token *Token_new(enum TokenType type, TokenValue *value);
void Token_free(Token *token);
TokenValue *TokenValue_cast(char *string, enum TokenType type);

#endif // GSCOMMON_H
