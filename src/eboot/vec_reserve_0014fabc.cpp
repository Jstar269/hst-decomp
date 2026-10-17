/* HSTMATCH module=EBOOT.BIN start=0x0014fabc end=0x0014fb58 symbol=FUN_0014fabc lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0014fabc { int pad[3]; void *err; };
Reent_0014fabc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dc360[];
extern char DAT_002c1a90[];
}
struct Elem_0014fabc { int w[2]; };
struct Alloc_0014fabc { Elem_0014fabc *allocate(unsigned n) { return (Elem_0014fabc *)FUN_00000bcc(n * sizeof(Elem_0014fabc)); } };
struct Vec_0014fabc { Elem_0014fabc *data; int size; unsigned capacity; };
extern "C" void FUN_0014fabc(Vec_0014fabc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014fabc)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dc360);
        FUN_0000d518();
    }
    Elem_0014fabc *p = Alloc_0014fabc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1a90);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
