/* HSTMATCH module=EBOOT.BIN start=0x000d7978 end=0x000d7a14 symbol=FUN_000d7978 lang=c++ */
/* Container reserve for a 64-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002d6854[];
extern char DAT_002c0608[];
}
/* Element type of the vector being reserved. */
struct Elem_000d7978 { int w[16]; };
struct Alloc_000d7978 { Elem_000d7978 *allocate(unsigned n) { return (Elem_000d7978 *)FUN_00000bcc(n * sizeof(Elem_000d7978)); } };
/* Vector header: element storage, elements in use, elements allocated. */
struct Vec_000d7978 { Elem_000d7978 *data; int size; unsigned capacity; };
extern "C" void FUN_000d7978(Vec_000d7978 *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem_000d7978)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6854);
        FUN_0000d518();
    }
    Elem_000d7978 *storage = Alloc_000d7978().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0608);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
