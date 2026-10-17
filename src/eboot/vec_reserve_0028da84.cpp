/* HSTMATCH module=EBOOT.BIN start=0x0028da84 end=0x0028db20 symbol=FUN_0028da84 lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0028da84 { int pad[3]; void *err; };
Reent_0028da84 *FUN_0000fe3c(void);
int FUN_0028c0cc(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002feed0[];
extern char DAT_002cab40[];
}
struct Elem_0028da84 { int w[2]; };
struct Alloc_0028da84 { Elem_0028da84 *allocate(unsigned n) { return (Elem_0028da84 *)FUN_00000bcc(n * sizeof(Elem_0028da84)); } };
struct Vec_0028da84 { Elem_0028da84 *data; int size; unsigned capacity; };
extern "C" void FUN_0028da84(Vec_0028da84 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0028da84)) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002feed0);
        FUN_0000d518();
    }
    Elem_0028da84 *p = Alloc_0028da84().allocate(n);
    if (p == 0) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002cab40);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
