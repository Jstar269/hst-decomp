/* HSTMATCH module=EBOOT.BIN start=0x000668a0 end=0x00066930 symbol=FUN_000668a0 lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000668a0 { int pad[3]; void *err; };
Reent_000668a0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002bc634[];
}
struct Elem_000668a0 { int w[3]; };
struct Alloc_000668a0 { Elem_000668a0 *allocate(unsigned n) { return (Elem_000668a0 *)FUN_00000bcc(n * sizeof(Elem_000668a0)); } };
struct Vec_000668a0 { Elem_000668a0 *data; int size; unsigned capacity; };
extern "C" void FUN_000668a0(Vec_000668a0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000668a0))
        FUN_000043b4();
    Elem_000668a0 *p = Alloc_000668a0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc634);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
