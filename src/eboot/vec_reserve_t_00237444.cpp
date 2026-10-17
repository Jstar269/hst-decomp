/* HSTMATCH module=EBOOT.BIN start=0x00237444 end=0x002374c8 symbol=FUN_00237444 lang=c++ */
/* Container reserve for a 2-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00237444 { int pad[3]; void *err; };
Reent_00237444 *FUN_0000fe3c(void);
int FUN_002374c8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c1d74[];
}
struct Elem_00237444 { char b[2]; };
struct Alloc_00237444 { Elem_00237444 *allocate(unsigned n) { return (Elem_00237444 *)FUN_00000bcc(n * sizeof(Elem_00237444)); } };
struct Vec_00237444 { Elem_00237444 *data; int size; unsigned capacity; };
extern "C" void FUN_00237444(Vec_00237444 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00237444))
        FUN_000043b4();
    Elem_00237444 *p = Alloc_00237444().allocate(n);
    if (p == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c1d74);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
