/* HSTMATCH module=EBOOT.BIN start=0x0006d708 end=0x0006d798 symbol=FUN_0006d708 lang=c++ */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0006d708 { int pad[3]; void *err; };
Reent_0006d708 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002bc66c[];
}
struct Elem_0006d708 { int w[10]; };
struct Alloc_0006d708 { Elem_0006d708 *allocate(unsigned n) { return (Elem_0006d708 *)FUN_00000bcc(n * sizeof(Elem_0006d708)); } };
struct Vec_0006d708 { Elem_0006d708 *data; int size; unsigned capacity; };
extern "C" void FUN_0006d708(Vec_0006d708 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0006d708))
        FUN_000043b4();
    Elem_0006d708 *p = Alloc_0006d708().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc66c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
