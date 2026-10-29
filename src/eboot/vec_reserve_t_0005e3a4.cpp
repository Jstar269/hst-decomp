/* HSTMATCH module=EBOOT.BIN start=0x0005e3a4 end=0x0005e434 symbol=FUN_0005e3a4 lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0005dd0c(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002bc5a8[];                              /* allocation-failure message */
}
struct Elem12 { int w[3]; };
struct Elem12Alloc { Elem12 *allocate(unsigned n) { return (Elem12 *)FUN_00000bcc(n * sizeof(Elem12)); } };
extern "C" void FUN_0005e3a4(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem12))
        FUN_000043b4();
    Elem12 *p = Elem12Alloc().allocate(n);
    if (p == 0) {
        FUN_0005dd0c(FUN_0000fe3c()->err, DAT_002bc5a8);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
