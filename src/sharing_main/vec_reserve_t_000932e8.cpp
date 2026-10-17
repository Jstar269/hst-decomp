/* HSTMATCH module=hstp_trans_main.prx start=0x000932e8 end=0x0009336c symbol=FUN_000932e8 lang=c++ */
/* Container reserve for a 32-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000932e8 { int pad[3]; void *err; };
Reent_000932e8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cea90[];
}
struct Elem_000932e8 { int w[8]; };
struct Alloc_000932e8 { Elem_000932e8 *allocate(unsigned n) { return (Elem_000932e8 *)FUN_00000bcc(n * sizeof(Elem_000932e8)); } };
struct Vec_000932e8 { Elem_000932e8 *data; int size; unsigned capacity; };
extern "C" void FUN_000932e8(Vec_000932e8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000932e8))
        FUN_000043b4();
    Elem_000932e8 *p = Alloc_000932e8().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cea90);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
