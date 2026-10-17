/* HSTMATCH module=EBOOT.BIN start=0x0020673c end=0x002067c0 symbol=FUN_0020673c lang=c++ */
/* Clone of src/eboot/vec_reserve_000c4450.cpp (hstclone.py tag c7): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve (length_error variant): length check throws through 0x43b4; allocate n words through
   an allocator temporary (32-byte frame); report allocation failure on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0020673c { int pad[3]; void *err; };
Reent_0020673c *FUN_0000fe3c(void);
int FUN_002059ec(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002bffcc[];
}
struct Alloc_0020673c { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0020673c { void **data; int size; unsigned capacity; };
extern "C" void FUN_0020673c(Vec_0020673c *v, unsigned n)
{
    if (n > 0x3fffffff)
        FUN_000043b4();
    void **p = Alloc_0020673c().allocate(n);
    if (p == 0) {
        FUN_002059ec(FUN_0000fe3c()->err, DAT_002bffcc);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
