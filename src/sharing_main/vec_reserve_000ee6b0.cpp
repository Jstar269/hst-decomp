/* HSTMATCH module=hstp_trans_main.prx start=0x000ee6b0 end=0x000ee74c symbol=FUN_000ee6b0 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000ee6b0 { int pad[3]; void *err; };
Reent_000ee6b0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d948[];
extern char DAT_002d09b8[];
}
struct Elem_000ee6b0 { int w[4]; };
struct Alloc_000ee6b0 { Elem_000ee6b0 *allocate(unsigned n) { return (Elem_000ee6b0 *)FUN_00000bcc(n * sizeof(Elem_000ee6b0)); } };
struct Vec_000ee6b0 { Elem_000ee6b0 *data; int size; unsigned capacity; };
extern "C" void FUN_000ee6b0(Vec_000ee6b0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000ee6b0)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037d948);
        FUN_0000d530();
    }
    Elem_000ee6b0 *p = Alloc_000ee6b0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d09b8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
