/* HSTMATCH module=EBOOT.BIN start=0x0010984c end=0x001098e8 symbol=FUN_0010984c lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0010984c { int pad[3]; void *err; };
Reent_0010984c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d8dbc[];
extern char DAT_002c0ff4[];
}
struct Elem_0010984c { int w[2]; };
struct Alloc_0010984c { Elem_0010984c *allocate(unsigned n) { return (Elem_0010984c *)FUN_00000bcc(n * sizeof(Elem_0010984c)); } };
struct Vec_0010984c { Elem_0010984c *data; int size; unsigned capacity; };
extern "C" void FUN_0010984c(Vec_0010984c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0010984c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d8dbc);
        FUN_0000d518();
    }
    Elem_0010984c *p = Alloc_0010984c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0ff4);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
