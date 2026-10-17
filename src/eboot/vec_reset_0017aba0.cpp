/* HSTMATCH module=EBOOT.BIN start=0x0017aba0 end=0x0017ac68 symbol=FUN_0017aba0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container reset to capacity n for 4-byte elements (vec_reset_001a710c with the reserve inlined): clear the
   size through an inline shrink with an empty allocator temporary, free and forget the old block, then check
   n against max_size (0xffffffff / 4), allocate through an allocator temporary, report failures on newlib
   stderr and abort; both paths merge into one data store (bnezl with the sw in its delay slot). The second
   argument is an unused empty allocator. Names provisional. */
extern "C" {
struct Reent_0017aba0 { int pad[3]; void *err; };
Reent_0017aba0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e0680[]; /* "vector length error" */
extern char DAT_002c1ff8[]; /* "Memory allocation failure" */
}
typedef int Elem_0017aba0;
struct Alloc_0017aba0 {
    Elem_0017aba0 *allocate(unsigned n) { return (Elem_0017aba0 *)FUN_00000bcc(n * sizeof(Elem_0017aba0)); }
};
struct Vec_0017aba0 {
    Elem_0017aba0 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0017aba0) { size -= n; }
    void reserve(unsigned n)
    {
        if (n > 0xffffffffu / sizeof(Elem_0017aba0)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e0680);
            FUN_0000d518();
        }
        Elem_0017aba0 *p = Alloc_0017aba0().allocate(n);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1ff8);
            FUN_0000d518();
        }
        data = p;
        capacity = n;
    }
};
extern "C" void FUN_0017aba0(Vec_0017aba0 *v, Alloc_0017aba0, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_0017aba0());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    v->reserve(n);
}
