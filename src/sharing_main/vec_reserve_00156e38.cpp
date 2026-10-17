/* HSTMATCH module=hstp_trans_main.prx start=0x00156e38 end=0x00156ed4 symbol=FUN_00156e38 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00156e38 { int pad[3]; void *err; };
Reent_00156e38 *FUN_0000fe3c(void);
int FUN_0014db60(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00383478[];
extern char DAT_002d1bf4[];
}
struct Alloc_00156e38 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_00156e38 { void **data; int size; unsigned capacity; };
extern "C" void FUN_00156e38(Vec_00156e38 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_00383478);
        FUN_0000d530();
    }
    void **p = Alloc_00156e38().allocate(n);
    if (p == 0) {
        FUN_0014db60(FUN_0000fe3c()->err, DAT_002d1bf4);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
