/* HSTMATCH module=EBOOT.BIN start=0x000edde0 end=0x000ede88 symbol=FUN_000edde0 lang=c++ data=0x002d6c88 */
/* Container reserve for a 24-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional; readability pass. Data: its string literals (1 strings, 0x002d6c88-0x002d6c9c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002c0848[];
}
struct Elem_000edde0 { int w[6]; };
struct Alloc_000edde0 { Elem_000edde0 *allocate(unsigned n) { return (Elem_000edde0 *)FUN_00000bcc(n * sizeof(Elem_000edde0)); } };
extern "C" void FUN_000edde0(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000edde0)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem_000edde0 *p = Alloc_000edde0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0848);
        FUN_0000d518();
    }
    v->data = p; /* new element storage */
    v->capacity = n;
}
