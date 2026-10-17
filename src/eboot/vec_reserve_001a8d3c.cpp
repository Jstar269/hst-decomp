/* HSTMATCH module=EBOOT.BIN start=0x001a8d3c end=0x001a8dd8 symbol=FUN_001a8d3c lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001a8d3c { int pad[3]; void *err; };
Reent_001a8d3c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e1d10[];
extern char DAT_002c2f18[];
}
struct Alloc_001a8d3c { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001a8d3c { void **data; int size; unsigned capacity; };
extern "C" void FUN_001a8d3c(Vec_001a8d3c *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e1d10);
        FUN_0000d518();
    }
    void **p = Alloc_001a8d3c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2f18);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
