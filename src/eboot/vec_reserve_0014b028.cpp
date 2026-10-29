/* HSTMATCH module=EBOOT.BIN start=0x0014b028 end=0x0014b0d0 symbol=FUN_0014b028 lang=c++ */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_00145ac4(void *stream, const char *format, ...);
extern char DAT_002dc120[];   /* length error message */
extern char DAT_002c18d8[]; /* allocation failure message */
}
struct Elem_0014b028 { int w[10]; };
struct Alloc_0014b028 { Elem_0014b028 *allocate(unsigned n) { return (Elem_0014b028 *)FUN_00000bcc(n * sizeof(Elem_0014b028)); } };
extern "C" void FUN_0014b028(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem_0014b028)) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002dc120);
        FUN_0000d518();
    }
    Elem_0014b028 *mem = Alloc_0014b028().allocate(count);
    if (mem == 0) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c18d8);
        FUN_0000d518();
    }
    vec->data = mem;
    vec->capacity = count;
}
