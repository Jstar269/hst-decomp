/* HSTMATCH module=EBOOT.BIN start=0x0017ad10 end=0x0017adac symbol=FUN_0017ad10 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0017ad10 { int pad[3]; void *err; };
Reent_0017ad10 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e0680[];
extern char DAT_002c1fdc[];
}
struct Alloc_0017ad10 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0017ad10 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0017ad10(Vec_0017ad10 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e0680);
        FUN_0000d518();
    }
    void **p = Alloc_0017ad10().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1fdc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
