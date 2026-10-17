/* HSTMATCH module=EBOOT.BIN start=0x001097a4 end=0x0010984c symbol=FUN_001097a4 lang=c++ */
/* Container reserve for a 36-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_001097a4 { int pad[3]; void *err; };
Reent_001097a4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d8dbc[];
extern char DAT_002c1010[];
}
struct Elem_001097a4 { int w[9]; };
struct Alloc_001097a4 { Elem_001097a4 *allocate(unsigned n) { return (Elem_001097a4 *)FUN_00000bcc(n * sizeof(Elem_001097a4)); } };
struct Vec_001097a4 { Elem_001097a4 *data; int size; unsigned capacity; };
extern "C" void FUN_001097a4(Vec_001097a4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001097a4)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d8dbc);
        FUN_0000d518();
    }
    Elem_001097a4 *p = Alloc_001097a4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1010);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
