
#include "tokenizer.h"
#include "token.h"

int main() {
    // Initialize the tokenizer
    Tokenizer_t *tokenizer = Tokenizer_init(NULL, NULL, 100);

    // Read input from the user or from a file
    char input[1000]; // Adjust the size according to your needs
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);

    // Tokenize the input
    Token_t *tokens = tokenize(tokenizer, input);

    // Process or print the tokens
    if (tokens != NULL) {
        printf("Tokens:\n");
        printf("Type: %d, Value: %s\n", tokens->type, tokens->value.data);
    }

    // Free memory
    Tokenizer_free(tokenizer);
    Token_free(tokens);

    return 0;
}

