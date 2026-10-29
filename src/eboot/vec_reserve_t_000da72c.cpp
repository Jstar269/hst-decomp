/* HSTMATCH module=EBOOT.BIN start=0x000da72c end=0x000da7bc symbol=FUN_000da72c lang=c++ */
/* Container reserve for a 6-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Readability pass: shared RawVec/Reent from the header. */
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

/* Reserve storage for n elements: the length-error handler runs when n exceeds the maximum, and the
   out-of-memory message is printed when the allocation returns null. */
extern "C" void FUN_000da72c(RawVec *vec, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem6))
        FUN_000043b4();
    Elem6 *p = Elem6Alloc().allocate(n);
    if (p == 0) {
        FUN_000d9a00(FUN_0000fe3c()->err, DAT_002c06f0);
        FUN_0000d518();
    }
    vec->data = p;
    vec->capacity = n;
}
