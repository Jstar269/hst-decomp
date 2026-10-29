/* HSTMATCH module=EBOOT.BIN start=0x0028db20 end=0x0028dbc8 symbol=FUN_0028db20 lang=c++ */
/* Container reserve for a 96-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0028c0cc(void *stream, const char *format, ...);
extern char DAT_002feed0[];
extern char DAT_002cab24[];
}
struct Elem96 { int w[24]; };
struct Alloc { Elem96 *allocate(unsigned n) { return (Elem96 *)FUN_00000bcc(n * sizeof(Elem96)); } };

/* Reserves room for new_capacity elements in an empty vector; length error or allocation failure aborts. */
extern "C" void FUN_0028db20(RawVec *vec, unsigned new_capacity)
{
    if (new_capacity > 0xffffffffu / sizeof(Elem96)) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002feed0);
        FUN_0000d518();
    }
    Elem96 *p = Alloc().allocate(new_capacity);
    if (p == 0) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002cab24);
        FUN_0000d518();
    }
    vec->data = p;
    vec->capacity = new_capacity;
}
