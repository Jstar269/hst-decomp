/* HSTMATCH module=EBOOT.BIN start=0x001606f4 end=0x00160790 symbol=FUN_001606f4 lang=c++ data=0x002de880 */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002de880-0x002de894) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001606f4 { int pad[3]; void *err; };
Reent_001606f4 *FUN_0000fe3c(void);
int FUN_00160658(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c1d58[];
}
struct Alloc_001606f4 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001606f4 { void **data; int size; unsigned capacity; };
extern "C" void FUN_001606f4(Vec_001606f4 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_00160658(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    void **p = Alloc_001606f4().allocate(n);
    if (p == 0) {
        FUN_00160658(FUN_0000fe3c()->err, DAT_002c1d58);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
