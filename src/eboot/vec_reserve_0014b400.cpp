/* HSTMATCH module=EBOOT.BIN start=0x0014b400 end=0x0014b4a8 symbol=FUN_0014b400 lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0014b400 { int pad[3]; void *err; };
Reent_0014b400 *FUN_0000fe3c(void);
int FUN_00145ac4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dc120[];
extern char DAT_002c184c[];
}
struct Elem_0014b400 { int w[3]; };
struct Alloc_0014b400 { Elem_0014b400 *allocate(unsigned n) { return (Elem_0014b400 *)FUN_00000bcc(n * sizeof(Elem_0014b400)); } };
struct Vec_0014b400 { Elem_0014b400 *data; int size; unsigned capacity; };
extern "C" void FUN_0014b400(Vec_0014b400 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014b400)) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002dc120);
        FUN_0000d518();
    }
    Elem_0014b400 *p = Alloc_0014b400().allocate(n);
    if (p == 0) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c184c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
