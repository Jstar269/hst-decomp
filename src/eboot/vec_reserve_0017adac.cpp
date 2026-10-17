/* HSTMATCH module=EBOOT.BIN start=0x0017adac end=0x0017ae48 symbol=FUN_0017adac lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0017adac { int pad[3]; void *err; };
Reent_0017adac *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e0680[];
extern char DAT_002c1ff8[];
}
struct Alloc_0017adac { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0017adac { void **data; int size; unsigned capacity; };
extern "C" void FUN_0017adac(Vec_0017adac *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e0680);
        FUN_0000d518();
    }
    void **p = Alloc_0017adac().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1ff8);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
