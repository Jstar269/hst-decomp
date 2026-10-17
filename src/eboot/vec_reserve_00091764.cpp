/* HSTMATCH module=EBOOT.BIN start=0x00091764 end=0x00091800 symbol=FUN_00091764 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00091764 { int pad[3]; void *err; };
Reent_00091764 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d2828[];
extern char DAT_002beb00[];
}
struct Elem_00091764 { int w[8]; };
struct Alloc_00091764 { Elem_00091764 *allocate(unsigned n) { return (Elem_00091764 *)FUN_00000bcc(n * sizeof(Elem_00091764)); } };
struct Vec_00091764 { Elem_00091764 *data; int size; unsigned capacity; };
extern "C" void FUN_00091764(Vec_00091764 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00091764)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d2828);
        FUN_0000d518();
    }
    Elem_00091764 *p = Alloc_00091764().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002beb00);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
