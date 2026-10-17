/* HSTMATCH module=EBOOT.BIN start=0x0006728c end=0x00067334 symbol=FUN_0006728c lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0006728c { int pad[3]; void *err; };
Reent_0006728c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d11f0[];
extern char DAT_002bc634[];
}
struct Elem_0006728c { int w[3]; };
struct Alloc_0006728c { Elem_0006728c *allocate(unsigned n) { return (Elem_0006728c *)FUN_00000bcc(n * sizeof(Elem_0006728c)); } };
struct Vec_0006728c { Elem_0006728c *data; int size; unsigned capacity; };
extern "C" void FUN_0006728c(Vec_0006728c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0006728c)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d11f0);
        FUN_0000d518();
    }
    Elem_0006728c *p = Alloc_0006728c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc634);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
