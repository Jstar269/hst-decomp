/* HSTMATCH module=hstp_trans_main.prx start=0x000b9728 end=0x000b97d0 symbol=FUN_000b9728 lang=c++ */
/* Container reserve for a 18-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000b9728 { int pad[3]; void *err; };
Reent_000b9728 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037b044[];
extern char DAT_002cffd4[];
}
struct Elem_000b9728 { char b[18]; };
struct Alloc_000b9728 { Elem_000b9728 *allocate(unsigned n) { return (Elem_000b9728 *)FUN_00000bcc(n * sizeof(Elem_000b9728)); } };
struct Vec_000b9728 { Elem_000b9728 *data; int size; unsigned capacity; };
extern "C" void FUN_000b9728(Vec_000b9728 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000b9728)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037b044);
        FUN_0000d530();
    }
    Elem_000b9728 *p = Alloc_000b9728().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cffd4);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
