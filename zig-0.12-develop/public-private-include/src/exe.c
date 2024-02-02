#include "compression.h" // this should be the one from lib-a
#include "loader.h" // from lib-b

int main()
{
    struct LibBDocument doc;
    if(!libb_load(&doc, "build.zig"))
        return false;

    size_t o = 0;
    while(o < doc.size)
    {
        char tmp[128];
        size_t l = liba_compress(tmp, sizeof tmp, (char*)doc.data + o, doc.size - o);

        fwrite(tmp, 1, l, stderr);
    }

    libb_free(doc);
}