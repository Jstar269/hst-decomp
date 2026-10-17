/* HSTMATCH module=hstp_trans_main.prx start=0x0014abd4 end=0x0014ac70 symbol=FUN_0014abd4 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0014abd4 { int pad[3]; void *err; };
Reent_0014abd4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00382d80[];
extern char DAT_002d1b4c[];
}
struct Elem_0014abd4 { int w[4]; };
struct Alloc_0014abd4 { Elem_0014abd4 *allocate(unsigned n) { return (Elem_0014abd4 *)FUN_00000bcc(n * sizeof(Elem_0014abd4)); } };
struct Vec_0014abd4 { Elem_0014abd4 *data; int size; unsigned capacity; };
extern "C" void FUN_0014abd4(Vec_0014abd4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014abd4)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00382d80);
        FUN_0000d530();
    }
    Elem_0014abd4 *p = Alloc_0014abd4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1b4c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
