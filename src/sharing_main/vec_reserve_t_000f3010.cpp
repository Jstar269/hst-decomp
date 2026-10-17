/* HSTMATCH module=hstp_trans_main.prx start=0x000f3010 end=0x000f30a0 symbol=FUN_000f3010 lang=c++ */
/* Container reserve for a 96-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000f3010 { int pad[3]; void *err; };
Reent_000f3010 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d0ad4[];
}
struct Elem_000f3010 { int w[24]; };
struct Alloc_000f3010 { Elem_000f3010 *allocate(unsigned n) { return (Elem_000f3010 *)FUN_00000bcc(n * sizeof(Elem_000f3010)); } };
struct Vec_000f3010 { Elem_000f3010 *data; int size; unsigned capacity; };
extern "C" void FUN_000f3010(Vec_000f3010 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000f3010))
        FUN_000043b4();
    Elem_000f3010 *p = Alloc_000f3010().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d0ad4);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
