/* HSTMATCH module=EBOOT.BIN start=0x0013f588 end=0x0013f624 symbol=FUN_0013f588 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002dbb20[]; /* "vector length error" */
extern char DAT_002c176c[]; /* "Memory allocation failure" */
}

enum { ELEM_SIZE = 16 }; /* bytes per element */
struct Elem { int w[ELEM_SIZE / 4]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };

/* Allocate storage for count elements; abort with a message when too many or out of memory. */
extern "C" void FUN_0013f588(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dbb20);
        FUN_0000d518();
    }
    Elem *storage = Alloc().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c176c);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
