// LIB-A
#pragma once 

#include <stddef.h>

size_t liba_compress(
    void * out_buffer, 
    size_t out_buffer_len, 
    void const * in_buffer,
    size_t in_buffer_len
);
