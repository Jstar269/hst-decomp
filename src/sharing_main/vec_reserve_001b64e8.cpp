/* HSTMATCH module=hstp_trans_main.prx start=0x001b64e8 end=0x001b6584 symbol=FUN_001b64e8 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001b64e8 { int pad[3]; void *err; };
Reent_001b64e8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003895e0[];
extern char DAT_002d345c[];
}
struct Alloc_001b64e8 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001b64e8 { void **data; int size; unsigned capacity; };
extern "C" void FUN_001b64e8(Vec_001b64e8 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003895e0);
        FUN_0000d530();
    }
    void **p = Alloc_001b64e8().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d345c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
