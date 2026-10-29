/* HSTMATCH module=EBOOT.BIN start=0x002944ac end=0x00294554 symbol=FUN_002944ac lang=c++ data=0x002ffc40 */
/* Container reserve for a 10-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional; readability pass. Data: its string literals (1 strings, 0x002ffc40-0x002ffc54) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_00294480(void *stream, const char *format, ...);
extern char DAT_002cac44[];
}
struct Elem10 { char b[10]; };
struct Alloc10 { Elem10 *allocate(unsigned n) { return (Elem10 *)FUN_00000bcc(n * sizeof(Elem10)); } };

/* Allocates room for n elements; aborts through the error stream on a length error or failed allocation. */
extern "C" void FUN_002944ac(RawVec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem10)) {
        FUN_00294480(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem10 *p = Alloc10().allocate(n);
    if (p == 0) {
        FUN_00294480(FUN_0000fe3c()->err, DAT_002cac44);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
