/* HSTMATCH module=hstp_trans_main.prx start=0x001dddd8 end=0x001dde74 symbol=FUN_001dddd8 lang=c++ */
/* Clone of src/eboot/vec_reserve_00054d9c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve: length check, allocate n words, report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001dddd8 { int pad[3]; void *err; };
Reent_001dddd8 *FUN_0000fe3c(void);
int FUN_001d0468(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00392aa4[];
extern char DAT_002d698c[];
}
struct Alloc_001dddd8 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001dddd8 { void **data; int size; unsigned capacity; };
extern "C" void FUN_001dddd8(Vec_001dddd8 *v, unsigned n)
{
    if (n > 0x3fffffff) {
        FUN_001d0468(FUN_0000fe3c()->err, DAT_00392aa4);
        FUN_0000d530();
    }
    void **p = Alloc_001dddd8().allocate(n);
    if (p == 0) {
        FUN_001d0468(FUN_0000fe3c()->err, DAT_002d698c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
