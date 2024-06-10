#ifndef CONTEXT_H
#define CONTEXT_H

#include <string.h>

#include "file.h"
#include "arena.h"

typedef struct BlyatCtx_t BlyatCtx_t;

struct BlyatCtx_t {
    size_t           sources_len;
    SourceFile_t    *sources;
};

// void context_destroy(BlyatCtx_t *ctx, Arena *arena);
SourceFileId context_add_source(BlyatCtx_t *ctx, Arena *arena, const char *src_path);
SourceFile_t *context_get_source(BlyatCtx_t *ctx, const SourceFileId id);

#endif //CONTEXT_H