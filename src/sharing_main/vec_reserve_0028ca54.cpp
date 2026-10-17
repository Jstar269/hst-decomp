/* HSTMATCH module=hstp_trans_main.prx start=0x0028ca54 end=0x0028caf0 symbol=FUN_0028ca54 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0028ca54 { int pad[3]; void *err; };
Reent_0028ca54 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003a73d4[];
extern char DAT_002dafa8[];
}
struct Alloc_0028ca54 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0028ca54 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0028ca54(Vec_0028ca54 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003a73d4);
        FUN_0000d530();
    }
    void **p = Alloc_0028ca54().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dafa8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
