/* HSTMATCH module=EBOOT.BIN start=0x0023790c end=0x002379a4 symbol=FUN_0023790c lang=c++ */
/* Container reserve for a 560-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_002374c8(void *stream, const char *format, ...);
extern char DAT_002c9f3c[];
}
struct Elem { int w[140]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
/* Allocates storage for n elements and records it as the capacity; aborts on a length or allocation error. */
extern "C" void FUN_0023790c(RawVec *vec, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem))
        FUN_000043b4();
    Elem *mem = Alloc().allocate(n);
    if (mem == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f3c);
        FUN_0000d518();
    }
    vec->data = mem;
    vec->capacity = n;
}
