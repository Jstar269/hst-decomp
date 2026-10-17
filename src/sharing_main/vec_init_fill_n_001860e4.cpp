/* HSTMATCH module=hstp_trans_main.prx start=0x001860e4 end=0x00186164 symbol=FUN_001860e4 lang=c++ */
/* Clone of src/eboot/vec_init_fill_n_001799f0.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: construct n copies of x at the end (constructor helper). Storage comes from the
   out-of-line reserve 0x17a430, which takes the empty allocator by value (`move v0,zero; seb a2,v0` and the
   16-byte frame slot); the fill is a count-down loop with plain assignment (placement new adds a null test).
   Names provisional. */
struct Alloc_001860e4 {};
typedef int Elem_001860e4;
struct V_001860e4 {
    Elem_001860e4 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_00186b24(V_001860e4 *v, unsigned n, Alloc_001860e4 a);

inline void FillN_001860e4(Elem_001860e4 *p, unsigned n, const Elem_001860e4 &x)
{
    for (; n != 0; --n, ++p)
        *p = x;
}

extern "C" void FUN_001860e4(V_001860e4 *v, unsigned n, const Elem_001860e4 &x)
{
    if (n != 0) {
        FUN_00186b24(v, n, Alloc_001860e4());
        FillN_001860e4(v->data + v->size, n, x);
        v->size += n;
    }
}
