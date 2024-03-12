#include "indirection.h"
#include "tokenizer.h"
#include "table.h"
#include "tokens.h"
#include "token.h"


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

    char input[1000];
    Token_t *token;
    
    // Tokenize each line separately
    while (fgets(input, sizeof(input), fp) != NULL) {
        // Tokenize the input line
        tokenize(tokenizer, input);
        
        // Process tokens
        for (size_t i = 0; i < tokenizer->capacity; i++) {
            token = tokenizer->tokens[i];
            // Check if token is NULL (end of line)
            if (token == NULL) {
                break;
            }


            // Process or add tokens to the symbol table

switch (*token->type) {
                case TOKEN_KEYWORD:
                    if (strcmp(token->value->data, "oru") == 0) {
                        SymbolTable_add(table, "oru", token->type, token->value);
                    }
                    break;
                case TOKEN_IDENTIFIER:
                    SymbolTable_add(table, token->value->data, token->type, token->value);
                    break;
                default:
                    break;
            }

        }
    }
    
    // Free memory and close file
    Tokenizer_free(tokenizer);
    SymbolTable_free(table);
    fclose(fp);

    return 0;
}
