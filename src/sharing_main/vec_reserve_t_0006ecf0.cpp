/* HSTMATCH module=hstp_trans_main.prx start=0x0006ecf0 end=0x0006ed80 symbol=FUN_0006ecf0 lang=c++ */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0006ecf0 { int pad[3]; void *err; };
Reent_0006ecf0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc514[];
}
struct Elem_0006ecf0 { int w[10]; };
struct Alloc_0006ecf0 { Elem_0006ecf0 *allocate(unsigned n) { return (Elem_0006ecf0 *)FUN_00000bcc(n * sizeof(Elem_0006ecf0)); } };
struct Vec_0006ecf0 { Elem_0006ecf0 *data; int size; unsigned capacity; };
extern "C" void FUN_0006ecf0(Vec_0006ecf0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0006ecf0))
        FUN_000043b4();
    Elem_0006ecf0 *p = Alloc_0006ecf0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc514);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
