#include "view.h"

StringView_t view_fstr(const char *ptr)
{
    return (StringView_t){
        .ptr = ptr,
        .length = strlen(ptr)
    };
}

StringView_t view_fstrl(const char *ptr, size_t length)
{
    return (StringView_t){
        .ptr = ptr,
        .length = length,
    };
}

StringView_t view_slice(StringView_t view, size_t index, size_t length) 
{
    assert(index + length <= view.length);
    return (StringView_t){
        .ptr = view.ptr + index,
        .length = length,
    };
}

unsigned char view_char_at(const StringView_t view, size_t index)
{
    if (index >= view.length) return '\0';
    return view.ptr[index];
}

bool view_streq(const StringView_t left, const char *right)
{
    for (size_t i = 0; i < left.length; i++, right++) {
        if (view_char_at(left, i) != *right) {
            return false;
        }
    }

    return true;
}

bool view_eq(const StringView_t left, const StringView_t right)
{
    if (left.length != right.length) return false;
    for (size_t i = 0; i < left.length; i++) {
        if (view_char_at(left, i) != view_char_at(right, i)) {
            return false;
        }
    }
    return false;
}