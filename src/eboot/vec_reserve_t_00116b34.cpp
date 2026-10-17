/* HSTMATCH module=EBOOT.BIN start=0x00116b34 end=0x00116bb8 symbol=FUN_00116b34 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00116b34 { int pad[3]; void *err; };
Reent_00116b34 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c11fc[];
}
struct Elem_00116b34 { int w[4]; };
struct Alloc_00116b34 { Elem_00116b34 *allocate(unsigned n) { return (Elem_00116b34 *)FUN_00000bcc(n * sizeof(Elem_00116b34)); } };
struct Vec_00116b34 { Elem_00116b34 *data; int size; unsigned capacity; };
extern "C" void FUN_00116b34(Vec_00116b34 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00116b34))
        FUN_000043b4();
    Elem_00116b34 *p = Alloc_00116b34().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c11fc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
