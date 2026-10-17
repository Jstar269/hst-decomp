/* HSTMATCH module=hstp_trans_main.prx start=0x000ded64 end=0x000dee0c symbol=FUN_000ded64 lang=c++ */
/* Container reserve for a 6-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000ded64 { int pad[3]; void *err; };
Reent_000ded64 *FUN_0000fe3c(void);
int FUN_000dd96c(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d724[];
extern char DAT_002d0920[];
}
struct Elem_000ded64 { char b[6]; };
struct Alloc_000ded64 { Elem_000ded64 *allocate(unsigned n) { return (Elem_000ded64 *)FUN_00000bcc(n * sizeof(Elem_000ded64)); } };
struct Vec_000ded64 { Elem_000ded64 *data; int size; unsigned capacity; };
extern "C" void FUN_000ded64(Vec_000ded64 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000ded64)) {
        FUN_000dd96c(FUN_0000fe3c()->err, DAT_0037d724);
        FUN_0000d530();
    }
    Elem_000ded64 *p = Alloc_000ded64().allocate(n);
    if (p == 0) {
        FUN_000dd96c(FUN_0000fe3c()->err, DAT_002d0920);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
