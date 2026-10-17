/* HSTMATCH module=EBOOT.BIN start=0x00054d9c end=0x00054e38 symbol=FUN_00054d9c lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00054d9c { int pad[3]; void *err; };
Reent_00054d9c *FUN_0000fe3c(void);
int FUN_00054c90(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d0edc[];
extern char DAT_002bc46c[];
}
struct Alloc_00054d9c { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_00054d9c { void **data; int size; unsigned capacity; };
extern "C" void FUN_00054d9c(Vec_00054d9c *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_00054c90(FUN_0000fe3c()->err, DAT_002d0edc);
        FUN_0000d518();
    }
    void **p = Alloc_00054d9c().allocate(n);
    if (p == 0) {
        FUN_00054c90(FUN_0000fe3c()->err, DAT_002bc46c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
