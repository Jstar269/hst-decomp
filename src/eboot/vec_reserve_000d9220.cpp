/* HSTMATCH module=EBOOT.BIN start=0x000d9220 end=0x000d92bc symbol=FUN_000d9220 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000d9220 { int pad[3]; void *err; };
Reent_000d9220 *FUN_0000fe3c(void);
int FUN_000d8b10(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d6a70[];
extern char DAT_002c0694[];
}
struct Alloc_000d9220 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000d9220 { void **data; int size; unsigned capacity; };
extern "C" void FUN_000d9220(Vec_000d9220 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_000d8b10(FUN_0000fe3c()->err, DAT_002d6a70);
        FUN_0000d518();
    }
    void **p = Alloc_000d9220().allocate(n);
    if (p == 0) {
        FUN_000d8b10(FUN_0000fe3c()->err, DAT_002c0694);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
