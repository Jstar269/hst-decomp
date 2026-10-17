/* HSTMATCH module=hstp_trans_main.prx start=0x002c466c end=0x002c4704 symbol=FUN_002c466c lang=c++ */
/* Clone of src/eboot/vec_reserve_t_002b4bac.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 100-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_002c466c { int pad[3]; void *err; };
Reent_002c466c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dc7c0[];
}
struct Elem_002c466c { int w[25]; };
struct Alloc_002c466c { Elem_002c466c *allocate(unsigned n) { return (Elem_002c466c *)FUN_00000bcc(n * sizeof(Elem_002c466c)); } };
struct Vec_002c466c { Elem_002c466c *data; int size; unsigned capacity; };
extern "C" void FUN_002c466c(Vec_002c466c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002c466c))
        FUN_000043b4();
    Elem_002c466c *p = Alloc_002c466c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dc7c0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
