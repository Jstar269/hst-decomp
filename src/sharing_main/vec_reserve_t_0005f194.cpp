/* HSTMATCH module=hstp_trans_main.prx start=0x0005f194 end=0x0005f224 symbol=FUN_0005f194 lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0005f194 { int pad[3]; void *err; };
Reent_0005f194 *FUN_0000fe3c(void);
int FUN_0005dfc0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc3f8[];
}
struct Elem_0005f194 { int w[3]; };
struct Alloc_0005f194 { Elem_0005f194 *allocate(unsigned n) { return (Elem_0005f194 *)FUN_00000bcc(n * sizeof(Elem_0005f194)); } };
struct Vec_0005f194 { Elem_0005f194 *data; int size; unsigned capacity; };
extern "C" void FUN_0005f194(Vec_0005f194 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0005f194))
        FUN_000043b4();
    Elem_0005f194 *p = Alloc_0005f194().allocate(n);
    if (p == 0) {
        FUN_0005dfc0(FUN_0000fe3c()->err, DAT_002cc3f8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
