/* HSTMATCH module=EBOOT.BIN start=0x000e95dc end=0x000e9678 symbol=FUN_000e95dc lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000e95dc { int pad[3]; void *err; };
Reent_000e95dc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d6b70[];
extern char DAT_002c0788[];
}
struct Elem_000e95dc { int w[4]; };
struct Alloc_000e95dc { Elem_000e95dc *allocate(unsigned n) { return (Elem_000e95dc *)FUN_00000bcc(n * sizeof(Elem_000e95dc)); } };
struct Vec_000e95dc { Elem_000e95dc *data; int size; unsigned capacity; };
extern "C" void FUN_000e95dc(Vec_000e95dc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000e95dc)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6b70);
        FUN_0000d518();
    }
    Elem_000e95dc *p = Alloc_000e95dc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0788);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
