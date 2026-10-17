/* HSTMATCH module=EBOOT.BIN start=0x001a8a94 end=0x001a8b30 symbol=FUN_001a8a94 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001a8a94 { int pad[3]; void *err; };
Reent_001a8a94 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e1d10[];
extern char DAT_002c2ec4[];
}
struct Alloc_001a8a94 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001a8a94 { void **data; int size; unsigned capacity; };
extern "C" void FUN_001a8a94(Vec_001a8a94 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e1d10);
        FUN_0000d518();
    }
    void **p = Alloc_001a8a94().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2ec4);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
