/* HSTMATCH module=hstp_trans_main.prx start=0x001c92a4 end=0x001c9340 symbol=FUN_001c92a4 lang=c++ data=0x003918d4 */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003918d4-0x003918e8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001c92a4 { int pad[3]; void *err; };
Reent_001c92a4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d6754[];
}
struct Alloc_001c92a4 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001c92a4 { void **data; int size; unsigned capacity; };
extern "C" void FUN_001c92a4(Vec_001c92a4 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    void **p = Alloc_001c92a4().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6754);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
