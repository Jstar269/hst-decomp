/* HSTMATCH module=EBOOT.BIN start=0x00238608 end=0x00238698 symbol=FUN_00238608 lang=c++ */
/* Container reserve for a 28-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00238608 { int pad[3]; void *err; };
Reent_00238608 *FUN_0000fe3c(void);
int FUN_002374c8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c9f04[];
}
struct Elem_00238608 { int w[7]; };
struct Alloc_00238608 { Elem_00238608 *allocate(unsigned n) { return (Elem_00238608 *)FUN_00000bcc(n * sizeof(Elem_00238608)); } };
struct Vec_00238608 { Elem_00238608 *data; int size; unsigned capacity; };
extern "C" void FUN_00238608(Vec_00238608 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00238608))
        FUN_000043b4();
    Elem_00238608 *p = Alloc_00238608().allocate(n);
    if (p == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f04);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
