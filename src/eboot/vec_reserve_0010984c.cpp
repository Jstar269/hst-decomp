/* HSTMATCH module=EBOOT.BIN start=0x0010984c end=0x001098e8 symbol=FUN_0010984c lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002d8dbc[];                              /* length-error message */
extern char DAT_002c0ff4[];                              /* allocation-failure message */
}
struct Elem8 { int w[2]; };
struct Elem8Alloc { Elem8 *allocate(unsigned n) { return (Elem8 *)FUN_00000bcc(n * sizeof(Elem8)); } };
extern "C" void FUN_0010984c(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem8)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d8dbc);
        FUN_0000d518();
    }
    Elem8 *p = Elem8Alloc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0ff4);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
