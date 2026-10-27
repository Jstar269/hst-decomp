/* HSTMATCH module=EBOOT.BIN start=0x000c4544 end=0x000c45e0 symbol=FUN_000c4544 lang=c++ data=0x002d5ab4 */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d5ab4-0x002d5ac8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000c4544 { int pad[3]; void *err; };
Reent_000c4544 *FUN_0000fe3c(void);
int FUN_000c3f0c(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002bc5e0[];
}
struct Alloc_000c4544 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000c4544 { void **data; int size; unsigned capacity; };
extern "C" void FUN_000c4544(Vec_000c4544 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_000c3f0c(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    void **p = Alloc_000c4544().allocate(n);
    if (p == 0) {
        FUN_000c3f0c(FUN_0000fe3c()->err, DAT_002bc5e0);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
