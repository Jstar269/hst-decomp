/* HSTMATCH module=hstp_trans_main.prx start=0x001b6240 end=0x001b6308 symbol=FUN_001b6240 lang=c++ */
/* Clone of src/eboot/vec_reset_0017aba0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container reset to capacity n for 4-byte elements (vec_reset_001a710c with the reserve inlined): clear the
   size through an inline shrink with an empty allocator temporary, free and forget the old block, then check
   n against max_size (0xffffffff / 4), allocate through an allocator temporary, report failures on newlib
   stderr and abort; both paths merge into one data store (bnezl with the sw in its delay slot). The second
   argument is an unused empty allocator. Names provisional. */
extern "C" {
struct Reent_001b6240 { int pad[3]; void *err; };
Reent_001b6240 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003895e0[]; /* "vector length error" */
extern char DAT_002d3424[]; /* "Memory allocation failure" */
}
typedef int Elem_001b6240;
struct Alloc_001b6240 {
    Elem_001b6240 *allocate(unsigned n) { return (Elem_001b6240 *)FUN_00000bcc(n * sizeof(Elem_001b6240)); }
};
struct Vec_001b6240 {
    Elem_001b6240 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001b6240) { size -= n; }
    void reserve(unsigned n)
    {
        if (n > 0xffffffffu / sizeof(Elem_001b6240)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003895e0);
            FUN_0000d530();
        }
        Elem_001b6240 *p = Alloc_001b6240().allocate(n);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d3424);
            FUN_0000d530();
        }
        data = p;
        capacity = n;
    }
};
extern "C" void FUN_001b6240(Vec_001b6240 *v, Alloc_001b6240, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_001b6240());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    v->reserve(n);
}
