/* HSTMATCH module=hstp_trans_main.prx start=0x0014ad0c end=0x0014adb4 symbol=FUN_0014ad0c lang=c++ */
/* Container reserve for a 36-byte element type (template instance, hsttmpl.py tag t2s): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0014ad0c { int pad[3]; void *err; };
Reent_0014ad0c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00382d80[];
extern char DAT_002d1b14[];
}
struct Elem_0014ad0c { int w[9]; };
struct Alloc_0014ad0c { Elem_0014ad0c *allocate(unsigned n) { return (Elem_0014ad0c *)FUN_00000bcc(n * sizeof(Elem_0014ad0c)); } };
struct Vec_0014ad0c { Elem_0014ad0c *data; int size; unsigned capacity; };
extern "C" void FUN_0014ad0c(Vec_0014ad0c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014ad0c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00382d80);
        FUN_0000d530();
    }
    Elem_0014ad0c *p = Alloc_0014ad0c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1b14);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
