/* HSTMATCH module=EBOOT.BIN start=0x001cf6fc end=0x001cf798 symbol=FUN_001cf6fc lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001cf6fc { int pad[3]; void *err; };
Reent_001cf6fc *FUN_0000fe3c(void);
int FUN_001c5018(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002eac90[];
extern char DAT_002c647c[];
}
struct Alloc_001cf6fc { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001cf6fc { void **data; int size; unsigned capacity; };
extern "C" void FUN_001cf6fc(Vec_001cf6fc *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_001c5018(FUN_0000fe3c()->err, DAT_002eac90);
        FUN_0000d518();
    }
    void **p = Alloc_001cf6fc().allocate(n);
    if (p == 0) {
        FUN_001c5018(FUN_0000fe3c()->err, DAT_002c647c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
