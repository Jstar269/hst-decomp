/* HSTMATCH module=EBOOT.BIN start=0x0014b028 end=0x0014b0d0 symbol=FUN_0014b028 lang=c++ */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0014b028 { int pad[3]; void *err; };
Reent_0014b028 *FUN_0000fe3c(void);
int FUN_00145ac4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dc120[];
extern char DAT_002c18d8[];
}
struct Elem_0014b028 { int w[10]; };
struct Alloc_0014b028 { Elem_0014b028 *allocate(unsigned n) { return (Elem_0014b028 *)FUN_00000bcc(n * sizeof(Elem_0014b028)); } };
struct Vec_0014b028 { Elem_0014b028 *data; int size; unsigned capacity; };
extern "C" void FUN_0014b028(Vec_0014b028 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014b028)) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002dc120);
        FUN_0000d518();
    }
    Elem_0014b028 *p = Alloc_0014b028().allocate(n);
    if (p == 0) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c18d8);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
