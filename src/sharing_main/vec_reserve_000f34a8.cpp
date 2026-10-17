/* HSTMATCH module=hstp_trans_main.prx start=0x000f34a8 end=0x000f3550 symbol=FUN_000f34a8 lang=c++ */
/* Container reserve for a 24-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000f34a8 { int pad[3]; void *err; };
Reent_000f34a8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037da60[];
extern char DAT_002d0ab8[];
}
struct Elem_000f34a8 { int w[6]; };
struct Alloc_000f34a8 { Elem_000f34a8 *allocate(unsigned n) { return (Elem_000f34a8 *)FUN_00000bcc(n * sizeof(Elem_000f34a8)); } };
struct Vec_000f34a8 { Elem_000f34a8 *data; int size; unsigned capacity; };
extern "C" void FUN_000f34a8(Vec_000f34a8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000f34a8)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037da60);
        FUN_0000d530();
    }
    Elem_000f34a8 *p = Alloc_000f34a8().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d0ab8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
