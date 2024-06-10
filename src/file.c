#include "file.h"

char *file_read_buffer(Arena *arena, const char *path)
{
    FILE    *fptr;
    char    *buffer;
    size_t   fsize;
    size_t   bytes_read;

    fptr = fopen(path, "r");
    if (!fptr) return NULL;

    if (fseek(fptr, 0, SEEK_END) != 0) {
        fclose(fptr);
        return NULL;
    }

    fsize = ftell(fptr);

    if (fseek(fptr, 0, SEEK_SET) != 0) {
        fclose(fptr);
        return NULL;
    }

    //allocate memory for the buffer
    buffer = arena_alloc(arena, sizeof(char) * (fsize + 1));
    if (!buffer) {
        fclose(fptr);
        return NULL;
    }

    bytes_read = fread(buffer, sizeof(char), fsize, fptr);
    if (bytes_read < fsize) {
        fclose(fptr);
        arena_free(arena);
        return NULL;
    }

    buffer[fsize] = '\0';

    if (fclose(fptr) != 0) {
        arena_free(arena);
        return NULL;
    }

    return buffer;
}