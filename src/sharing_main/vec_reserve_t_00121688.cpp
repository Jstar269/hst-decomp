/* HSTMATCH module=hstp_trans_main.prx start=0x00121688 end=0x00121718 symbol=FUN_00121688 lang=c++ */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00121688 { int pad[3]; void *err; };
Reent_00121688 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d15f8[];
}
struct Elem_00121688 { int w[3]; };
struct Alloc_00121688 { Elem_00121688 *allocate(unsigned n) { return (Elem_00121688 *)FUN_00000bcc(n * sizeof(Elem_00121688)); } };
struct Vec_00121688 { Elem_00121688 *data; int size; unsigned capacity; };
extern "C" void FUN_00121688(Vec_00121688 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00121688))
        FUN_000043b4();
    Elem_00121688 *p = Alloc_00121688().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d15f8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
