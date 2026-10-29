/* HSTMATCH module=EBOOT.BIN start=0x000c4450 end=0x000c44d4 symbol=FUN_000c4450 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve (length_error variant): length check throws through 0x43b4; allocate n words through
   an allocator temporary (32-byte frame); report allocation failure on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000c4450 { int pad[3]; void *err; };
Reent_000c4450 *FUN_0000fe3c(void);
int FUN_000c3f0c(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002bc450[];
}
struct Alloc_000c4450 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_000c4450 { void **data; int size; unsigned capacity; };

/* Allocates storage for n pointers into v (throws when n is too large, aborts when the allocation fails). */
#define MAX_ELEMENTS 0x3fffffff /* larger counts overflow the byte size */

extern "C" void FUN_000c4450(Vec_000c4450 *v, unsigned n)
{
    if (n > MAX_ELEMENTS)
        FUN_000043b4();
    void **p = Alloc_000c4450().allocate(n);
    if (p == 0) {
        FUN_000c3f0c(FUN_0000fe3c()->err, DAT_002bc450);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
