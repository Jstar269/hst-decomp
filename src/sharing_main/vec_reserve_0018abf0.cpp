/* HSTMATCH module=hstp_trans_main.prx start=0x0018abf0 end=0x0018ac8c symbol=FUN_0018abf0 lang=c++ data=0x00387d50 */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00387d50-0x00387d64) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0018abf0 { int pad[3]; void *err; };
Reent_0018abf0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d254c[];
}
struct Alloc_0018abf0 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0018abf0 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0018abf0(Vec_0018abf0 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    void **p = Alloc_0018abf0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d254c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
