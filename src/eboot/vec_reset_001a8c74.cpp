/* HSTMATCH module=EBOOT.BIN start=0x001a8c74 end=0x001a8d3c symbol=FUN_001a8c74 lang=c++ */
/* Clone of src/eboot/vec_reset_0017aba0.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container reset to capacity n for 4-byte elements (vec_reset_001a710c with the reserve inlined): clear the
   size through an inline shrink with an empty allocator temporary, free and forget the old block, then check
   n against max_size (0xffffffff / 4), allocate through an allocator temporary, report failures on newlib
   stderr and abort; both paths merge into one data store (bnezl with the sw in its delay slot). The second
   argument is an unused empty allocator. Names provisional. */
extern "C" {
struct Reent_001a8c74 { int pad[3]; void *err; };
Reent_001a8c74 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002e1d10[]; /* "vector length error" */
extern char DAT_002c2f18[]; /* "Memory allocation failure" */
}
typedef int Elem_001a8c74;
struct Alloc_001a8c74 {
    Elem_001a8c74 *allocate(unsigned n) { return (Elem_001a8c74 *)FUN_00000bcc(n * sizeof(Elem_001a8c74)); }
};
struct Vec_001a8c74 {
    Elem_001a8c74 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001a8c74) { size -= n; }
    void reserve(unsigned n)
    {
        if (n > 0xffffffffu / sizeof(Elem_001a8c74)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002e1d10);
            FUN_0000d518();
        }
        Elem_001a8c74 *p = Alloc_001a8c74().allocate(n);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2f18);
            FUN_0000d518();
        }
        data = p;
        capacity = n;
    }
};
extern "C" void FUN_001a8c74(Vec_001a8c74 *v, Alloc_001a8c74, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_001a8c74());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    v->reserve(n);
}
