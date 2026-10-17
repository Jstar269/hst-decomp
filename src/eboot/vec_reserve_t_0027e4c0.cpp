/* HSTMATCH module=EBOOT.BIN start=0x0027e4c0 end=0x0027e558 symbol=FUN_0027e4c0 lang=c++ */
/* Container reserve for a 104-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0027e4c0 { int pad[3]; void *err; };
Reent_0027e4c0 *FUN_0000fe3c(void);
int FUN_0027e558(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002caa20[];
}
struct Elem_0027e4c0 { int w[26]; };
struct Alloc_0027e4c0 { Elem_0027e4c0 *allocate(unsigned n) { return (Elem_0027e4c0 *)FUN_00000bcc(n * sizeof(Elem_0027e4c0)); } };
struct Vec_0027e4c0 { Elem_0027e4c0 *data; int size; unsigned capacity; };
extern "C" void FUN_0027e4c0(Vec_0027e4c0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0027e4c0))
        FUN_000043b4();
    Elem_0027e4c0 *p = Alloc_0027e4c0().allocate(n);
    if (p == 0) {
        FUN_0027e558(FUN_0000fe3c()->err, DAT_002caa20);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
