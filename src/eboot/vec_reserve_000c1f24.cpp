/* HSTMATCH module=EBOOT.BIN start=0x000c1f24 end=0x000c1fcc symbol=FUN_000c1f24 lang=c++ data=0x002d5a78 */
/* Container reserve for a 80-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x002d5a78-0x002d5a8c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
struct Reent_000c1f24 { int pad[3]; void *err; };
Reent_000c1f24 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c01a0[];
}
struct Elem_000c1f24 { int w[20]; };
struct Alloc_000c1f24 { Elem_000c1f24 *allocate(unsigned n) { return (Elem_000c1f24 *)FUN_00000bcc(n * sizeof(Elem_000c1f24)); } };
struct Vec_000c1f24 { Elem_000c1f24 *data; int size; unsigned capacity; };
extern "C" void FUN_000c1f24(Vec_000c1f24 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000c1f24)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem_000c1f24 *p = Alloc_000c1f24().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c01a0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
