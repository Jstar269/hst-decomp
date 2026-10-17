/* HSTMATCH module=EBOOT.BIN start=0x0014a7bc end=0x0014a86c symbol=FUN_0014a7bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Word vector re-reserve: clear the size through `int n = size; shrink(n, Alloc());` (unfolded size - size;
   the empty allocator temporary gives the 16-byte frame slot), free the old block, then the inline reserve(n)
   (length check through 0x43b4, allocate, report failure on newlib stderr and abort). The second argument
   is unused. Names provisional. */
extern "C" {
struct Reent_0014a7bc { int pad[3]; void *err; };
Reent_0014a7bc *FUN_0000fe3c(void);
int FUN_00145ac4(void *stream, const char *format, ...);
void FUN_0000d518(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c18f4[];
}
struct Alloc_0014a7bc { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_0014a7bc {
    void **data; int size; unsigned capacity;
    void shrink(int n, Alloc_0014a7bc) { size -= n; }
    void reserve(unsigned n)
    {
        if (n > 0x3fffffff)
            FUN_000043b4();
        void **p = Alloc_0014a7bc().allocate(n);
        if (p == 0) {
            FUN_00145ac4(FUN_0000fe3c()->err, DAT_002c18f4);
            FUN_0000d518();
        }
        data = p;
        capacity = n;
    }
};
extern "C" void FUN_0014a7bc(Vec_0014a7bc *v, int x, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_0014a7bc());
    if (v->data) {
        operator delete(v->data);
        v->data = 0;
        v->capacity = 0;
    }
    v->reserve(n);
}
