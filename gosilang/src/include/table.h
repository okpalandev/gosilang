#ifndef TABLE_H
#define TABLE_H

#include "indirection.h"
#include "token.h"
#include "tokens.h"


typedef struct HashItem_s {
    int key;
    // Direct value of a token->value
    // is an instance of string.
    char *value;
} HashItem;

// A hash table.
typedef struct HashTable_s {
    int count;
    HashItem **slots;
    size_t capacity;
} HashTable;

HashTable* Hashtable_init();
size_t HashTable_hash(int key, size_t capacity);
HashItem* HashItem_create(int key, const char *value);
void HashTable_put(HashTable *table, int key, const char *value);
void HashTable_free(HashTable* table);

// A SymbolTable to lookup value given a MinHeap and MaxHeap.
// using a two-pointer technique.
typedef struct SymbolTable_s SymbolTable_t;
struct SymbolTable_s {
    char *name;
    TokenType* type;
    TokenValue* value;
    TokenKeywordType* kw_type;
};



#endif // TABLE_H

