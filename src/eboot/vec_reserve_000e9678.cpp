/* HSTMATCH module=EBOOT.BIN start=0x000e9678 end=0x000e9728 symbol=FUN_000e9678 lang=c++ */
/* Container reserve for a 752-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002d6b70[];
extern char DAT_002c076c[];
}

enum { ELEM_SIZE = 752 }; /* bytes per element */
struct Elem752 { int w[ELEM_SIZE / 4]; };
struct Alloc752 { Elem752 *allocate(unsigned n) { return (Elem752 *)FUN_00000bcc(n * sizeof(Elem752)); } };

/* Allocate storage for count elements; abort with a message when too many or out of memory. */
extern "C" void FUN_000e9678(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem752)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6b70);
        FUN_0000d518();
    }
    Elem752 *storage = Alloc752().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c076c);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
