/* HSTMATCH module=EBOOT.BIN start=0x0005e954 end=0x0005e9fc symbol=FUN_0005e954 lang=c++ */
/* Clone of src/eboot/vec_reserve_00116d74.cpp (hstclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0005e954 { int pad[3]; void *err; };
Reent_0005e954 *FUN_0000fe3c(void);
int FUN_0005dd0c(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d0f88[];
extern char DAT_002bc5a8[];
}
struct Elem_0005e954 { int w[3]; };
struct Alloc_0005e954 { Elem_0005e954 *allocate(unsigned n) { return (Elem_0005e954 *)FUN_00000bcc(n * sizeof(Elem_0005e954)); } };
struct Vec_0005e954 { Elem_0005e954 *data; int size; unsigned capacity; };
extern "C" void FUN_0005e954(Vec_0005e954 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0005e954)) {
        FUN_0005dd0c(FUN_0000fe3c()->err, DAT_002d0f88);
        FUN_0000d518();
    }
    Elem_0005e954 *p = Alloc_0005e954().allocate(n);
    if (p == 0) {
        FUN_0005dd0c(FUN_0000fe3c()->err, DAT_002bc5a8);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
