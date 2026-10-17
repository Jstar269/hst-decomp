/* HSTMATCH module=EBOOT.BIN start=0x00166874 end=0x00166910 symbol=FUN_00166874 lang=c++ */
/* Container reserve for a 2-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00166874 { int pad[3]; void *err; };
Reent_00166874 *FUN_0000fe3c(void);
int FUN_00165ef4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e03e8[];
extern char DAT_002c1d74[];
}
struct Elem_00166874 { char b[2]; };
struct Alloc_00166874 { Elem_00166874 *allocate(unsigned n) { return (Elem_00166874 *)FUN_00000bcc(n * sizeof(Elem_00166874)); } };
struct Vec_00166874 { Elem_00166874 *data; int size; unsigned capacity; };
extern "C" void FUN_00166874(Vec_00166874 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00166874)) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002e03e8);
        FUN_0000d518();
    }
    Elem_00166874 *p = Alloc_00166874().allocate(n);
    if (p == 0) {
        FUN_00165ef4(FUN_0000fe3c()->err, DAT_002c1d74);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
