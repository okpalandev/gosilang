#ifndef TABLE_H
#define TABLE_H

#include "indirection.h"


typedef struct HashItem_s {
    int key;
    // Direct value of a token->value
    //is an instance of string.
    char *value;

} HashItem_t;

// A hash table.
typedef struct HashTable_s HashTable_t;
struct HashTable_s {
    int count;
    HashItem_t **slots;
    size_t capacity;
};

HashTable_t* Hashtable_init();
size_t HashTable_hash(int key, size_t capacity);
void HashTable_put(HashTable_t *table, int key, const char *value);
HashItem_t *HashItem_create(int key, const char *value);
void HashTable_free(HashTable_t* table);

// A SymbolTable to lookup value given a MinHeap and MaxHeap.
// using a two-pointer technique.


#endif // TABLE_H
