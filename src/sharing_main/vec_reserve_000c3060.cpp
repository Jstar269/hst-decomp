/* HSTMATCH module=hstp_trans_main.prx start=0x000c3060 end=0x000c30fc symbol=FUN_000c3060 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000c3060 { int pad[3]; void *err; };
Reent_000c3060 *FUN_0000fe3c(void);
int FUN_000bd6f0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037bf00[];
extern char DAT_002d02d8[];
}
struct Alloc_000c3060 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000c3060 { void **data; int size; unsigned capacity; };
extern "C" void FUN_000c3060(Vec_000c3060 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_000bd6f0(FUN_0000fe3c()->err, DAT_0037bf00);
        FUN_0000d530();
    }
    void **p = Alloc_000c3060().allocate(n);
    if (p == 0) {
        FUN_000bd6f0(FUN_0000fe3c()->err, DAT_002d02d8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
