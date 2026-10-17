/* HSTMATCH module=EBOOT.BIN start=0x0023790c end=0x002379a4 symbol=FUN_0023790c lang=c++ */
/* Container reserve for a 560-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0023790c { int pad[3]; void *err; };
Reent_0023790c *FUN_0000fe3c(void);
int FUN_002374c8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c9f3c[];
}
struct Elem_0023790c { int w[140]; };
struct Alloc_0023790c { Elem_0023790c *allocate(unsigned n) { return (Elem_0023790c *)FUN_00000bcc(n * sizeof(Elem_0023790c)); } };
struct Vec_0023790c { Elem_0023790c *data; int size; unsigned capacity; };
extern "C" void FUN_0023790c(Vec_0023790c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0023790c))
        FUN_000043b4();
    Elem_0023790c *p = Alloc_0023790c().allocate(n);
    if (p == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f3c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
