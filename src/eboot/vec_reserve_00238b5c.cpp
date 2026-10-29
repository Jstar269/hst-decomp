/* HSTMATCH module=EBOOT.BIN start=0x00238b5c end=0x00238c0c symbol=FUN_00238b5c lang=c++ */
/* Container reserve for a 560-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_002374c8(void *stream, const char *format, ...);
extern char DAT_002f5300[];
extern char DAT_002c9f3c[];
}

enum { ELEM_SIZE = 560 }; /* bytes per element */
struct Elem560 { int w[ELEM_SIZE / 4]; };
struct Alloc560 { Elem560 *allocate(unsigned n) { return (Elem560 *)FUN_00000bcc(n * sizeof(Elem560)); } };

/* Allocate storage for count elements; abort with a message when too many or out of memory. */
extern "C" void FUN_00238b5c(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem560)) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002f5300);
        FUN_0000d518();
    }
    Elem560 *storage = Alloc560().allocate(count);
    if (storage == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f3c);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
