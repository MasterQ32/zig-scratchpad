#pragma once 

#include <stddef.h>
#include <stdbool.h>

struct LibBDocument {
    void * data;
    size_t size;
};

bool libb_load(struct LibBDocument * result, char const * fname);

void libb_free(struct LibBDocument document);
