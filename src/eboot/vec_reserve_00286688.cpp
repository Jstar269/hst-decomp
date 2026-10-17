/* HSTMATCH module=EBOOT.BIN start=0x00286688 end=0x0028670c symbol=FUN_00286688 lang=c++ */
/* Clone of src/eboot/vec_reserve_000c4450.cpp (hstclone.py tag c7): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve (length_error variant): length check throws through 0x43b4; allocate n words through
   an allocator temporary (32-byte frame); report allocation failure on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00286688 { int pad[3]; void *err; };
Reent_00286688 *FUN_0000fe3c(void);
int FUN_002803d8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002bc46c[];
}
struct Alloc_00286688 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_00286688 { void **data; int size; unsigned capacity; };
extern "C" void FUN_00286688(Vec_00286688 *v, unsigned n)
{
    if (n > 0x3fffffff)
        FUN_000043b4();
    void **p = Alloc_00286688().allocate(n);
    if (p == 0) {
        FUN_002803d8(FUN_0000fe3c()->err, DAT_002bc46c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
