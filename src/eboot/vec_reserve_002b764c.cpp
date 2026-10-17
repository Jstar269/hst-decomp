/* HSTMATCH module=EBOOT.BIN start=0x002b764c end=0x002b76e8 symbol=FUN_002b764c lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_002b764c { int pad[3]; void *err; };
Reent_002b764c *FUN_0000fe3c(void);
int FUN_002b71e0(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00303180[];
extern char DAT_002cc538[];
}
struct Elem_002b764c { int w[2]; };
struct Alloc_002b764c { Elem_002b764c *allocate(unsigned n) { return (Elem_002b764c *)FUN_00000bcc(n * sizeof(Elem_002b764c)); } };
struct Vec_002b764c { Elem_002b764c *data; int size; unsigned capacity; };
extern "C" void FUN_002b764c(Vec_002b764c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002b764c)) {
        FUN_002b71e0(FUN_0000fe3c()->err, DAT_00303180);
        FUN_0000d518();
    }
    Elem_002b764c *p = Alloc_002b764c().allocate(n);
    if (p == 0) {
        FUN_002b71e0(FUN_0000fe3c()->err, DAT_002cc538);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
