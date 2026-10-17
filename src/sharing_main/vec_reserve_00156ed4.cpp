/* HSTMATCH module=hstp_trans_main.prx start=0x00156ed4 end=0x00156f70 symbol=FUN_00156ed4 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00156ed4 { int pad[3]; void *err; };
Reent_00156ed4 *FUN_0000fe3c(void);
int FUN_0014db60(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00383478[];
extern char DAT_002d1bd8[];
}
struct Alloc_00156ed4 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_00156ed4 { void **data; int size; unsigned capacity; };
extern "C" void FUN_00156ed4(Vec_00156ed4 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_00383478);
        FUN_0000d530();
    }
    void **p = Alloc_00156ed4().allocate(n);
    if (p == 0) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_002d1bd8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
