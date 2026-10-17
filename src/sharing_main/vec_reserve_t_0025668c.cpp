/* HSTMATCH module=hstp_trans_main.prx start=0x0025668c end=0x0025671c symbol=FUN_0025668c lang=c++ */
/* Clone of src/eboot/vec_reserve_t_0005e3a4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0025668c { int pad[3]; void *err; };
Reent_0025668c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002daa5c[];
}
struct Elem_0025668c { int w[3]; };
struct Alloc_0025668c { Elem_0025668c *allocate(unsigned n) { return (Elem_0025668c *)FUN_00000bcc(n * sizeof(Elem_0025668c)); } };
struct Vec_0025668c { Elem_0025668c *data; int size; unsigned capacity; };
extern "C" void FUN_0025668c(Vec_0025668c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0025668c))
        FUN_000043b4();
    Elem_0025668c *p = Alloc_0025668c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002daa5c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
