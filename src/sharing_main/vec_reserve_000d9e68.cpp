/* HSTMATCH module=hstp_trans_main.prx start=0x000d9e68 end=0x000d9eec symbol=FUN_000d9e68 lang=c++ */
/* Clone of src/eboot/vec_reserve_00050f3c.cpp (hstclone.py tag x3): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve (length_error variant): length check throws through 0x43b4; allocate n words through
   an allocator temporary (32-byte frame); report allocation failure on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000d9e68 { int pad[3]; void *err; };
Reent_000d9e68 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d0870[];
}
struct Alloc_000d9e68 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000d9e68 { void **data; int size; unsigned capacity; };
extern "C" void FUN_000d9e68(Vec_000d9e68 *v, unsigned n)
{
    if (n > 0x3fffffff)
        FUN_000043b4();
    void **p = Alloc_000d9e68().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d0870);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}
