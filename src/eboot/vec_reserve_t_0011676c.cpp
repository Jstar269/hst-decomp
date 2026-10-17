/* HSTMATCH module=EBOOT.BIN start=0x0011676c end=0x001167fc symbol=FUN_0011676c lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0011676c { int pad[3]; void *err; };
Reent_0011676c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c1218[];
}
struct Elem_0011676c { int w[3]; };
struct Alloc_0011676c { Elem_0011676c *allocate(unsigned n) { return (Elem_0011676c *)FUN_00000bcc(n * sizeof(Elem_0011676c)); } };
struct Vec_0011676c { Elem_0011676c *data; int size; unsigned capacity; };
extern "C" void FUN_0011676c(Vec_0011676c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0011676c))
        FUN_000043b4();
    Elem_0011676c *p = Alloc_0011676c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1218);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
