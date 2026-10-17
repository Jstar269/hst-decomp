/* HSTMATCH module=EBOOT.BIN start=0x002381f0 end=0x00238280 symbol=FUN_002381f0 lang=c++ */
/* Container reserve for a 72-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_002381f0 { int pad[3]; void *err; };
Reent_002381f0 *FUN_0000fe3c(void);
int FUN_002374c8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c9f20[];
}
struct Elem_002381f0 { int w[18]; };
struct Alloc_002381f0 { Elem_002381f0 *allocate(unsigned n) { return (Elem_002381f0 *)FUN_00000bcc(n * sizeof(Elem_002381f0)); } };
struct Vec_002381f0 { Elem_002381f0 *data; int size; unsigned capacity; };
extern "C" void FUN_002381f0(Vec_002381f0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002381f0))
        FUN_000043b4();
    Elem_002381f0 *p = Alloc_002381f0().allocate(n);
    if (p == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f20);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
