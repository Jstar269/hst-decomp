/* HSTMATCH module=EBOOT.BIN start=0x001a89ec end=0x001a8a94 symbol=FUN_001a89ec lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001a89ec { int pad[3]; void *err; };
Reent_001a89ec *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e1d10[];
extern char DAT_002c2ee0[];
}
struct Elem_001a89ec { int w[3]; };
struct Alloc_001a89ec { Elem_001a89ec *allocate(unsigned n) { return (Elem_001a89ec *)FUN_00000bcc(n * sizeof(Elem_001a89ec)); } };
struct Vec_001a89ec { Elem_001a89ec *data; int size; unsigned capacity; };
extern "C" void FUN_001a89ec(Vec_001a89ec *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001a89ec)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e1d10);
        FUN_0000d518();
    }
    Elem_001a89ec *p = Alloc_001a89ec().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2ee0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
