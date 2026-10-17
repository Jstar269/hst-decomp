/* HSTMATCH module=hstp_trans_main.prx start=0x0005af4c end=0x0005afe8 symbol=FUN_0005af4c lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0005af4c { int pad[3]; void *err; };
Reent_0005af4c *FUN_0000fe3c(void);
int FUN_000593d0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00376c88[];
extern char DAT_002cc33c[];
}
struct Alloc_0005af4c { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0005af4c { void **data; int size; unsigned capacity; };
extern "C" void FUN_0005af4c(Vec_0005af4c *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_000593d0(FUN_0000fe3c()->err, DAT_00376c88);
        FUN_0000d530();
    }
    void **p = Alloc_0005af4c().allocate(n);
    if (p == 0) {
        FUN_000593d0(FUN_0000fe3c()->err, DAT_002cc33c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
