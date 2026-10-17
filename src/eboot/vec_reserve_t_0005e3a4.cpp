/* HSTMATCH module=EBOOT.BIN start=0x0005e3a4 end=0x0005e434 symbol=FUN_0005e3a4 lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0005e3a4 { int pad[3]; void *err; };
Reent_0005e3a4 *FUN_0000fe3c(void);
int FUN_0005dd0c(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002bc5a8[];
}
struct Elem_0005e3a4 { int w[3]; };
struct Alloc_0005e3a4 { Elem_0005e3a4 *allocate(unsigned n) { return (Elem_0005e3a4 *)FUN_00000bcc(n * sizeof(Elem_0005e3a4)); } };
struct Vec_0005e3a4 { Elem_0005e3a4 *data; int size; unsigned capacity; };
extern "C" void FUN_0005e3a4(Vec_0005e3a4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0005e3a4))
        FUN_000043b4();
    Elem_0005e3a4 *p = Alloc_0005e3a4().allocate(n);
    if (p == 0) {
        FUN_0005dd0c(FUN_0000fe3c()->err, DAT_002bc5a8);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
