/* HSTMATCH module=EBOOT.BIN start=0x000bfa5c end=0x000bfaf8 symbol=FUN_000bfa5c lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000bfa5c { int pad[3]; void *err; };
Reent_000bfa5c *FUN_0000fe3c(void);
int FUN_000ba3ac(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d55b0[];
extern char DAT_002c0094[];
}
struct Alloc_000bfa5c { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000bfa5c { void **data; int size; unsigned capacity; };
extern "C" void FUN_000bfa5c(Vec_000bfa5c *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_000ba3ac(FUN_0000fe3c()->err, DAT_002d55b0);
        FUN_0000d518();
    }
    void **p = Alloc_000bfa5c().allocate(n);
    if (p == 0) {
        FUN_000ba3ac(FUN_0000fe3c()->err, DAT_002c0094);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
