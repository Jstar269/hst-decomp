/* HSTMATCH module=EBOOT.BIN start=0x00048dd0 end=0x00048e6c symbol=FUN_00048dd0 lang=c++ data=0x002d0718 */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x002d0718-0x002d072c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
struct Reent_00048dd0 { int pad[3]; void *err; };
Reent_00048dd0 *FUN_0000fe3c(void);
int FUN_00046564(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002bc204[];
}
struct Elem_00048dd0 { int w[4]; };
struct Alloc_00048dd0 { Elem_00048dd0 *allocate(unsigned n) { return (Elem_00048dd0 *)FUN_00000bcc(n * sizeof(Elem_00048dd0)); } };
struct Vec_00048dd0 { Elem_00048dd0 *data; int size; unsigned capacity; };
extern "C" void FUN_00048dd0(Vec_00048dd0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00048dd0)) {
        FUN_00046564(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem_00048dd0 *p = Alloc_00048dd0().allocate(n);
    if (p == 0) {
        FUN_00046564(FUN_0000fe3c()->err, DAT_002bc204);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
