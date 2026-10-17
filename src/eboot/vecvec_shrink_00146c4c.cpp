/* HSTMATCH module=EBOOT.BIN start=0x00146c4c end=0x00146ce0 symbol=FUN_00146c4c lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00146c4c {};
struct Elem_00146c4c { int v; ~Elem_00146c4c() {} };
struct Base_00146c4c {
    Elem_00146c4c *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00146c4c) { size -= n; }
    ~Base_00146c4c() { int n = size; shrink(n, Alloc_00146c4c()); delete data; }
};
struct Inner_00146c4c : Base_00146c4c { ~Inner_00146c4c() {} };
inline void Destroy_00146c4c(Inner_00146c4c *p) { if (p) p->~Inner_00146c4c(); }
struct Outer_00146c4c { Inner_00146c4c *data; int size; };
extern "C" void FUN_00146c4c(Outer_00146c4c *v, int n)
{
    Inner_00146c4c *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_00146c4c(--p);
}
