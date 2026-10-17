/* HSTMATCH module=EBOOT.BIN start=0x001667cc end=0x00166874 symbol=FUN_001667cc lang=c++ */
/* Container reserve for a 20-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_001667cc { int pad[3]; void *err; };
Reent_001667cc *FUN_0000fe3c(void);
int FUN_00165ef4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e03e8[];
extern char DAT_002c1d90[];
}
struct Elem_001667cc { int w[5]; };
struct Alloc_001667cc { Elem_001667cc *allocate(unsigned n) { return (Elem_001667cc *)FUN_00000bcc(n * sizeof(Elem_001667cc)); } };
struct Vec_001667cc { Elem_001667cc *data; int size; unsigned capacity; };
extern "C" void FUN_001667cc(Vec_001667cc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001667cc)) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002e03e8);
        FUN_0000d518();
    }
    Elem_001667cc *p = Alloc_001667cc().allocate(n);
    if (p == 0) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002c1d90);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
