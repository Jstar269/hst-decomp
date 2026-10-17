/* HSTMATCH module=EBOOT.BIN start=0x000e9678 end=0x000e9728 symbol=FUN_000e9678 lang=c++ */
/* Container reserve for a 752-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000e9678 { int pad[3]; void *err; };
Reent_000e9678 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d6b70[];
extern char DAT_002c076c[];
}
struct Elem_000e9678 { int w[188]; };
struct Alloc_000e9678 { Elem_000e9678 *allocate(unsigned n) { return (Elem_000e9678 *)FUN_00000bcc(n * sizeof(Elem_000e9678)); } };
struct Vec_000e9678 { Elem_000e9678 *data; int size; unsigned capacity; };
extern "C" void FUN_000e9678(Vec_000e9678 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000e9678)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6b70);
        FUN_0000d518();
    }
    Elem_000e9678 *p = Alloc_000e9678().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c076c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
