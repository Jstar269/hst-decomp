/* HSTMATCH module=EBOOT.BIN start=0x0006d828 end=0x0006d8d0 symbol=FUN_0006d828 lang=c++ */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0006d828 { int pad[3]; void *err; };
Reent_0006d828 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d12e0[];
extern char DAT_002bc66c[];
}
struct Elem_0006d828 { int w[10]; };
struct Alloc_0006d828 { Elem_0006d828 *allocate(unsigned n) { return (Elem_0006d828 *)FUN_00000bcc(n * sizeof(Elem_0006d828)); } };
struct Vec_0006d828 { Elem_0006d828 *data; int size; unsigned capacity; };
extern "C" void FUN_0006d828(Vec_0006d828 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0006d828)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d12e0);
        FUN_0000d518();
    }
    Elem_0006d828 *p = Alloc_0006d828().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc66c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
