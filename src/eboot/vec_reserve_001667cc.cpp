/* HSTMATCH module=EBOOT.BIN start=0x001667cc end=0x00166874 symbol=FUN_001667cc lang=c++ */
/* Container reserve for a 20-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern char DAT_002e03e8[]; /* length-error message */
extern char DAT_002c1d90[]; /* allocation-failure message */

struct Elem { int w[5]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
struct Vec { Elem *data; int size; unsigned capacity; };
/* Reserve storage for `count` 20-byte elements: abort with a message when the length is too large or the allocation fails. */
extern "C" void FUN_001667cc(Vec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem)) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002e03e8);
        FUN_0000d518();
    }
    Elem *p = Alloc().allocate(count);
    if (p == 0) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002c1d90);
        FUN_0000d518();
    }
    vec->data = p;
    vec->capacity = count;
}
