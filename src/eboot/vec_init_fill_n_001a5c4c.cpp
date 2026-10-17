/* HSTMATCH module=EBOOT.BIN start=0x001a5c4c end=0x001a5ccc symbol=FUN_001a5c4c lang=c++ */
/* Clone of src/eboot/vec_init_fill_n_001799f0.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 4-byte elements: construct n copies of x at the end (constructor helper). Storage comes from the
   out-of-line reserve 0x17a430, which takes the empty allocator by value (`move v0,zero; seb a2,v0` and the
   16-byte frame slot); the fill is a count-down loop with plain assignment (placement new adds a null test).
   Names provisional. */
struct Alloc_001a5c4c {};
typedef int Elem_001a5c4c;
struct V_001a5c4c {
    Elem_001a5c4c *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_000c4450(V_001a5c4c *v, unsigned n, Alloc_001a5c4c a);

inline void FillN_001a5c4c(Elem_001a5c4c *p, unsigned n, const Elem_001a5c4c &x)
{
    for (; n != 0; --n, ++p)
        *p = x;
}

extern "C" void FUN_001a5c4c(V_001a5c4c *v, unsigned n, const Elem_001a5c4c &x)
{
    if (n != 0) {
        FUN_000c4450(v, n, Alloc_001a5c4c());
        FillN_001a5c4c(v->data + v->size, n, x);
        v->size += n;
    }
}
