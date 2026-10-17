/* HSTMATCH module=EBOOT.BIN start=0x0005e8b8 end=0x0005e954 symbol=FUN_0005e8b8 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0005e8b8 { int pad[3]; void *err; };
Reent_0005e8b8 *FUN_0000fe3c(void);
int FUN_0005dd0c(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d0f88[];
extern char DAT_002bc58c[];
}
struct Alloc_0005e8b8 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0005e8b8 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0005e8b8(Vec_0005e8b8 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0005dd0c(FUN_0000fe3c()->err, DAT_002d0f88);
        FUN_0000d518();
    }
    void **p = Alloc_0005e8b8().allocate(n);
    if (p == 0) {
        FUN_0005dd0c(FUN_0000fe3c()->err, DAT_002bc58c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
