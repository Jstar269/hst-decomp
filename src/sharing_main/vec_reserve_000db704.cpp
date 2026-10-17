/* HSTMATCH module=hstp_trans_main.prx start=0x000db704 end=0x000db7ac symbol=FUN_000db704 lang=c++ */
/* Container reserve for a 24-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000db704 { int pad[3]; void *err; };
Reent_000db704 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d344[];
extern char DAT_002d081c[];
}
struct Elem_000db704 { int w[6]; };
struct Alloc_000db704 { Elem_000db704 *allocate(unsigned n) { return (Elem_000db704 *)FUN_00000bcc(n * sizeof(Elem_000db704)); } };
struct Vec_000db704 { Elem_000db704 *data; int size; unsigned capacity; };
extern "C" void FUN_000db704(Vec_000db704 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000db704)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037d344);
        FUN_0000d530();
    }
    Elem_000db704 *p = Alloc_000db704().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d081c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
