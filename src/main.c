#define ARENA_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "syntax.h"
#include "context.h"

int main() 
{
    BlyatCtx_t ctx = {0};
    Arena ctx_arena = {0};

    if (!context_add_source(&ctx, &ctx_arena, "samples/main.cya")) {
        arena_free(&ctx_arena);
        return EXIT_FAILURE;
    }

    

    arena_free(&ctx_arena);
    return 0;
}