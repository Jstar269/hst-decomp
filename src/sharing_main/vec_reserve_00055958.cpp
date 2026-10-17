/* HSTMATCH module=hstp_trans_main.prx start=0x00055958 end=0x000559f4 symbol=FUN_00055958 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00055958 { int pad[3]; void *err; };
Reent_00055958 *FUN_0000fe3c(void);
int FUN_00054928(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00376acc[];
extern char DAT_002cc2a0[];
}
struct Alloc_00055958 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_00055958 { void **data; int size; unsigned capacity; };
extern "C" void FUN_00055958(Vec_00055958 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_00054928(FUN_0000fe3c()->err, DAT_00376acc);
        FUN_0000d530();
    }
    void **p = Alloc_00055958().allocate(n);
    if (p == 0) {
        FUN_00054928(FUN_0000fe3c()->err, DAT_002cc2a0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
