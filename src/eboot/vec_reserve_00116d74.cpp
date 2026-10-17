/* HSTMATCH module=EBOOT.BIN start=0x00116d74 end=0x00116e1c symbol=FUN_00116d74 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00116d74 { int pad[3]; void *err; };
Reent_00116d74 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d9370[];
extern char DAT_002c1218[];
}
struct Elem_00116d74 { int w[3]; };
struct Alloc_00116d74 { Elem_00116d74 *allocate(unsigned n) { return (Elem_00116d74 *)FUN_00000bcc(n * sizeof(Elem_00116d74)); } };
struct Vec_00116d74 { Elem_00116d74 *data; int size; unsigned capacity; };
extern "C" void FUN_00116d74(Vec_00116d74 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00116d74)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d9370);
        FUN_0000d518();
    }
    Elem_00116d74 *p = Alloc_00116d74().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1218);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
