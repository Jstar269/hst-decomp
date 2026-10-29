/* HSTMATCH module=EBOOT.BIN start=0x0005a1ec end=0x0005a294 symbol=FUN_0005a1ec lang=c++ */
/* Container reserve for a 144-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_00059cc8(void *stream, const char *format, ...);
extern char DAT_002d0f50[];
extern char DAT_002bc4d0[];
}
struct Elem { int w[36]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
/* Allocates storage for n elements and records it as the capacity; aborts on a length or allocation error. */
extern "C" void FUN_0005a1ec(RawVec *vec, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem)) {
        FUN_00059cc8(FUN_0000fe3c()->err, DAT_002d0f50);
        FUN_0000d518();
    }
    Elem *mem = Alloc().allocate(n);
    if (mem == 0) {
        FUN_00059cc8(FUN_0000fe3c()->err, DAT_002bc4d0);
        FUN_0000d518();
    }
    vec->data = mem;
    vec->capacity = n;
}
