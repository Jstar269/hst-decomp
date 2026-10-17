/* HSTMATCH module=EBOOT.BIN start=0x000fc784 end=0x000fc820 symbol=FUN_000fc784 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000fc784 { int pad[3]; void *err; };
Reent_000fc784 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d8354[];
extern char DAT_002c0d74[];
}
struct Alloc_000fc784 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000fc784 { void **data; int size; unsigned capacity; };
extern "C" void FUN_000fc784(Vec_000fc784 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d8354);
        FUN_0000d518();
    }
    void **p = Alloc_000fc784().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0d74);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
