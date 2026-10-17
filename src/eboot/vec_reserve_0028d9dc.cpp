/* HSTMATCH module=EBOOT.BIN start=0x0028d9dc end=0x0028da84 symbol=FUN_0028d9dc lang=c++ */
/* Container reserve for a 28-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0028d9dc { int pad[3]; void *err; };
Reent_0028d9dc *FUN_0000fe3c(void);
int FUN_0028c0cc(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002feed0[];
extern char DAT_002cab5c[];
}
struct Elem_0028d9dc { int w[7]; };
struct Alloc_0028d9dc { Elem_0028d9dc *allocate(unsigned n) { return (Elem_0028d9dc *)FUN_00000bcc(n * sizeof(Elem_0028d9dc)); } };
struct Vec_0028d9dc { Elem_0028d9dc *data; int size; unsigned capacity; };
extern "C" void FUN_0028d9dc(Vec_0028d9dc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0028d9dc)) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002feed0);
        FUN_0000d518();
    }
    Elem_0028d9dc *p = Alloc_0028d9dc().allocate(n);
    if (p == 0) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002cab5c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
