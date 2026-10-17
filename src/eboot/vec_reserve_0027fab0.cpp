/* HSTMATCH module=EBOOT.BIN start=0x0027fab0 end=0x0027fb58 symbol=FUN_0027fab0 lang=c++ */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0027fab0 { int pad[3]; void *err; };
Reent_0027fab0 *FUN_0000fe3c(void);
int FUN_0027ed88(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002fe84c[];
extern char DAT_002caa3c[];
}
struct Elem_0027fab0 { int w[10]; };
struct Alloc_0027fab0 { Elem_0027fab0 *allocate(unsigned n) { return (Elem_0027fab0 *)FUN_00000bcc(n * sizeof(Elem_0027fab0)); } };
struct Vec_0027fab0 { Elem_0027fab0 *data; int size; unsigned capacity; };
extern "C" void FUN_0027fab0(Vec_0027fab0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0027fab0)) {
        FUN_0027ed88(FUN_0000fe3c()->err, DAT_002fe84c);
        FUN_0000d518();
    }
    Elem_0027fab0 *p = Alloc_0027fab0().allocate(n);
    if (p == 0) {
        FUN_0027ed88(FUN_0000fe3c()->err, DAT_002caa3c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
