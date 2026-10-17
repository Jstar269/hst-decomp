/* HSTMATCH module=EBOOT.BIN start=0x001a8dd8 end=0x001a8e80 symbol=FUN_001a8dd8 lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001a8dd8 { int pad[3]; void *err; };
Reent_001a8dd8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e1d10[];
extern char DAT_002c2e8c[];
}
struct Elem_001a8dd8 { int w[3]; };
struct Alloc_001a8dd8 { Elem_001a8dd8 *allocate(unsigned n) { return (Elem_001a8dd8 *)FUN_00000bcc(n * sizeof(Elem_001a8dd8)); } };
struct Vec_001a8dd8 { Elem_001a8dd8 *data; int size; unsigned capacity; };
extern "C" void FUN_001a8dd8(Vec_001a8dd8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001a8dd8)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e1d10);
        FUN_0000d518();
    }
    Elem_001a8dd8 *p = Alloc_001a8dd8().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2e8c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
