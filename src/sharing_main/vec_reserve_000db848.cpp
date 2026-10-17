/* HSTMATCH module=hstp_trans_main.prx start=0x000db848 end=0x000db8e4 symbol=FUN_000db848 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000db848 { int pad[3]; void *err; };
Reent_000db848 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d344[];
extern char DAT_002d07e4[];
}
struct Elem_000db848 { int w[4]; };
struct Alloc_000db848 { Elem_000db848 *allocate(unsigned n) { return (Elem_000db848 *)FUN_00000bcc(n * sizeof(Elem_000db848)); } };
struct Vec_000db848 { Elem_000db848 *data; int size; unsigned capacity; };
extern "C" void FUN_000db848(Vec_000db848 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000db848)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037d344);
        FUN_0000d530();
    }
    Elem_000db848 *p = Alloc_000db848().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d07e4);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
