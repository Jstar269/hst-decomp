/* HSTMATCH module=EBOOT.BIN start=0x000e9728 end=0x000e97c4 symbol=FUN_000e9728 lang=c++ */
/* Clone of src/eboot/vec_reserve_00091764.cpp (hstclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000e9728 { int pad[3]; void *err; };
Reent_000e9728 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d6b70[];
extern char DAT_002c0750[];
}
struct Elem_000e9728 { int w[8]; };
struct Alloc_000e9728 { Elem_000e9728 *allocate(unsigned n) { return (Elem_000e9728 *)FUN_00000bcc(n * sizeof(Elem_000e9728)); } };
struct Vec_000e9728 { Elem_000e9728 *data; int size; unsigned capacity; };
extern "C" void FUN_000e9728(Vec_000e9728 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000e9728)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6b70);
        FUN_0000d518();
    }
    Elem_000e9728 *p = Alloc_000e9728().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0750);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
