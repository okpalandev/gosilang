#include "indirection.h"
#include "table.h"

#define INITIAL_CAPACITY 10

// Function to initialize a hash table
HashTable_t *HashTable_init() {
    HashTable_t *table = (HashTable_t *)malloc(sizeof(HashTable_t));
    if (table == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    table->count = 0;
    table->capacity = INITIAL_CAPACITY;
    table->slots = (HashItem_t **)malloc(table->capacity * sizeof(HashItem_t *));
    if (table->slots == NULL) {
        free(table);
        return NULL;
    }
    // Initialize all slots to NULL
    for (size_t i = 0; i < table->capacity; i++) {
        table->slots[i] = NULL;
    }
    return table;
}

// Function to create a hash item
HashItem_t *HashItem_create(int key, const char *value) {
    HashItem_t *item = (HashItem_t *)malloc(sizeof(HashItem_t));
    if (item == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    item->key = key;
    item->value = strdup(value); // Make a copy of the value
    return item;
}

// Function to compute the hash index for a given key
size_t HashTable_hash(int key, size_t capacity) {
    // Simple hash function using modulo operator
    return key % capacity;
}

// Function to insert a key-value pair into the hash table
void HashTable_put(HashTable_t *table, int key, const char *value) {
    // Compute the hash index for the key
    size_t index = HashTable_hash(key, table->capacity);
    // Create a new hash item
    HashItem_t *item = HashItem_create(key, value);
    if (item == NULL) {
        // Handle memory allocation failure
        return;
    }
    // Linear probing to handle collisions
    while (table->slots[index] != NULL) {
        index = (index + 1) % table->capacity;
    }
    // Insert the hash item into the table
    table->slots[index] = item;
    table->count++;
}

// Function to free memory allocated for a hash table
void HashTable_free(HashTable_t *table) {
    if (table != NULL) {
        // Free each hash item and its value
        for (size_t i = 0; i < table->capacity; i++) {
            if (table->slots[i] != NULL) {
                free(table->slots[i]->value);
                free(table->slots[i]);
            }
        }
        free(table->slots);
        free(table);
    }
}
