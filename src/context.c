#include "context.h"

SourceFileId context_add_source(BlyatCtx_t *ctx, Arena *ctx_arena, const char *src_path)
{
    static SourceFileId sid = 1;

    size_t new_len = ctx->sources_len + 1;
    SourceFile_t *new_array = arena_alloc(ctx_arena, sizeof(SourceFile_t) * new_len);
    if (!new_array) return 0;

    if (ctx->sources_len > 0)
        memcpy(new_array, ctx->sources, sizeof(SourceFile_t) * ctx->sources_len);

    char *buffer = file_read_buffer(ctx_arena, src_path);
    if (!buffer) return 0;

    new_array[ctx->sources_len] = (SourceFile_t){
        .id = sid++,
        .name = src_path,
        .buffer = buffer,
    };

    ctx->sources = new_array;
    ctx->sources_len = new_len;

    return sid - 1;
}

SourceFile_t *context_get_source(BlyatCtx_t *ctx, const SourceFileId id)
{
    assert(id <= ctx->sources_len);
    return &ctx->sources[id - 1];
}

// void context_destroy(BlyatCtx_t *ctx, Allocator_t *alctr)
// {
//     for (size_t i = 0; i < ctx->sources_len; i++) {
//         SourceFileId id = i + 1;
//         SourceFile_t *source = context_get_source(ctx, id);

//         alctr_free(alctr, source->buffer);
//     }
    
//     alctr_free(alctr, ctx->sources);
// }