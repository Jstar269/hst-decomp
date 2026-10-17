/* HSTMATCH module=hstp_trans_main.prx start=0x0029f108 end=0x0029f1a4 symbol=FUN_0029f108 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0029f108 { int pad[3]; void *err; };
Reent_0029f108 *FUN_0000fe3c(void);
int FUN_0029baf0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003a7e44[];
extern char DAT_002db1ac[];
}
struct Alloc_0029f108 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0029f108 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0029f108(Vec_0029f108 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_0029baf0(FUN_0000fe3c()->err, DAT_003a7e44);
        FUN_0000d530();
    }
    void **p = Alloc_0029f108().allocate(n);
    if (p == 0) {
        FUN_0029baf0(FUN_0000fe3c()->err, DAT_002db1ac);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
