/* HSTMATCH module=EBOOT.BIN start=0x002944ac end=0x00294554 symbol=FUN_002944ac lang=c++ */
/* Container reserve for a 10-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_002944ac { int pad[3]; void *err; };
Reent_002944ac *FUN_0000fe3c(void);
int FUN_00294480(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002ffc40[];
extern char DAT_002cac44[];
}
struct Elem_002944ac { char b[10]; };
struct Alloc_002944ac { Elem_002944ac *allocate(unsigned n) { return (Elem_002944ac *)FUN_00000bcc(n * sizeof(Elem_002944ac)); } };
struct Vec_002944ac { Elem_002944ac *data; int size; unsigned capacity; };
extern "C" void FUN_002944ac(Vec_002944ac *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002944ac)) {
        FUN_00294480(FUN_0000fe3c()->err, DAT_002ffc40);
        FUN_0000d518();
    }
    Elem_002944ac *p = Alloc_002944ac().allocate(n);
    if (p == 0) {
        FUN_00294480(FUN_0000fe3c()->err, DAT_002cac44);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
