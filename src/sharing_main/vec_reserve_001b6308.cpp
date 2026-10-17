/* HSTMATCH module=hstp_trans_main.prx start=0x001b6308 end=0x001b63a4 symbol=FUN_001b6308 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001b6308 { int pad[3]; void *err; };
Reent_001b6308 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003895e0[];
extern char DAT_002d3424[];
}
struct Alloc_001b6308 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001b6308 { void **data; int size; unsigned capacity; };
extern "C" void FUN_001b6308(Vec_001b6308 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003895e0);
        FUN_0000d530();
    }
    void **p = Alloc_001b6308().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d3424);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
