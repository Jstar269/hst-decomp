/* HSTMATCH module=EBOOT.BIN start=0x00238ab4 end=0x00238b5c symbol=FUN_00238ab4 lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00238ab4 { int pad[3]; void *err; };
Reent_00238ab4 *FUN_0000fe3c(void);
int FUN_002374c8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002f5300[];
extern char DAT_002c9ee8[];
}
struct Elem_00238ab4 { int w[3]; };
struct Alloc_00238ab4 { Elem_00238ab4 *allocate(unsigned n) { return (Elem_00238ab4 *)FUN_00000bcc(n * sizeof(Elem_00238ab4)); } };
struct Vec_00238ab4 { Elem_00238ab4 *data; int size; unsigned capacity; };
extern "C" void FUN_00238ab4(Vec_00238ab4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00238ab4)) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002f5300);
        FUN_0000d518();
    }
    Elem_00238ab4 *p = Alloc_00238ab4().allocate(n);
    if (p == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9ee8);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
