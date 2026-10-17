/* HSTMATCH module=EBOOT.BIN start=0x0005a1ec end=0x0005a294 symbol=FUN_0005a1ec lang=c++ */
/* Container reserve for a 144-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0005a1ec { int pad[3]; void *err; };
Reent_0005a1ec *FUN_0000fe3c(void);
int FUN_00059cc8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d0f50[];
extern char DAT_002bc4d0[];
}
struct Elem_0005a1ec { int w[36]; };
struct Alloc_0005a1ec { Elem_0005a1ec *allocate(unsigned n) { return (Elem_0005a1ec *)FUN_00000bcc(n * sizeof(Elem_0005a1ec)); } };
struct Vec_0005a1ec { Elem_0005a1ec *data; int size; unsigned capacity; };
extern "C" void FUN_0005a1ec(Vec_0005a1ec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0005a1ec)) {
        FUN_00059cc8(FUN_0000fe3c()->err, DAT_002d0f50);
        FUN_0000d518();
    }
    Elem_0005a1ec *p = Alloc_0005a1ec().allocate(n);
    if (p == 0) {
        FUN_00059cc8(FUN_0000fe3c()->err, DAT_002bc4d0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
