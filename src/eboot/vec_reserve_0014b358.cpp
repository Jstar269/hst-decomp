/* HSTMATCH module=EBOOT.BIN start=0x0014b358 end=0x0014b400 symbol=FUN_0014b358 lang=c++ */
/* Container reserve for a 48-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0014b358 { int pad[3]; void *err; };
Reent_0014b358 *FUN_0000fe3c(void);
int FUN_00145ac4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dc120[];
extern char DAT_002c1868[];
}
struct Elem_0014b358 { int w[12]; };
struct Alloc_0014b358 { Elem_0014b358 *allocate(unsigned n) { return (Elem_0014b358 *)FUN_00000bcc(n * sizeof(Elem_0014b358)); } };
struct Vec_0014b358 { Elem_0014b358 *data; int size; unsigned capacity; };
extern "C" void FUN_0014b358(Vec_0014b358 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014b358)) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002dc120);
        FUN_0000d518();
    }
    Elem_0014b358 *p = Alloc_0014b358().allocate(n);
    if (p == 0) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c1868);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
