/* HSTMATCH module=hstp_trans_main.prx start=0x0018735c end=0x00187404 symbol=FUN_0018735c lang=c++ */
/* Clone of src/eboot/vec_reserve_0005e954.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0018735c { int pad[3]; void *err; };
Reent_0018735c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00387cb8[];
extern char DAT_002d24b8[];
}
struct Elem_0018735c { int w[3]; };
struct Alloc_0018735c { Elem_0018735c *allocate(unsigned n) { return (Elem_0018735c *)FUN_00000bcc(n * sizeof(Elem_0018735c)); } };
struct Vec_0018735c { Elem_0018735c *data; int size; unsigned capacity; };
extern "C" void FUN_0018735c(Vec_0018735c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0018735c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00387cb8);
        FUN_0000d530();
    }
    Elem_0018735c *p = Alloc_0018735c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d24b8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
