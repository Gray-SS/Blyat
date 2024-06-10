#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "view.h"
#include "arena.h"

typedef uint16_t SourceFileId;
typedef struct SourceFile_t SourceFile_t;

struct SourceFile_t {
    SourceFileId    id;
    char            *buffer;
    const char      *name;
};

char *file_read_buffer(Arena *arena, const char *path);

#endif //FILE_H