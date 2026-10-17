/* HSTMATCH module=hstp_trans_main.prx start=0x0014aeec end=0x0014af88 symbol=FUN_0014aeec lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0014aeec { int pad[3]; void *err; };
Reent_0014aeec *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00382d80[];
extern char DAT_002d1ac0[];
}
struct Alloc_0014aeec { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0014aeec { void **data; int size; unsigned capacity; };
extern "C" void FUN_0014aeec(Vec_0014aeec *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00382d80);
        FUN_0000d530();
    }
    void **p = Alloc_0014aeec().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1ac0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
