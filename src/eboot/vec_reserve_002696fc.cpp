/* HSTMATCH module=EBOOT.BIN start=0x002696fc end=0x00269798 symbol=FUN_002696fc lang=c++ */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_002696fc { int pad[3]; void *err; };
Reent_002696fc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002fe048[];
extern char DAT_002ca8bc[];
}
struct Alloc_002696fc { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_002696fc { void **data; int size; unsigned capacity; };
extern "C" void FUN_002696fc(Vec_002696fc *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002fe048);
        FUN_0000d518();
    }
    void **p = Alloc_002696fc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002ca8bc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
