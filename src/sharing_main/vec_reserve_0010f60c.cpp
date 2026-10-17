/* HSTMATCH module=hstp_trans_main.prx start=0x0010f60c end=0x0010f6a8 symbol=FUN_0010f60c lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag x13): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0010f60c { int pad[3]; void *err; };
Reent_0010f60c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037fb90[];
extern char DAT_002d12a4[];
}
struct Elem_0010f60c { int w[2]; };
struct Alloc_0010f60c { Elem_0010f60c *allocate(unsigned n) { return (Elem_0010f60c *)FUN_00000bcc(n * sizeof(Elem_0010f60c)); } };
struct Vec_0010f60c { Elem_0010f60c *data; int size; unsigned capacity; };
extern "C" void FUN_0010f60c(Vec_0010f60c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0010f60c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037fb90);
        FUN_0000d530();
    }
    Elem_0010f60c *p = Alloc_0010f60c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d12a4);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
