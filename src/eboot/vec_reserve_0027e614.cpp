/* HSTMATCH module=EBOOT.BIN start=0x0027e614 end=0x0027e6c4 symbol=FUN_0027e614 lang=c++ data=0x002fe784 */
/* Container reserve for a 104-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. Data: its string literals (1 strings, 0x002fe784-0x002fe798) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
struct Reent_0027e614 { int pad[3]; void *err; };
Reent_0027e614 *FUN_0000fe3c(void);
int FUN_0027e558(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002caa20[];
}
struct Elem_0027e614 { int w[26]; };
struct Alloc_0027e614 { Elem_0027e614 *allocate(unsigned n) { return (Elem_0027e614 *)FUN_00000bcc(n * sizeof(Elem_0027e614)); } };
struct Vec_0027e614 { Elem_0027e614 *data; int size; unsigned capacity; };
extern "C" void FUN_0027e614(Vec_0027e614 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0027e614)) {
        FUN_0027e558(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    Elem_0027e614 *p = Alloc_0027e614().allocate(n);
    if (p == 0) {
        FUN_0027e558(FUN_0000fe3c()->err, DAT_002caa20);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
