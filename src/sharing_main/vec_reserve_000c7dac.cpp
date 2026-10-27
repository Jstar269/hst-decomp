/* HSTMATCH module=hstp_trans_main.prx start=0x000c7dac end=0x000c7e48 symbol=FUN_000c7dac lang=c++ data=0x0037c444 */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037c444-0x0037c458) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000c7dac { int pad[3]; void *err; };
Reent_000c7dac *FUN_0000fe3c(void);
int FUN_000c7774(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc430[];
}
struct Alloc_000c7dac { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000c7dac { void **data; int size; unsigned capacity; };
extern "C" void FUN_000c7dac(Vec_000c7dac *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_000c7774(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    void **p = Alloc_000c7dac().allocate(n);
    if (p == 0) {
        FUN_000c7774(FUN_0000fe3c()->err, DAT_002cc430);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
