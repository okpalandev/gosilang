#include "gstokenizer.h"

int main() {
    Tokenizer *tokenizer = Tokenizer_new("Hello, World!");
    Token *token = Tokenizer_next(tokenizer);
    Token_free(token);
    Tokenizer_free(tokenizer);
    return 0;
}