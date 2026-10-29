/* HSTMATCH module=EBOOT.BIN start=0x0027b80c end=0x0027b8b4 symbol=FUN_0027b80c lang=c++ */
/* Container reserve for a 48-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002fe6ac[];
extern char DAT_002ca9cc[];
}
struct Elem48 { int w[12]; };
struct Alloc48 { Elem48 *allocate(unsigned n) { return (Elem48 *)FUN_00000bcc(n * sizeof(Elem48)); } };

/* Allocate storage for n elements and set the capacity; aborts when n is too large or allocation fails. */
extern "C" void FUN_0027b80c(RawVec *vec, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem48)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002fe6ac);
        FUN_0000d518();
    }
    Elem48 *p = Alloc48().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002ca9cc);
        FUN_0000d518();
    }
    vec->data = p;
    vec->capacity = n;
}
