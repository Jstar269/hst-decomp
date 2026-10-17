/* HSTMATCH module=EBOOT.BIN start=0x0023ec10 end=0x0023ecb8 symbol=FUN_0023ec10 lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0023ec10 { int pad[3]; void *err; };
Reent_0023ec10 *FUN_0000fe3c(void);
int FUN_0023e4d4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002f550c[];
extern char DAT_002ca49c[];
}
struct Elem_0023ec10 { int w[3]; };
struct Alloc_0023ec10 { Elem_0023ec10 *allocate(unsigned n) { return (Elem_0023ec10 *)FUN_00000bcc(n * sizeof(Elem_0023ec10)); } };
struct Vec_0023ec10 { Elem_0023ec10 *data; int size; unsigned capacity; };
extern "C" void FUN_0023ec10(Vec_0023ec10 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0023ec10)) {
        FUN_0023e4d4(FUN_0000fe3c()->err, DAT_002f550c);
        FUN_0000d518();
    }
    Elem_0023ec10 *p = Alloc_0023ec10().allocate(n);
    if (p == 0) {
        FUN_0023e4d4(FUN_0000fe3c()->err, DAT_002ca49c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
