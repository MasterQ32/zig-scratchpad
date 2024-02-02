#include "loader.h"

#include <compression.h> // external dependency

#include <stdlib.h>
#include <stdio.h>

#define DATA_MAX_LEN (1024UL)

bool libb_load(struct LibBDocument * result, char const * fname)
{
    FILE * f = fopen(fname, "rb");
    if(!f)
        return false;

    char * out = malloc(DATA_MAX_LEN);

    struct LibCompression_Stream stream = {0};

    size_t cursor = 0;
    while(cursor < DATA_MAX_LEN)
    {
        char tmp[512];
        ssize_t l = fread(tmp, 1, sizeof tmp, f);
        if(l < 0) {
            free(out);
            return false;
        }

        size_t o = 0;
        while(o < sizeof tmp && cursor < DATA_MAX_LEN)
        {
            o += libc_push(&stream, tmp + o, sizeof tmp - o);
            cursor += libc_pull(&stream, out + cursor, DATA_MAX_LEN - cursor);
        }
    }
    
    fclose(f);
    *result = (struct LibBDocument) {
        .data = out,
        .size = 
    };
    return true;
}

void libb_free(struct LibBDocument document)
{
    free(document.data);
}

