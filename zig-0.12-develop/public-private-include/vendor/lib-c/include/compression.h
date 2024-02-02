// LIB-C
#pragma once 

#include <stddef.h>

struct LibCompression_Stream {
    char buffer[256 - sizeof(size_t)];
    size_t level;
};

size_t libc_push(
    struct LibCompression_Stream * stream,
    void const * in_buffer,
    size_t in_buffer_len
);

size_t libc_pull(
    struct LibCompression_Stream * stream,
    void * out_buffer,
    size_t out_buffer_len
);
