/* HSTMATCH module=EBOOT.BIN start=0x0012cb38 end=0x0012cbbc symbol=FUN_0012cb38 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0012cb38 { int pad[3]; void *err; };
Reent_0012cb38 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c0788[];
}
struct Elem_0012cb38 { int w[4]; };
struct Alloc_0012cb38 { Elem_0012cb38 *allocate(unsigned n) { return (Elem_0012cb38 *)FUN_00000bcc(n * sizeof(Elem_0012cb38)); } };
struct Vec_0012cb38 { Elem_0012cb38 *data; int size; unsigned capacity; };
extern "C" void FUN_0012cb38(Vec_0012cb38 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0012cb38))
        FUN_000043b4();
    Elem_0012cb38 *p = Alloc_0012cb38().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0788);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
