/* HSTMATCH module=hstp_trans_main.prx start=0x00121a50 end=0x00121ad4 symbol=FUN_00121a50 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00121a50 { int pad[3]; void *err; };
Reent_00121a50 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d15dc[];
}
struct Elem_00121a50 { int w[4]; };
struct Alloc_00121a50 { Elem_00121a50 *allocate(unsigned n) { return (Elem_00121a50 *)FUN_00000bcc(n * sizeof(Elem_00121a50)); } };
struct Vec_00121a50 { Elem_00121a50 *data; int size; unsigned capacity; };
extern "C" void FUN_00121a50(Vec_00121a50 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00121a50))
        FUN_000043b4();
    Elem_00121a50 *p = Alloc_00121a50().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d15dc);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
