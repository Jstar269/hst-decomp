/* HSTMATCH module=EBOOT.BIN start=0x000bf9c0 end=0x000bfa5c symbol=FUN_000bf9c0 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000bf9c0 { int pad[3]; void *err; };
Reent_000bf9c0 *FUN_0000fe3c(void);
int FUN_000ba3ac(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d55b0[];
extern char DAT_002c00b0[];
}
struct Alloc_000bf9c0 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000bf9c0 { void **data; int size; unsigned capacity; };
extern "C" void FUN_000bf9c0(Vec_000bf9c0 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_000ba3ac(FUN_0000fe3c()->err, DAT_002d55b0);
        FUN_0000d518();
    }
    void **p = Alloc_000bf9c0().allocate(n);
    if (p == 0) {
        FUN_000ba3ac(FUN_0000fe3c()->err, DAT_002c00b0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
