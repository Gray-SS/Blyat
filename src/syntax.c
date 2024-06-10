#include "syntax.h"

Token_t *token_new(Arena *arena, TokenType type, uint32_t col, uint32_t line)
{
    Token_t *token = arena_alloc(arena, sizeof(Token_t));
    if (token) {
        token->type = type;
        token->loc.col = col;
        token->loc.line = line;
    }
    return token;
}