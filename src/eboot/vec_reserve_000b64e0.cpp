/* HSTMATCH module=EBOOT.BIN start=0x000b64e0 end=0x000b657c symbol=FUN_000b64e0 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000b64e0 { int pad[3]; void *err; };
Reent_000b64e0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d47c0[];
extern char DAT_002bffcc[];
}
struct Alloc_000b64e0 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000b64e0 { void **data; int size; unsigned capacity; };
extern "C" void FUN_000b64e0(Vec_000b64e0 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d47c0);
        FUN_0000d518();
    }
    void **p = Alloc_000b64e0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bffcc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
