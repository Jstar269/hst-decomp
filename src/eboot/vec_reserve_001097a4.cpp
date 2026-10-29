/* HSTMATCH module=EBOOT.BIN start=0x001097a4 end=0x0010984c symbol=FUN_001097a4 lang=c++ */
/* Container reserve for a 36-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002d8dbc[];                              /* length-error message */
extern char DAT_002c1010[];                              /* allocation-failure message */
}
struct Elem36 { int w[9]; };
struct Elem36Alloc { Elem36 *allocate(unsigned n) { return (Elem36 *)FUN_00000bcc(n * sizeof(Elem36)); } };
extern "C" void FUN_001097a4(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem36)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d8dbc);
        FUN_0000d518();
    }
    Elem36 *p = Elem36Alloc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1010);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
