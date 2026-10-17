/* HSTMATCH module=EBOOT.BIN start=0x0028670c end=0x00286790 symbol=FUN_0028670c lang=c++ */
/* Clone of src/eboot/vec_reserve_000c4450.cpp (hstclone.py tag c7): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve (length_error variant): length check throws through 0x43b4; allocate n words through
   an allocator temporary (32-byte frame); report allocation failure on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0028670c { int pad[3]; void *err; };
Reent_0028670c *FUN_0000fe3c(void);
int FUN_002803d8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c0078[];
}
struct Alloc_0028670c { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0028670c { void **data; int size; unsigned capacity; };
extern "C" void FUN_0028670c(Vec_0028670c *v, unsigned n)
{
    if (n > 0x3fffffff)
        FUN_000043b4();
    void **p = Alloc_0028670c().allocate(n);
    if (p == 0) {
        FUN_002803d8(FUN_0000fe3c()->err, DAT_002c0078);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
