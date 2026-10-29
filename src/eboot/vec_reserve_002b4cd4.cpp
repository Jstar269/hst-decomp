/* HSTMATCH module=EBOOT.BIN start=0x002b4cd4 end=0x002b4d84 symbol=FUN_002b4cd4 lang=c++ data=0x003030ec */
/* Container reserve for a 100-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x003030ec-0x00303100) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002cc4d4[];
}
struct Elem { int w[25]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
/* Allocates storage for n elements and records it as the capacity; aborts on a length or allocation error. */
extern "C" void FUN_002b4cd4(RawVec *vec, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem *mem = Alloc().allocate(n);
    if (mem == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc4d4);
        FUN_0000d518();
    }
    vec->data = mem;
    vec->capacity = n;
}
