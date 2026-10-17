/* HSTMATCH module=EBOOT.BIN start=0x0013f624 end=0x0013f6c0 symbol=FUN_0013f624 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0013f624 { int pad[3]; void *err; };
Reent_0013f624 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dbb20[];
extern char DAT_002c1750[];
}
struct Elem_0013f624 { int w[4]; };
struct Alloc_0013f624 { Elem_0013f624 *allocate(unsigned n) { return (Elem_0013f624 *)FUN_00000bcc(n * sizeof(Elem_0013f624)); } };
struct Vec_0013f624 { Elem_0013f624 *data; int size; unsigned capacity; };
extern "C" void FUN_0013f624(Vec_0013f624 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0013f624)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dbb20);
        FUN_0000d518();
    }
    Elem_0013f624 *p = Alloc_0013f624().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1750);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
