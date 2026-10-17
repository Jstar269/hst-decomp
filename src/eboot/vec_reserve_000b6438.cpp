/* HSTMATCH module=EBOOT.BIN start=0x000b6438 end=0x000b64e0 symbol=FUN_000b6438 lang=c++ */
/* Container reserve for a 18-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_000b6438 { int pad[3]; void *err; };
Reent_000b6438 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d47c0[];
extern char DAT_002bffe8[];
}
struct Elem_000b6438 { char b[18]; };
struct Alloc_000b6438 { Elem_000b6438 *allocate(unsigned n) { return (Elem_000b6438 *)FUN_00000bcc(n * sizeof(Elem_000b6438)); } };
struct Vec_000b6438 { Elem_000b6438 *data; int size; unsigned capacity; };
extern "C" void FUN_000b6438(Vec_000b6438 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000b6438)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d47c0);
        FUN_0000d518();
    }
    Elem_000b6438 *p = Alloc_000b6438().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bffe8);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
