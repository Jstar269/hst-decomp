/* HSTMATCH module=hstp_trans_main.prx start=0x0005f7ec end=0x0005f888 symbol=FUN_0005f7ec lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0005f7ec { int pad[3]; void *err; };
Reent_0005f7ec *FUN_0000fe3c(void);
int FUN_0005dfc0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00376dd8[];
extern char DAT_002cc3c0[];
}
struct Alloc_0005f7ec { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0005f7ec { void **data; int size; unsigned capacity; };
extern "C" void FUN_0005f7ec(Vec_0005f7ec *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0005dfc0(FUN_0000fe3c()->err, DAT_00376dd8);
        FUN_0000d530();
    }
    void **p = Alloc_0005f7ec().allocate(n);
    if (p == 0) {
        FUN_0005dfc0(FUN_0000fe3c()->err, DAT_002cc3c0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
