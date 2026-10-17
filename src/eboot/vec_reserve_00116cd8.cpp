/* HSTMATCH module=EBOOT.BIN start=0x00116cd8 end=0x00116d74 symbol=FUN_00116cd8 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00116cd8 { int pad[3]; void *err; };
Reent_00116cd8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d9370[];
extern char DAT_002c11fc[];
}
struct Elem_00116cd8 { int w[4]; };
struct Alloc_00116cd8 { Elem_00116cd8 *allocate(unsigned n) { return (Elem_00116cd8 *)FUN_00000bcc(n * sizeof(Elem_00116cd8)); } };
struct Vec_00116cd8 { Elem_00116cd8 *data; int size; unsigned capacity; };
extern "C" void FUN_00116cd8(Vec_00116cd8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00116cd8)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d9370);
        FUN_0000d518();
    }
    Elem_00116cd8 *p = Alloc_00116cd8().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c11fc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
