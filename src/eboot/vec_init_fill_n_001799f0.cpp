/* HSTMATCH module=EBOOT.BIN start=0x001799f0 end=0x00179a70 symbol=FUN_001799f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: construct n copies of x at the end (constructor helper). Storage comes from the
   out-of-line reserve 0x17a430, which takes the empty allocator by value (`move v0,zero; seb a2,v0` and the
   16-byte frame slot); the fill is a count-down loop with plain assignment (placement new adds a null test).
   Names provisional. */
struct Alloc_001799f0 {};
typedef int Elem_001799f0;
struct V_001799f0 {
    Elem_001799f0 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_0017a430(V_001799f0 *v, unsigned n, Alloc_001799f0 a);

inline void FillN_001799f0(Elem_001799f0 *p, unsigned n, const Elem_001799f0 &x)
{
    for (; n != 0; --n, ++p)
        *p = x;
}

extern "C" void FUN_001799f0(V_001799f0 *v, unsigned n, const Elem_001799f0 &x)
{
    if (n != 0) {
        FUN_0017a430(v, n, Alloc_001799f0());
        FillN_001799f0(v->data + v->size, n, x);
        v->size += n;
    }
}
