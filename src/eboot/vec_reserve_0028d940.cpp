/* HSTMATCH module=EBOOT.BIN start=0x0028d940 end=0x0028d9dc symbol=FUN_0028d940 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0028d940 { int pad[3]; void *err; };
Reent_0028d940 *FUN_0000fe3c(void);
int FUN_0028c0cc(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002feed0[];
extern char DAT_002cab78[];
}
struct Alloc_0028d940 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0028d940 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0028d940(Vec_0028d940 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002feed0);
        FUN_0000d518();
    }
    void **p = Alloc_0028d940().allocate(n);
    if (p == 0) {
        FUN_0028c0cc(FUN_0000fe3c()->err, DAT_002cab78);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
