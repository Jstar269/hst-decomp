/* HSTMATCH module=hstp_trans_main.prx start=0x000558bc end=0x00055958 symbol=FUN_000558bc lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000558bc { int pad[3]; void *err; };
Reent_000558bc *FUN_0000fe3c(void);
int FUN_00054928(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00376acc[];
extern char DAT_002cc2bc[];
}
struct Alloc_000558bc { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000558bc { void **data; int size; unsigned capacity; };
extern "C" void FUN_000558bc(Vec_000558bc *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_00054928(FUN_0000fe3c()->err, DAT_00376acc);
        FUN_0000d530();
    }
    void **p = Alloc_000558bc().allocate(n);
    if (p == 0) {
        FUN_00054928(FUN_0000fe3c()->err, DAT_002cc2bc);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
