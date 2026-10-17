/* HSTMATCH module=EBOOT.BIN start=0x001a8944 end=0x001a89ec symbol=FUN_001a8944 lang=c++ */
/* Container reserve for a 48-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_001a8944 { int pad[3]; void *err; };
Reent_001a8944 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e1d10[];
extern char DAT_002c2efc[];
}
struct Elem_001a8944 { int w[12]; };
struct Alloc_001a8944 { Elem_001a8944 *allocate(unsigned n) { return (Elem_001a8944 *)FUN_00000bcc(n * sizeof(Elem_001a8944)); } };
struct Vec_001a8944 { Elem_001a8944 *data; int size; unsigned capacity; };
extern "C" void FUN_001a8944(Vec_001a8944 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001a8944)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e1d10);
        FUN_0000d518();
    }
    Elem_001a8944 *p = Alloc_001a8944().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2efc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
