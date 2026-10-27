/* HSTMATCH module=EBOOT.BIN start=0x000dada4 end=0x000dae4c symbol=FUN_000dada4 lang=c++ data=0x002d6af0 */
/* Container reserve for a 6-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x002d6af0-0x002d6b04) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
struct Reent_000dada4 { int pad[3]; void *err; };
Reent_000dada4 *FUN_0000fe3c(void);
int FUN_000d9a00(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c06f0[];
}
struct Elem_000dada4 { char b[6]; };
struct Alloc_000dada4 { Elem_000dada4 *allocate(unsigned n) { return (Elem_000dada4 *)FUN_00000bcc(n * sizeof(Elem_000dada4)); } };
struct Vec_000dada4 { Elem_000dada4 *data; int size; unsigned capacity; };
extern "C" void FUN_000dada4(Vec_000dada4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000dada4)) {
        FUN_000d9a00(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem_000dada4 *p = Alloc_000dada4().allocate(n);
    if (p == 0) {
        FUN_000d9a00(FUN_0000fe3c()->err, DAT_002c06f0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
