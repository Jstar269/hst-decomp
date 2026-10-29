/* HSTMATCH module=EBOOT.BIN start=0x000b64e0 end=0x000b657c symbol=FUN_000b64e0 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
#include "hst/vec_reserve.h"

#define MAX_WORDS 0x3fffffff /* largest element count whose byte size fits in 32 bits */

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002d47c0[];                              /* length-error message */
extern char DAT_002bffcc[];                              /* allocation-failure message */
}
struct WordAlloc { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
extern "C" void FUN_000b64e0(RawVec *v, unsigned n)
{
    if (n > MAX_WORDS) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d47c0);
        FUN_0000d518();
    }
    void **p = WordAlloc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bffcc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
