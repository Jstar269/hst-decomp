/* HSTMATCH module=hstp_trans_main.prx start=0x0016cc80 end=0x0016cd1c symbol=FUN_0016cc80 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0016cc80 { int pad[3]; void *err; };
Reent_0016cc80 *FUN_0000fe3c(void);
int FUN_0016cbe4(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00385e3c[];
extern char DAT_002d2194[];
}
struct Alloc_0016cc80 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0016cc80 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0016cc80(Vec_0016cc80 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0016cbe4(FUN_0000fe3c()->err, DAT_00385e3c);
        FUN_0000d530();
    }
    void **p = Alloc_0016cc80().allocate(n);
    if (p == 0) {
        FUN_0016cbe4(FUN_0000fe3c()->err, DAT_002d2194);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
