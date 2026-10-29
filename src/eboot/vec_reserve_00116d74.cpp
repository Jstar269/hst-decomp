/* HSTMATCH module=EBOOT.BIN start=0x00116d74 end=0x00116e1c symbol=FUN_00116d74 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
extern char DAT_002d9370[];
extern char DAT_002c1218[];
}
/* 12-byte element */
struct Elem { int w[3]; };
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
struct Vec { Elem *data; int size; unsigned capacity; };
extern "C" void FUN_00116d74(Vec *vec, unsigned count)
{
    if (count > 0xffffffffu / sizeof(Elem)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d9370);
        FUN_0000d518();
    }
    Elem *storage = Alloc().allocate(count);
    if (storage == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1218);
        FUN_0000d518();
    }
    vec->data = storage;
    vec->capacity = count;
}
