/* HSTMATCH module=EBOOT.BIN start=0x00091650 end=0x000916d4 symbol=FUN_00091650 lang=c++ */
/* Container reserve for a 32-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002beb00[];
}

enum { ELEM_SIZE = 32 }; /* bytes per element */
struct Elem32 { int w[ELEM_SIZE / 4]; };
struct Alloc32 { Elem32 *allocate(unsigned n) { return (Elem32 *)FUN_00000bcc(n * sizeof(Elem32)); } };

/* Allocate storage for count elements; length error handler when too many, abort when out of memory. */
extern "C" void FUN_00091650(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem32))
        FUN_000043b4();
    Elem32 *storage = Alloc32().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002beb00);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
