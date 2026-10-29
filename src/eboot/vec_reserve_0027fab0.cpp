/* HSTMATCH module=EBOOT.BIN start=0x0027fab0 end=0x0027fb58 symbol=FUN_0027fab0 lang=c++ */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0027ed88(void *stream, const char *format, ...);
extern char DAT_002fe84c[];
extern char DAT_002caa3c[];
}
/* 40-byte element */
struct Elem { int w[10]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
struct Vec { Elem *data; int size; unsigned capacity; };
extern "C" void FUN_0027fab0(Vec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem)) {
        FUN_0027ed88(FUN_0000fe3c()->err, DAT_002fe84c);
        FUN_0000d518();
    }
    Elem *storage = Alloc().allocate(count);
    if (storage == 0) {
        FUN_0027ed88(FUN_0000fe3c()->err, DAT_002caa3c);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
