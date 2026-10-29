/* HSTMATCH module=EBOOT.BIN start=0x0014b208 end=0x0014b2b0 symbol=FUN_0014b208 lang=c++ */
/* Container reserve for a 80-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_00145ac4(void *stream, const char *format, ...);
extern char DAT_002dc120[];   /* length error message */
extern char DAT_002c18a0[]; /* allocation failure message */
}
struct Elem_0014b208 { int w[20]; };
struct Alloc_0014b208 { Elem_0014b208 *allocate(unsigned n) { return (Elem_0014b208 *)FUN_00000bcc(n * sizeof(Elem_0014b208)); } };
extern "C" void FUN_0014b208(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem_0014b208)) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002dc120);
        FUN_0000d518();
    }
    Elem_0014b208 *mem = Alloc_0014b208().allocate(count);
    if (mem == 0) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c18a0);
        FUN_0000d518();
    }
    vec->data = mem;
    vec->capacity = count;
}
