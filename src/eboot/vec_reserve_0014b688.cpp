/* HSTMATCH module=EBOOT.BIN start=0x0014b688 end=0x0014b724 symbol=FUN_0014b688 lang=c++ */
/* Clone of src/eboot/vec_reserve_00091764.cpp (hstclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0014b688 { int pad[3]; void *err; };
Reent_0014b688 *FUN_0000fe3c(void);
int FUN_00145ac4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dc120[];
extern char DAT_002c17dc[];
}
struct Elem_0014b688 { int w[8]; };
struct Alloc_0014b688 { Elem_0014b688 *allocate(unsigned n) { return (Elem_0014b688 *)FUN_00000bcc(n * sizeof(Elem_0014b688)); } };
struct Vec_0014b688 { Elem_0014b688 *data; int size; unsigned capacity; };
extern "C" void FUN_0014b688(Vec_0014b688 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0014b688)) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002dc120);
        FUN_0000d518();
    }
    Elem_0014b688 *p = Alloc_0014b688().allocate(n);
    if (p == 0) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c17dc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
