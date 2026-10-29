/* HSTMATCH module=EBOOT.BIN start=0x0027e614 end=0x0027e6c4 symbol=FUN_0027e614 lang=c++ data=0x002fe784 */
/* Container reserve for a 104-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x002fe784-0x002fe798) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0027e558(void *stream, const char *format, ...); /* fprintf */
extern char DAT_002caa20[];                              /* allocation-failure message */
}
struct Elem104 { int w[26]; };
struct Elem104Alloc { Elem104 *allocate(unsigned n) { return (Elem104 *)FUN_00000bcc(n * sizeof(Elem104)); } };
extern "C" void FUN_0027e614(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem104)) {
        FUN_0027e558(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem104 *p = Elem104Alloc().allocate(n);
    if (p == 0) {
        FUN_0027e558(FUN_0000fe3c()->err, DAT_002caa20);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
