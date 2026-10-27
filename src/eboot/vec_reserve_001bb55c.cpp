/* HSTMATCH module=EBOOT.BIN start=0x001bb55c end=0x001bb5f8 symbol=FUN_001bb55c lang=c++ data=0x002e9d0c */
/* Clone of src/eboot/vec_reserve_000b64e0.cpp (hstclone.py tag c5): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e9d0c-0x002e9d20) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001bb55c { int pad[3]; void *err; };
Reent_001bb55c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c6244[];
}
struct Alloc_001bb55c { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001bb55c { void **data; int size; unsigned capacity; };
extern "C" void FUN_001bb55c(Vec_001bb55c *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d518();
    }
    void **p = Alloc_001bb55c().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c6244);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
