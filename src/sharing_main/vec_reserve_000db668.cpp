/* HSTMATCH module=hstp_trans_main.prx start=0x000db668 end=0x000db704 symbol=FUN_000db668 lang=c++ */
/* Container reserve for a 64-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000db668 { int pad[3]; void *err; };
Reent_000db668 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d344[];
extern char DAT_002d0838[];
}
struct Elem_000db668 { int w[16]; };
struct Alloc_000db668 { Elem_000db668 *allocate(unsigned n) { return (Elem_000db668 *)FUN_00000bcc(n * sizeof(Elem_000db668)); } };
struct Vec_000db668 { Elem_000db668 *data; int size; unsigned capacity; };
extern "C" void FUN_000db668(Vec_000db668 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000db668)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037d344);
        FUN_0000d530();
    }
    Elem_000db668 *p = Alloc_000db668().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d0838);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
