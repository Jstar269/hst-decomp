/* HSTMATCH module=EBOOT.BIN start=0x0017ac68 end=0x0017ad10 symbol=FUN_0017ac68 lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0017ac68 { int pad[3]; void *err; };
Reent_0017ac68 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e0680[];
extern char DAT_002c1fc0[];
}
struct Elem_0017ac68 { int w[3]; };
struct Alloc_0017ac68 { Elem_0017ac68 *allocate(unsigned n) { return (Elem_0017ac68 *)FUN_00000bcc(n * sizeof(Elem_0017ac68)); } };
struct Vec_0017ac68 { Elem_0017ac68 *data; int size; unsigned capacity; };
extern "C" void FUN_0017ac68(Vec_0017ac68 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0017ac68)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e0680);
        FUN_0000d518();
    }
    Elem_0017ac68 *p = Alloc_0017ac68().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1fc0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
