/* HSTMATCH module=EBOOT.BIN start=0x000b6438 end=0x000b64e0 symbol=FUN_000b6438 lang=c++ */
/* Container reserve for a 18-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002d47c0[];                              /* length-error message */
extern char DAT_002bffe8[];                              /* allocation-failure message */
}
struct Elem18 { char b[18]; };
struct Elem18Alloc { Elem18 *allocate(unsigned n) { return (Elem18 *)FUN_00000bcc(n * sizeof(Elem18)); } };
extern "C" void FUN_000b6438(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem18)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d47c0);
        FUN_0000d518();
    }
    Elem18 *p = Elem18Alloc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bffe8);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
