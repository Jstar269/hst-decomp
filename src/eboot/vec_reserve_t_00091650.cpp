/* HSTMATCH module=EBOOT.BIN start=0x00091650 end=0x000916d4 symbol=FUN_00091650 lang=c++ */
/* Container reserve for a 32-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00091650 { int pad[3]; void *err; };
Reent_00091650 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002beb00[];
}
struct Elem_00091650 { int w[8]; };
struct Alloc_00091650 { Elem_00091650 *allocate(unsigned n) { return (Elem_00091650 *)FUN_00000bcc(n * sizeof(Elem_00091650)); } };
struct Vec_00091650 { Elem_00091650 *data; int size; unsigned capacity; };
extern "C" void FUN_00091650(Vec_00091650 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00091650))
        FUN_000043b4();
    Elem_00091650 *p = Alloc_00091650().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002beb00);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
