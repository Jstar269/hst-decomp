/* HSTMATCH module=EBOOT.BIN start=0x0006d708 end=0x0006d798 symbol=FUN_0006d708 lang=c++ */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002bc66c[];
}
struct Elem { int w[10]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
struct Vec { Elem *data; int size; unsigned capacity; };
extern "C" void FUN_0006d708(Vec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem))
        FUN_000043b4();
    Elem *p = Alloc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc66c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
