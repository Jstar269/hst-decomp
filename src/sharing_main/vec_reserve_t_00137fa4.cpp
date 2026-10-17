/* HSTMATCH module=hstp_trans_main.prx start=0x00137fa4 end=0x00138028 symbol=FUN_00137fa4 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00137fa4 { int pad[3]; void *err; };
Reent_00137fa4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d09b8[];
}
struct Elem_00137fa4 { int w[4]; };
struct Alloc_00137fa4 { Elem_00137fa4 *allocate(unsigned n) { return (Elem_00137fa4 *)FUN_00000bcc(n * sizeof(Elem_00137fa4)); } };
struct Vec_00137fa4 { Elem_00137fa4 *data; int size; unsigned capacity; };
extern "C" void FUN_00137fa4(Vec_00137fa4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00137fa4))
        FUN_000043b4();
    Elem_00137fa4 *p = Alloc_00137fa4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d09b8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
