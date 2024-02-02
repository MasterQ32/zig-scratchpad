#include "compression.h"

#include <string.h>

static size_t minl(size_t a, size_t b)
{
    return (a < b) ? a : b;
}

size_t libc_push(
    struct LibCompression_Stream * stream,
    void const * in_buffer,
    size_t in_buffer_len
)
{
    size_t limit = minl(sizeof stream->buffer - stream->level, in_buffer_len);
    memcpy(stream->buffer + stream->level, in_buffer, limit);
    stream->level += limit;
    return limit;
}

size_t libc_pull(
    struct LibCompression_Stream * stream,
    void * out_buffer,
    size_t out_buffer_len
)
{
    size_t limit = minl(stream->level, out_buffer_len);
    memcpy(out_buffer, stream->buffer, limit);
    for(size_t i = 0; i < limit; i++) {
        stream->buffer[i] = stream->buffer[i + limit];
    }
    stream->level -= limit;
    return limit;
}
