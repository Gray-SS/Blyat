#ifndef SYNTAX_H
#define SYNTAX_H

#include <stdint.h>

#include "file.h"
#include "view.h"
#include "arena.h"

typedef enum    TokenType TokenType;
typedef struct  Token_t Token_t;
typedef struct  TokenLoc_t TokenLoc_t;

enum TokenType {
    //Special token types
    TK_EOF,
    TK_IDENTIFIER,

    //Literals
    TK_NUMBER_LIT,

    //Keywords
    TK_RETURN_KW,
    TK_PROC_KW,
    TK_END_KW,

    //Characters
    TK_PLUS,
    TK_MINUS,
    TK_STAR,
    TK_SLASH,
    TK_SEMICOLON,
    TK_OPEN_BRCKT,
    TK_CLOSE_BRCKT,
    TK_OPEN_C_BRCKT,
    TK_CLOSE_C_BRCKT,
};

//TODO: Add the SourceFile_t
struct TokenLoc_t {
    uint32_t        col;
    uint32_t        line;
    SourceFileId    source_id;
};

struct Token_t {
    TokenType       type;
    TokenLoc_t      loc;

    union {
        StringView_t    str_value;
        int32_t         int32_value;
    };
};

Token_t *token_new(Arena *arena, TokenType type, uint32_t col, uint32_t line);

#endif //SYNTAX_H