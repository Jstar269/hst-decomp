/* HSTMATCH module=EBOOT.BIN start=0x00238964 end=0x00238a0c symbol=FUN_00238964 lang=c++ */
/* Container reserve for a 28-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00238964 { int pad[3]; void *err; };
Reent_00238964 *FUN_0000fe3c(void);
int FUN_002374c8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002f5300[];
extern char DAT_002c9f04[];
}
struct Elem_00238964 { int w[7]; };
struct Alloc_00238964 { Elem_00238964 *allocate(unsigned n) { return (Elem_00238964 *)FUN_00000bcc(n * sizeof(Elem_00238964)); } };
struct Vec_00238964 { Elem_00238964 *data; int size; unsigned capacity; };
extern "C" void FUN_00238964(Vec_00238964 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00238964)) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002f5300);
        FUN_0000d518();
    }
    Elem_00238964 *p = Alloc_00238964().allocate(n);
    if (p == 0) {
        FUN_002374c8(FUN_0000fe3c()->err, DAT_002c9f04);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
