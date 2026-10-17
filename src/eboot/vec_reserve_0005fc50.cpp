/* HSTMATCH module=EBOOT.BIN start=0x0005fc50 end=0x0005fcec symbol=FUN_0005fc50 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0005fc50 { int pad[3]; void *err; };
Reent_0005fc50 *FUN_0000fe3c(void);
int FUN_0005f300(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d0fb4[];
extern char DAT_002bc5c4[];
}
struct Alloc_0005fc50 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0005fc50 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0005fc50(Vec_0005fc50 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0005f300(FUN_0000fe3c()->err, DAT_002d0fb4);
        FUN_0000d518();
    }
    void **p = Alloc_0005fc50().allocate(n);
    if (p == 0) {
        FUN_0005f300(FUN_0000fe3c()->err, DAT_002bc5c4);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
