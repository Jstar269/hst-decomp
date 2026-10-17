/* HSTMATCH module=EBOOT.BIN start=0x00215fb4 end=0x00216038 symbol=FUN_00215fb4 lang=c++ */
/* Container reserve for a 8-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00215fb4 { int pad[3]; void *err; };
Reent_00215fb4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c9820[];
}
struct Elem_00215fb4 { int w[2]; };
struct Alloc_00215fb4 { Elem_00215fb4 *allocate(unsigned n) { return (Elem_00215fb4 *)FUN_00000bcc(n * sizeof(Elem_00215fb4)); } };
struct Vec_00215fb4 { Elem_00215fb4 *data; int size; unsigned capacity; };
extern "C" void FUN_00215fb4(Vec_00215fb4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00215fb4))
        FUN_000043b4();
    Elem_00215fb4 *p = Alloc_00215fb4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c9820);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
