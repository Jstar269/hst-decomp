/* HSTMATCH module=hstp_trans_main.prx start=0x00156c40 end=0x00156ce8 symbol=FUN_00156c40 lang=c++ */
/* Container reserve for a 48-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00156c40 { int pad[3]; void *err; };
Reent_00156c40 *FUN_0000fe3c(void);
int FUN_0014db60(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00383478[];
extern char DAT_002d1c48[];
}
struct Elem_00156c40 { int w[12]; };
struct Alloc_00156c40 { Elem_00156c40 *allocate(unsigned n) { return (Elem_00156c40 *)FUN_00000bcc(n * sizeof(Elem_00156c40)); } };
struct Vec_00156c40 { Elem_00156c40 *data; int size; unsigned capacity; };
extern "C" void FUN_00156c40(Vec_00156c40 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00156c40)) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_00383478);
        FUN_0000d530();
    }
    Elem_00156c40 *p = Alloc_00156c40().allocate(n);
    if (p == 0) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_002d1c48);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
