/* HSTMATCH module=EBOOT.BIN start=0x0006ef74 end=0x0006f010 symbol=FUN_0006ef74 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0006ef74 { int pad[3]; void *err; };
Reent_0006ef74 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d130c[];
extern char DAT_002bc714[];
}
struct Alloc_0006ef74 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0006ef74 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0006ef74(Vec_0006ef74 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d130c);
        FUN_0000d518();
    }
    void **p = Alloc_0006ef74().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc714);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
