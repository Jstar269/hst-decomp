/* HSTMATCH module=EBOOT.BIN start=0x002381f0 end=0x00238280 symbol=FUN_002381f0 lang=c++ */
/* Container reserve for a 72-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_002374c8(void *stream, const char *format, ...);
extern char DAT_002c9f20[];
}

enum { ELEM_SIZE = 72 }; /* bytes per element */
struct Elem72 { int w[ELEM_SIZE / 4]; };
struct Alloc72 { Elem72 *allocate(unsigned n) { return (Elem72 *)FUN_00000bcc(n * sizeof(Elem72)); } };

/* Allocate storage for count elements; abort with a message when too many or out of memory. */
extern "C" void FUN_002381f0(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem72))
        FUN_000043b4();
    Elem72 *storage = Alloc72().allocate(count);
    if (storage == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f20);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
