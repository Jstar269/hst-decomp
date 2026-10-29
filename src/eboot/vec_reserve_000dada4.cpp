/* HSTMATCH module=EBOOT.BIN start=0x000dada4 end=0x000dae4c symbol=FUN_000dada4 lang=c++ data=0x002d6af0 */
/* Container reserve for a 6-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x002d6af0-0x002d6b04) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. Readability pass: shared RawVec/Reent from the header. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_000d9a00(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002c06f0[];                              /* out-of-memory message */
}

struct Elem6 { char b[6]; };

/* Allocator that returns uninitialised storage for n elements. */
struct Elem6Alloc {
    Elem6 *allocate(unsigned n) { return (Elem6 *)FUN_00000bcc(n * sizeof(Elem6)); }
};

/* Reserve storage for n elements: fail with a length error when n exceeds the maximum, or with the
   out-of-memory message when the allocation returns null. */
extern "C" void FUN_000dada4(RawVec *vec, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem6)) {
        FUN_000d9a00(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem6 *p = Elem6Alloc().allocate(n);
    if (p == 0) {
        FUN_000d9a00(FUN_0000fe3c()->err, DAT_002c06f0);
        FUN_0000d518();
    }
    vec->data = p;
    vec->capacity = n;
}
