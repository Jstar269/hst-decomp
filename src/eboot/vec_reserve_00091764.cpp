/* HSTMATCH module=EBOOT.BIN start=0x00091764 end=0x00091800 symbol=FUN_00091764 lang=c++ data=0x002d2828 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d2828-0x002d283c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002beb00[];
}

enum { ELEM_SIZE = 32 }; /* bytes per element */
struct Elem32 { int w[ELEM_SIZE / 4]; };
struct Alloc32 { Elem32 *allocate(unsigned n) { return (Elem32 *)FUN_00000bcc(n * sizeof(Elem32)); } };

/* Allocate storage for count elements; abort with a message when too many or out of memory. */
extern "C" void FUN_00091764(RawVec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem32)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem32 *storage = Alloc32().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002beb00);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
