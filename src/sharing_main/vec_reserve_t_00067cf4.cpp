/* HSTMATCH module=hstp_trans_main.prx start=0x00067cf4 end=0x00067d84 symbol=FUN_00067cf4 lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00067cf4 { int pad[3]; void *err; };
Reent_00067cf4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc484[];
}
struct Elem_00067cf4 { int w[3]; };
struct Alloc_00067cf4 { Elem_00067cf4 *allocate(unsigned n) { return (Elem_00067cf4 *)FUN_00000bcc(n * sizeof(Elem_00067cf4)); } };
struct Vec_00067cf4 { Elem_00067cf4 *data; int size; unsigned capacity; };
extern "C" void FUN_00067cf4(Vec_00067cf4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00067cf4))
        FUN_000043b4();
    Elem_00067cf4 *p = Alloc_00067cf4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc484);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
