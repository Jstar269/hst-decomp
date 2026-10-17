/* HSTMATCH module=EBOOT.BIN start=0x0028db20 end=0x0028dbc8 symbol=FUN_0028db20 lang=c++ */
/* Container reserve for a 96-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0028db20 { int pad[3]; void *err; };
Reent_0028db20 *FUN_0000fe3c(void);
int FUN_0028c0cc(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002feed0[];
extern char DAT_002cab24[];
}
struct Elem_0028db20 { int w[24]; };
struct Alloc_0028db20 { Elem_0028db20 *allocate(unsigned n) { return (Elem_0028db20 *)FUN_00000bcc(n * sizeof(Elem_0028db20)); } };
struct Vec_0028db20 { Elem_0028db20 *data; int size; unsigned capacity; };
extern "C" void FUN_0028db20(Vec_0028db20 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0028db20)) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002feed0);
        FUN_0000d518();
    }
    Elem_0028db20 *p = Alloc_0028db20().allocate(n);
    if (p == 0) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002cab24);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
