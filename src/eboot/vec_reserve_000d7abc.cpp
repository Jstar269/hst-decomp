/* HSTMATCH module=EBOOT.BIN start=0x000d7abc end=0x000d7b58 symbol=FUN_000d7abc lang=c++ */
/* Clone of src/eboot/vec_reserve_00091764.cpp (hstclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000d7abc { int pad[3]; void *err; };
Reent_000d7abc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d6854[];
extern char DAT_002c05d0[];
}
struct Elem_000d7abc { int w[8]; };
struct Alloc_000d7abc { Elem_000d7abc *allocate(unsigned n) { return (Elem_000d7abc *)FUN_00000bcc(n * sizeof(Elem_000d7abc)); } };
struct Vec_000d7abc { Elem_000d7abc *data; int size; unsigned capacity; };
extern "C" void FUN_000d7abc(Vec_000d7abc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000d7abc)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6854);
        FUN_0000d518();
    }
    Elem_000d7abc *p = Alloc_000d7abc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c05d0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
