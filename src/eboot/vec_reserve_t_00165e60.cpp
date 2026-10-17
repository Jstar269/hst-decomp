/* HSTMATCH module=EBOOT.BIN start=0x00165e60 end=0x00165ef4 symbol=FUN_00165e60 lang=c++ */
/* Container reserve for a 556-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00165e60 { int pad[3]; void *err; };
Reent_00165e60 *FUN_0000fe3c(void);
int FUN_00165ef4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c1dac[];
}
struct Elem_00165e60 { int w[139]; };
struct Alloc_00165e60 { Elem_00165e60 *allocate(unsigned n) { return (Elem_00165e60 *)FUN_00000bcc(n * sizeof(Elem_00165e60)); } };
struct Vec_00165e60 { Elem_00165e60 *data; int size; unsigned capacity; };
extern "C" void FUN_00165e60(Vec_00165e60 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00165e60))
        FUN_000043b4();
    Elem_00165e60 *p = Alloc_00165e60().allocate(n);
    if (p == 0) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002c1dac);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
