/* HSTMATCH module=EBOOT.BIN start=0x000d7a14 end=0x000d7abc symbol=FUN_000d7a14 lang=c++ */
/* Container reserve for a 24-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000d7a14 { int pad[3]; void *err; };
Reent_000d7a14 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d6854[];
extern char DAT_002c05ec[];
}
struct Elem_000d7a14 { int w[6]; };
struct Alloc_000d7a14 { Elem_000d7a14 *allocate(unsigned n) { return (Elem_000d7a14 *)FUN_00000bcc(n * sizeof(Elem_000d7a14)); } };
struct Vec_000d7a14 { Elem_000d7a14 *data; int size; unsigned capacity; };
extern "C" void FUN_000d7a14(Vec_000d7a14 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000d7a14)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6854);
        FUN_0000d518();
    }
    Elem_000d7a14 *p = Alloc_000d7a14().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c05ec);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
