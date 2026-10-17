/* HSTMATCH module=hstp_trans_main.prx start=0x0005a928 end=0x0005a9ac symbol=FUN_0005a928 lang=c++ */
/* Clone of src/eboot/vec_reserve_00050f3c.cpp (hstclone.py tag x3): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve (length_error variant): length check throws through 0x43b4; allocate n words through
   an allocator temporary (32-byte frame); report allocation failure on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0005a928 { int pad[3]; void *err; };
Reent_0005a928 *FUN_0000fe3c(void);
int FUN_000593d0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc33c[];
}
struct Alloc_0005a928 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0005a928 { void **data; int size; unsigned capacity; };
extern "C" void FUN_0005a928(Vec_0005a928 *v, unsigned n)
{
    if (n > 0x3fffffff)
        FUN_000043b4();
    void **p = Alloc_0005a928().allocate(n);
    if (p == 0) {
        FUN_000593d0(FUN_0000fe3c()->err, DAT_002cc33c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
