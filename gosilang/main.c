#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "token.h"
#include "table.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 1;
    }

    Tokenizer_t *tokenizer = Tokenizer_init(NULL, NULL, 8);
    if (tokenizer == NULL) {
        fprintf(stderr, "Failed to initialize tokenizer\n");
        fclose(fp);
        return 1;
    }

    // Create a SymbolTable with a capacity of 10
    SymbolTable *table = SymbolTable_init(10);

    Token_t *token;
    char input[1000];
    while (fgets(input, sizeof(input), fp) != NULL) {
        // Tokenize the input
        token = tokenize(tokenizer, input);

        // Process or add tokens to the symbol table
        while (token != NULL) {
            // Add the token to the symbol table
            if (token->type == TOKEN_IDENTIFIER) {
                SymbolTable_add(table, token->value.data, token->type, token->value);
            }
            // Tokenize the next input line
            token = tokenize(tokenizer, NULL);
        }
    }

    // Retrieve and print some symbols from the table (just for demonstration)
    SymbolEntry *entry = SymbolTable_get(table, "symbol1");
    if (entry != NULL) {
        printf("Symbol name: %s\n", entry->name);
        printf("Symbol type: %d\n", entry->type);
        printf("Symbol value: %s\n", entry->value.data);
    }

    // Free memory
    Tokenizer_free(tokenizer);
    SymbolTable_free(table);
    fclose(fp);

    return 0;
}

