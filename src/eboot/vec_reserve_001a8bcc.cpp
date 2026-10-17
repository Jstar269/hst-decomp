/* HSTMATCH module=EBOOT.BIN start=0x001a8bcc end=0x001a8c74 symbol=FUN_001a8bcc lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001a8bcc { int pad[3]; void *err; };
Reent_001a8bcc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e1d10[];
extern char DAT_002c2e8c[];
}
struct Elem_001a8bcc { int w[3]; };
struct Alloc_001a8bcc { Elem_001a8bcc *allocate(unsigned n) { return (Elem_001a8bcc *)FUN_00000bcc(n * sizeof(Elem_001a8bcc)); } };
struct Vec_001a8bcc { Elem_001a8bcc *data; int size; unsigned capacity; };
extern "C" void FUN_001a8bcc(Vec_001a8bcc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001a8bcc)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e1d10);
        FUN_0000d518();
    }
    Elem_001a8bcc *p = Alloc_001a8bcc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2e8c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
