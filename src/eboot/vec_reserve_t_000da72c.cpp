/* HSTMATCH module=EBOOT.BIN start=0x000da72c end=0x000da7bc symbol=FUN_000da72c lang=c++ */
/* Container reserve for a 6-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000da72c { int pad[3]; void *err; };
Reent_000da72c *FUN_0000fe3c(void);
int FUN_000d9a00(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c06f0[];
}
struct Elem_000da72c { char b[6]; };
struct Alloc_000da72c { Elem_000da72c *allocate(unsigned n) { return (Elem_000da72c *)FUN_00000bcc(n * sizeof(Elem_000da72c)); } };
struct Vec_000da72c { Elem_000da72c *data; int size; unsigned capacity; };
extern "C" void FUN_000da72c(Vec_000da72c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000da72c))
        FUN_000043b4();
    Elem_000da72c *p = Alloc_000da72c().allocate(n);
    if (p == 0) {
        FUN_000d9a00(FUN_0000fe3c()->err, DAT_002c06f0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
