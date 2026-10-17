/* HSTMATCH module=hstp_trans_main.prx start=0x0014ab2c end=0x0014abd4 symbol=FUN_0014ab2c lang=c++ */
/* Clone of src/eboot/vec_reserve_0005e954.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0014ab2c { int pad[3]; void *err; };
Reent_0014ab2c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00382d80[];
extern char DAT_002d1b68[];
}
struct Elem_0014ab2c { int w[3]; };
struct Alloc_0014ab2c { Elem_0014ab2c *allocate(unsigned n) { return (Elem_0014ab2c *)FUN_00000bcc(n * sizeof(Elem_0014ab2c)); } };
struct Vec_0014ab2c { Elem_0014ab2c *data; int size; unsigned capacity; };
extern "C" void FUN_0014ab2c(Vec_0014ab2c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014ab2c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00382d80);
        FUN_0000d530();
    }
    Elem_0014ab2c *p = Alloc_0014ab2c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1b68);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
