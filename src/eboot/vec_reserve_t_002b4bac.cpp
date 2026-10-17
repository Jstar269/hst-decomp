/* HSTMATCH module=EBOOT.BIN start=0x002b4bac end=0x002b4c44 symbol=FUN_002b4bac lang=c++ */
/* Container reserve for a 100-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_002b4bac { int pad[3]; void *err; };
Reent_002b4bac *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc4d4[];
}
struct Elem_002b4bac { int w[25]; };
struct Alloc_002b4bac { Elem_002b4bac *allocate(unsigned n) { return (Elem_002b4bac *)FUN_00000bcc(n * sizeof(Elem_002b4bac)); } };
struct Vec_002b4bac { Elem_002b4bac *data; int size; unsigned capacity; };
extern "C" void FUN_002b4bac(Vec_002b4bac *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002b4bac))
        FUN_000043b4();
    Elem_002b4bac *p = Alloc_002b4bac().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc4d4);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
