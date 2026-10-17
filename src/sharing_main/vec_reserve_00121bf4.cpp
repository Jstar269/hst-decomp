/* HSTMATCH module=hstp_trans_main.prx start=0x00121bf4 end=0x00121c90 symbol=FUN_00121bf4 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00121bf4 { int pad[3]; void *err; };
Reent_00121bf4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003801bc[];
extern char DAT_002d15dc[];
}
struct Elem_00121bf4 { int w[4]; };
struct Alloc_00121bf4 { Elem_00121bf4 *allocate(unsigned n) { return (Elem_00121bf4 *)FUN_00000bcc(n * sizeof(Elem_00121bf4)); } };
struct Vec_00121bf4 { Elem_00121bf4 *data; int size; unsigned capacity; };
extern "C" void FUN_00121bf4(Vec_00121bf4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00121bf4)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003801bc);
        FUN_0000d530();
    }
    Elem_00121bf4 *p = Alloc_00121bf4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d15dc);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
