/* HSTMATCH module=EBOOT.BIN start=0x001665ac end=0x0016663c symbol=FUN_001665ac lang=c++ */
/* Container reserve for a 20-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_001665ac { int pad[3]; void *err; };
Reent_001665ac *FUN_0000fe3c(void);
int FUN_00165ef4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c1d90[];
}
struct Elem_001665ac { int w[5]; };
struct Alloc_001665ac { Elem_001665ac *allocate(unsigned n) { return (Elem_001665ac *)FUN_00000bcc(n * sizeof(Elem_001665ac)); } };
struct Vec_001665ac { Elem_001665ac *data; int size; unsigned capacity; };
extern "C" void FUN_001665ac(Vec_001665ac *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001665ac))
        FUN_000043b4();
    Elem_001665ac *p = Alloc_001665ac().allocate(n);
    if (p == 0) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002c1d90);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
