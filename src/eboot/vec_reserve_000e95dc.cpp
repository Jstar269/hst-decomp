/* HSTMATCH module=EBOOT.BIN start=0x000e95dc end=0x000e9678 symbol=FUN_000e95dc lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002d6b70[];
extern char DAT_002c0788[];
}

enum { ELEM_SIZE = 16 }; /* bytes per element */
struct Elem16 { int w[ELEM_SIZE / 4]; };
struct Alloc16 { Elem16 *allocate(unsigned n) { return (Elem16 *)FUN_00000bcc(n * sizeof(Elem16)); } };

/* Allocate storage for count elements; abort with a message when too many or out of memory. */
extern "C" void FUN_000e95dc(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem16)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6b70);
        FUN_0000d518();
    }
    Elem16 *storage = Alloc16().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0788);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
