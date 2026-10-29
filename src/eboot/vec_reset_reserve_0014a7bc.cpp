/* HSTMATCH module=EBOOT.BIN start=0x0014a7bc end=0x0014a86c symbol=FUN_0014a7bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Word vector re-reserve: clear the size through `int n = size; shrink(n, Alloc());` (unfolded size - size;
   the empty allocator temporary gives the 16-byte frame slot), free the old block, then the inline reserve(n)
   (length check through 0x43b4, allocate, report failure on newlib stderr and abort). The second argument
   is unused. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_00145ac4(void *stream, const char *format, ...);
extern char DAT_002c18f4[];
}
struct Alloc { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec {
    void **data; int size; unsigned capacity;
    void shrink(int n, Alloc) { size -= n; }
    void reserve(unsigned n)
    {
        if (n > 0x3fffffff)
            FUN_000043b4();
        void **mem = Alloc().allocate(n);
        if (mem == 0) {
            FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c18f4);
            FUN_0000d518();
        }
        data = mem;
        capacity = n;
    }
};
/* Empties the vector, frees its block and reserves room for n elements. */
extern "C" void FUN_0014a7bc(Vec *vec, int unused, unsigned n)
{
    int k = vec->size;
    vec->shrink(k, Alloc());
    if (vec->data) {
        operator delete(vec->data);
        vec->data = 0;
        vec->capacity = 0;
    }
    vec->reserve(n);
}
