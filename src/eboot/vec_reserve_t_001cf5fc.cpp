/* HSTMATCH module=EBOOT.BIN start=0x001cf5fc end=0x001cf68c symbol=FUN_001cf5fc lang=c++ */
/* Container reserve for a 80-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_001cf5fc { int pad[3]; void *err; };
Reent_001cf5fc *FUN_0000fe3c(void);
int FUN_001c5018(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c18a0[];
}
struct Elem_001cf5fc { int w[20]; };
struct Alloc_001cf5fc { Elem_001cf5fc *allocate(unsigned n) { return (Elem_001cf5fc *)FUN_00000bcc(n * sizeof(Elem_001cf5fc)); } };
struct Vec_001cf5fc { Elem_001cf5fc *data; int size; unsigned capacity; };
extern "C" void FUN_001cf5fc(Vec_001cf5fc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_001cf5fc))
        FUN_000043b4();
    Elem_001cf5fc *p = Alloc_001cf5fc().allocate(n);
    if (p == 0) {
        FUN_001c5018(FUN_0000fe3c()->err, DAT_002c18a0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
