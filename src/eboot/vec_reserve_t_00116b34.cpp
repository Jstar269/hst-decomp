/* HSTMATCH module=EBOOT.BIN start=0x00116b34 end=0x00116bb8 symbol=FUN_00116b34 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002c11fc[];
}
/* 16-byte element */
struct Elem { int w[4]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
struct Vec { Elem *data; int size; unsigned capacity; };
extern "C" void FUN_00116b34(Vec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem))
        FUN_000043b4();
    Elem *storage = Alloc().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c11fc);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
