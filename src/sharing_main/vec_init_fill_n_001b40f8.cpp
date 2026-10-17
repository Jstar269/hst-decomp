/* HSTMATCH module=hstp_trans_main.prx start=0x001b40f8 end=0x001b4178 symbol=FUN_001b40f8 lang=c++ */
/* Clone of src/eboot/vec_init_fill_n_001799f0.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: construct n copies of x at the end (constructor helper). Storage comes from the
   out-of-line reserve 0x17a430, which takes the empty allocator by value (`move v0,zero; seb a2,v0` and the
   16-byte frame slot); the fill is a count-down loop with plain assignment (placement new adds a null test).
   Names provisional. */
struct Alloc_001b40f8 {};
typedef int Elem_001b40f8;
struct V_001b40f8 {
    Elem_001b40f8 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_001b5c18(V_001b40f8 *v, unsigned n, Alloc_001b40f8 a);

inline void FillN_001b40f8(Elem_001b40f8 *p, unsigned n, const Elem_001b40f8 &x)
{
    for (; n != 0; --n, ++p)
        *p = x;
}

extern "C" void FUN_001b40f8(V_001b40f8 *v, unsigned n, const Elem_001b40f8 &x)
{
    if (n != 0) {
        FUN_001b5c18(v, n, Alloc_001b40f8());
        FillN_001b40f8(v->data + v->size, n, x);
        v->size += n;
    }
}
