/* HSTMATCH module=EBOOT.BIN start=0x000ed948 end=0x000ed9d8 symbol=FUN_000ed948 lang=c++ */
/* Container reserve for a 96-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional; readability pass. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002c0864[];
}
struct Elem_000ed948 { int w[24]; };
struct Alloc_000ed948 { Elem_000ed948 *allocate(unsigned n) { return (Elem_000ed948 *)FUN_00000bcc(n * sizeof(Elem_000ed948)); } };
extern "C" void FUN_000ed948(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000ed948))
        FUN_000043b4();
    Elem_000ed948 *p = Alloc_000ed948().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0864);
        FUN_0000d518();
    }
    v->data = p; /* new element storage */
    v->capacity = n;
}
