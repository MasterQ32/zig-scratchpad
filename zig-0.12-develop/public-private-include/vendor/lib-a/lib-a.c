#include "compression.h"

#include <string.h>

static size_t minl(size_t a, size_t b)
{
    return (a < b) ? a : b;
}

size_t liba_compress(
    void * out_buffer, 
    size_t out_buffer_len, 
    void const * in_buffer,
    size_t in_buffer_len
)
{
    size_t const l = minl(out_buffer_len, in_buffer_len);
    memcpy(out_buffer, in_buffer, l); // lol "compression" my ass
    return l;
}
