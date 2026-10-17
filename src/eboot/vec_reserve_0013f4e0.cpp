/* HSTMATCH module=EBOOT.BIN start=0x0013f4e0 end=0x0013f588 symbol=FUN_0013f4e0 lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0013f4e0 { int pad[3]; void *err; };
Reent_0013f4e0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dbb20[];
extern char DAT_002c1788[];
}
struct Elem_0013f4e0 { int w[3]; };
struct Alloc_0013f4e0 { Elem_0013f4e0 *allocate(unsigned n) { return (Elem_0013f4e0 *)FUN_00000bcc(n * sizeof(Elem_0013f4e0)); } };
struct Vec_0013f4e0 { Elem_0013f4e0 *data; int size; unsigned capacity; };
extern "C" void FUN_0013f4e0(Vec_0013f4e0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0013f4e0)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dbb20);
        FUN_0000d518();
    }
    Elem_0013f4e0 *p = Alloc_0013f4e0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1788);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
