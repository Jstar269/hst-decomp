/* HSTMATCH module=hstp_trans_main.prx start=0x001569b8 end=0x00156a54 symbol=FUN_001569b8 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001569b8 { int pad[3]; void *err; };
Reent_001569b8 *FUN_0000fe3c(void);
int FUN_0014db60(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00383478[];
extern char DAT_002d1cd4[];
}
struct Alloc_001569b8 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001569b8 { void **data; int size; unsigned capacity; };
extern "C" void FUN_001569b8(Vec_001569b8 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_00383478);
        FUN_0000d530();
    }
    void **p = Alloc_001569b8().allocate(n);
    if (p == 0) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_002d1cd4);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
