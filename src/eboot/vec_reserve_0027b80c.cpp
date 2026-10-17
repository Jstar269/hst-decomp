/* HSTMATCH module=EBOOT.BIN start=0x0027b80c end=0x0027b8b4 symbol=FUN_0027b80c lang=c++ */
/* Container reserve for a 48-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0027b80c { int pad[3]; void *err; };
Reent_0027b80c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002fe6ac[];
extern char DAT_002ca9cc[];
}
struct Elem_0027b80c { int w[12]; };
struct Alloc_0027b80c { Elem_0027b80c *allocate(unsigned n) { return (Elem_0027b80c *)FUN_00000bcc(n * sizeof(Elem_0027b80c)); } };
struct Vec_0027b80c { Elem_0027b80c *data; int size; unsigned capacity; };
extern "C" void FUN_0027b80c(Vec_0027b80c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0027b80c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002fe6ac);
        FUN_0000d518();
    }
    Elem_0027b80c *p = Alloc_0027b80c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002ca9cc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
