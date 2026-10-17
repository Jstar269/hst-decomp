/* HSTMATCH module=EBOOT.BIN start=0x00238a0c end=0x00238ab4 symbol=FUN_00238a0c lang=c++ */
/* Container reserve for a 72-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00238a0c { int pad[3]; void *err; };
Reent_00238a0c *FUN_0000fe3c(void);
int FUN_002374c8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002f5300[];
extern char DAT_002c9f20[];
}
struct Elem_00238a0c { int w[18]; };
struct Alloc_00238a0c { Elem_00238a0c *allocate(unsigned n) { return (Elem_00238a0c *)FUN_00000bcc(n * sizeof(Elem_00238a0c)); } };
struct Vec_00238a0c { Elem_00238a0c *data; int size; unsigned capacity; };
extern "C" void FUN_00238a0c(Vec_00238a0c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00238a0c)) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002f5300);
        FUN_0000d518();
    }
    Elem_00238a0c *p = Alloc_00238a0c().allocate(n);
    if (p == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f20);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
