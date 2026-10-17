/* HSTMATCH module=hstp_trans_main.prx start=0x00187294 end=0x0018735c symbol=FUN_00187294 lang=c++ */
/* Clone of src/eboot/vec_reset_0017aba0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container reset to capacity n for 4-byte elements (vec_reset_001a710c with the reserve inlined): clear the
   size through an inline shrink with an empty allocator temporary, free and forget the old block, then check
   n against max_size (0xffffffff / 4), allocate through an allocator temporary, report failures on newlib
   stderr and abort; both paths merge into one data store (bnezl with the sw in its delay slot). The second
   argument is an unused empty allocator. Names provisional. */
extern "C" {
struct Reent_00187294 { int pad[3]; void *err; };
Reent_00187294 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00387cb8[]; /* "vector length error" */
extern char DAT_002d24f0[]; /* "Memory allocation failure" */
}
typedef int Elem_00187294;
struct Alloc_00187294 {
    Elem_00187294 *allocate(unsigned n) { return (Elem_00187294 *)FUN_00000bcc(n * sizeof(Elem_00187294)); }
};
struct Vec_00187294 {
    Elem_00187294 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00187294) { size -= n; }
    void reserve(unsigned n)
    {
        if (n > 0xffffffffu / sizeof(Elem_00187294)) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_00387cb8);
            FUN_0000d530();
        }
        Elem_00187294 *p = Alloc_00187294().allocate(n);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d24f0);
            FUN_0000d530();
        }
        data = p;
        capacity = n;
    }
};
extern "C" void FUN_00187294(Vec_00187294 *v, Alloc_00187294, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_00187294());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    v->reserve(n);
}
