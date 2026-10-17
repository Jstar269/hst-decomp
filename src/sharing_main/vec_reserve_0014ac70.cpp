/* HSTMATCH module=hstp_trans_main.prx start=0x0014ac70 end=0x0014ad0c symbol=FUN_0014ac70 lang=c++ */
/* Container reserve for a 16-byte element type (template instance, hsttmpl.py tag t1s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0014ac70 { int pad[3]; void *err; };
Reent_0014ac70 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00382d80[];
extern char DAT_002d1b30[];
}
struct Elem_0014ac70 { int w[4]; };
struct Alloc_0014ac70 { Elem_0014ac70 *allocate(unsigned n) { return (Elem_0014ac70 *)FUN_00000bcc(n * sizeof(Elem_0014ac70)); } };
struct Vec_0014ac70 { Elem_0014ac70 *data; int size; unsigned capacity; };
extern "C" void FUN_0014ac70(Vec_0014ac70 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014ac70)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00382d80);
        FUN_0000d530();
    }
    Elem_0014ac70 *p = Alloc_0014ac70().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1b30);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
