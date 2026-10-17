/* HSTMATCH module=EBOOT.BIN start=0x0023b71c end=0x0023b7b8 symbol=FUN_0023b71c lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0023b71c { int pad[3]; void *err; };
Reent_0023b71c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002f5404[];
extern char DAT_002c9f80[];
}
struct Elem_0023b71c { int w[2]; };
struct Alloc_0023b71c { Elem_0023b71c *allocate(unsigned n) { return (Elem_0023b71c *)FUN_00000bcc(n * sizeof(Elem_0023b71c)); } };
struct Vec_0023b71c { Elem_0023b71c *data; int size; unsigned capacity; };
extern "C" void FUN_0023b71c(Vec_0023b71c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0023b71c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002f5404);
        FUN_0000d518();
    }
    Elem_0023b71c *p = Alloc_0023b71c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c9f80);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
