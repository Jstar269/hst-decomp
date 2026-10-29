/* HSTMATCH module=EBOOT.BIN start=0x00215fb4 end=0x00216038 symbol=FUN_00215fb4 lang=c++ */
/* Container reserve for a 8-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002c9820[];
}
struct Elem { int w[2]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
/* Allocates storage for n elements and records it as the capacity; aborts on a length or allocation error. */
extern "C" void FUN_00215fb4(RawVec *vec, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem))
        FUN_000043b4();
    Elem *mem = Alloc().allocate(n);
    if (mem == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c9820);
        FUN_0000d518();
    }
    vec->data = mem;
    vec->capacity = n;
}
