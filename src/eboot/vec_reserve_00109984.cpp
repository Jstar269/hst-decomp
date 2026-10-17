/* HSTMATCH module=EBOOT.BIN start=0x00109984 end=0x00109a20 symbol=FUN_00109984 lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00109984 { int pad[3]; void *err; };
Reent_00109984 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d8dbc[];
extern char DAT_002c1048[];
}
struct Alloc_00109984 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_00109984 { void **data; int size; unsigned capacity; };
extern "C" void FUN_00109984(Vec_00109984 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d8dbc);
        FUN_0000d518();
    }
    void **p = Alloc_00109984().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1048);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
