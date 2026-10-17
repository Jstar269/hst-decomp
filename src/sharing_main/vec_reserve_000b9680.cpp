/* HSTMATCH module=hstp_trans_main.prx start=0x000b9680 end=0x000b9728 symbol=FUN_000b9680 lang=c++ */
/* Container reserve for a 80-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000b9680 { int pad[3]; void *err; };
Reent_000b9680 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037b044[];
extern char DAT_002cfff0[];
}
struct Elem_000b9680 { int w[20]; };
struct Alloc_000b9680 { Elem_000b9680 *allocate(unsigned n) { return (Elem_000b9680 *)FUN_00000bcc(n * sizeof(Elem_000b9680)); } };
struct Vec_000b9680 { Elem_000b9680 *data; int size; unsigned capacity; };
extern "C" void FUN_000b9680(Vec_000b9680 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000b9680)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037b044);
        FUN_0000d530();
    }
    Elem_000b9680 *p = Alloc_000b9680().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cfff0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
