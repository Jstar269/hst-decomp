/* HSTMATCH module=EBOOT.BIN start=0x0011676c end=0x001167fc symbol=FUN_0011676c lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002c1218[];
}
/* 12-byte element */
struct Elem { int w[3]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
struct Vec { Elem *data; int size; unsigned capacity; };
extern "C" void FUN_0011676c(Vec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem))
        FUN_000043b4();
    Elem *storage = Alloc().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1218);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
