/* HSTMATCH module=hstp_trans_main.prx start=0x000ee74c end=0x000ee7fc symbol=FUN_000ee74c lang=c++ */
/* Container reserve for a 752-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000ee74c { int pad[3]; void *err; };
Reent_000ee74c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d948[];
extern char DAT_002d099c[];
}
struct Elem_000ee74c { int w[188]; };
struct Alloc_000ee74c { Elem_000ee74c *allocate(unsigned n) { return (Elem_000ee74c *)FUN_00000bcc(n * sizeof(Elem_000ee74c)); } };
struct Vec_000ee74c { Elem_000ee74c *data; int size; unsigned capacity; };
extern "C" void FUN_000ee74c(Vec_000ee74c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000ee74c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037d948);
        FUN_0000d530();
    }
    Elem_000ee74c *p = Alloc_000ee74c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d099c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
