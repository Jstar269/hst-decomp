/* HSTMATCH module=EBOOT.BIN start=0x00165e60 end=0x00165ef4 symbol=FUN_00165e60 lang=c++ */
/* Container reserve for a 556-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
#include "hst/vec_reserve.h"
#include "hst/char_param.h"

extern "C" {
extern char DAT_002c1dac[];
}
typedef CharParam Elem;
struct Alloc { Elem *allocate(unsigned n) { return (Elem *)FUN_00000bcc(n * sizeof(Elem)); } };
struct Vec { Elem *data; int size; unsigned capacity; };
extern "C" void FUN_00165e60(Vec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem))
        FUN_000043b4();
    Elem *p = Alloc().allocate(n);
    if (p == 0) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002c1dac);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
