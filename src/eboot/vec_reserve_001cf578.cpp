/* HSTMATCH module=EBOOT.BIN start=0x001cf578 end=0x001cf5fc symbol=FUN_001cf578 lang=c++ */
/* Clone of src/eboot/vec_reserve_000c4450.cpp (hstclone.py tag c7): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve (length_error variant): length check throws through 0x43b4; allocate n words through
   an allocator temporary (32-byte frame); report allocation failure on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_001cf578 { int pad[3]; void *err; };
Reent_001cf578 *FUN_0000fe3c(void);
int FUN_001c5018(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c647c[];
}
struct Alloc_001cf578 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001cf578 { void **data; int size; unsigned capacity; };
extern "C" void FUN_001cf578(Vec_001cf578 *v, unsigned n)
{
    if (n > 0x3fffffff)
        FUN_000043b4();
    void **p = Alloc_001cf578().allocate(n);
    if (p == 0) {
        FUN_001c5018(FUN_0000fe3c()->err, DAT_002c647c);
        FUN_0000d518();
    }
    v->data = p;
    v->capacity = n;
}
