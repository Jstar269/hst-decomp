/* HSTMATCH module=hstp_trans_main.prx start=0x000dd14c end=0x000dd1e8 symbol=FUN_000dd14c lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000dd14c { int pad[3]; void *err; };
Reent_000dd14c *FUN_0000fe3c(void);
int FUN_000dbf00(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d640[];
extern char DAT_002d08c4[];
}
struct Alloc_000dd14c { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000dd14c { void **data; int size; unsigned capacity; };
extern "C" void FUN_000dd14c(Vec_000dd14c *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_000dbf00(FUN_0000fe3c()->err, DAT_0037d640);
        FUN_0000d530();
    }
    void **p = Alloc_000dd14c().allocate(n);
    if (p == 0) {
        FUN_000dbf00(FUN_0000fe3c()->err, DAT_002d08c4);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
