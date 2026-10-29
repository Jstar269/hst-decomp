/* HSTMATCH module=EBOOT.BIN start=0x0028d9dc end=0x0028da84 symbol=FUN_0028d9dc lang=c++ */
/* Container reserve for a 28-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0028c0cc(void *stream, const char *format, ...);
extern char DAT_002feed0[];
extern char DAT_002cab5c[];
}
struct Elem28 { int w[7]; };
struct Alloc { Elem28 *allocate(unsigned n) { return (Elem28 *)FUN_00000bcc(n * sizeof(Elem28)); } };

/* Reserves room for new_capacity elements in an empty vector; length error or allocation failure aborts. */
extern "C" void FUN_0028d9dc(RawVec *vec, unsigned new_capacity)
{
    if (new_capacity > 0xffffffffu / sizeof(Elem28)) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002feed0);
        FUN_0000d518();
    }
    Elem28 *p = Alloc().allocate(new_capacity);
    if (p == 0) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002cab5c);
        FUN_0000d518();
    }
    vec->data = p;
    vec->capacity = new_capacity;
}
