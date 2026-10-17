/* HSTMATCH module=hstp_trans_main.prx start=0x0010f564 end=0x0010f60c symbol=FUN_0010f564 lang=c++ */
/* Container reserve for a 36-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0010f564 { int pad[3]; void *err; };
Reent_0010f564 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037fb90[];
extern char DAT_002d12c0[];
}
struct Elem_0010f564 { int w[9]; };
struct Alloc_0010f564 { Elem_0010f564 *allocate(unsigned n) { return (Elem_0010f564 *)FUN_00000bcc(n * sizeof(Elem_0010f564)); } };
struct Vec_0010f564 { Elem_0010f564 *data; int size; unsigned capacity; };
extern "C" void FUN_0010f564(Vec_0010f564 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0010f564)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037fb90);
        FUN_0000d530();
    }
    Elem_0010f564 *p = Alloc_0010f564().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d12c0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
