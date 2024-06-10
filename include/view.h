#ifndef VIEW_H
#define VIEW_H

#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define __VIEW_FMT__ "%.*s"
#define __VIEW_ARGS__(V) V.length, V.buffer

typedef struct StringView_t StringView_t;

struct StringView_t {
    const char  *ptr;
    size_t      length;
};

StringView_t view_fstr(const char *ptr);
StringView_t view_fstrl(const char *ptr, size_t length);
StringView_t view_slice(StringView_t view, size_t index, size_t length);

bool view_eq(const StringView_t left, const StringView_t right);
bool view_streq(const StringView_t left, const char *right);

unsigned char view_char_at(const StringView_t view, size_t index);

#endif //VIEW_H