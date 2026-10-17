/* HSTMATCH module=EBOOT.BIN start=0x0014b724 end=0x0014b7c0 symbol=FUN_0014b724 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0014b724 { int pad[3]; void *err; };
Reent_0014b724 *FUN_0000fe3c(void);
int FUN_00145ac4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dc120[];
extern char DAT_002c17c0[];
}
struct Alloc_0014b724 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0014b724 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0014b724(Vec_0014b724 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002dc120);
        FUN_0000d518();
    }
    void **p = Alloc_0014b724().allocate(n);
    if (p == 0) {
        FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c17c0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
