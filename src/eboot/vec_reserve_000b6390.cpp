/* HSTMATCH module=EBOOT.BIN start=0x000b6390 end=0x000b6438 symbol=FUN_000b6390 lang=c++ */
/* Container reserve for a 80-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002d47c0[];                              /* length-error message */
extern char DAT_002c0004[];                              /* allocation-failure message */
}
struct Elem80 { int w[20]; };
struct Elem80Alloc { Elem80 *allocate(unsigned n) { return (Elem80 *)FUN_00000bcc(n * sizeof(Elem80)); } };
extern "C" void FUN_000b6390(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem80)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d47c0);
        FUN_0000d518();
    }
    Elem80 *p = Elem80Alloc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0004);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
