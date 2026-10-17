/* HSTMATCH module=hstp_trans_main.prx start=0x000de6ec end=0x000de77c symbol=FUN_000de6ec lang=c++ */
/* Container reserve for a 6-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000de6ec { int pad[3]; void *err; };
Reent_000de6ec *FUN_0000fe3c(void);
int FUN_000dd96c(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d0920[];
}
struct Elem_000de6ec { char b[6]; };
struct Alloc_000de6ec { Elem_000de6ec *allocate(unsigned n) { return (Elem_000de6ec *)FUN_00000bcc(n * sizeof(Elem_000de6ec)); } };
struct Vec_000de6ec { Elem_000de6ec *data; int size; unsigned capacity; };
extern "C" void FUN_000de6ec(Vec_000de6ec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000de6ec))
        FUN_000043b4();
    Elem_000de6ec *p = Alloc_000de6ec().allocate(n);
    if (p == 0) {
        FUN_000dd96c(FUN_0000fe3c()->err, DAT_002d0920);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
