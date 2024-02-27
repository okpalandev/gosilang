#include "tokenizer.h"
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

    // Initialize the tokenizer
    Tokenizer_t *tokenizer = Tokenizer_init(NULL, NULL, 20);

    // Tokenize the input
    Token_t *token;
    char input[1000]; // Adjust the size according to your needs
    while (fgets(input, sizeof(input), fp) != NULL) {
        token = tokenize(tokenizer, input);
        // Process or print the tokens
        if (token != NULL) {
            printf("Tokens:\n");
            printf("Type: %d, Value: %s\n", token->type, token->value.data);
        }
    }

    // Free memory
    Tokenizer_free(tokenizer);
    Token_free(token);

    fclose(fp);
    return 0;
}
