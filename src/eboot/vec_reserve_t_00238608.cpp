/* HSTMATCH module=EBOOT.BIN start=0x00238608 end=0x00238698 symbol=FUN_00238608 lang=c++ */
/* Container reserve for a 28-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_002374c8(void *stream, const char *format, ...);
extern char DAT_002c9f04[];
}

enum { ELEM_SIZE = 28 }; /* bytes per element */
struct Elem28 { int w[ELEM_SIZE / 4]; };
struct Alloc28 { Elem28 *allocate(unsigned n) { return (Elem28 *)FUN_00000bcc(n * sizeof(Elem28)); } };

/* Allocate storage for count elements; abort with a message when too many or out of memory. */
extern "C" void FUN_00238608(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem28))
        FUN_000043b4();
    Elem28 *storage = Alloc28().allocate(count);
    if (storage == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f04);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
