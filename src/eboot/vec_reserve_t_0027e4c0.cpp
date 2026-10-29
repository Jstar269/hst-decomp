/* HSTMATCH module=EBOOT.BIN start=0x0027e4c0 end=0x0027e558 symbol=FUN_0027e4c0 lang=c++ */
/* Container reserve for a 104-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0027e558(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002caa20[];                              /* allocation-failure message */
}
struct Elem104 { int w[26]; };
struct Elem104Alloc { Elem104 *allocate(unsigned n) { return (Elem104 *)FUN_00000bcc(n * sizeof(Elem104)); } };
extern "C" void FUN_0027e4c0(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem104))
        FUN_000043b4();
    Elem104 *p = Elem104Alloc().allocate(n);
    if (p == 0) {
        FUN_0027e558(FUN_0000fe3c()->err, DAT_002caa20);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
