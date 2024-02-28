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

    // Initialize tokenizer with a capacity (adjust the capacity as needed)
    Tokenizer_t *tokenizer = Tokenizer_init(100);
    if (tokenizer == NULL) {
        fprintf(stderr, "Failed to initialize tokenizer\n");
        fclose(fp);
        return 1;
    }

    // Create a SymbolTable with a capacity of 10
    SymbolTable *table = SymbolTable_init(10);

    Token_t *token;
    char input[1000];
    // Inside your main function where you tokenize the input
    while (fgets(input, sizeof(input), fp) != NULL) {
        // Tokenize the input
        token = tokenize(tokenizer, input);

        // Process or add tokens to the symbol table
        while (token != NULL) {
            // Check if the token is the 'oru' keyword
            if (token->type == TOKEN_KEYWORD && strcmp(token->value->data, "oru") == 0) {
                // Add 'oru' to the symbol table
                SymbolTable_add(table, "oru", token->type, token->value);
            }

            // Tokenize the next input line
            token = tokenize(tokenizer, NULL);
        }
    }

    // Free memory and close file
    Tokenizer_free(tokenizer);
    SymbolTable_free(table);
    fclose(fp);

    return 0;
}



