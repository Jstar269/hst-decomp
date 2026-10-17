/* HSTMATCH module=EBOOT.BIN start=0x00246484 end=0x00246514 symbol=FUN_00246484 lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00246484 { int pad[3]; void *err; };
Reent_00246484 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002ca49c[];
}
struct Elem_00246484 { int w[3]; };
struct Alloc_00246484 { Elem_00246484 *allocate(unsigned n) { return (Elem_00246484 *)FUN_00000bcc(n * sizeof(Elem_00246484)); } };
struct Vec_00246484 { Elem_00246484 *data; int size; unsigned capacity; };
extern "C" void FUN_00246484(Vec_00246484 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00246484))
        FUN_000043b4();
    Elem_00246484 *p = Alloc_00246484().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002ca49c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
